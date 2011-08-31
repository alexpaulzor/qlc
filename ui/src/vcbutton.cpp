/*
  Q Light Controller
  vcbutton.cpp

  Copyright (c) Heikki Junnila

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  Version 2 as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details. The license is
  in the file "COPYING".

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include <QStyleOptionButton>
#include <QColorDialog>
#include <QImageReader>
#include <QFileDialog>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QByteArray>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QEvent>
#include <QTimer>
#include <QBrush>
#include <QStyle>
#include <QtXml>
#include <QMenu>
#include <QSize>
#include <QPen>

#include "qlcfile.h"

#include "vcbuttonproperties.h"
#include "functionselection.h"
#include "vcsoloframe.h"
#include "virtualconsole.h"
#include "mastertimer.h"
#include "outputmap.h"
#include "inputmap.h"
#include "vcbutton.h"
#include "function.h"
#include "fixture.h"
#include "doc.h"

const QSize VCButton::minimumSize(QSize(20, 20));
const QSize VCButton::defaultSize(QSize(50, 50));

/*****************************************************************************
 * Initialization
 *****************************************************************************/

VCButton::VCButton(QWidget* parent, Doc* doc, OutputMap* outputMap, InputMap* inputMap,
                   MasterTimer* masterTimer)
    : VCWidget(parent, doc, outputMap, inputMap, masterTimer)
    , m_adjustIntensity(false)
    , m_intensityAdjustment(1.0)
{
    /* Set the class name "VCButton" as the object name as well */
    setObjectName(VCButton::staticMetaObject.className());

    /* No function is initially attached to the button */
    m_function = Function::invalidId();

    setCaption(QString());
    setOn(false);
    setAction(Toggle);
    setFrameStyle(KVCFrameStyleNone);

    /* Menu actions */
    m_chooseIconAction = new QAction(QIcon(":/image.png"), tr("Choose..."),
                                     this);
    m_chooseIconAction->setShortcut(QKeySequence("SHIFT+C"));

    m_resetIconAction = new QAction(QIcon(":/undo.png"), tr("None"), this);
    m_resetIconAction->setShortcut(QKeySequence("SHIFT+ALT+C"));

    connect(m_chooseIconAction, SIGNAL(triggered(bool)),
            this, SLOT(slotChooseIcon()));
    connect(m_resetIconAction, SIGNAL(triggered(bool)),
            this, SLOT(slotResetIcon()));

    /* Initial size */
    setMinimumSize(VCButton::minimumSize);
    resize(VCButton::defaultSize);

    setStyle(App::saneStyle());

    /* Listen to function removals */
    connect(m_doc, SIGNAL(functionRemoved(quint32)),
            this, SLOT(slotFunctionRemoved(quint32)));
}

VCButton::~VCButton()
{
}

/*****************************************************************************
 * Clipboard
 *****************************************************************************/

VCWidget* VCButton::createCopy(VCWidget* parent)
{
    Q_ASSERT(parent != NULL);

    VCButton* button = new VCButton(parent, m_doc, m_outputMap, m_inputMap, m_masterTimer);
    if (button->copyFrom(this) == false)
    {
        delete button;
        button = NULL;
    }

    return button;
}

bool VCButton::copyFrom(VCWidget* widget)
{
    VCButton* button = qobject_cast <VCButton*> (widget);
    if (button == NULL)
        return false;

    /* Copy button-specific stuff */
    setIcon(button->icon());
    setKeySequence(button->keySequence());
    setFunction(button->function());
    setAdjustIntensity(button->adjustIntensity());
    setIntensityAdjustment(button->intensityAdjustment());

    /* Copy common stuff */
    return VCWidget::copyFrom(widget);
}

/*****************************************************************************
 * Properties
 *****************************************************************************/

void VCButton::editProperties()
{
    VCButtonProperties prop(this, m_doc, m_outputMap, m_inputMap, m_masterTimer);
    if (prop.exec() == QDialog::Accepted)
        m_doc->setModified();
}

/*****************************************************************************
 * Background color
 *****************************************************************************/

void VCButton::setBackgroundColor(const QColor& color)
{
    QPalette pal = palette();

    m_hasCustomBackgroundColor = true;
    m_backgroundImage = QString();
    pal.setColor(QPalette::Button, color);
    setPalette(pal);

    m_doc->setModified();
}

