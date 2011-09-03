/********************************************************************************
** Form generated from reading UI file 'configuremidiout.ui'
**
** Created: Fri Sep 2 17:15:27 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREMIDIOUT_H
#define UI_CONFIGUREMIDIOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigureMIDIOut
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *m_list;
    QPushButton *m_refreshButton;
    QPushButton *m_editButton;
    QSpacerItem *spacerItem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigureMIDIOut)
    {
        if (ConfigureMIDIOut->objectName().isEmpty())
            ConfigureMIDIOut->setObjectName(QString::fromUtf8("ConfigureMIDIOut"));
        ConfigureMIDIOut->resize(449, 300);
        gridLayout = new QGridLayout(ConfigureMIDIOut);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_list = new QTreeWidget(ConfigureMIDIOut);
        m_list->setObjectName(QString::fromUtf8("m_list"));
        m_list->setAlternatingRowColors(true);
        m_list->setRootIsDecorated(false);
        m_list->setItemsExpandable(false);
        m_list->setAllColumnsShowFocus(true);

        gridLayout->addWidget(m_list, 0, 0, 1, 4);

        m_refreshButton = new QPushButton(ConfigureMIDIOut);
        m_refreshButton->setObjectName(QString::fromUtf8("m_refreshButton"));

        gridLayout->addWidget(m_refreshButton, 1, 0, 1, 1);

        m_editButton = new QPushButton(ConfigureMIDIOut);
        m_editButton->setObjectName(QString::fromUtf8("m_editButton"));

        gridLayout->addWidget(m_editButton, 1, 1, 1, 1);

        spacerItem = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(ConfigureMIDIOut);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 3, 1, 1);


        retranslateUi(ConfigureMIDIOut);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigureMIDIOut, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigureMIDIOut, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigureMIDIOut);
    } // setupUi

    void retranslateUi(QDialog *ConfigureMIDIOut)
    {
        ConfigureMIDIOut->setWindowTitle(QApplication::translate("ConfigureMIDIOut", "Configure MIDI Output Plugin", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = m_list->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("ConfigureMIDIOut", "Mode", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("ConfigureMIDIOut", "MIDI Channel", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("ConfigureMIDIOut", "Name", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("ConfigureMIDIOut", "Output", 0, QApplication::UnicodeUTF8));
        m_refreshButton->setText(QApplication::translate("ConfigureMIDIOut", "Refresh", 0, QApplication::UnicodeUTF8));
        m_editButton->setText(QApplication::translate("ConfigureMIDIOut", "Edit...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigureMIDIOut: public Ui_ConfigureMIDIOut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREMIDIOUT_H
