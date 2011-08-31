/********************************************************************************
** Form generated from reading UI file 'editchannel.ui'
**
** Created: Mon Apr 25 20:19:21 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCHANNEL_H
#define UI_EDITCHANNEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditChannel
{
public:
    QGridLayout *gridLayout;
    QLabel *m_nameLabel;
    QLineEdit *m_nameEdit;
    QLabel *m_groupLabel;
    QComboBox *m_groupCombo;
    QLabel *m_colourLabel;
    QComboBox *m_colourCombo;
    QGroupBox *m_controlByteGroup;
    QHBoxLayout *hboxLayout;
    QRadioButton *m_msbRadio;
    QRadioButton *m_lsbRadio;
    QGroupBox *groupBox_2;
    QHBoxLayout *hboxLayout1;
    QTreeWidget *m_capabilityList;
    QVBoxLayout *vboxLayout;
    QToolButton *m_addCapabilityButton;
    QToolButton *m_removeCapabilityButton;
    QToolButton *m_editCapabilityButton;
    QSpacerItem *spacerItem;
    QToolButton *m_wizardButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditChannel)
    {
        if (EditChannel->objectName().isEmpty())
            EditChannel->setObjectName(QString::fromUtf8("EditChannel"));
        EditChannel->resize(406, 462);
        gridLayout = new QGridLayout(EditChannel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_nameLabel = new QLabel(EditChannel);
        m_nameLabel->setObjectName(QString::fromUtf8("m_nameLabel"));

        gridLayout->addWidget(m_nameLabel, 0, 0, 1, 1);

        m_nameEdit = new QLineEdit(EditChannel);
        m_nameEdit->setObjectName(QString::fromUtf8("m_nameEdit"));

        gridLayout->addWidget(m_nameEdit, 0, 1, 1, 1);

        m_groupLabel = new QLabel(EditChannel);
        m_groupLabel->setObjectName(QString::fromUtf8("m_groupLabel"));

        gridLayout->addWidget(m_groupLabel, 1, 0, 1, 1);

        m_groupCombo = new QComboBox(EditChannel);
        m_groupCombo->setObjectName(QString::fromUtf8("m_groupCombo"));

        gridLayout->addWidget(m_groupCombo, 1, 1, 1, 1);

        m_colourLabel = new QLabel(EditChannel);
        m_colourLabel->setObjectName(QString::fromUtf8("m_colourLabel"));

        gridLayout->addWidget(m_colourLabel, 2, 0, 1, 1);

        m_colourCombo = new QComboBox(EditChannel);
        m_colourCombo->setObjectName(QString::fromUtf8("m_colourCombo"));

        gridLayout->addWidget(m_colourCombo, 2, 1, 1, 1);

        m_controlByteGroup = new QGroupBox(EditChannel);
        m_controlByteGroup->setObjectName(QString::fromUtf8("m_controlByteGroup"));
        hboxLayout = new QHBoxLayout(m_controlByteGroup);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_msbRadio = new QRadioButton(m_controlByteGroup);
        m_msbRadio->setObjectName(QString::fromUtf8("m_msbRadio"));

        hboxLayout->addWidget(m_msbRadio);

        m_lsbRadio = new QRadioButton(m_controlByteGroup);
        m_lsbRadio->setObjectName(QString::fromUtf8("m_lsbRadio"));

        hboxLayout->addWidget(m_lsbRadio);


        gridLayout->addWidget(m_controlByteGroup, 3, 0, 1, 2);

        groupBox_2 = new QGroupBox(EditChannel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        hboxLayout1 = new QHBoxLayout(groupBox_2);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_capabilityList = new QTreeWidget(groupBox_2);
        m_capabilityList->setObjectName(QString::fromUtf8("m_capabilityList"));
        m_capabilityList->setAlternatingRowColors(true);
        m_capabilityList->setRootIsDecorated(false);
        m_capabilityList->setItemsExpandable(false);
        m_capabilityList->setAllColumnsShowFocus(true);

        hboxLayout1->addWidget(m_capabilityList);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_addCapabilityButton = new QToolButton(groupBox_2);
        m_addCapabilityButton->setObjectName(QString::fromUtf8("m_addCapabilityButton"));
        m_addCapabilityButton->setText(QString::fromUtf8("..."));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_addCapabilityButton->setIcon(icon);
        m_addCapabilityButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_addCapabilityButton);

        m_removeCapabilityButton = new QToolButton(groupBox_2);
        m_removeCapabilityButton->setObjectName(QString::fromUtf8("m_removeCapabilityButton"));
        m_removeCapabilityButton->setText(QString::fromUtf8("..."));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/edit_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_removeCapabilityButton->setIcon(icon1);
        m_removeCapabilityButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_removeCapabilityButton);

        m_editCapabilityButton = new QToolButton(groupBox_2);
        m_editCapabilityButton->setObjectName(QString::fromUtf8("m_editCapabilityButton"));
        m_editCapabilityButton->setText(QString::fromUtf8("..."));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_editCapabilityButton->setIcon(icon2);
        m_editCapabilityButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_editCapabilityButton);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

        m_wizardButton = new QToolButton(groupBox_2);
        m_wizardButton->setObjectName(QString::fromUtf8("m_wizardButton"));
        m_wizardButton->setText(QString::fromUtf8("..."));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/wizard.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_wizardButton->setIcon(icon3);
        m_wizardButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_wizardButton);


        hboxLayout1->addLayout(vboxLayout);


        gridLayout->addWidget(groupBox_2, 4, 0, 1, 2);

        buttonBox = new QDialogButtonBox(EditChannel);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 2);


        retranslateUi(EditChannel);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditChannel, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditChannel, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditChannel);
    } // setupUi

    void retranslateUi(QDialog *EditChannel)
    {
        EditChannel->setWindowTitle(QApplication::translate("EditChannel", "Edit Channel", 0, QApplication::UnicodeUTF8));
        m_nameLabel->setText(QApplication::translate("EditChannel", "Name", 0, QApplication::UnicodeUTF8));
        m_groupLabel->setText(QApplication::translate("EditChannel", "Group", 0, QApplication::UnicodeUTF8));
        m_colourLabel->setText(QApplication::translate("EditChannel", "Colour", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_colourCombo->setToolTip(QApplication::translate("EditChannel", "Primary colour level controlled by this channel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_controlByteGroup->setTitle(QApplication::translate("EditChannel", "Control Byte", 0, QApplication::UnicodeUTF8));
        m_msbRadio->setText(QApplication::translate("EditChannel", "Coarse (MSB)", 0, QApplication::UnicodeUTF8));
        m_lsbRadio->setText(QApplication::translate("EditChannel", "Fine (LSB)", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("EditChannel", "Capabilities", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = m_capabilityList->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("EditChannel", "Description", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("EditChannel", "Maximum value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("EditChannel", "Minimum value", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_wizardButton->setToolTip(QApplication::translate("EditChannel", "Capability wizard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class EditChannel: public Ui_EditChannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCHANNEL_H
