/********************************************************************************
** Form generated from reading UI file 'fixtureeditor.ui'
**
** Created: Mon Apr 25 20:19:21 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIXTUREEDITOR_H
#define UI_FIXTUREEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FixtureEditor
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *m_tab;
    QWidget *General;
    QGridLayout *gridLayout;
    QLabel *m_manufacturerLabel;
    QLineEdit *m_manufacturerEdit;
    QLabel *m_modelLabel;
    QLineEdit *m_modelEdit;
    QLabel *m_typeLabel;
    QComboBox *m_typeCombo;
    QLabel *m_authorLabel;
    QLineEdit *m_authorEdit;
    QSpacerItem *spacerItem;
    QWidget *Channels;
    QHBoxLayout *hboxLayout;
    QTreeWidget *m_channelList;
    QVBoxLayout *vboxLayout;
    QToolButton *m_addChannelButton;
    QToolButton *m_removeChannelButton;
    QToolButton *m_editChannelButton;
    QFrame *line_2;
    QToolButton *m_copyChannelButton;
    QToolButton *m_pasteChannelButton;
    QSpacerItem *spacerItem1;
    QToolButton *m_expandChannelsButton;
    QWidget *Modes;
    QHBoxLayout *hboxLayout1;
    QTreeWidget *m_modeList;
    QVBoxLayout *vboxLayout1;
    QToolButton *m_addModeButton;
    QToolButton *m_removeModeButton;
    QToolButton *m_editModeButton;
    QFrame *line;
    QToolButton *m_cloneModeButton;
    QSpacerItem *spacerItem2;
    QToolButton *m_expandModesButton;

    void setupUi(QWidget *FixtureEditor)
    {
        if (FixtureEditor->objectName().isEmpty())
            FixtureEditor->setObjectName(QString::fromUtf8("FixtureEditor"));
        FixtureEditor->resize(510, 482);
        verticalLayout = new QVBoxLayout(FixtureEditor);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_tab = new QTabWidget(FixtureEditor);
        m_tab->setObjectName(QString::fromUtf8("m_tab"));
        General = new QWidget();
        General->setObjectName(QString::fromUtf8("General"));
        gridLayout = new QGridLayout(General);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_manufacturerLabel = new QLabel(General);
        m_manufacturerLabel->setObjectName(QString::fromUtf8("m_manufacturerLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_manufacturerLabel->sizePolicy().hasHeightForWidth());
        m_manufacturerLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(m_manufacturerLabel, 0, 0, 1, 1);

        m_manufacturerEdit = new QLineEdit(General);
        m_manufacturerEdit->setObjectName(QString::fromUtf8("m_manufacturerEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_manufacturerEdit->sizePolicy().hasHeightForWidth());
        m_manufacturerEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(m_manufacturerEdit, 0, 1, 1, 1);

        m_modelLabel = new QLabel(General);
        m_modelLabel->setObjectName(QString::fromUtf8("m_modelLabel"));

        gridLayout->addWidget(m_modelLabel, 1, 0, 1, 1);

        m_modelEdit = new QLineEdit(General);
        m_modelEdit->setObjectName(QString::fromUtf8("m_modelEdit"));
        sizePolicy1.setHeightForWidth(m_modelEdit->sizePolicy().hasHeightForWidth());
        m_modelEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(m_modelEdit, 1, 1, 1, 1);

        m_typeLabel = new QLabel(General);
        m_typeLabel->setObjectName(QString::fromUtf8("m_typeLabel"));

        gridLayout->addWidget(m_typeLabel, 2, 0, 1, 1);

        m_typeCombo = new QComboBox(General);
        m_typeCombo->insertItems(0, QStringList()
         << QString::fromUtf8("Color Changer")
         << QString::fromUtf8("Dimmer")
         << QString::fromUtf8("Effect")
         << QString::fromUtf8("Fan")
         << QString::fromUtf8("Flower")
         << QString::fromUtf8("Hazer")
         << QString::fromUtf8("Laser")
         << QString::fromUtf8("Moving Head")
         << QString::fromUtf8("Other")
         << QString::fromUtf8("Scanner")
         << QString::fromUtf8("Smoke")
         << QString::fromUtf8("Strobe")
        );
        m_typeCombo->setObjectName(QString::fromUtf8("m_typeCombo"));
        sizePolicy1.setHeightForWidth(m_typeCombo->sizePolicy().hasHeightForWidth());
        m_typeCombo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(m_typeCombo, 2, 1, 1, 1);

        m_authorLabel = new QLabel(General);
        m_authorLabel->setObjectName(QString::fromUtf8("m_authorLabel"));

        gridLayout->addWidget(m_authorLabel, 3, 0, 1, 1);

        m_authorEdit = new QLineEdit(General);
        m_authorEdit->setObjectName(QString::fromUtf8("m_authorEdit"));

        gridLayout->addWidget(m_authorEdit, 3, 1, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 4, 1, 1, 1);

        m_tab->addTab(General, QString());
        Channels = new QWidget();
        Channels->setObjectName(QString::fromUtf8("Channels"));
        hboxLayout = new QHBoxLayout(Channels);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        m_channelList = new QTreeWidget(Channels);
        m_channelList->setObjectName(QString::fromUtf8("m_channelList"));
        m_channelList->setAlternatingRowColors(true);
        m_channelList->setRootIsDecorated(true);
        m_channelList->setItemsExpandable(true);
        m_channelList->setAllColumnsShowFocus(true);
        m_channelList->setExpandsOnDoubleClick(false);

        hboxLayout->addWidget(m_channelList);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        m_addChannelButton = new QToolButton(Channels);
        m_addChannelButton->setObjectName(QString::fromUtf8("m_addChannelButton"));
        m_addChannelButton->setText(QString::fromUtf8("..."));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_addChannelButton->setIcon(icon);
        m_addChannelButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_addChannelButton);

        m_removeChannelButton = new QToolButton(Channels);
        m_removeChannelButton->setObjectName(QString::fromUtf8("m_removeChannelButton"));
        m_removeChannelButton->setText(QString::fromUtf8("..."));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/edit_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_removeChannelButton->setIcon(icon1);
        m_removeChannelButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_removeChannelButton);

        m_editChannelButton = new QToolButton(Channels);
        m_editChannelButton->setObjectName(QString::fromUtf8("m_editChannelButton"));
        m_editChannelButton->setText(QString::fromUtf8("..."));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_editChannelButton->setIcon(icon2);
        m_editChannelButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_editChannelButton);

        line_2 = new QFrame(Channels);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line_2);

        m_copyChannelButton = new QToolButton(Channels);
        m_copyChannelButton->setObjectName(QString::fromUtf8("m_copyChannelButton"));
        m_copyChannelButton->setText(QString::fromUtf8("..."));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_copyChannelButton->setIcon(icon3);
        m_copyChannelButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_copyChannelButton);

        m_pasteChannelButton = new QToolButton(Channels);
        m_pasteChannelButton->setObjectName(QString::fromUtf8("m_pasteChannelButton"));
        m_pasteChannelButton->setText(QString::fromUtf8("..."));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/editpaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pasteChannelButton->setIcon(icon4);
        m_pasteChannelButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_pasteChannelButton);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem1);

        m_expandChannelsButton = new QToolButton(Channels);
        m_expandChannelsButton->setObjectName(QString::fromUtf8("m_expandChannelsButton"));
        m_expandChannelsButton->setText(QString::fromUtf8("..."));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_expandChannelsButton->setIcon(icon5);
        m_expandChannelsButton->setIconSize(QSize(26, 26));

        vboxLayout->addWidget(m_expandChannelsButton);


        hboxLayout->addLayout(vboxLayout);

        m_tab->addTab(Channels, QString());
        Modes = new QWidget();
        Modes->setObjectName(QString::fromUtf8("Modes"));
        hboxLayout1 = new QHBoxLayout(Modes);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        m_modeList = new QTreeWidget(Modes);
        m_modeList->setObjectName(QString::fromUtf8("m_modeList"));
        m_modeList->setAlternatingRowColors(true);
        m_modeList->setRootIsDecorated(true);
        m_modeList->setAllColumnsShowFocus(true);
        m_modeList->setExpandsOnDoubleClick(false);

        hboxLayout1->addWidget(m_modeList);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        m_addModeButton = new QToolButton(Modes);
        m_addModeButton->setObjectName(QString::fromUtf8("m_addModeButton"));
        m_addModeButton->setText(QString::fromUtf8("..."));
        m_addModeButton->setIcon(icon);
        m_addModeButton->setIconSize(QSize(26, 26));

        vboxLayout1->addWidget(m_addModeButton);

        m_removeModeButton = new QToolButton(Modes);
        m_removeModeButton->setObjectName(QString::fromUtf8("m_removeModeButton"));
        m_removeModeButton->setText(QString::fromUtf8("..."));
        m_removeModeButton->setIcon(icon1);
        m_removeModeButton->setIconSize(QSize(26, 26));

        vboxLayout1->addWidget(m_removeModeButton);

        m_editModeButton = new QToolButton(Modes);
        m_editModeButton->setObjectName(QString::fromUtf8("m_editModeButton"));
        m_editModeButton->setText(QString::fromUtf8("..."));
        m_editModeButton->setIcon(icon2);
        m_editModeButton->setIconSize(QSize(26, 26));

        vboxLayout1->addWidget(m_editModeButton);

        line = new QFrame(Modes);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout1->addWidget(line);

        m_cloneModeButton = new QToolButton(Modes);
        m_cloneModeButton->setObjectName(QString::fromUtf8("m_cloneModeButton"));
        m_cloneModeButton->setText(QString::fromUtf8("..."));
        m_cloneModeButton->setIcon(icon3);
        m_cloneModeButton->setIconSize(QSize(26, 26));

        vboxLayout1->addWidget(m_cloneModeButton);

        spacerItem2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem2);

        m_expandModesButton = new QToolButton(Modes);
        m_expandModesButton->setObjectName(QString::fromUtf8("m_expandModesButton"));
        m_expandModesButton->setText(QString::fromUtf8("..."));
        m_expandModesButton->setIcon(icon5);
        m_expandModesButton->setIconSize(QSize(26, 26));

        vboxLayout1->addWidget(m_expandModesButton);


        hboxLayout1->addLayout(vboxLayout1);

        m_tab->addTab(Modes, QString());

        verticalLayout->addWidget(m_tab);


        retranslateUi(FixtureEditor);

        m_tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FixtureEditor);
    } // setupUi

    void retranslateUi(QWidget *FixtureEditor)
    {
        FixtureEditor->setWindowTitle(QApplication::translate("FixtureEditor", "Fixture", 0, QApplication::UnicodeUTF8));
        m_manufacturerLabel->setText(QApplication::translate("FixtureEditor", "Manufacturer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_manufacturerEdit->setToolTip(QApplication::translate("FixtureEditor", "The manufacturer name for this fixture (e.g. Martin)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_modelLabel->setText(QApplication::translate("FixtureEditor", "Model", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_modelEdit->setToolTip(QApplication::translate("FixtureEditor", "The model name for this fixture (e.g. MAC250)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_typeLabel->setText(QApplication::translate("FixtureEditor", "Type", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_typeCombo->setToolTip(QApplication::translate("FixtureEditor", "The general type of this fixture", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_authorLabel->setText(QApplication::translate("FixtureEditor", "Author", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_authorEdit->setToolTip(QApplication::translate("FixtureEditor", "The author name of this fixture definition", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_tab->setTabText(m_tab->indexOf(General), QApplication::translate("FixtureEditor", "General", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = m_channelList->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("FixtureEditor", "Group", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("FixtureEditor", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_addChannelButton->setToolTip(QApplication::translate("FixtureEditor", "Add a channel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_removeChannelButton->setToolTip(QApplication::translate("FixtureEditor", "Remove the selected channel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_editChannelButton->setToolTip(QApplication::translate("FixtureEditor", "Edit the selected channel", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_copyChannelButton->setToolTip(QApplication::translate("FixtureEditor", "Copy the selected channel to the clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_pasteChannelButton->setToolTip(QApplication::translate("FixtureEditor", "Paste the channel in clipboard to this fixture", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_expandChannelsButton->setToolTip(QApplication::translate("FixtureEditor", "Open/close all channel items", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_tab->setTabText(m_tab->indexOf(Channels), QApplication::translate("FixtureEditor", "Channels", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = m_modeList->headerItem();
        ___qtreewidgetitem1->setText(1, QApplication::translate("FixtureEditor", "Channels", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("FixtureEditor", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_addModeButton->setToolTip(QApplication::translate("FixtureEditor", "Add a mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_removeModeButton->setToolTip(QApplication::translate("FixtureEditor", "Remove the selected mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_editModeButton->setToolTip(QApplication::translate("FixtureEditor", "Edit the selected mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_cloneModeButton->setToolTip(QApplication::translate("FixtureEditor", "Create a copy of the selected mode", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_expandModesButton->setToolTip(QApplication::translate("FixtureEditor", "Open/close all mode items", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_tab->setTabText(m_tab->indexOf(Modes), QApplication::translate("FixtureEditor", "Modes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FixtureEditor: public Ui_FixtureEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIXTUREEDITOR_H