void VCButton::resetBackgroundColor()
{
    QColor fg;

    m_hasCustomBackgroundColor = false;
    m_backgroundImage = QString();

    /* Store foreground color */
    if (m_hasCustomForegroundColor == true)
        fg = palette().color(QPalette::ButtonText);

    /* Reset the whole palette to application palette */
    setPalette(QApplication::palette());

    /* Restore foreground color */
    if (fg.isValid() == true)
    {
        QPalette pal = palette();
        pal.setColor(QPalette::ButtonText, fg);
        setPalette(pal);
    }

    m_doc->setModified();
}

/*****************************************************************************
 * Foreground color
 *****************************************************************************/

void VCButton::setForegroundColor(const QColor& color)
{
    QPalette pal = palette();

    m_hasCustomForegroundColor = true;

    pal.setColor(QPalette::WindowText, color);
    pal.setColor(QPalette::ButtonText, color);
    setPalette(pal);

    m_doc->setModified();
}

void VCButton::resetForegroundColor()
{
    QColor bg;

    m_hasCustomForegroundColor = false;

    /* Store background color */
    if (m_hasCustomBackgroundColor == true)
        bg = palette().color(QPalette::Button);

    /* Reset the whole palette to application palette */
    setPalette(QApplication::palette());

    /* Restore foreground color */
    if (bg.isValid() == true)
        setBackgroundColor(bg);
    else if (m_backgroundImage.isEmpty() == false)
        setBackgroundImage(m_backgroundImage);

    m_doc->setModified();
}

/*****************************************************************************
 * Button icon
 *****************************************************************************/

void VCButton::setIcon(const QString& icon)
{
    m_icon = icon;
    update();
}

void VCButton::slotChooseIcon()
{
    /* No point coming here if there is no VC */
    VirtualConsole* vc = VirtualConsole::instance();
    if (vc == NULL)
        return;

    QString formats;
    QListIterator <QByteArray> it(QImageReader::supportedImageFormats());
    while (it.hasNext() == true)
        formats += QString("*.%1 ").arg(QString(it.next()).toLower());

    QString path;
    path = QFileDialog::getOpenFileName(this, tr("Select button icon"),
                                        icon(), tr("Images (%1)").arg(formats));
    if (path.isEmpty() == false)
    {
        VCWidget* widget;
        foreach(widget, vc->selectedWidgets())
        {
            VCButton* button = qobject_cast<VCButton*> (widget);
            if (button != NULL)
                button->setIcon(path);
        }
    }
}

void VCButton::slotResetIcon()
{
    m_icon = QString();
    update();
}

/*****************************************************************************
 * Load & Save
 *****************************************************************************/

bool VCButton::loadXML(const QDomElement* root)
{
    bool visible = false;
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;

    QDomNode node;
    QDomElement tag;
    QString str;

    Q_ASSERT(root != NULL);

    if (root->tagName() != KXMLQLCVCButton)
    {
        qWarning() << Q_FUNC_INFO << "Button node not found";
        return false;
    }

    /* Caption */
    setCaption(root->attribute(KXMLQLCVCCaption));

    /* Icon */
    setIcon(root->attribute(KXMLQLCVCButtonIcon));

    /* Children */
    node = root->firstChild();
    while (node.isNull() == false)
    {
        tag = node.toElement();
        if (tag.tagName() == KXMLQLCWindowState)
        {
            loadXMLWindowState(&tag, &x, &y, &w, &h, &visible);
            setGeometry(x, y, w, h);
        }
        else if (tag.tagName() == KXMLQLCVCAppearance)
        {
            loadXMLAppearance(&tag);
        }
        else if (tag.tagName() == KXMLQLCVCButtonFunction)
        {
            str = tag.attribute(KXMLQLCVCButtonFunctionID);
            setFunction(str.toUInt());
        }
        else if (tag.tagName() == KXMLQLCVCWidgetInput)
        {
            loadXMLInput(&tag);
        }
        else if (tag.tagName() == KXMLQLCVCButtonAction)
        {
            setAction(stringToAction(tag.text()));
        }
        else if (tag.tagName() == KXMLQLCVCButtonKey)
        {
            setKeySequence(QKeySequence(tag.text()));
        }
        else if (tag.tagName() == KXMLQLCVCButtonIntensity)
        {
            bool adjust;
            if (tag.attribute(KXMLQLCVCButtonIntensityAdjust) == KXMLQLCTrue)
                adjust = true;
            else
                adjust = false;
            setIntensityAdjustment(double(tag.text().toInt()) / double(100));
            setAdjustIntensity(adjust);
        }
        else if (tag.tagName() == "KeyBind") /* Legacy */
        {
            loadKeyBind(&tag);
        }
        else
        {
            qWarning() << Q_FUNC_INFO << "Unknown button tag:" << tag.tagName();
        }

        node = node.nextSibling();
    }

    /* All buttons start raised... */
    setOn(false);

    return true;
}

