/*
  Q Light Controller
  vccuelistproperties.h

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

#ifndef VCCUELISTPROPERTIES_H
#define VCCUELISTPROPERTIES_H

#include <QKeySequence>
#include <QDialog>
#include <QList>

#include "ui_vccuelistproperties.h"

class MasterTimer;
class VCCueList;
class OutputMap;
class InputMap;
class Function;
class Doc;

class VCCueListProperties : public QDialog, public Ui_VCCueListProperties
{
    Q_OBJECT
    Q_DISABLE_COPY(VCCueListProperties)

    /************************************************************************
     * Initialization
     ************************************************************************/
public:
    VCCueListProperties(VCCueList* cueList, Doc* doc, OutputMap* outputMap,
                        InputMap* inputMap, MasterTimer* masterTimer);
    ~VCCueListProperties();

public slots:
    void accept();
    void slotTabChanged();

protected:
    VCCueList* m_cueList;
    Doc* m_doc;
    OutputMap* m_outputMap;
    InputMap* m_inputMap;
    MasterTimer* m_masterTimer;

    /************************************************************************
     * Cues
     ************************************************************************/
protected slots:
    void slotAddClicked();
    void slotRemoveClicked();
    void slotRaiseClicked();
    void slotLowerClicked();

    void slotCutClicked();
    void slotCopyClicked();
    void slotPasteClicked();

private:
    void updateFunctionItem(QTreeWidgetItem* item, const Function* function);
    void updateStepNumbers();

private:
    QList <quint32> m_clipboard;
    QAction* m_cutAction;
    QAction* m_copyAction;
    QAction* m_pasteAction;

    /************************************************************************
     * Next Cue
     ************************************************************************/
protected slots:
    void slotNextAttachClicked();
    void slotNextDetachClicked();
    void slotNextChooseInputClicked();
    void slotNextAutoDetectInputToggled(bool state);
    void slotNextInputValueChanged(quint32 uni, quint32 ch);

protected:
    void updateNextInputSource();

protected:
    QKeySequence m_nextKeySequence;
    quint32 m_nextInputUniverse;
    quint32 m_nextInputChannel;

    /************************************************************************
     * Previous Cue
     ************************************************************************/
protected slots:
    void slotPreviousAttachClicked();
    void slotPreviousDetachClicked();
    void slotPreviousChooseInputClicked();
    void slotPreviousAutoDetectInputToggled(bool state);
    void slotPreviousInputValueChanged(quint32 uni, quint32 ch);

protected:
    void updatePreviousInputSource();

protected:
    QKeySequence m_previousKeySequence;
    quint32 m_previousInputUniverse;
    quint32 m_previousInputChannel;
};

#endif
