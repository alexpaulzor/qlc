/*
  Q Light Controller
  collectioneditor.h

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

#ifndef COLLECTIONEDITOR_H
#define COLLECTIONEDITOR_H

#include <QDialog>

#include "ui_collectioneditor.h"

class FunctionSelection;
class MasterTimer;
class Collection;
class OutputMap;
class InputMap;
class Doc;

class CollectionEditor : public QDialog, public Ui_CollectionEditor
{
    Q_OBJECT
    Q_DISABLE_COPY(CollectionEditor)

public:
    CollectionEditor(QWidget* parent, Collection* fc, Doc* doc, OutputMap* outputMap,
                     InputMap* inputMap, MasterTimer* masterTimer);
    ~CollectionEditor();

private:
    Doc* m_doc;
    OutputMap* m_outputMap;
    InputMap* m_inputMap;
    MasterTimer* m_masterTimer;

protected slots:
    void slotNameEdited(const QString& text);
    void slotAdd();
    void slotRemove();
    void accept();

protected:
    void updateFunctionList();

protected:
    Collection* m_fc;
    Collection* m_original;
};

#endif

