/*
  Q Light Controller
  vcbuttonproperties.cpp

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

#include <QIntValidator>
#include <QKeySequence>
#include <QRadioButton>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>

#include "qlcinputchannel.h"
#include "qlcinputprofile.h"
#include "qlcfixturedef.h"
#include "qlcinplugin.h"

#include "vcbuttonproperties.h"
#include "selectinputchannel.h"
#include "functionselection.h"
#include "virtualconsole.h"
#include "assignhotkey.h"
#include "inputpatch.h"
#include "inputmap.h"
#include "function.h"
#include "fixture.h"
#include "app.h"
#include "doc.h"

VCButtonProperties::VCButtonProperties(VCButton* button, Doc* doc, OutputMap* outputMap,
                                       InputMap* inputMap, MasterTimer* masterTimer)
    : QDialog(button)
    , m_doc(doc)
    , m_outputMap(outputMap)
    , m_inputMap(inputMap)
    , m_masterTimer(masterTimer)
{
    Q_ASSERT(button != NULL);
    Q_ASSERT(doc != NULL);
    Q_ASSERT(outputMap != NULL);
    Q_ASSERT(inputMap != NULL);
    Q_ASSERT(masterTimer != NULL);

    setupUi(this);

    QAction* action = new QAction(this);
    action->setShortcut(QKeySequence(QKeySequence::Close));
    connect(action, SIGNAL(triggered(bool)), this, SLOT(reject()));
    addAction(action);

    /* Button text and function */
    m_button = button;
    m_nameEdit->setText(m_button->caption());
    slotSetFunction(button->function());

    /* Key sequence */
    m_keySequence = QKeySequence(button->keySequence());
    m_keyEdit->setText(m_keySequence.toString(QKeySequence::NativeText));

    /* External input */
    m_inputUniverse = m_button->inputUniverse();
    m_inputChannel = m_button->inputChannel();
    updateInputSource();

    /* Press action */
    if (button->action() == VCButton::Toggle)
        m_toggle->setChecked(true);
    else
        m_flash->setChecked(true);

    /* Intensity adjustment */
    m_intensityEdit->setValidator(new QIntValidator(0, 100, this));
    m_intensityGroup->setChecked(m_button->adjustIntensity());
    int intensity = int(floor(m_button->intensityAdjustment() * double(100)));
    m_intensityEdit->setText(QString::number(intensity));
    m_intensitySlider->setValue(intensity);

    /* Button connections */
    connect(m_attachFunction, SIGNAL(clicked()),
            this, SLOT(slotAttachFunction()));
    connect(m_detachFunction, SIGNAL(clicked()),
            this, SLOT(slotSetFunction()));
    connect(m_attachKey, SIGNAL(clicked()), this, SLOT(slotAttachKey()));
    connect(m_detachKey, SIGNAL(clicked()), this, SLOT(slotDetachKey()));
    connect(m_autoDetectInputButton, SIGNAL(toggled(bool)),
            this, SLOT(slotAutoDetectInputToggled(bool)));
    connect(m_chooseInputButton, SIGNAL(clicked()),
            this, SLOT(slotChooseInputClicked()));
    connect(m_intensitySlider, SIGNAL(valueChanged(int)),
            this, SLOT(slotIntensitySliderMoved(int)));
    connect(m_intensityEdit, SIGNAL(textEdited(QString)),
            this, SLOT(slotIntensityEdited(QString)));
}

VCButtonProperties::~VCButtonProperties()
{
}

void VCButtonProperties::slotAttachFunction()
{
    FunctionSelection sel(this, m_doc, m_outputMap, m_inputMap, m_masterTimer, false);
    if (sel.exec() == QDialog::Accepted)
    {
        /* Get the first selected function */
        slotSetFunction(sel.selection().at(0));
    }
}

void VCButtonProperties::slotSetFunction(quint32 fid)
{
    m_function = fid;
    Function* func = m_doc->function(m_function);
    if (func == NULL)
    {
        m_functionEdit->setText(tr("No function"));
    }
    else
    {
        m_functionEdit->setText(func->name());
        if (m_nameEdit->text().simplified().isEmpty() == true)
            m_nameEdit->setText(func->name());
    }
}

