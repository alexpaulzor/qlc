/*
  Q Light Controller
  vcslider.cpp

  Copyright (c) Heikki Junnila, Stefan Krumm

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

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QString>
#include <QSlider>
#include <QDebug>
#include <QLabel>
#include <QTime>
#include <QSize>
#include <QtXml>
#include <QPen>

#include "vcsliderproperties.h"
#include "qlcinputchannel.h"
#include "virtualconsole.h"
#include "universearray.h"
#include "mastertimer.h"
#include "collection.h"
#include "inputpatch.h"
#include "inputmap.h"
#include "vcslider.h"
#include "qlcmacros.h"
#include "qlcfile.h"
#include "chaser.h"
#include "scene.h"
#include "efx.h"
#include "app.h"
#include "doc.h"

static const quint32 KDefaultBusLowLimit ( 0 );
static const quint32 KDefaultBusHighLimit ( 10 );
const QSize VCSlider::defaultSize(QSize(60, 200));

/*****************************************************************************
 * Initialization
 *****************************************************************************/

VCSlider::VCSlider(QWidget* parent, Doc* doc, OutputMap* outputMap, InputMap* inputMap, MasterTimer* masterTimer)
    : VCWidget(parent, doc, outputMap, inputMap, masterTimer)
{
    /* Set the class name "VCSlider" as the object name as well */
    setObjectName(VCSlider::staticMetaObject.className());

    m_hbox = NULL;
    m_topLabel = NULL;
    m_slider = NULL;
    m_bottomLabel = NULL;
    m_tapButton = NULL;

    m_sliderMode = Bus;
    m_valueDisplayStyle = ExactValue;

    m_levelLowLimit = 0;
    m_levelHighLimit = UCHAR_MAX;

    m_bus = Bus::defaultFade();
    m_busLowLimit = KDefaultBusLowLimit;
    m_busHighLimit = KDefaultBusHighLimit;

    m_levelValue = 0;
    m_levelValueChanged = false;

    m_playbackFunction = Function::invalidId();
    m_playbackValue = 0;
    m_playbackValueChanged = false;

    m_time = NULL;

    setCaption(QString());
    setFrameStyle(KVCFrameStyleSunken);

    /* Main VBox */
    new QVBoxLayout(this);

    /* Top label */
    m_topLabel = new QLabel(this);
    layout()->addWidget(m_topLabel);
    m_topLabel->setAlignment(Qt::AlignHCenter);

    /* Slider's HBox |stretch|slider|stretch| */
    m_hbox = new QHBoxLayout();
    layout()->addItem(m_hbox);

    /* Put stretchable space before the slider (to its left side) */
    m_hbox->addStretch();

    /* The slider */
    m_slider = new QSlider(this);
    m_slider->setStyle(App::saneStyle());
    m_hbox->addWidget(m_slider);
    m_slider->setRange(KDefaultBusLowLimit * MasterTimer::frequency(),
                       KDefaultBusHighLimit * MasterTimer::frequency());
    m_slider->setPageStep(1);
    m_slider->setInvertedAppearance(false);
    connect(m_slider, SIGNAL(valueChanged(int)),
            this, SLOT(slotSliderMoved(int)));
    m_externalMovement = false;

    /* Put stretchable space after the slider (to its right side) */
    m_hbox->addStretch();

    /* Tap button */
    m_tapButton = new QPushButton(this);
    layout()->addWidget(m_tapButton);
    connect(m_tapButton, SIGNAL(clicked()),
            this, SLOT(slotTapButtonClicked()));
    m_time = new QTime();

    /* Bottom label */
    m_bottomLabel = new QLabel(this);
    layout()->addWidget(m_bottomLabel);
    m_bottomLabel->setAlignment(Qt::AlignCenter);
    m_bottomLabel->hide();

    setMinimumSize(VCSlider::defaultSize);
    resize(VCSlider::defaultSize);

    /* Initialize to bus mode by default */
    setInvertedAppearance(true);
    setBus(Bus::defaultFade());
    setSliderMode(Bus);

    /* Update the slider according to current mode */
    slotModeChanged(mode());

    /* Listen to fixture removals so that LevelChannels can be removed when
       they no longer point to an existing fixture->channel */
    connect(m_doc, SIGNAL(fixtureRemoved(quint32)),
            this, SLOT(slotFixtureRemoved(quint32)));
}

