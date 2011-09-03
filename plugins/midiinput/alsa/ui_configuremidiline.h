/********************************************************************************
** Form generated from reading UI file 'configuremidiline.ui'
**
** Created: Fri Sep 2 17:16:14 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREMIDILINE_H
#define UI_CONFIGUREMIDILINE_H

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

QT_BEGIN_NAMESPACE

class Ui_ConfigureMIDILine
{
public:
    QGridLayout *gridLayout;
    QLabel *m_feedBackLabel;
    QComboBox *m_feedBackCombo;
    QLabel *m_midiChannelLabel;
    QComboBox *m_midiChannelCombo;
    QFrame *line;
    QDialogButtonBox *m_buttonBox;

    void setupUi(QDialog *ConfigureMIDILine)
    {
        if (ConfigureMIDILine->objectName().isEmpty())
            ConfigureMIDILine->setObjectName(QString::fromUtf8("ConfigureMIDILine"));
        ConfigureMIDILine->resize(287, 127);
        gridLayout = new QGridLayout(ConfigureMIDILine);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_feedBackLabel = new QLabel(ConfigureMIDILine);
        m_feedBackLabel->setObjectName(QString::fromUtf8("m_feedBackLabel"));

        gridLayout->addWidget(m_feedBackLabel, 0, 0, 1, 1);

        m_feedBackCombo = new QComboBox(ConfigureMIDILine);
        m_feedBackCombo->setObjectName(QString::fromUtf8("m_feedBackCombo"));

        gridLayout->addWidget(m_feedBackCombo, 0, 1, 1, 1);

        m_midiChannelLabel = new QLabel(ConfigureMIDILine);
        m_midiChannelLabel->setObjectName(QString::fromUtf8("m_midiChannelLabel"));

        gridLayout->addWidget(m_midiChannelLabel, 1, 0, 1, 1);

        m_midiChannelCombo = new QComboBox(ConfigureMIDILine);
        m_midiChannelCombo->setObjectName(QString::fromUtf8("m_midiChannelCombo"));

        gridLayout->addWidget(m_midiChannelCombo, 1, 1, 1, 1);

        line = new QFrame(ConfigureMIDILine);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 2);

        m_buttonBox = new QDialogButtonBox(ConfigureMIDILine);
        m_buttonBox->setObjectName(QString::fromUtf8("m_buttonBox"));
        m_buttonBox->setOrientation(Qt::Horizontal);
        m_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(m_buttonBox, 3, 1, 1, 1);


        retranslateUi(ConfigureMIDILine);
        QObject::connect(m_buttonBox, SIGNAL(accepted()), ConfigureMIDILine, SLOT(accept()));
        QObject::connect(m_buttonBox, SIGNAL(rejected()), ConfigureMIDILine, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigureMIDILine);
    } // setupUi

    void retranslateUi(QDialog *ConfigureMIDILine)
    {
        ConfigureMIDILine->setWindowTitle(QApplication::translate("ConfigureMIDILine", "Configure MIDI Input Line", 0, QApplication::UnicodeUTF8));
        m_feedBackLabel->setText(QApplication::translate("ConfigureMIDILine", "Feedback Line", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_feedBackCombo->setToolTip(QApplication::translate("ConfigureMIDILine", "The MIDI line that is used to send feedback data to the input device (to move motorized sliders etc.)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_midiChannelLabel->setText(QApplication::translate("ConfigureMIDILine", "MIDI Channel", 0, QApplication::UnicodeUTF8));
        m_midiChannelCombo->clear();
        m_midiChannelCombo->insertItems(0, QStringList()
         << QApplication::translate("ConfigureMIDILine", "Channel 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Channel 16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigureMIDILine", "Any Channel", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class ConfigureMIDILine: public Ui_ConfigureMIDILine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREMIDILINE_H