void VCButtonProperties::slotAttachKey()
{
    AssignHotKey ahk(this, m_keySequence);
    if (ahk.exec() == QDialog::Accepted)
    {
        m_keySequence = QKeySequence(ahk.keySequence());
        m_keyEdit->setText(m_keySequence.toString(QKeySequence::NativeText));
    }
}

void VCButtonProperties::slotDetachKey()
{
    m_keySequence = QKeySequence();
    m_keyEdit->setText(m_keySequence.toString(QKeySequence::NativeText));
}

void VCButtonProperties::slotAutoDetectInputToggled(bool checked)
{
    if (checked == true)
    {
        connect(m_inputMap,
                SIGNAL(inputValueChanged(quint32,quint32,uchar)),
                this, SLOT(slotInputValueChanged(quint32,quint32)));
    }
    else
    {
        disconnect(m_inputMap,
                   SIGNAL(inputValueChanged(quint32,quint32,uchar)),
                   this, SLOT(slotInputValueChanged(quint32,quint32)));
    }
}

void VCButtonProperties::slotInputValueChanged(quint32 universe,
                                               quint32 channel)
{
    m_inputUniverse = universe;
    m_inputChannel = channel;
    updateInputSource();
}

void VCButtonProperties::slotChooseInputClicked()
{
    SelectInputChannel sic(this, m_inputMap);
    if (sic.exec() == QDialog::Accepted)
    {
        m_inputUniverse = sic.universe();
        m_inputChannel = sic.channel();

        updateInputSource();
    }
}

void VCButtonProperties::updateInputSource()
{
    QLCInputProfile* profile;
    InputPatch* patch;
    QString uniName;
    QString chName;

    if (m_inputUniverse == InputMap::invalidUniverse() ||
            m_inputChannel == InputMap::invalidChannel())
    {
        /* Nothing selected for input universe and/or channel */
        uniName = KInputNone;
        chName = KInputNone;
    }
    else
    {
        patch = m_inputMap->patch(m_inputUniverse);
        if (patch == NULL || patch->plugin() == NULL)
        {
            /* There is no patch for the given universe */
            uniName = KInputNone;
            chName = KInputNone;
        }
        else
        {
            profile = patch->profile();
            if (profile == NULL)
            {
                /* There is no profile. Display plugin
                   name and channel number. Boring. */
                uniName = patch->plugin()->name();
                chName = tr("%1: Unknown").arg(m_inputChannel);
            }
            else
            {
                QLCInputChannel* ich;
                QString name;

                /* Display profile name for universe */
                uniName = QString("%1: %2")
                          .arg(m_inputUniverse + 1)
                          .arg(profile->name());

                /* User can input the channel number by hand,
                   so put something rational to the channel
                   name in those cases as well. */
                ich = profile->channel(m_inputChannel);
                if (ich != NULL)
                    name = ich->name();
                else
                    name = tr("Unknown");

                /* Display channel name */
                chName = QString("%1: %2")
                         .arg(m_inputChannel + 1).arg(name);
            }
        }
    }

    /* Display the gathered information */
    m_inputUniverseEdit->setText(uniName);
    m_inputChannelEdit->setText(chName);
}

void VCButtonProperties::slotIntensitySliderMoved(int value)
{
    m_intensityEdit->setText(QString::number(value));
}

void VCButtonProperties::slotIntensityEdited(const QString& text)
{
    m_intensitySlider->setValue(text.toInt());
}

void VCButtonProperties::accept()
{
    m_button->setCaption(m_nameEdit->text());
    m_button->setFunction(m_function);
    m_button->setKeySequence(m_keySequence);
    m_button->setInputSource(m_inputUniverse, m_inputChannel);
    m_button->setAdjustIntensity(m_intensityGroup->isChecked());
    m_button->setIntensityAdjustment(double(m_intensitySlider->value()) / double(100));

    if (m_toggle->isChecked() == true)
        m_button->setAction(VCButton::Toggle);
    else
        m_button->setAction(VCButton::Flash);

    QDialog::accept();
}