VCSlider::~VCSlider()
{
    if (m_time != NULL)
        delete m_time;
    m_time = NULL;

    /* When application exits these are already NULL and unregistration
       is no longer necessary. But a normal deletion of a VCSlider in
       design mode must unregister the slider. */
    m_masterTimer->unregisterDMXSource(this);
}

/*****************************************************************************
 * Clipboard
 *****************************************************************************/

VCWidget* VCSlider::createCopy(VCWidget* parent)
{
    Q_ASSERT(parent != NULL);

    VCSlider* slider = new VCSlider(parent, m_doc, m_outputMap, m_inputMap, m_masterTimer);
    if (slider->copyFrom(this) == false)
    {
        delete slider;
        slider = NULL;
    }

    return slider;
}

bool VCSlider::copyFrom(VCWidget* widget)
{
    VCSlider* slider = qobject_cast<VCSlider*> (widget);
    if (slider == NULL)
        return false;

    /* Copy level stuff */
    setLevelLowLimit(slider->levelLowLimit());
    setLevelHighLimit(slider->levelHighLimit());
    m_levelChannels = slider->m_levelChannels;

    /* Copy bus stuff */
    setBusLowLimit(slider->busLowLimit());
    setBusHighLimit(slider->busHighLimit());
    setBus(slider->bus());

    /* Copy slider appearance */
    setValueDisplayStyle(slider->valueDisplayStyle());
    setInvertedAppearance(slider->invertedAppearance());

    /* Copy mode & current value */
    setSliderMode(slider->sliderMode());
    m_slider->setValue(slider->sliderValue());

    /* Copy common stuff */
    return VCWidget::copyFrom(widget);
}

/*****************************************************************************
 * Caption
 *****************************************************************************/

void VCSlider::setCaption(const QString& text)
{
    VCWidget::setCaption(text);

    if (m_bottomLabel != NULL)
        setBottomLabelText(text);

    if (m_tapButton != NULL)
        setTapButtonText(text);
}

/*****************************************************************************
 * Properties
 *****************************************************************************/

void VCSlider::editProperties()
{
    VCSliderProperties prop(this, m_doc, m_outputMap, m_inputMap, m_masterTimer);
    if (prop.exec() == QDialog::Accepted)
        m_doc->setModified();
}

/*****************************************************************************
 * QLC Mode
 *****************************************************************************/

void VCSlider::slotModeChanged(Doc::Mode mode)
{
    if (mode == Doc::Operate)
    {
        m_topLabel->setEnabled(true);
        m_slider->setEnabled(true);
        m_bottomLabel->setEnabled(true);
        m_tapButton->setEnabled(true);

        if (sliderMode() == Playback)
        {
            /* Follow playback function running/stopped status in case the
               function is started from another control. */
            Function* function = m_doc->function(playbackFunction());
            if (function != NULL)
            {
                connect(function, SIGNAL(running(quint32)),
                        this, SLOT(slotPlaybackFunctionRunning(quint32)));
                connect(function, SIGNAL(stopped(quint32)),
                        this, SLOT(slotPlaybackFunctionStopped(quint32)));
                connect(function, SIGNAL(intensityChanged(qreal)),
                        this, SLOT(slotPlaybackFunctionIntensityChanged(qreal)));
            }
        }
    }
    else
    {
        m_topLabel->setEnabled(false);
        m_slider->setEnabled(false);
        m_bottomLabel->setEnabled(false);
        m_tapButton->setEnabled(false);

        if (sliderMode() == Playback)
        {
            /* Stop following playback function running/stopped status in case
               the function is changed in Design mode to another. */
            Function* function = m_doc->function(playbackFunction());
            if (function != NULL)
            {
                disconnect(function, SIGNAL(running(quint32)),
                        this, SLOT(slotPlaybackFunctionRunning(quint32)));
                disconnect(function, SIGNAL(stopped(quint32)),
                        this, SLOT(slotPlaybackFunctionStopped(quint32)));
                disconnect(function, SIGNAL(intensityChanged(qreal)),
                        this, SLOT(slotPlaybackFunctionIntensityChanged(qreal)));
            }
        }
    }

    VCWidget::slotModeChanged(mode);
}

