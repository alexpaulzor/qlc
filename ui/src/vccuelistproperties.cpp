/*
  Q Light Controller
  vccuelistproperties.cpp

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

#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QHeaderView>
#include <QDebug>

#include "vccuelistproperties.h"
#include "selectinputchannel.h"
#include "functionselection.h"
#include "assignhotkey.h"
#include "vccuelist.h"
#include "qlcmacros.h"
#include "inputmap.h"
#include "doc.h"

#define KColumnNumber 0
#define KColumnName   1
#define KColumnID     2

VCCueListProperties::VCCueListProperties(VCCueList* cueList, Doc* doc, OutputMap* outputMap,
                                         InputMap* inputMap, MasterTimer* masterTimer)
    : QDialog(cueList)
    , m_doc(doc)
    , m_outputMap(outputMap)
    , m_inputMap(inputMap)
    , m_masterTimer(masterTimer)
{
    Q_ASSERT(doc != NULL);
    Q_ASSERT(outputMap != NULL);
    Q_ASSERT(inputMap != NULL);
    Q_ASSERT(masterTimer != NULL);
    Q_ASSERT(cueList != NULL);
    m_cueList = cueList;

    setupUi(this);

    QAction* action = new QAction(this);
    action->setShortcut(QKeySequence(QKeySequence::Close));
    connect(action, SIGNAL(triggered(bool)), this, SLOT(reject()));
    addAction(action);

    /************************************************************************
     * Cues page
     ************************************************************************/

    /* Name */
    m_nameEdit->setText(cueList->caption());
    m_nameEdit->setSelection(0, cueList->caption().length());

    /* Connections */
    connect(m_addButton, SIGNAL(clicked()),
            this, SLOT(slotAddClicked()));
    connect(m_removeButton, SIGNAL(clicked()),
            this, SLOT(slotRemoveClicked()));
    connect(m_raiseButton, SIGNAL(clicked()),
            this, SLOT(slotRaiseClicked()));
    connect(m_lowerButton, SIGNAL(clicked()),
            this, SLOT(slotLowerClicked()));

    /* Put all cues into the tree widget */
    QTreeWidgetItemIterator it(m_cueList->m_list);
    while (*it != NULL)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(m_list);
        item->setText(KColumnNumber, QString("%1")
                      .arg(m_list->indexOfTopLevelItem(item) + 1));
        item->setText(KColumnName, (*it)->text(KColumnName));
        item->setText(KColumnID, (*it)->text(KColumnID));
        ++it;
    }

    m_list->header()->setResizeMode(QHeaderView::ResizeToContents);

    m_cutAction = new QAction(QIcon(":/editcut.png"), tr("Cut"), this);
    m_cutButton->setDefaultAction(m_cutAction);
    m_cutAction->setShortcut(QKeySequence(QKeySequence::Cut));
    connect(m_cutAction, SIGNAL(triggered(bool)), this, SLOT(slotCutClicked()));

    m_copyAction = new QAction(QIcon(":/editcopy.png"), tr("Copy"), this);
    m_copyButton->setDefaultAction(m_copyAction);
    m_copyAction->setShortcut(QKeySequence(QKeySequence::Copy));
    connect(m_copyAction, SIGNAL(triggered(bool)), this, SLOT(slotCopyClicked()));

    m_pasteAction = new QAction(QIcon(":/editpaste.png"), tr("Paste"), this);
    m_pasteButton->setDefaultAction(m_pasteAction);
    m_pasteAction->setShortcut(QKeySequence(QKeySequence::Paste));
    connect(m_pasteAction, SIGNAL(triggered(bool)), this, SLOT(slotPasteClicked()));

    /************************************************************************
     * Next Cue page
     ************************************************************************/

    /* Connections */
    connect(m_nextAttachButton, SIGNAL(clicked()),
            this, SLOT(slotNextAttachClicked()));
    connect(m_nextDetachButton, SIGNAL(clicked()),
            this, SLOT(slotNextDetachClicked()));
    connect(m_nextAutoDetectInputButton, SIGNAL(toggled(bool)),
            this, SLOT(slotNextAutoDetectInputToggled(bool)));
    connect(m_nextChooseInputButton, SIGNAL(clicked()),
            this, SLOT(slotNextChooseInputClicked()));

    /* Key binding */
    m_nextKeySequence = QKeySequence(cueList->nextKeySequence());
    m_nextKeyEdit->setText(m_nextKeySequence.toString(QKeySequence::NativeText));

    /* External input */
    m_nextInputUniverse = cueList->nextInputUniverse();
    m_nextInputChannel = cueList->nextInputChannel();
    updateNextInputSource();

    /************************************************************************
     * Previous Cue page
     ************************************************************************/

    /* Connections */
    connect(m_previousAttachButton, SIGNAL(clicked()),
            this, SLOT(slotPreviousAttachClicked()));
    connect(m_previousDetachButton, SIGNAL(clicked()),
            this, SLOT(slotPreviousDetachClicked()));
    connect(m_previousAutoDetectInputButton, SIGNAL(toggled(bool)),
            this, SLOT(slotPreviousAutoDetectInputToggled(bool)));
    connect(m_previousChooseInputButton, SIGNAL(clicked()),
            this, SLOT(slotPreviousChooseInputClicked()));

    /* Key binding */
    m_previousKeySequence = QKeySequence(cueList->previousKeySequence());
    m_previousKeyEdit->setText(m_previousKeySequence.toString(QKeySequence::NativeText));

    /* External input */
    m_previousInputUniverse = cueList->previousInputUniverse();
    m_previousInputChannel = cueList->previousInputChannel();
    updatePreviousInputSource();
}

