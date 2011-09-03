/********************************************************************************
** Form generated from reading UI file 'configuremididevice.ui'
**
** Created: Fri Sep 2 17:15:27 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREMIDIDEVICE_H
#define UI_CONFIGUREMIDIDEVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ConfigureMIDIDevice
{
public:
    QGridLayout *gridLayout;
    QLabel *m_midiChannelLabel;
    QSpinBox *m_midiChannelSpin;
    QLabel *m_modeLabel;
    QComboBox *m_modeCombo;
    QDialogButtonBox *m_buttonBox;
    QFrame *line;

    void setupUi(QDialog *ConfigureMIDIDevice)
    {
        if (ConfigureMIDIDevice->objectName().isEmpty())
            ConfigureMIDIDevice->setObjectName(QString::fromUtf8("ConfigureMIDIDevice"));
        ConfigureMIDIDevice->resize(245, 121);
        gridLayout = new QGridLayout(ConfigureMIDIDevice);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_midiChannelLabel = new QLabel(ConfigureMIDIDevice);
        m_midiChannelLabel->setObjectName(QString::fromUtf8("m_midiChannelLabel"));

        gridLayout->addWidget(m_midiChannelLabel, 0, 0, 1, 1);

        m_midiChannelSpin = new QSpinBox(ConfigureMIDIDevice);
        m_midiChannelSpin->setObjectName(QString::fromUtf8("m_midiChannelSpin"));
        m_midiChannelSpin->setMinimum(1);
        m_midiChannelSpin->setMaximum(16);

        gridLayout->addWidget(m_midiChannelSpin, 0, 1, 1, 1);

        m_modeLabel = new QLabel(ConfigureMIDIDevice);
        m_modeLabel->setObjectName(QString::fromUtf8("m_modeLabel"));

        gridLayout->addWidget(m_modeLabel, 1, 0, 1, 1);

        m_modeCombo = new QComboBox(ConfigureMIDIDevice);
        m_modeCombo->setObjectName(QString::fromUtf8("m_modeCombo"));

        gridLayout->addWidget(m_modeCombo, 1, 1, 1, 1);

        m_buttonBox = new QDialogButtonBox(ConfigureMIDIDevice);
        m_buttonBox->setObjectName(QString::fromUtf8("m_buttonBox"));
        m_buttonBox->setOrientation(Qt::Horizontal);
        m_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(m_buttonBox, 3, 0, 1, 2);

        line = new QFrame(ConfigureMIDIDevice);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 2);


        retranslateUi(ConfigureMIDIDevice);
        QObject::connect(m_buttonBox, SIGNAL(accepted()), ConfigureMIDIDevice, SLOT(accept()));
        QObject::connect(m_buttonBox, SIGNAL(rejected()), ConfigureMIDIDevice, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigureMIDIDevice);
    } // setupUi

    void retranslateUi(QDialog *ConfigureMIDIDevice)
    {
        ConfigureMIDIDevice->setWindowTitle(QApplication::translate("ConfigureMIDIDevice", "Configure MIDI Device", 0, QApplication::UnicodeUTF8));
        m_midiChannelLabel->setText(QApplication::translate("ConfigureMIDIDevice", "MIDI Channel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_midiChannelSpin->setToolTip(QApplication::translate("ConfigureMIDIDevice", "The MIDI channel that sends DMX data to the MIDI device", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_modeLabel->setText(QApplication::translate("ConfigureMIDIDevice", "DMX Channel Mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_modeCombo->setToolTip(QApplication::translate("ConfigureMIDIDevice", "MIDI control method used as DMX channels", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ConfigureMIDIDevice: public Ui_ConfigureMIDIDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREMIDIDEVICE_H