/*****************************************************************************
 * Value display style
 *****************************************************************************/

QString VCSlider::valueDisplayStyleToString(VCSlider::ValueDisplayStyle style)
{
    switch (style)
    {
    case ExactValue:
        return KXMLQLCVCSliderValueDisplayStyleExact;
    case PercentageValue:
        return KXMLQLCVCSliderValueDisplayStylePercentage;
    default:
        return QString("Unknown");
    };
}

VCSlider::ValueDisplayStyle VCSlider::stringToValueDisplayStyle(QString style)
{
    if (style == KXMLQLCVCSliderValueDisplayStyleExact)
        return ExactValue;
    else if (style == KXMLQLCVCSliderValueDisplayStylePercentage)
        return PercentageValue;
    else
        return ExactValue;
}

void VCSlider::setValueDisplayStyle(VCSlider::ValueDisplayStyle style)
{
    m_valueDisplayStyle = style;
}

VCSlider::ValueDisplayStyle VCSlider::valueDisplayStyle()
{
    return m_valueDisplayStyle;
}

/*****************************************************************************
 * Inverted appearance
 *****************************************************************************/

bool VCSlider::invertedAppearance() const
{
    Q_ASSERT(m_slider != NULL);
    return m_slider->invertedAppearance();
}

void VCSlider::setInvertedAppearance(bool invert)
{
    Q_ASSERT(m_slider != NULL);
    m_slider->setInvertedAppearance(invert);
    m_slider->setInvertedControls(invert);
}

/*****************************************************************************
 * Slider Mode
 *****************************************************************************/

QString VCSlider::sliderModeToString(SliderMode mode)
{
    switch (mode)
    {
    case Bus:
        return QString("Bus");
        break;

    case Level:
        return QString("Level");
        break;

    case Playback:
        return QString("Playback");
        break;

    default:
        return QString("Unknown");
        break;
    }
}

VCSlider::SliderMode VCSlider::stringToSliderMode(const QString& mode)
{
    if (mode == QString("Bus"))
        return Bus;
    else if (mode == QString("Level"))
        return Level;
    else if (mode == QString("Playback"))
        return Playback;
    else
        return Bus;
}

VCSlider::SliderMode VCSlider::sliderMode()
{
    return m_sliderMode;
}

void VCSlider::setSliderMode(SliderMode mode)
{
    Q_ASSERT(mode >= Bus && mode <= Playback);

    /* Disconnect these to prevent double callbacks and non-needes signals */
    disconnect(Bus::instance(), SIGNAL(nameChanged(quint32, const QString&)),
               this, SLOT(slotBusNameChanged(quint32, const QString&)));
    disconnect(Bus::instance(), SIGNAL(valueChanged(quint32, quint32)),
               this, SLOT(slotBusValueChanged(quint32, quint32)));

    /* Unregister this as a DMX source if the new mode is not "Level" or "Playback" */
    if ((m_sliderMode == Level && mode != Level) ||
        (m_sliderMode == Playback && mode != Playback))
    {
        m_masterTimer->unregisterDMXSource(this);
    }

    m_sliderMode = mode;

    if (mode == Bus)
    {
        /* Set the slider range */
        m_slider->setRange(busLowLimit() * MasterTimer::frequency(),
                           busHighLimit() * MasterTimer::frequency());
        m_slider->setValue(Bus::instance()->value(bus()));
        slotSliderMoved(m_slider->value());

        /* Reconnect to bus emitter */
        connect(Bus::instance(), SIGNAL(nameChanged(quint32, const QString&)),
                this, SLOT(slotBusNameChanged(quint32, const QString&)));
        connect(Bus::instance(), SIGNAL(valueChanged(quint32, quint32)),
                this, SLOT(slotBusValueChanged(quint32, quint32)));

        m_bottomLabel->hide();
        m_tapButton->show();

        m_time->start();
    }
    else if (mode == Level)
    {
        /* Set the slider range */
        uchar level = levelValue();
        m_slider->setRange(levelLowLimit(), levelHighLimit());
        m_slider->setValue(level);
        slotSliderMoved(level);

        m_bottomLabel->show();
        m_tapButton->hide();

        m_masterTimer->registerDMXSource(this);
    }
    else if (mode == Playback)
    {
        m_bottomLabel->show();
        m_tapButton->hide();

        uchar level = playbackValue();
        m_slider->setRange(0, UCHAR_MAX);
        m_slider->setValue(level);
        slotSliderMoved(level);

        m_masterTimer->registerDMXSource(this);
    }
}

/*****************************************************************************
 * Bus
 *****************************************************************************/

void VCSlider::setBus(quint32 bus)
{
    m_bus = bus;
    setCaption(Bus::instance()->idName(bus));
}

quint32 VCSlider::bus()
{
    return m_bus;
}

void VCSlider::setBusLowLimit(quint32 limit)
{
    m_busLowLimit = limit;
}

quint32 VCSlider::busLowLimit()
{
    return m_busLowLimit;
}

void VCSlider::setBusHighLimit(quint32 limit)
{
    m_busHighLimit = limit;
}

quint32 VCSlider::busHighLimit()
{
    return m_busHighLimit;
}

void VCSlider::setBusValue(int value)
{
    Bus::instance()->setValue(m_bus, value);
}

void VCSlider::slotBusValueChanged(quint32 bus, quint32 value)
{
    if (bus == m_bus && m_slider->isSliderDown() == false)
        m_slider->setValue(value);
}

void VCSlider::slotBusNameChanged(quint32 bus, const QString&)
{
    if (m_bus == bus)
        setBus(bus);
}

/*****************************************************************************
 * Level
 *****************************************************************************/

void VCSlider::addLevelChannel(quint32 fixture, quint32 channel)
{
    LevelChannel lch(fixture, channel);

    if (m_levelChannels.contains(lch) == false)
    {
        m_levelChannels.append(lch);
        qSort(m_levelChannels.begin(), m_levelChannels.end());
    }
}

void VCSlider::removeLevelChannel(quint32 fixture, quint32 channel)
{
    LevelChannel lch(fixture, channel);
    m_levelChannels.removeAll(lch);
}

void VCSlider::clearLevelChannels()
{
    m_levelChannels.clear();
}

QList <VCSlider::LevelChannel> VCSlider::levelChannels()
{
    return m_levelChannels;
}

void VCSlider::setLevelLowLimit(uchar value)
{
    m_levelLowLimit = value;
}

uchar VCSlider::levelLowLimit()
{
    return m_levelLowLimit;
}

void VCSlider::setLevelHighLimit(uchar value)
{
    m_levelHighLimit = value;
}

uchar VCSlider::levelHighLimit()
{
    return m_levelHighLimit;
}

void VCSlider::setLevelValue(uchar value)
{
    m_levelValueMutex.lock();
    m_levelValue = value;
    m_levelValueChanged = true;
    m_levelValueMutex.unlock();
}

uchar VCSlider::levelValue() const
{
    return m_levelValue;
}

void VCSlider::slotFixtureRemoved(quint32 fxi_id)
{
    QMutableListIterator <LevelChannel> it(m_levelChannels);
    while (it.hasNext() == true)
    {
        it.next();
        if (it.value().fixture == fxi_id)
            it.remove();
    }
}

/*****************************************************************************
 * Playback
 *****************************************************************************/

void VCSlider::setPlaybackFunction(quint32 fid)
{
    m_playbackFunction = fid;
}

quint32 VCSlider::playbackFunction() const
{
    return m_playbackFunction;
}

void VCSlider::setPlaybackValue(uchar value)
{
    if (m_externalMovement == true)
        return;

    m_playbackValueMutex.lock();
    m_playbackValue = value;
    m_playbackValueChanged = true;
    m_playbackValueMutex.unlock();
}

uchar VCSlider::playbackValue() const
{
    return m_playbackValue;
}

void VCSlider::slotPlaybackFunctionRunning(quint32 fid)
{
    Q_UNUSED(fid);
}

void VCSlider::slotPlaybackFunctionStopped(quint32 fid)
{
    m_externalMovement = true;
    if (fid == playbackFunction())
        m_slider->setValue(0);
    m_externalMovement = false;
}