VCCueListProperties::~VCCueListProperties()
{
}

void VCCueListProperties::accept()
{
    m_cueList->setCaption(m_nameEdit->text());

    /* Replace existing list of cues */
    m_cueList->clear();

    QTreeWidgetItemIterator it(m_list);
    while (*it != NULL)
    {
        m_cueList->append((*it)->text(KColumnID).toUInt());
        ++it;
    }

    /* Key sequences */
    m_cueList->setNextKeySequence(m_nextKeySequence);
    m_cueList->setPreviousKeySequence(m_previousKeySequence);

    /* Input sources */
    m_cueList->setNextInputSource(m_nextInputUniverse, m_nextInputChannel);
    m_cueList->setPreviousInputSource(m_previousInputUniverse, m_previousInputChannel);

    QDialog::accept();
}

void VCCueListProperties::slotTabChanged()
{
    // Disengage both auto-detect buttons
    if (m_nextAutoDetectInputButton->isChecked() == true)
        m_nextAutoDetectInputButton->toggle();
    if (m_previousAutoDetectInputButton->isChecked() == true)
        m_previousAutoDetectInputButton->toggle();
}

/****************************************************************************
 * Cues
 ****************************************************************************/

void VCCueListProperties::slotAddClicked()
{
    /* Select functions */
    FunctionSelection fs(this, m_doc, m_outputMap, m_inputMap, m_masterTimer, true,
                         Function::invalidId(), Function::Scene, true);
    if (fs.exec() == QDialog::Accepted)
    {
        int insertionPoint = m_list->topLevelItemCount();
        QTreeWidgetItem* item = m_list->currentItem();
        if (item != NULL)
            insertionPoint = m_list->indexOfTopLevelItem(item);

        /* Append selected functions */
        QListIterator <quint32> it(fs.selection());
        while (it.hasNext() == true)
        {
            Function* function = m_doc->function(it.next());
            item = new QTreeWidgetItem;
            updateFunctionItem(item, function);
            m_list->insertTopLevelItem(insertionPoint++, item);
        }

        m_list->setCurrentItem(item);
        updateStepNumbers();
    }
}

void VCCueListProperties::slotRemoveClicked()
{
    slotCutClicked();
    m_clipboard.clear();
}

void VCCueListProperties::slotRaiseClicked()
{
    QList <QTreeWidgetItem*> items(m_list->selectedItems());
    QListIterator <QTreeWidgetItem*> it(items);

    // Check, whether even one of the items would "bleed" over the edge and
    // cancel the operation if that is the case.
    while (it.hasNext() == true)
    {
        QTreeWidgetItem* item(it.next());
        int index = m_list->indexOfTopLevelItem(item);
        if (index == 0)
            return;
    }

    // Move the items
    it.toFront();
    while (it.hasNext() == true)
    {
        QTreeWidgetItem* item(it.next());
        int index = m_list->indexOfTopLevelItem(item);
        m_list->takeTopLevelItem(index);
        m_list->insertTopLevelItem(index - 1, item);
    }

    updateStepNumbers();

    // Select the moved items
    it.toFront();
    while (it.hasNext() == true)
        it.next()->setSelected(true);
}

