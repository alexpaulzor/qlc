/********************************************************************************
** Form generated from reading UI file 'vccuelistproperties.ui'
**
** Created: Mon Apr 25 20:16:55 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCCUELISTPROPERTIES_H
#define UI_VCCUELISTPROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VCCueListProperties
{
public:
    QGridLayout *gridLayout_2;
    QLabel *m_nameLabel;
    QLineEdit *m_nameEdit;
    QTabWidget *m_tab;
    QWidget *Cues;
    QGridLayout *gridLayout;
    QTreeWidget *m_list;
    QToolButton *m_addButton;
    QToolButton *m_removeButton;
    QToolButton *m_raiseButton;
    QToolButton *m_lowerButton;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QToolButton *m_cutButton;
    QToolButton *m_copyButton;
    QToolButton *m_pasteButton;
    QFrame *line_2;
    QWidget *NextCue;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_nextKeyEdit;
    QToolButton *m_nextAttachButton;
    QToolButton *m_nextDetachButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *m_nextInputUniverseEdit;
    QLabel *label_2;
    QLineEdit *m_nextInputChannelEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_nextAutoDetectInputButton;
    QPushButton *m_nextChooseInputButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *PreviousCue;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *m_previousKeyEdit;
    QToolButton *m_previousAttachButton;
    QToolButton *m_previousDetachButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLineEdit *m_previousInputUniverseEdit;
    QLabel *label_4;
    QLineEdit *m_previousInputChannelEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_previousAutoDetectInputButton;
    QPushButton *m_previousChooseInputButton;
    QSpacerItem *verticalSpacer_3;
    QDialogButtonBox *m_buttonBox;

    void setupUi(QDialog *VCCueListProperties)
    {
        if (VCCueListProperties->objectName().isEmpty())
            VCCueListProperties->setObjectName(QString::fromUtf8("VCCueListProperties"));
        VCCueListProperties->resize(488, 481);
        gridLayout_2 = new QGridLayout(VCCueListProperties);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        m_nameLabel = new QLabel(VCCueListProperties);
        m_nameLabel->setObjectName(QString::fromUtf8("m_nameLabel"));

        gridLayout_2->addWidget(m_nameLabel, 0, 0, 1, 1);

        m_nameEdit = new QLineEdit(VCCueListProperties);
        m_nameEdit->setObjectName(QString::fromUtf8("m_nameEdit"));

        gridLayout_2->addWidget(m_nameEdit, 0, 1, 1, 1);

        m_tab = new QTabWidget(VCCueListProperties);
        m_tab->setObjectName(QString::fromUtf8("m_tab"));
        Cues = new QWidget();
        Cues->setObjectName(QString::fromUtf8("Cues"));
        gridLayout = new QGridLayout(Cues);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_list = new QTreeWidget(Cues);
        m_list->setObjectName(QString::fromUtf8("m_list"));
        m_list->setAlternatingRowColors(true);
        m_list->setSelectionMode(QAbstractItemView::ExtendedSelection);
        m_list->setRootIsDecorated(false);
        m_list->setItemsExpandable(false);
        m_list->setAllColumnsShowFocus(true);
        m_list->setExpandsOnDoubleClick(false);

        gridLayout->addWidget(m_list, 0, 0, 10, 1);

        m_addButton = new QToolButton(Cues);
        m_addButton->setObjectName(QString::fromUtf8("m_addButton"));
        m_addButton->setText(QString::fromUtf8("..."));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_addButton->setIcon(icon);
        m_addButton->setIconSize(QSize(26, 26));

        gridLayout->addWidget(m_addButton, 0, 1, 1, 1);

        m_removeButton = new QToolButton(Cues);
        m_removeButton->setObjectName(QString::fromUtf8("m_removeButton"));
        m_removeButton->setText(QString::fromUtf8("..."));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/edit_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_removeButton->setIcon(icon1);
        m_removeButton->setIconSize(QSize(26, 26));

        gridLayout->addWidget(m_removeButton, 1, 1, 1, 1);

        m_raiseButton = new QToolButton(Cues);
        m_raiseButton->setObjectName(QString::fromUtf8("m_raiseButton"));
        m_raiseButton->setText(QString::fromUtf8("..."));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_raiseButton->setIcon(icon2);
        m_raiseButton->setIconSize(QSize(26, 26));

        gridLayout->addWidget(m_raiseButton, 3, 1, 1, 1);

        m_lowerButton = new QToolButton(Cues);
        m_lowerButton->setObjectName(QString::fromUtf8("m_lowerButton"));
        m_lowerButton->setText(QString::fromUtf8("..."));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_lowerButton->setIcon(icon3);
        m_lowerButton->setIconSize(QSize(26, 26));

        gridLayout->addWidget(m_lowerButton, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 49, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 1);

        line = new QFrame(Cues);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 1, 1, 1);

        m_cutButton = new QToolButton(Cues);
        m_cutButton->setObjectName(QString::fromUtf8("m_cutButton"));
        m_cutButton->setText(QString::fromUtf8("..."));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/editcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_cutButton->setIcon(icon4);
        m_cutButton->setIconSize(QSize(26, 26));

        gridLayout->addWidget(m_cutButton, 6, 1, 1, 1);

        m_copyButton = new QToolButton(Cues);
        m_copyButton->setObjectName(QString::fromUtf8("m_copyButton"));
        m_copyButton->setText(QString::fromUtf8("..."));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/editcopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_copyButton->setIcon(icon5);
        m_copyButton->setIconSize(QSize(26, 26));

        gridLayout->addWidget(m_copyButton, 7, 1, 1, 1);

        m_pasteButton = new QToolButton(Cues);
        m_pasteButton->setObjectName(QString::fromUtf8("m_pasteButton"));
        m_pasteButton->setText(QString::fromUtf8("..."));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/editpaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pasteButton->setIcon(icon6);
        m_pasteButton->setIconSize(QSize(26, 26));

        gridLayout->addWidget(m_pasteButton, 8, 1, 1, 1);

        line_2 = new QFrame(Cues);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 1, 1, 1);

        m_tab->addTab(Cues, QString());
        NextCue = new QWidget();
        NextCue->setObjectName(QString::fromUtf8("NextCue"));
        verticalLayout = new QVBoxLayout(NextCue);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(NextCue);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_nextKeyEdit = new QLineEdit(groupBox);
        m_nextKeyEdit->setObjectName(QString::fromUtf8("m_nextKeyEdit"));
        m_nextKeyEdit->setReadOnly(true);

        horizontalLayout->addWidget(m_nextKeyEdit);

        m_nextAttachButton = new QToolButton(groupBox);
        m_nextAttachButton->setObjectName(QString::fromUtf8("m_nextAttachButton"));
        m_nextAttachButton->setText(QString::fromUtf8("..."));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/key_bindings.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_nextAttachButton->setIcon(icon7);
        m_nextAttachButton->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(m_nextAttachButton);

        m_nextDetachButton = new QToolButton(groupBox);
        m_nextDetachButton->setObjectName(QString::fromUtf8("m_nextDetachButton"));
        m_nextDetachButton->setText(QString::fromUtf8("..."));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/fileclose.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_nextDetachButton->setIcon(icon8);
        m_nextDetachButton->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(m_nextDetachButton);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(NextCue);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        m_nextInputUniverseEdit = new QLineEdit(groupBox_3);
        m_nextInputUniverseEdit->setObjectName(QString::fromUtf8("m_nextInputUniverseEdit"));

        gridLayout_3->addWidget(m_nextInputUniverseEdit, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        m_nextInputChannelEdit = new QLineEdit(groupBox_3);
        m_nextInputChannelEdit->setObjectName(QString::fromUtf8("m_nextInputChannelEdit"));

        gridLayout_3->addWidget(m_nextInputChannelEdit, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 0, 1, 1);

        m_nextAutoDetectInputButton = new QPushButton(groupBox_3);
        m_nextAutoDetectInputButton->setObjectName(QString::fromUtf8("m_nextAutoDetectInputButton"));
        m_nextAutoDetectInputButton->setCheckable(true);

        gridLayout_3->addWidget(m_nextAutoDetectInputButton, 2, 1, 1, 1);

        m_nextChooseInputButton = new QPushButton(groupBox_3);
        m_nextChooseInputButton->setObjectName(QString::fromUtf8("m_nextChooseInputButton"));

        gridLayout_3->addWidget(m_nextChooseInputButton, 2, 2, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_2 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        m_tab->addTab(NextCue, QString());
        PreviousCue = new QWidget();
        PreviousCue->setObjectName(QString::fromUtf8("PreviousCue"));
        verticalLayout_2 = new QVBoxLayout(PreviousCue);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(PreviousCue);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_previousKeyEdit = new QLineEdit(groupBox_2);
        m_previousKeyEdit->setObjectName(QString::fromUtf8("m_previousKeyEdit"));
        m_previousKeyEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(m_previousKeyEdit);

        m_previousAttachButton = new QToolButton(groupBox_2);
        m_previousAttachButton->setObjectName(QString::fromUtf8("m_previousAttachButton"));
        m_previousAttachButton->setText(QString::fromUtf8("..."));
        m_previousAttachButton->setIcon(icon7);
        m_previousAttachButton->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(m_previousAttachButton);

        m_previousDetachButton = new QToolButton(groupBox_2);
        m_previousDetachButton->setObjectName(QString::fromUtf8("m_previousDetachButton"));
        m_previousDetachButton->setText(QString::fromUtf8("..."));
        m_previousDetachButton->setIcon(icon8);
        m_previousDetachButton->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(m_previousDetachButton);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(PreviousCue);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        m_previousInputUniverseEdit = new QLineEdit(groupBox_4);
        m_previousInputUniverseEdit->setObjectName(QString::fromUtf8("m_previousInputUniverseEdit"));

        gridLayout_4->addWidget(m_previousInputUniverseEdit, 0, 1, 1, 2);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        m_previousInputChannelEdit = new QLineEdit(groupBox_4);
        m_previousInputChannelEdit->setObjectName(QString::fromUtf8("m_previousInputChannelEdit"));

        gridLayout_4->addWidget(m_previousInputChannelEdit, 1, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        m_previousAutoDetectInputButton = new QPushButton(groupBox_4);
        m_previousAutoDetectInputButton->setObjectName(QString::fromUtf8("m_previousAutoDetectInputButton"));
        m_previousAutoDetectInputButton->setCheckable(true);

        gridLayout_4->addWidget(m_previousAutoDetectInputButton, 2, 1, 1, 1);

        m_previousChooseInputButton = new QPushButton(groupBox_4);
        m_previousChooseInputButton->setObjectName(QString::fromUtf8("m_previousChooseInputButton"));

        gridLayout_4->addWidget(m_previousChooseInputButton, 2, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        m_tab->addTab(PreviousCue, QString());

        gridLayout_2->addWidget(m_tab, 1, 0, 1, 2);

        m_buttonBox = new QDialogButtonBox(VCCueListProperties);
        m_buttonBox->setObjectName(QString::fromUtf8("m_buttonBox"));
        m_buttonBox->setOrientation(Qt::Horizontal);
        m_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(m_buttonBox, 2, 0, 1, 2);


        retranslateUi(VCCueListProperties);
        QObject::connect(m_buttonBox, SIGNAL(accepted()), VCCueListProperties, SLOT(accept()));
        QObject::connect(m_buttonBox, SIGNAL(rejected()), VCCueListProperties, SLOT(reject()));
        QObject::connect(m_tab, SIGNAL(currentChanged(int)), VCCueListProperties, SLOT(slotTabChanged()));

        m_tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VCCueListProperties);
    } // setupUi

    void retranslateUi(QDialog *VCCueListProperties)
    {
        VCCueListProperties->setWindowTitle(QApplication::translate("VCCueListProperties", "Cue list properties", 0, QApplication::UnicodeUTF8));
        m_nameLabel->setText(QApplication::translate("VCCueListProperties", "Cue list name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_nameEdit->setToolTip(QApplication::translate("VCCueListProperties", "The name of the cue list widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_tab->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem = m_list->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("VCCueListProperties", "Scene", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("VCCueListProperties", "Number", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_list->setToolTip(QApplication::translate("VCCueListProperties", "List of scenes that can be activated with this cue list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_addButton->setToolTip(QApplication::translate("VCCueListProperties", "Add scene(s) to the cue list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_removeButton->setToolTip(QApplication::translate("VCCueListProperties", "Remove selected scene(s) from the cue list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_raiseButton->setToolTip(QApplication::translate("VCCueListProperties", "Raise the selected scene", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_lowerButton->setToolTip(QApplication::translate("VCCueListProperties", "Lower the selected scene", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_cutButton->setToolTip(QApplication::translate("VCCueListProperties", "Cut the selected scenes from their current positions", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_copyButton->setToolTip(QApplication::translate("VCCueListProperties", "Copy the selected scenes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_pasteButton->setToolTip(QApplication::translate("VCCueListProperties", "Paste scenes from the clipboard to the currently selected position", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_tab->setTabText(m_tab->indexOf(Cues), QApplication::translate("VCCueListProperties", "Cues", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("VCCueListProperties", "Key Combination", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_nextKeyEdit->setToolTip(QApplication::translate("VCCueListProperties", "The key combination used to step to the next cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_nextAttachButton->setToolTip(QApplication::translate("VCCueListProperties", "Bind a key combination to skip to the next cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_nextDetachButton->setToolTip(QApplication::translate("VCCueListProperties", "Clear the key binding", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("VCCueListProperties", "External Input", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VCCueListProperties", "Input universe", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_nextInputUniverseEdit->setToolTip(QApplication::translate("VCCueListProperties", "Input universe for skipping to the next cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("VCCueListProperties", "Input channel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_nextInputChannelEdit->setToolTip(QApplication::translate("VCCueListProperties", "Input channel for skipping to the next cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_nextAutoDetectInputButton->setToolTip(QApplication::translate("VCCueListProperties", "When toggled, you can click an external button to assign it as the control that skips to the next cue.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_nextAutoDetectInputButton->setText(QApplication::translate("VCCueListProperties", "Auto Detect", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_nextChooseInputButton->setToolTip(QApplication::translate("VCCueListProperties", "Choose an input universe/channel for skipping to the next cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_nextChooseInputButton->setText(QApplication::translate("VCCueListProperties", "Choose...", 0, QApplication::UnicodeUTF8));
        m_tab->setTabText(m_tab->indexOf(NextCue), QApplication::translate("VCCueListProperties", "Next Cue", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("VCCueListProperties", "Key Combination", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_previousKeyEdit->setToolTip(QApplication::translate("VCCueListProperties", "The key combination used to step to the previous cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_previousAttachButton->setToolTip(QApplication::translate("VCCueListProperties", "Bind a key combination to skip to the previous cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_previousDetachButton->setToolTip(QApplication::translate("VCCueListProperties", "Clear the key binding", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_4->setTitle(QApplication::translate("VCCueListProperties", "External Input", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VCCueListProperties", "Input universe", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_previousInputUniverseEdit->setToolTip(QApplication::translate("VCCueListProperties", "Input universe for skipping to the previous cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("VCCueListProperties", "Input channel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_previousInputChannelEdit->setToolTip(QApplication::translate("VCCueListProperties", "Input channel for skipping to the previous cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        m_previousAutoDetectInputButton->setToolTip(QApplication::translate("VCCueListProperties", "When toggled, you can click an external button to assign it as the control that skips to the previous cue.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_previousAutoDetectInputButton->setText(QApplication::translate("VCCueListProperties", "Auto Detect", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        m_previousChooseInputButton->setToolTip(QApplication::translate("VCCueListProperties", "Choose an input universe/channel for skipping to the previous cue", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        m_previousChooseInputButton->setText(QApplication::translate("VCCueListProperties", "Choose...", 0, QApplication::UnicodeUTF8));
        m_tab->setTabText(m_tab->indexOf(PreviousCue), QApplication::translate("VCCueListProperties", "Previous Cue", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VCCueListProperties: public Ui_VCCueListProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCCUELISTPROPERTIES_H
