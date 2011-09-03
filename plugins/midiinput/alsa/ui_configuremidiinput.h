/********************************************************************************
** Form generated from reading UI file 'configuremidiinput.ui'
**
** Created: Fri Sep 2 17:16:14 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREMIDIINPUT_H
#define UI_CONFIGUREMIDIINPUT_H

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

class Ui_ConfigureMIDIInput
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *m_tree;
    QPushButton *m_refreshButton;
    QPushButton *m_editButton;
    QSpacerItem *spacerItem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigureMIDIInput)
    {
        if (ConfigureMIDIInput->objectName().isEmpty())
            ConfigureMIDIInput->setObjectName(QString::fromUtf8("ConfigureMIDIInput"));
        ConfigureMIDIInput->resize(451, 300);
        gridLayout = new QGridLayout(ConfigureMIDIInput);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_tree = new QTreeWidget(ConfigureMIDIInput);
        m_tree->setObjectName(QString::fromUtf8("m_tree"));
        m_tree->setAlternatingRowColors(true);
        m_tree->setRootIsDecorated(false);
        m_tree->setItemsExpandable(false);
        m_tree->setAllColumnsShowFocus(true);

        gridLayout->addWidget(m_tree, 0, 0, 1, 4);

        m_refreshButton = new QPushButton(ConfigureMIDIInput);
        m_refreshButton->setObjectName(QString::fromUtf8("m_refreshButton"));

        gridLayout->addWidget(m_refreshButton, 1, 0, 1, 1);

        m_editButton = new QPushButton(ConfigureMIDIInput);
        m_editButton->setObjectName(QString::fromUtf8("m_editButton"));

        gridLayout->addWidget(m_editButton, 1, 1, 1, 1);

        spacerItem = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(ConfigureMIDIInput);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 3, 1, 1);


        retranslateUi(ConfigureMIDIInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigureMIDIInput, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigureMIDIInput, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigureMIDIInput);
    } // setupUi

    void retranslateUi(QDialog *ConfigureMIDIInput)
    {
        ConfigureMIDIInput->setWindowTitle(QApplication::translate("ConfigureMIDIInput", "Configure MIDI Input Plugin", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = m_tree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ConfigureMIDIInput", "1", 0, QApplication::UnicodeUTF8));
        m_refreshButton->setText(QApplication::translate("ConfigureMIDIInput", "Refresh", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_editButton->setToolTip(QApplication::translate("ConfigureMIDIInput", "Edit the selected input line", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_editButton->setText(QApplication::translate("ConfigureMIDIInput", "Edit...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigureMIDIInput: public Ui_ConfigureMIDIInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREMIDIINPUT_H