void VCCueListProperties::slotLowerClicked()
{
    QList <QTreeWidgetItem*> items(m_list->selectedItems());
    QListIterator <QTreeWidgetItem*> it(items);

    // Check, whether even one of the items would "bleed" over the edge and
    // cancel the operation if that is the case.
    while (it.hasNext() == true)
    {
        QTreeWidgetItem* item(it.next());
        int index = m_list->indexOfTopLevelItem(item);
        if (index == m_list->topLevelItemCount() - 1)
            return;
    }

    // Move the items
    it.toBack();
    while (it.hasPrevious() == true)
    {
        QTreeWidgetItem* item(it.previous());
        int index = m_list->indexOfTopLevelItem(item);
        m_list->takeTopLevelItem(index);
        m_list->insertTopLevelItem(index + 1, item);
    }

    updateStepNumbers();

    // Select the items
    it.toFront();
    while (it.hasNext() == true)
        it.next()->setSelected(true);
}

void VCCueListProperties::slotCutClicked()
{
    m_clipboard.clear();
    QListIterator <QTreeWidgetItem*> it(m_list->selectedItems());
    while (it.hasNext() == true)
    {
        QTreeWidgetItem* item(it.next());
        m_clipboard << quint32(item->text(KColumnID).toUInt());
        delete item;
    }

    m_list->setCurrentItem(NULL);
    updateStepNumbers();
}

void VCCueListProperties::slotCopyClicked()
{
    m_clipboard.clear();
    QListIterator <QTreeWidgetItem*> it(m_list->selectedItems());
    while (it.hasNext() == true)
        m_clipboard << quint32(it.next()->text(KColumnID).toUInt());
}

void VCCueListProperties::slotPasteClicked()
{
    if (m_clipboard.isEmpty() == true)
        return;

    int insertionPoint = 0;
    QTreeWidgetItem* currentItem = m_list->currentItem();
    if (currentItem != NULL)
    {
        insertionPoint = m_list->indexOfTopLevelItem(currentItem);
        currentItem->setSelected(false);
    }
    else
    {
        insertionPoint = CLAMP(0, 0, m_list->topLevelItemCount() - 1);
    }

    QListIterator <quint32> it(m_clipboard);
    while (it.hasNext() == true)
    {
        quint32 fid(it.next());
        Function* function = m_doc->function(fid);
        if (function == NULL)
            continue;

        QTreeWidgetItem* item = new QTreeWidgetItem;
        m_list->insertTopLevelItem(insertionPoint, item);
        updateFunctionItem(item, function);
        item->setSelected(true);
        insertionPoint = CLAMP(m_list->indexOfTopLevelItem(item) + 1, 0, m_list->topLevelItemCount() - 1);
    }

    updateStepNumbers();
}

void VCCueListProperties::updateFunctionItem(QTreeWidgetItem* item, const Function* function)
{
    Q_ASSERT(item != NULL);
    Q_ASSERT(function != NULL);

    item->setText(KColumnNumber, QString("%1").arg(m_list->indexOfTopLevelItem(item) + 1));
    item->setText(KColumnName, function->name());
    item->setText(KColumnID, QString("%1").arg(function->id()));
}

void VCCueListProperties::updateStepNumbers()
{
    for (int i = 0; i < m_list->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item = m_list->topLevelItem(i);
        Q_ASSERT(item != NULL);
        item->setText(KColumnNumber, QString("%1").arg(i + 1));
    }
}

/****************************************************************************
 * Next Cue
 ****************************************************************************/

void VCCueListProperties::slotNextAttachClicked()
{
    AssignHotKey ahk(this, m_nextKeySequence);
    if (ahk.exec() == QDialog::Accepted)
    {
        m_nextKeySequence = QKeySequence(ahk.keySequence());
        m_nextKeyEdit->setText(m_nextKeySequence.toString(QKeySequence::NativeText));
    }
}

