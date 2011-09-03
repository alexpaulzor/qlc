/********************************************************************************
** Form generated from reading UI file 'configurehidinput.ui'
**
** Created: Fri Sep 2 17:16:29 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREHIDINPUT_H
#define UI_CONFIGUREHIDINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigureHIDInput
{
public:
    QVBoxLayout *vboxLayout;
    QTreeWidget *m_list;
    QHBoxLayout *hboxLayout;
    QPushButton *m_refreshButton;
    QSpacerItem *spacerItem;
    QDialogButtonBox *m_buttonBox;

    void setupUi(QDialog *ConfigureHIDInput)
    {
        if (ConfigureHIDInput->objectName().isEmpty())
            ConfigureHIDInput->setObjectName(QString::fromUtf8("ConfigureHIDInput"));
        ConfigureHIDInput->resize(451, 300);
        vboxLayout = new QVBoxLayout(ConfigureHIDInput);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_list = new QTreeWidget(ConfigureHIDInput);
        m_list->setObjectName(QString::fromUtf8("m_list"));
        m_list->setAlternatingRowColors(true);
        m_list->setRootIsDecorated(false);
        m_list->setItemsExpandable(false);
        m_list->setAllColumnsShowFocus(true);

        vboxLayout->addWidget(m_list);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_refreshButton = new QPushButton(ConfigureHIDInput);
        m_refreshButton->setObjectName(QString::fromUtf8("m_refreshButton"));

        hboxLayout->addWidget(m_refreshButton);

        spacerItem = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        m_buttonBox = new QDialogButtonBox(ConfigureHIDInput);
        m_buttonBox->setObjectName(QString::fromUtf8("m_buttonBox"));
        m_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        hboxLayout->addWidget(m_buttonBox);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(ConfigureHIDInput);
        QObject::connect(m_buttonBox, SIGNAL(accepted()), ConfigureHIDInput, SLOT(accept()));
        QObject::connect(m_buttonBox, SIGNAL(rejected()), ConfigureHIDInput, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigureHIDInput);
    } // setupUi

    void retranslateUi(QDialog *ConfigureHIDInput)
    {
        ConfigureHIDInput->setWindowTitle(QApplication::translate("ConfigureHIDInput", "Configure HID Input Plugin", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = m_list->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("ConfigureHIDInput", "Name", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("ConfigureHIDInput", "Input Line", 0, QApplication::UnicodeUTF8));
        m_refreshButton->setText(QApplication::translate("ConfigureHIDInput", "Refresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigureHIDInput: public Ui_ConfigureHIDInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREHIDINPUT_H
