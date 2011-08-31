/*
  Q Light Controller
  functionwizard.cpp

  Copyright (C) Heikki Junnila

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

#include <QString>
#include <QDebug>
#include <QHash>

#include <cstdlib>

#include "intensitygenerator.h"
#include "palettegenerator.h"
#include "fixtureselection.h"
#include "functionwizard.h"
#include "qlcchannel.h"
#include "fixture.h"
#include "chaser.h"
#include "scene.h"
#include "app.h"
#include "doc.h"

#include "qlccapability.h"
#include "qlcchannel.h"

#define KColumnName 0
#define KColumnCaps 1
#define KColumnID   2

FunctionWizard::FunctionWizard(QWidget* parent, Doc* doc)
    : QDialog(parent)
    , m_doc(doc)
{
    Q_ASSERT(doc != NULL);
    setupUi(this);

    QAction* action = new QAction(this);
    action->setShortcut(QKeySequence(QKeySequence::Close));
    connect(action, SIGNAL(triggered(bool)), this, SLOT(reject()));
    addAction(action);

    m_fixtureTree->sortItems(KColumnName, Qt::AscendingOrder);
}

FunctionWizard::~FunctionWizard()
{
}

void FunctionWizard::slotAddClicked()
{
    FixtureSelection fs(this, m_doc, true, fixtureIds());
    if (fs.exec() == QDialog::Accepted)
    {
        QListIterator <quint32> it(fs.selection);
        while (it.hasNext() == true)
            addFixture(it.next());
    }
}

void FunctionWizard::slotRemoveClicked()
{
    QListIterator <QTreeWidgetItem*> it(m_fixtureTree->selectedItems());
    while (it.hasNext() == true)
        delete it.next();
}

void FunctionWizard::accept()
{
    PaletteGenerator pal(m_doc, fixtures());

    if (m_coloursCheck->isChecked() == true)
        pal.createColours();
    if (m_goboCheck->isChecked() == true)
        pal.createGobos();
    if (m_shutterCheck->isChecked() == true)
        pal.createShutters();

    if (m_intensityCheck->isChecked() == true)
    {
        QList <Scene*> sceneList;

        // Random chaser
        sceneList = IntensityGenerator::randomScenes(fixtures(), m_doc,
                                    QDateTime::currentDateTime().toTime_t());
        if (sceneList.size() > 0)
        {
            int i = 0;
            Chaser* chaser = new Chaser(m_doc);
            chaser->setName(tr("Random Multi"));
            m_doc->addFunction(chaser);
            foreach (Scene* scene, sceneList)
            {
                scene->setName(tr("Random Step %1").arg(++i));
                m_doc->addFunction(scene);
                chaser->addStep(scene->id());
            }
        }

        // Forward & Backward Sequence chasers
        sceneList = IntensityGenerator::sequenceScenes(fixtures(), m_doc);
        if (sceneList.size() > 0)
        {
            int i = 0;
            Chaser* fw = new Chaser(m_doc);
            fw->setName(tr("Sequence Forward"));
            m_doc->addFunction(fw);

            Chaser* bw = new Chaser(m_doc);
            bw->setName(tr("Sequence Backward"));
            bw->setDirection(Function::Backward);
            m_doc->addFunction(bw);

            foreach (Scene* scene, sceneList)
            {
                scene->setName(tr("Sequence Step %1").arg(++i));
                m_doc->addFunction(scene);
                fw->addStep(scene->id());
                bw->addStep(scene->id());
            }
        }

        // Single-channel sequence chaser (use sequence scene list)
        if (sceneList.size() > 0)
        {
            Chaser* chaser = new Chaser(m_doc);
            chaser->setName(tr("Random Single"));
            m_doc->addFunction(chaser);

            while (sceneList.isEmpty() == false)
            {
                Scene* scene = sceneList.takeAt(rand() % sceneList.size());
                chaser->addStep(scene->id());
            }
        }

        // Even/Odd chaser
        sceneList = IntensityGenerator::evenOddScenes(fixtures(), m_doc);
        if (sceneList.size() == 2)
        {
            Chaser* chaser = new Chaser(m_doc);
            chaser->setName(tr("Even/Odd"));
            m_doc->addFunction(chaser);
            sceneList[0]->setName(tr("Odd"));
            m_doc->addFunction(sceneList[0]);
            sceneList[1]->setName(tr("Even"));
            m_doc->addFunction(sceneList[1]);
            chaser->addStep(sceneList[0]->id());
            chaser->addStep(sceneList[1]->id());
        }

        // Full/Zero chaser
        sceneList = IntensityGenerator::fullZeroScenes(fixtures(), m_doc);
        if (sceneList.size() == 2)
        {
            Chaser* chaser = new Chaser(m_doc);
            chaser->setName(tr("Full/Zero"));
            m_doc->addFunction(chaser);
            sceneList[0]->setName(tr("Full"));
            m_doc->addFunction(sceneList[0]);
            sceneList[1]->setName(tr("Zero"));
            m_doc->addFunction(sceneList[1]);
            chaser->addStep(sceneList[0]->id());
            chaser->addStep(sceneList[1]->id());
        }
    }

    QDialog::accept();
}

/****************************************************************************
 * Fixtures
 ****************************************************************************/

void FunctionWizard::addFixture(quint32 fxi_id)
{
    Fixture* fxi = m_doc->fixture(fxi_id);
    Q_ASSERT(fxi != NULL);

    QTreeWidgetItem* item = new QTreeWidgetItem(m_fixtureTree);
    item->setText(KColumnName, fxi->name());
    item->setData(KColumnID, Qt::UserRole, fxi_id);

    QStringList caps;
    if (!PaletteGenerator::findChannels(fxi, QLCChannel::Colour).isEmpty())
        caps << QLCChannel::groupToString(QLCChannel::Colour);

    if (!PaletteGenerator::findChannels(fxi, QLCChannel::Gobo).isEmpty())
        caps << QLCChannel::groupToString(QLCChannel::Gobo);

    if (!PaletteGenerator::findChannels(fxi, QLCChannel::Shutter).isEmpty())
        caps << QLCChannel::groupToString(QLCChannel::Shutter);

    if (IntensityGenerator::intensityChannel(fxi) != QLCChannel::invalid() || fxi->isDimmer())
        caps << QLCChannel::groupToString(QLCChannel::Intensity);

    item->setText(KColumnCaps, caps.join(", "));
}

QList <Fixture*> FunctionWizard::fixtures() const
{
    QList <Fixture*> list;
    for (int i = 0; i < m_fixtureTree->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item(m_fixtureTree->topLevelItem(i));
        Q_ASSERT(item != NULL);

        quint32 id = item->data(KColumnID, Qt::UserRole).toInt();
        Fixture* fxi = m_doc->fixture(id);
        Q_ASSERT(fxi != NULL);

        list << fxi;
    }

    return list;
}

QList <quint32> FunctionWizard::fixtureIds() const
{
    QList <quint32> list;
    for (int i = 0; i < m_fixtureTree->topLevelItemCount(); i++)
    {
        QTreeWidgetItem* item(m_fixtureTree->topLevelItem(i));
        Q_ASSERT(item != NULL);

        list << item->data(KColumnID, Qt::UserRole).toInt();
    }

    return list;
}