bool VCButton::saveXML(QDomDocument* doc, QDomElement* vc_root)
{
    QDomElement root;
    QDomElement tag;
    QDomText text;
    QString str;

    Q_ASSERT(doc != NULL);
    Q_ASSERT(vc_root != NULL);

    /* VC button entry */
    root = doc->createElement(KXMLQLCVCButton);
    vc_root->appendChild(root);

    /* Caption */
    root.setAttribute(KXMLQLCVCCaption, caption());

    /* Icon */
    root.setAttribute(KXMLQLCVCButtonIcon, icon());

    /* Function */
    tag = doc->createElement(KXMLQLCVCButtonFunction);
    root.appendChild(tag);
    str.setNum(function());
    tag.setAttribute(KXMLQLCVCButtonFunctionID, str);

    /* Action */
    tag = doc->createElement(KXMLQLCVCButtonAction);
    root.appendChild(tag);
    text = doc->createTextNode(actionToString(action()));
    tag.appendChild(text);

    /* Key sequence */
    if (m_keySequence.isEmpty() == false)
    {
        tag = doc->createElement(KXMLQLCVCButtonKey);
        root.appendChild(tag);
        text = doc->createTextNode(m_keySequence.toString());
        tag.appendChild(text);
    }

    /* Intensity adjustment */
    tag = doc->createElement(KXMLQLCVCButtonIntensity);
    tag.setAttribute(KXMLQLCVCButtonIntensityAdjust,
                     adjustIntensity() ? KXMLQLCTrue : KXMLQLCFalse);
    root.appendChild(tag);
    text = doc->createTextNode(QString::number(int(intensityAdjustment() * 100)));
    tag.appendChild(text);

    /* External input */
    saveXMLInput(doc, &root);

    /* Window state */
    saveXMLWindowState(doc, &root);

    /* Appearance */
    saveXMLAppearance(doc, &root);

    return true;
}

bool VCButton::loadKeyBind(const QDomElement* key_root)
{
    QDomElement tag;
    QDomNode node;

    if (key_root->tagName() != "KeyBind")
    {
        qWarning() << Q_FUNC_INFO << "KeyBind node not found";
        return false;
    }

    node = key_root->firstChild();
    while (node.isNull() == false)
    {
        tag = node.toElement();
        if (tag.tagName() == "Key")
        {
            int mod = tag.attribute("Modifier").toInt();
            int key = tag.text().toInt();

            if (key < Qt::Key_unknown)
                setKeySequence(QKeySequence(key | mod));
        }
        else if (tag.tagName() == "Action")
        {
            setAction(stringToAction(tag.text()));
        }
        else
        {
            qWarning() << Q_FUNC_INFO << "Unknown key binding tag:" << tag.tagName();
        }

        node = node.nextSibling();
    }

    return true;
}

/*****************************************************************************
 * Button state
 *****************************************************************************/

void VCButton::setOn(bool on)
{
    m_on = on;

    /* Send input feedback */
    if (m_inputUniverse != InputMap::invalidUniverse() &&
            m_inputChannel != InputMap::invalidChannel())
    {
        if (on == true)
        {
            m_inputMap->feedBack(m_inputUniverse,
                                       m_inputChannel,
                                       UCHAR_MAX);
        }
        else
        {
            m_inputMap->feedBack(m_inputUniverse,
                                       m_inputChannel,
                                       0);
        }
    }

    update();
}