void VCSlider::slotPlaybackFunctionIntensityChanged(qreal fraction)
{
    m_externalMovement = true;
    m_slider->setValue(int(floor((qreal(m_slider->maximum()) * fraction) + 0.5)));
    m_externalMovement = false;
}

/*****************************************************************************
 * DMXSource
 *****************************************************************************/

void VCSlider::writeDMX(MasterTimer* timer, UniverseArray* universes)
{
    if (sliderMode() == Level)
        writeDMXLevel(timer, universes);
    else if (sliderMode() == Playback)
        writeDMXPlayback(timer, universes);
}

void VCSlider::writeDMXLevel(MasterTimer* timer, UniverseArray* universes)
{
    Q_UNUSED(timer);

    m_levelValueMutex.lock();

    QListIterator <LevelChannel> it(m_levelChannels);
    while (it.hasNext() == true)
    {
        LevelChannel lch(it.next());
        Fixture* fxi = m_doc->fixture(lch.fixture);
        if (fxi != NULL)
        {
            const QLCChannel* qlcch = fxi->channel(lch.channel);
            if (qlcch == NULL)
                continue;

            if (qlcch->group() != QLCChannel::Intensity &&
                m_levelValueChanged == false)
            {
                /* Value has not changed and this is not an intensity channel.
                   LTP in effect. */
                continue;
            }

            quint32 dmx_ch = fxi->channelAddress(lch.channel);
            universes->write(dmx_ch, m_levelValue, qlcch->group());
        }
    }
    m_levelValueChanged = false;
    m_levelValueMutex.unlock();
}

void VCSlider::writeDMXPlayback(MasterTimer* timer, UniverseArray* universes)
{
    Function* function = m_doc->function(m_playbackFunction);
    if (function == NULL)
        return;

    /* Grab current values inside a locked mutex */
    m_playbackValueMutex.lock();
     uchar value = m_playbackValue;
     bool changed = m_playbackValueChanged;

    qreal percentage = qreal(value) / qreal(UCHAR_MAX);

    switch(function->type())
    {
    case Function::Scene:
    {
        Scene* scene = qobject_cast<Scene*> (function);
        Q_ASSERT(scene != NULL);

        /* When the value has changed recently (= slider moved since last writeDMX cycle)
           write both HTP & LTP channels. Otherwise write only HTP channel values. */
        if (changed == true) {
            scene->writeValues(universes, Fixture::invalidId(),
                               QLCChannel::NoGroup, percentage);
        } else {
            scene->writeValues(universes, Fixture::invalidId(),
                               QLCChannel::Intensity, percentage);
        }
    }
    break;

    default:
        if (changed == true)
        {
            if (value == 0)
            {
                if (function->stopped() == false)
                    function->stop();
            }
            else
            {
                if (function->stopped() == true)
                    timer->startFunction(function, false);
                function->adjustIntensity(percentage);
            }
        }
        break;
    }

     m_playbackValueChanged = false;
    m_playbackValueMutex.unlock();
}

/*****************************************************************************
 * Top label
 *****************************************************************************/

void VCSlider::setTopLabelText(const QString& text)
{
    m_topLabel->setText(text);
}

QString VCSlider::topLabelText()
{
    return m_topLabel->text();
}

/*****************************************************************************
 * Slider
 *****************************************************************************/

int VCSlider::sliderValue() const
{
    Q_ASSERT(m_slider != NULL);
    return m_slider->value();
}

