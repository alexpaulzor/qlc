/*
  Q Light Controller
  inputmanager.cpp

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
#include <QTreeWidget>
#include <QHeaderView>
#include <QStringList>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSettings>
#include <QMdiArea>
#include <QToolBar>
#include <QAction>
#include <QTimer>
#include <QDebug>
#include <QIcon>

#include "qlcinplugin.h"

#include "inputpatcheditor.h"
#include "inputmanager.h"
#include "inputpatch.h"
#include "inputmap.h"
#include "apputil.h"
#include "doc.h"

#define SETTINGS_GEOMETRY "inputmanager/geometry"

#define KColumnUniverse 0
#define KColumnPlugin   1
#define KColumnInput    2
#define KColumnProfile  3
#define KColumnEditor   4
#define KColumnInputNum 5

InputManager* InputManager::s_instance = NULL;

/****************************************************************************
 * Initialization
 ****************************************************************************/

InputManager::InputManager(QWidget* parent, InputMap* inputMap, Qt::WindowFlags flags)
    : QWidget(parent, flags)
    , m_inputMap(inputMap)
{
    Q_ASSERT(inputMap != NULL);

    /* Create a new layout for this widget */
    new QVBoxLayout(this);

    /* Toolbar */
    m_toolbar = new QToolBar(tr("Input Manager"), this);
    m_toolbar->addAction(QIcon(":/edit.png"), tr("Edit Mapping"),
                         this, SLOT(slotEditClicked()));
    layout()->addWidget(m_toolbar);

    /* Tree */
    m_tree = new QTreeWidget(this);
    layout()->addWidget(m_tree);
    m_tree->setRootIsDecorated(false);
    m_tree->setItemsExpandable(false);
    m_tree->setSortingEnabled(false);
    m_tree->setAllColumnsShowFocus(true);
    m_tree->header()->setResizeMode(QHeaderView::ResizeToContents);

    QStringList columns;
    columns << tr("Universe") << tr("Plugin") << tr("Input") << tr("Profile")
            << tr("Editor universe");
    m_tree->setHeaderLabels(columns);

    connect(m_tree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
            this, SLOT(slotEditClicked()));

    /* Timer that clears the input data icon after a while */
    m_timer = new QTimer(this);
    m_timer->setSingleShot(true);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slotTimerTimeout()));

    /* Listen to input map's input data signals */
    connect(m_inputMap, SIGNAL(inputValueChanged(quint32,quint32,uchar)),
            this, SLOT(slotInputValueChanged(quint32,quint32,uchar)));

    /* Listen to plugin configuration changes */
    connect(m_inputMap, SIGNAL(pluginConfigurationChanged(const QString&)),
            this, SLOT(slotPluginConfigurationChanged()));

    updateTree();
}

InputManager::~InputManager()
{
    QSettings settings;
#ifdef __APPLE__
    settings.setValue(SETTINGS_GEOMETRY, saveGeometry());
#else
    settings.setValue(SETTINGS_GEOMETRY, parentWidget()->saveGeometry());
#endif
    InputManager::s_instance = NULL;
}

void InputManager::createAndShow(QWidget* parent, InputMap* inputMap)
{
    QWidget* window = NULL;

    /* Must not create more than one instance */
    if (s_instance == NULL)
    {
    #ifdef __APPLE__
        /* Create a separate window for OSX */
        s_instance = new InputManager(parent, inputMap, Qt::Window);
        window = s_instance;
    #else
        /* Create an MDI window for X11 & Win32 */
        QMdiArea* area = qobject_cast<QMdiArea*> (parent);
        Q_ASSERT(area != NULL);
        QMdiSubWindow* sub = new QMdiSubWindow;
        s_instance = new InputManager(sub, inputMap);
        sub->setWidget(s_instance);
        window = area->addSubWindow(sub);
    #endif

        /* Set some common properties for the window and show it */
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->setWindowIcon(QIcon(":/input.png"));
        window->setWindowTitle(tr("Input Manager"));
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

/*****************************************************************************
 * Tree widget
 *****************************************************************************/

void InputManager::updateTree()
{
    m_tree->clear();
    for (quint32 i = 0; i < m_inputMap->universes(); i++)
    {
        InputPatch* inputPatch = m_inputMap->patch(i);
        Q_ASSERT(inputPatch != NULL);

        QTreeWidgetItem* item = new QTreeWidgetItem(m_tree);
        updateItem(item, inputPatch, i);
    }
}

void InputManager::updateItem(QTreeWidgetItem* item, InputPatch* ip,
                              quint32 universe)
{
    Q_ASSERT(item != NULL);
    Q_ASSERT(ip != NULL);

    item->setText(KColumnUniverse, QString("%1").arg(universe + 1));
    item->setText(KColumnPlugin, ip->pluginName());
    item->setText(KColumnInput, ip->inputName());
    item->setText(KColumnProfile, ip->profileName());
    if (m_inputMap->editorUniverse() == universe)
    {
        item->setCheckState(KColumnEditor, Qt::Checked);
        item->setFlags(item->flags() & ~Qt::ItemIsUserCheckable);
    }
    item->setText(KColumnInputNum, QString("%1").arg(ip->input() + 1));
}

void InputManager::slotPluginConfigurationChanged()
{
    updateTree();
}

void InputManager::slotInputValueChanged(quint32 universe, quint32 channel,
                                         uchar value)
{
    Q_UNUSED(channel);
    Q_UNUSED(value);

    QTreeWidgetItem* item = m_tree->topLevelItem(universe);
    if (item == NULL)
        return;

    /* Show an icon on a universe row that received input data */
    QIcon icon(":/input.png");
    item->setIcon(KColumnUniverse, icon);

    /* Restart the timer */
    m_timer->start(250);
}

void InputManager::slotTimerTimeout()
{
    QTreeWidgetItemIterator it(m_tree);
    while (*it != NULL)
    {
        (*it)->setIcon(KColumnUniverse, QIcon());
        ++it;
    }
}

/****************************************************************************
 * Toolbar
 ****************************************************************************/

void InputManager::slotEditClicked()
{
    QTreeWidgetItem* item = m_tree->currentItem();
    if (item == NULL)
        return;

    quint32 universe = item->text(KColumnUniverse).toInt() - 1;
    InputPatchEditor ipe(this, universe, m_inputMap);
    if (ipe.exec() == QDialog::Accepted)
        updateTree();
}