bool VCButton::isChildOfSoloFrame()
{
    QWidget* parent = parentWidget();
    while (parent != NULL)
    {
        if (qobject_cast<VCSoloFrame*>(parent) != NULL)
            return true;
        parent = parent->parentWidget();
    }
    return false;
}

/*****************************************************************************
 * Key sequence handler
 *****************************************************************************/

void VCButton::setKeySequence(const QKeySequence& keySequence)
{
    m_keySequence = QKeySequence(keySequence);
}

void VCButton::slotKeyPressed(const QKeySequence& keySequence)
{
    if (m_keySequence == keySequence)
        pressFunction();
}

void VCButton::slotKeyReleased(const QKeySequence& keySequence)
{
    if (m_keySequence == keySequence)
        releaseFunction();
}

/*****************************************************************************
 * External input
 *****************************************************************************/

void VCButton::slotInputValueChanged(quint32 universe,
                                     quint32 channel,
                                     uchar value)
{
    Q_UNUSED(value);

    /* Don't allow operation during design mode */
    if (mode() == Doc::Design)
        return;

    if (universe == m_inputUniverse && channel == m_inputChannel)
    {
        if (m_action == Toggle && value > 0)
        {
            // Only toggle when the external button is pressed.
            // Releasing the button does nothing.
            pressFunction();
        }
        else if (m_action == Flash)
        {
            // Keep the button depressed only while the external button is kept down.
            // Raise the button when the external button is raised.
            if (isOn() == false && value > 0)
                pressFunction();
            else if (isOn() == true && value == 0)
                releaseFunction();
        }
    }
}

/*****************************************************************************
 * Function attachment
 *****************************************************************************/

void VCButton::setFunction(quint32 fid)
{
    Function* old = m_doc->function(m_function);
    if (old != NULL)
    {
        /* Get rid of old function connections */
        disconnect(old, SIGNAL(running(quint32)),
                   this, SLOT(slotFunctionRunning(quint32)));
        disconnect(old, SIGNAL(stopped(quint32)),
                   this, SLOT(slotFunctionStopped(quint32)));
        disconnect(old, SIGNAL(flashing(quint32,bool)),
                   this, SLOT(slotFunctionFlashing(quint32,bool)));
    }

    Function* function = m_doc->function(fid);
    if (function != NULL)
    {
        /* Connect to the new function */
        connect(function, SIGNAL(running(quint32)),
                this, SLOT(slotFunctionRunning(quint32)));
        connect(function, SIGNAL(stopped(quint32)),
                this, SLOT(slotFunctionStopped(quint32)));
        connect(function, SIGNAL(flashing(quint32,bool)),
                this, SLOT(slotFunctionFlashing(quint32,bool)));

        m_function = fid;

        setToolTip(function->name());
    }
    else
    {
        /* No function attachment */
        m_function = Function::invalidId();
        setToolTip(QString());
    }
}

void VCButton::slotFunctionRemoved(quint32 fid)
{
    /* Invalidate the button's function if it's the one that was removed */
    if (fid == m_function)
        setFunction(Function::invalidId());
}

/*****************************************************************************
 * Button action
 *****************************************************************************/

void VCButton::setAction(Action action)
{
    m_action = action;
}

QString VCButton::actionToString(VCButton::Action action)
{
    if (action == Flash)
        return QString(KXMLQLCVCButtonActionFlash);
    else
        return QString(KXMLQLCVCButtonActionToggle);
}

VCButton::Action VCButton::stringToAction(const QString& str)
{
    if (str == KXMLQLCVCButtonActionFlash)
        return Flash;
    else
        return Toggle;
}

/*****************************************************************************
 * Intensity adjustment
 *****************************************************************************/

void VCButton::setAdjustIntensity(bool adjust)
{
    m_adjustIntensity = adjust;
}

bool VCButton::adjustIntensity() const
{
    return m_adjustIntensity;
}

void VCButton::setIntensityAdjustment(qreal fraction)
{
    m_intensityAdjustment = fraction;
}

qreal VCButton::intensityAdjustment() const
{
    return m_intensityAdjustment;
}

/*****************************************************************************
 * Button press / release handlers
 *****************************************************************************/

