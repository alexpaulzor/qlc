/*
  Q Light Controller
  busmanager.cpp

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
#include <QMdiSubWindow>
#include <QInputDialog>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QStringList>
#include <QHeaderView>
#include <QSettings>
#include <QMdiArea>
#include <QToolBar>
#include <QAction>
#include <QString>
#include <QIcon>

#include "mastertimer.h"
#include "busmanager.h"
#include "apputil.h"
#include "bus.h"

#define SETTINGS_GEOMETRY "busmanager/geometry"

#define KColumnID   0
#define KColumnName 1
#define KColumnTime 2

BusManager* BusManager::s_instance = NULL;

/****************************************************************************
 * Initialization
 ****************************************************************************/

BusManager::BusManager(QWidget* parent, Qt::WindowFlags f) : QWidget(parent, f)
{
    Q_ASSERT(parent != NULL);

    /* Create a new layout for this widget */
    new QVBoxLayout(this);

    /* Toolbar */
    m_toolbar = new QToolBar(tr("Bus Manager"), this);
    m_toolbar->addAction(QIcon(":/edit.png"), tr("Edit bus name"),
                         this, SLOT(slotEditClicked()));
    layout()->addWidget(m_toolbar);

    /* Tree */
    m_tree = new QTreeWidget(this);
    layout()->addWidget(m_tree);
    m_tree->setRootIsDecorated(false);
    m_tree->setItemsExpandable(false);
    m_tree->setSortingEnabled(false);
    m_tree->setAllColumnsShowFocus(true);
    m_tree->header()->setResizeMode(QHeaderView::Stretch);

    QStringList columns;
    columns << tr("Bus") << tr("Name") << tr("Time");
    m_tree->setHeaderLabels(columns);

    fillTree();

    // Listen to bus value changes
    connect(Bus::instance(), SIGNAL(valueChanged(quint32,quint32)),
            this, SLOT(slotBusValueChanged(quint32,quint32)));
}

BusManager::~BusManager()
{
    QSettings settings;
#ifdef __APPLE__
    settings.setValue(SETTINGS_GEOMETRY, saveGeometry());
#else
    settings.setValue(SETTINGS_GEOMETRY, parentWidget()->saveGeometry());
#endif
    BusManager::s_instance = NULL;
}

void BusManager::createAndShow(QWidget* parent)
{
    QWidget* window = NULL;

    /* Must not create more than one instance */
    if (s_instance == NULL)
    {
    #ifdef __APPLE__
        /* Create a separate window for OSX */
        s_instance = new BusManager(parent, Qt::Window);
        window = s_instance;
    #else
        /* Create an MDI window for X11 & Win32 */
        QMdiArea* area = qobject_cast<QMdiArea*> (parent);
        Q_ASSERT(area != NULL);
        QMdiSubWindow* sub = new QMdiSubWindow;
        s_instance = new BusManager(sub);
        sub->setWidget(s_instance);
        window = area->addSubWindow(sub);
    #endif

        /* Set some common properties for the window and show it */
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->setWindowIcon(QIcon(":/bus.png"));
        window->setWindowTitle(tr("Bus Manager"));
        window->setContextMenuPolicy(Qt::CustomContextMenu);
        window->show();

        QSettings settings;
        QVariant var = settings.value(SETTINGS_GEOMETRY);
        if (var.isValid() == true)
        {
            window->restoreGeometry(var.toByteArray());
            AppUtil::ensureWidgetIsVisible(window);
        }
    }
    else
    {
    #ifdef __APPLE__
        window = s_instance;
    #else
        window = s_instance->parentWidget();
    #endif
    }

    window->show();
    window->raise();
}

/****************************************************************************
 * Toolbar
 ****************************************************************************/

void BusManager::slotEditClicked()
{
    QTreeWidgetItem* item = m_tree->currentItem();

    if (item != NULL)
    {
        QString label;
        QString name;
        quint32 bus;
        bool ok = false;

        bus = item->text(KColumnID).toUInt() - 1;
        label = tr("Bus #%1 name:").arg(bus + 1);
        name = QInputDialog::getText(this, tr("Rename bus"), label,
                                     QLineEdit::Normal,
                                     Bus::instance()->name(bus),
                                     &ok);
        if (ok == true)
        {
            Bus::instance()->setName(bus, name);
            item->setText(KColumnName, name);
        }
    }
}

/****************************************************************************
 * Tree widget
 ****************************************************************************/

void BusManager::fillTree()
{
    /* Fill all buses to tree */
    for (quint32 bus = 0; bus < Bus::count(); bus++)
    {
        QTreeWidgetItem* item;
        item = new QTreeWidgetItem(m_tree);
        item->setText(KColumnID, QString("%1").arg(bus + 1));
        item->setText(KColumnName, Bus::instance()->name(bus));
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        slotBusValueChanged(bus, Bus::instance()->value(bus));
    }

    /* Set first bus selected */
    m_tree->setCurrentItem(m_tree->topLevelItem(0));

    /* Listen to in-place item renaming */
    connect(m_tree, SIGNAL(itemChanged(QTreeWidgetItem*,int)),
            this, SLOT(slotItemChanged(QTreeWidgetItem*,int)));
}
#include <QDebug>
void BusManager::slotItemChanged(QTreeWidgetItem* item, int column)
{
    int index;

    Q_ASSERT(item != NULL);

    index = m_tree->indexOfTopLevelItem(item);
    if (column == KColumnID)
    {
        /* Reject ID column edits */
        item->setText(KColumnID, QString("%1").arg(index + 1));
    }
    else if (column == KColumnName)
    {
        /* Change bus name */
        Bus::instance()->setName(index, item->text(KColumnName));
    }
    else
    {
        /* Change bus value */
        bool ok = false;
        qreal value = item->text(KColumnTime).remove(QRegExp("([A-Z]|[a-z])")).toDouble(&ok);
        if (ok == true)
        {
            value = value * qreal(MasterTimer::frequency());
            Bus::instance()->setValue(index, value);
        }

        // Ensure the column displays the current value
        slotBusValueChanged(index, Bus::instance()->value(index));
    }
}

void BusManager::slotBusValueChanged(quint32 bus, quint32 value)
{
    QTreeWidgetItem* item = m_tree->topLevelItem(bus);
    if (item != NULL)
    {
        QString num;
        num.sprintf("%.2fs", qreal(value) / qreal(MasterTimer::frequency()));
        item->setText(KColumnTime, num);
    }
}