void VCCueListProperties::slotNextDetachClicked()
{
    m_nextKeySequence = QKeySequence();
    m_nextKeyEdit->setText(m_nextKeySequence.toString(QKeySequence::NativeText));
}

void VCCueListProperties::slotNextChooseInputClicked()
{
    SelectInputChannel sic(this, m_inputMap);
    if (sic.exec() == QDialog::Accepted)
    {
        m_nextInputUniverse = sic.universe();
        m_nextInputChannel = sic.channel();
        updateNextInputSource();
    }
}

void VCCueListProperties::slotNextAutoDetectInputToggled(bool checked)
{
    if (checked == true)
    {
        connect(m_inputMap, SIGNAL(inputValueChanged(quint32,quint32,uchar)),
                this, SLOT(slotNextInputValueChanged(quint32,quint32)));
    }
    else
    {
        disconnect(m_inputMap, SIGNAL(inputValueChanged(quint32,quint32,uchar)),
                   this, SLOT(slotNextInputValueChanged(quint32,quint32)));
    }
}

void VCCueListProperties::slotNextInputValueChanged(quint32 uni, quint32 ch)
{
    m_nextInputUniverse = uni;
    m_nextInputChannel = ch;
    updateNextInputSource();
}

void VCCueListProperties::updateNextInputSource()
{
    QString uniName;
    QString chName;

    if (m_inputMap->inputSourceNames(m_nextInputUniverse, m_nextInputChannel,
                                     uniName, chName) == true)
    {
        /* Display the gathered information */
        m_nextInputUniverseEdit->setText(uniName);
        m_nextInputChannelEdit->setText(chName);
    }
    else
    {
        m_nextInputUniverseEdit->setText(KInputNone);
        m_nextInputChannelEdit->setText(KInputNone);
    }
}

/****************************************************************************
 * Previous Cue
 ****************************************************************************/

void VCCueListProperties::slotPreviousAttachClicked()
{
    AssignHotKey ahk(this, m_previousKeySequence);
    if (ahk.exec() == QDialog::Accepted)
    {
        m_previousKeySequence = QKeySequence(ahk.keySequence());
        m_previousKeyEdit->setText(m_previousKeySequence.toString(QKeySequence::NativeText));
    }
}

void VCCueListProperties::slotPreviousDetachClicked()
{
    m_previousKeySequence = QKeySequence();
    m_previousKeyEdit->setText(m_previousKeySequence.toString(QKeySequence::NativeText));
}

void VCCueListProperties::slotPreviousChooseInputClicked()
{
    SelectInputChannel sic(this, m_inputMap);
    if (sic.exec() == QDialog::Accepted)
    {
        m_previousInputUniverse = sic.universe();
        m_previousInputChannel = sic.channel();
        updatePreviousInputSource();
    }
}

void VCCueListProperties::slotPreviousAutoDetectInputToggled(bool checked)
{
    if (checked == true)
    {
        if (m_nextAutoDetectInputButton->isChecked() == true)
            m_nextAutoDetectInputButton->toggle();

        connect(m_inputMap, SIGNAL(inputValueChanged(quint32,quint32,uchar)),
                this, SLOT(slotPreviousInputValueChanged(quint32,quint32)));
    }
    else
    {
        disconnect(m_inputMap, SIGNAL(inputValueChanged(quint32,quint32,uchar)),
                   this, SLOT(slotPreviousInputValueChanged(quint32,quint32)));
    }
}

void VCCueListProperties::slotPreviousInputValueChanged(quint32 uni, quint32 ch)
{
    m_previousInputUniverse = uni;
    m_previousInputChannel = ch;
    updatePreviousInputSource();
}

void VCCueListProperties::updatePreviousInputSource()
{
    QString uniName;
    QString chName;

    if (m_inputMap->inputSourceNames(m_previousInputUniverse, m_previousInputChannel,
                                     uniName, chName) == true)
    {
        /* Display the gathered information */
        m_previousInputUniverseEdit->setText(uniName);
        m_previousInputChannelEdit->setText(chName);
    }
    else
    {
        m_previousInputUniverseEdit->setText(KInputNone);
        m_previousInputChannelEdit->setText(KInputNone);
    }
}