void VCButton::pressFunction()
{
    Function* f = NULL;
    if (m_action == Toggle)
    {
        f = m_doc->function(m_function);
        if (f != NULL)
        {
            /* if the button is in a SoloFrame and the function is running but was started by a different function (a chaser or collection), 
             * turn of other functions and start it anyway.
             */
            if (isOn() == true && !(isChildOfSoloFrame() && f->initiatedByOtherFunction()))
                f->stop();
            else
            {
                emit functionStarting();
                m_masterTimer->startFunction(f, false);
                if (adjustIntensity() == true)
                    f->adjustIntensity(intensityAdjustment());
            }
        }
    }
    else if (m_action == Flash && isOn() == false)
    {
        f = m_doc->function(m_function);
        if (f != NULL)
            f->flash(m_masterTimer);
    }
}

void VCButton::releaseFunction()
{
    Function* f = NULL;

    if (m_action == Flash && isOn() == true)
    {
        f = m_doc->function(m_function);
        if (f != NULL)
            f->unFlash(m_masterTimer);
    }
}

void VCButton::slotFunctionRunning(quint32 fid)
{
    if (fid == m_function && m_action != Flash)
        setOn(true);
}

void VCButton::slotFunctionStopped(quint32 fid)
{
    if (fid == m_function && m_action != Flash)
    {
        setOn(false);
        slotBlinkReady();
        QTimer::singleShot(200, this, SLOT(slotBlinkReady()));
    }
}

void VCButton::slotFunctionFlashing(quint32 fid, bool state)
{
    if (fid == m_function)
        setOn(state);
}

void VCButton::slotBlinkReady()
{
    // This function is called twice with same XOR mask,
    // thus creating a brief opposite-color -- normal-color blink
    QPalette pal = palette();
    QColor color(pal.color(QPalette::Button));
    color.setRgb(color.red()^0xff, color.green()^0xff, color.blue()^0xff);
    pal.setColor(QPalette::Button, color);
    setPalette(pal);
}

/*****************************************************************************
 * Custom menu
 *****************************************************************************/

QMenu* VCButton::customMenu(QMenu* parentMenu)
{
    QMenu* menu = new QMenu(parentMenu);
    menu->setTitle(tr("Icon"));
    menu->addAction(m_chooseIconAction);
    menu->addAction(m_resetIconAction);

    return menu;
}

/*****************************************************************************
 * Event handlers
 *****************************************************************************/

void VCButton::paintEvent(QPaintEvent* e)
{
    QStyleOptionButton option;
    option.initFrom(this);

    /* This should look like a normal button */
    option.features = QStyleOptionButton::None;

    /* Sunken or raised based on isOn() status */
    if (isOn() == true)
        option.state = QStyle::State_Sunken;
    else
        option.state= QStyle::State_Raised;

    /* Enabled or disabled looks based on application mode */
    if (mode() == Doc::Operate)
        option.state |= QStyle::State_Enabled;

    /* Icon */
    if (icon() != QString())
    {
        option.icon = QIcon(icon());
        option.iconSize = QSize(26, 26);
    }
    else
    {
        option.icon = QIcon();
        option.iconSize = QSize(-1, -1);
    }

    /* Paint the button */
    QPainter painter(this);
    style()->drawControl(QStyle::CE_PushButton, &option, &painter, this);

    /* Paint caption with text wrapping */
    if (caption().isEmpty() == false)
    {
        style()->drawItemText(&painter,
                              rect(),
                              Qt::AlignCenter | Qt::TextWordWrap,
                              palette(),
                              (mode() == Doc::Operate),
                              caption());
    }

    /* Flash emblem */
    if (m_action == Flash)
    {
        QIcon icon(":/flash.png");
        painter.drawPixmap(rect().width() - 16, 0,
                           icon.pixmap(QSize(16, 16), QIcon::Normal, QIcon::On));
    }

    /* Stop painting here */
    painter.end();

    /* Draw a selection frame if appropriate */
    VCWidget::paintEvent(e);
}

void VCButton::mousePressEvent(QMouseEvent* e)
{
    if (mode() == Doc::Design)
        VCWidget::mousePressEvent(e);
    else
        pressFunction();
}

void VCButton::mouseReleaseEvent(QMouseEvent* e)
{
    if (mode() == Doc::Design)
        VCWidget::mouseReleaseEvent(e);
    else
        releaseFunction();
}