void VCSlider::slotSliderMoved(int value)
{
    QString num;

    switch (sliderMode())
    {
    case Bus:
    {
        setBusValue(value);

        /* Set text for the top label */
        if (valueDisplayStyle() == ExactValue)
        {
            num.sprintf("%.2fs", ((float) value / (float) MasterTimer::frequency()));
        }
        else
        {
            /* Horrible code... */
            num.sprintf("%.3d%%", static_cast<int>
                        (((float) ((m_busHighLimit * MasterTimer::frequency())
                                   - value) / (float) ((m_busHighLimit
                                                        - m_busLowLimit) *
                                                       (float) MasterTimer::frequency())) * 100.0));
        }

        setTopLabelText(num);
    }
    break;

    case Level:
    {
        setLevelValue(value);

        /* Set text for the top label */
        if (valueDisplayStyle() == ExactValue)
        {
            num.sprintf("%.3d", value);
        }
        else
        {
            float f = SCALE(float(value),
                            float(m_slider->minimum()),
                            float(m_slider->maximum()),
                            float(0), float(100));
            num.sprintf("%.3d%%", static_cast<int> (f));
        }
        setTopLabelText(num);
    }
    break;

    case Playback:
    {
        setPlaybackValue(value);

        /* Set text for the top label */
        if (valueDisplayStyle() == ExactValue)
        {
            num.sprintf("%.3d", value);
        }
        else
        {
            float f = SCALE(float(value),
                            float(m_slider->minimum()),
                            float(m_slider->maximum()),
                            float(0), float(100));
            num.sprintf("%.3d%%", static_cast<int> (f));
        }
        setTopLabelText(num);
    }
    break;

    default:
        break;
    }

    if (m_slider->isSliderDown() == true)
        sendFeedBack(value);
}

void VCSlider::sendFeedBack(int value)
{
    /* Send input feedback */
    if (m_inputUniverse != InputMap::invalidUniverse() &&
        m_inputChannel != InputMap::invalidChannel())
    {
        if (invertedAppearance() == true)
            value = m_slider->maximum() - value;

        float fb = SCALE(float(value), float(m_slider->minimum()),
                         float(m_slider->maximum()), float(0),
                         float(UCHAR_MAX));

        m_inputMap->feedBack(m_inputUniverse, m_inputChannel, int(fb));
    }
}

/*****************************************************************************
 * Bottom label
 *****************************************************************************/
void VCSlider::setBottomLabelText(const QString& text)
{
    m_bottomLabel->setText(text);
}

QString VCSlider::bottomLabelText()
{
    return m_bottomLabel->text();
}

/*****************************************************************************
 * Tap button
 *****************************************************************************/

void VCSlider::setTapButtonText(const QString& text)
{
    m_tapButton->setText(QString(text).replace(" ", "\n"));
}

QString VCSlider::tapButtonText()
{
    return m_tapButton->text();
}

void VCSlider::slotTapButtonClicked()
{
    int t = m_time->elapsed();
    m_slider->setValue(static_cast<int> (t * 0.001 * MasterTimer::frequency()));
    Bus::instance()->tap(m_bus);
    m_time->restart();
}

/*****************************************************************************
 * External input
 *****************************************************************************/

bool VCSlider::isButton(quint32 universe, quint32 channel)
{
    InputPatch* patch = NULL;
    QLCInputProfile* profile = NULL;
    QLCInputChannel* ch = NULL;

    patch = m_inputMap->patch(universe);
    if (patch != NULL)
    {
        profile = patch->profile();
        if (profile != NULL)
        {
            ch = profile->channels()[channel];
            if (ch != NULL)
            {
                return (ch->type() == QLCInputChannel::Button);
            }
        }
    }

    return false;
}

void VCSlider::slotInputValueChanged(quint32 universe, quint32 channel,
                                     uchar value)
{
    /* Don't let input data thru in design mode */
    if (mode() == Doc::Design)
        return;

    if (universe == m_inputUniverse && channel == m_inputChannel)
    {
        if (m_sliderMode == Bus && isButton(universe, channel) == true)
        {
            // Check value here so that value == 0 won't end up in the else branch
            if (value > 0)
                slotTapButtonClicked();
        }
        else
        {
            /* Scale the from input value range to this slider's range */
            float val;
            val = SCALE((float) value, (float) 0, (float) UCHAR_MAX,
                        (float) m_slider->minimum(),
                        (float) m_slider->maximum());

            if (m_slider->invertedAppearance() == true)
                m_slider->setValue(m_slider->maximum() - (int) val);
            else
                m_slider->setValue((int) val);
        }
    }
}

/*****************************************************************************
 * Load & Save
 *****************************************************************************/

