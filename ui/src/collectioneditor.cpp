/*
  Q Light Controller
  collectioneditor.cpp

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
#include <QSettings>
#include <QLineEdit>
#include <QLabel>

#include "qlcfixturedef.h"

#include "functionselection.h"
#include "collectioneditor.h"
#include "mastertimer.h"
#include "collection.h"
#include "outputmap.h"
#include "inputmap.h"
#include "function.h"
#include "fixture.h"
#include "apputil.h"
#include "doc.h"

#define SETTINGS_GEOMETRY "collectioneditor/geometry"

#define KColumnFunction 0
#define KColumnFunctionID 1

CollectionEditor::CollectionEditor(QWidget* parent, Collection* fc, Doc* doc,
                                   OutputMap* outputMap, InputMap* inputMap,
                                   MasterTimer* masterTimer)
    : QDialog(parent)
    , m_doc(doc)
    , m_outputMap(outputMap)
    , m_inputMap(inputMap)
    , m_masterTimer(masterTimer)
    , m_original(fc)
{
    Q_ASSERT(doc != NULL);
    Q_ASSERT(outputMap != NULL);
    Q_ASSERT(inputMap != NULL);
    Q_ASSERT(masterTimer != NULL);
    Q_ASSERT(fc != NULL);

    setupUi(this);

    QAction* action = new QAction(this);
    action->setShortcut(QKeySequence(QKeySequence::Close));
    connect(action, SIGNAL(triggered(bool)), this, SLOT(reject()));
    addAction(action);

    connect(m_nameEdit, SIGNAL(textEdited(const QString&)),
            this, SLOT(slotNameEdited(const QString&)));
    connect(m_add, SIGNAL(clicked()), this, SLOT(slotAdd()));
    connect(m_remove, SIGNAL(clicked()), this, SLOT(slotRemove()));

    m_fc = new Collection(doc);
    m_fc->copyFrom(fc);
    Q_ASSERT(m_fc != NULL);

    m_nameEdit->setText(m_fc->name());
    slotNameEdited(m_fc->name());

    updateFunctionList();

    QSettings settings;
    QVariant var = settings.value(SETTINGS_GEOMETRY);
    if (var.isValid() == true)
        restoreGeometry(var.toByteArray());
    AppUtil::ensureWidgetIsVisible(this);
}

CollectionEditor::~CollectionEditor()
{
    QSettings settings;
    settings.setValue(SETTINGS_GEOMETRY, saveGeometry());

    Q_ASSERT(m_fc != NULL);
    delete m_fc;
    m_fc = NULL;
}

void CollectionEditor::slotNameEdited(const QString& text)
{
    setWindowTitle(tr("Collection - %1").arg(text));
}

void CollectionEditor::slotAdd()
{
    FunctionSelection sel(this, m_doc, m_outputMap, m_inputMap, m_masterTimer, true, m_original->id());
    if (sel.exec() == QDialog::Accepted)
    {
        quint32 fid;

        QListIterator <quint32> it(sel.selection());
        while (it.hasNext() == true)
        {
            fid = it.next();
            m_fc->addFunction(fid);
        }

        updateFunctionList();
    }
}

void CollectionEditor::slotRemove()
{
    QTreeWidgetItem* item = m_tree->currentItem();
    if (item != NULL)
    {
        quint32 id = item->text(KColumnFunctionID).toInt();
        m_fc->removeFunction(id);
        delete item;
    }
}

void CollectionEditor::accept()
{
    m_fc->setName(m_nameEdit->text());
    m_original->copyFrom(m_fc);
    m_doc->setModified();

    QDialog::accept();
}

void CollectionEditor::updateFunctionList()
{
    m_tree->clear();

    QListIterator <quint32> it(m_fc->functions());
    while (it.hasNext() == true)
    {
        QTreeWidgetItem* item;
        Function* function;
        quint32 fid;
        QString s;

        fid = it.next();
        function = m_doc->function(fid);
        Q_ASSERT(function != NULL);

        item = new QTreeWidgetItem(m_tree);
        item->setText(KColumnFunction, function->name());
        item->setText(KColumnFunctionID, s.setNum(fid));
    }
}