bool VCSlider::loadXML(const QDomElement* root)
{
    bool visible = false;
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;

    SliderMode sliderMode = Bus;
    QDomElement tag;
    QDomNode node;
    QString caption;
    QString str;

    Q_ASSERT(root != NULL);

    if (root->tagName() != KXMLQLCVCSlider)
    {
        qWarning() << Q_FUNC_INFO << "Slider node not found";
        return false;
    }

    /* Caption */
    caption = root->attribute(KXMLQLCVCCaption);
    if (root->attribute(KXMLQLCVCSliderInvertedAppearance) == "false")
        setInvertedAppearance(false);
    else
        setInvertedAppearance(true);

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
        else if (tag.tagName() == KXMLQLCVCSliderMode)
        {
            sliderMode = stringToSliderMode(tag.text());

            str = tag.attribute(KXMLQLCVCSliderValueDisplayStyle);
            setValueDisplayStyle(stringToValueDisplayStyle(str));
        }
        else if (tag.tagName() == KXMLQLCVCSliderBus)
        {
            str = tag.attribute(KXMLQLCVCSliderBusLowLimit);
            setBusLowLimit(str.toUInt());

            str = tag.attribute(KXMLQLCVCSliderBusHighLimit);
            setBusHighLimit(str.toUInt());

            setBus(tag.text().toUInt());
        }
        else if (tag.tagName() == KXMLQLCVCSliderLevel)
        {
            loadXMLLevel(&tag);
        }
        else if (tag.tagName() == KXMLQLCVCWidgetInput)
        {
            loadXMLInput(&tag);
        }
        else if (tag.tagName() == KXMLQLCVCSliderPlayback)
        {
            loadXMLPlayback(&tag);
        }
        else
        {
            qWarning() << Q_FUNC_INFO << "Unknown slider tag:" << tag.tagName();
        }

        node = node.nextSibling();
    }

    /* Set the mode last, after everything else has been set */
    setSliderMode(sliderMode);
    if (sliderMode != Bus)
        setCaption(caption);

    return true;
}

bool VCSlider::loadXMLLevel(const QDomElement* level_root)
{
    QDomNode node;
    QDomElement tag;
    QString str;

    Q_ASSERT(level_root != NULL);

    if (level_root->tagName() != KXMLQLCVCSliderLevel)
    {
        qWarning() << Q_FUNC_INFO << "Slider level node not found";
        return false;
    }

    /* Level low limit */
    str = level_root->attribute(KXMLQLCVCSliderLevelLowLimit);
    setLevelLowLimit(str.toInt());

    /* Level high limit */
    str = level_root->attribute(KXMLQLCVCSliderLevelHighLimit);
    setLevelHighLimit(str.toInt());

    /* Level value */
    str = level_root->attribute(KXMLQLCVCSliderLevelValue);
    setLevelValue(str.toInt());

    /* Children */
    node = level_root->firstChild();
    while (node.isNull() == false)
    {
        tag = node.toElement();
        if (tag.tagName() == KXMLQLCVCSliderChannel)
        {
            /* Fixture & channel */
            str = tag.attribute(KXMLQLCVCSliderChannelFixture);
            addLevelChannel(
                static_cast<quint32>(str.toInt()),
                static_cast<quint32> (tag.text().toInt()));
        }
        else
        {
            qWarning() << Q_FUNC_INFO << "Unknown slider level tag:" << tag.tagName();
        }

        node = node.nextSibling();
    }

    return true;
}

bool VCSlider::loadXMLPlayback(const QDomElement* pb_root)
{
    QDomNode node;
    QDomElement tag;

    Q_ASSERT(pb_root != NULL);

    if (pb_root->tagName() != KXMLQLCVCSliderPlayback)
    {
        qWarning() << Q_FUNC_INFO << "Slider playback node not found";
        return false;
    }

    /* Children */
    node = pb_root->firstChild();
    while (node.isNull() == false)
    {
        tag = node.toElement();
        if (tag.tagName() == KXMLQLCVCSliderPlaybackFunction)
        {
            /* Function */
            setPlaybackFunction(tag.text().toUInt());
        }
        else
        {
            qWarning() << Q_FUNC_INFO << "Unknown slider playback tag:" << tag.tagName();
        }

        node = node.nextSibling();
    }

    return true;
}

bool VCSlider::saveXML(QDomDocument* doc, QDomElement* vc_root)
{
    QDomElement root;
    QDomElement tag;
    QDomElement subtag;
    QDomText text;
    QString str;

    Q_ASSERT(doc != NULL);
    Q_ASSERT(vc_root != NULL);

    /* VC Slider entry */
    root = doc->createElement(KXMLQLCVCSlider);
    vc_root->appendChild(root);

    /* Caption */
    root.setAttribute(KXMLQLCVCCaption, caption());

    /* Inverted appearance */
    if (invertedAppearance() == true)
        root.setAttribute(KXMLQLCVCSliderInvertedAppearance, "true");
    else
        root.setAttribute(KXMLQLCVCSliderInvertedAppearance, "false");

    /* Window state */
    saveXMLWindowState(doc, &root);

    /* Appearance */
    saveXMLAppearance(doc, &root);

    /* External input */
    saveXMLInput(doc, &root);

    /* Mode */
    tag = doc->createElement(KXMLQLCVCSliderMode);
    root.appendChild(tag);
    text = doc->createTextNode(sliderModeToString(m_sliderMode));
    tag.appendChild(text);

    /* Value display style */
    str = valueDisplayStyleToString(valueDisplayStyle());
    tag.setAttribute(KXMLQLCVCSliderValueDisplayStyle, str);

    /* Bus */
    tag = doc->createElement(KXMLQLCVCSliderBus);
    root.appendChild(tag);
    str.setNum(bus());
    text = doc->createTextNode(str);
    tag.appendChild(text);

    /* Bus low limit */
    str.setNum(busLowLimit());
    tag.setAttribute(KXMLQLCVCSliderBusLowLimit, str);

    /* Bus high limit */
    str.setNum(busHighLimit());
    tag.setAttribute(KXMLQLCVCSliderBusHighLimit, str);

    /* Level */
    tag = doc->createElement(KXMLQLCVCSliderLevel);
    root.appendChild(tag);

    /* Level low limit */
    str.setNum(levelLowLimit());
    tag.setAttribute(KXMLQLCVCSliderLevelLowLimit, str);

    /* Level high limit */
    str.setNum(levelHighLimit());
    tag.setAttribute(KXMLQLCVCSliderLevelHighLimit, str);

    /* Level value */
    str.setNum(levelValue());
    tag.setAttribute(KXMLQLCVCSliderLevelValue, str);

    /* Level channels */
    QListIterator <LevelChannel> it(m_levelChannels);
    while (it.hasNext() == true)
    {
        LevelChannel lch(it.next());
        lch.saveXML(doc, &tag);
    }

    /* Playback */
    tag = doc->createElement(KXMLQLCVCSliderPlayback);
    root.appendChild(tag);

    /* Playback function */
    subtag = doc->createElement(KXMLQLCVCSliderPlaybackFunction);
    text = doc->createTextNode(QString::number(playbackFunction()));
    subtag.appendChild(text);
    tag.appendChild(subtag);

    return true;
}

/****************************************************************************
 * LevelChannel implementation
 ****************************************************************************/

VCSlider::LevelChannel::LevelChannel(quint32 fid, quint32 ch)
{
    this->fixture = fid;
    this->channel = ch;
}

VCSlider::LevelChannel::LevelChannel(const LevelChannel& lc)
{
    this->fixture = lc.fixture;
    this->channel = lc.channel;
}

bool VCSlider::LevelChannel::operator==(const LevelChannel& lc) const
{
    return (this->fixture == lc.fixture && this->channel == lc.channel);
}

bool VCSlider::LevelChannel::operator<(const LevelChannel& lc) const
{
    if (this->fixture < lc.fixture)
        return true;
    else if (this->fixture == lc.fixture && this->channel < lc.channel)
        return true;
    else
        return false;
}

void VCSlider::LevelChannel::saveXML(QDomDocument* doc, QDomElement* root) const
{
    QDomElement chtag = doc->createElement(KXMLQLCVCSliderChannel);
    root->appendChild(chtag);

    chtag.setAttribute(KXMLQLCVCSliderChannelFixture,
                       QString::number(this->fixture));

    QDomText text = doc->createTextNode(QString::number(this->channel));
    chtag.appendChild(text);
}
