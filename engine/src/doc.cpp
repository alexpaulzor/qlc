/*
  Q Light Controller
  doc.cpp

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

#include <QStringList>
#include <QString>
#include <QDebug>
#include <QList>
#include <QtXml>
#include <QDir>

#include "qlcfixturedefcache.h"
#include "qlcfixturemode.h"
#include "qlcfixturedef.h"
#include "qlcfile.h"

#include "collection.h"
#include "function.h"
#include "fixture.h"
#include "chaser.h"
#include "scene.h"
#include "efx.h"
#include "doc.h"

Doc::Doc(QObject* parent, const QLCFixtureDefCache& fixtureDefCache)
    : QObject(parent)
    , m_mode(Design)
    , m_fixtureDefCache(fixtureDefCache)
    , m_latestFixtureId(0)
    , m_latestFunctionId(0)
{
    /* Connect to bus emitter so that Doc can be marked as modified when
       bus name changes. */
    connect(Bus::instance(), SIGNAL(nameChanged(quint32,const QString&)),
            this, SLOT(slotBusNameChanged()));

    resetModified();
}

Doc::~Doc()
{
    clearContents();
}

void Doc::clearContents()
{
    // Delete all function instances
    QListIterator <quint32> funcit(m_functions.keys());
    while (funcit.hasNext() == true)
    {
        Function* func = m_functions.take(funcit.next());
        emit functionRemoved(func->id());
        delete func;
    }

    // Delete all fixture instances
    QListIterator <quint32> fxit(m_fixtures.keys());
    while (fxit.hasNext() == true)
    {
        Fixture* fxi = m_fixtures.take(fxit.next());
        emit fixtureRemoved(fxi->id());
        delete fxi;
    }
}

/*****************************************************************************
 * Modified status
 *****************************************************************************/

bool Doc::isModified() const
{
    return m_modified;
}

void Doc::setModified()
{
    m_modified = true;
    emit modified(true);
}

void Doc::resetModified()
{
    m_modified = false;
    emit modified(false);
}

/*****************************************************************************
 * Main operating mode
 *****************************************************************************/

void Doc::setMode(Doc::Mode mode)
{
    /* Don't do mode switching twice */
    if (m_mode == mode)
        return;
    m_mode = mode;

    foreach(Function* func, m_functions.values())
    {
        Q_ASSERT(func != NULL);
        if (mode == Operate)
            func->arm();
        else if (mode == Design)
            func->disarm();
    }

    emit modeChanged(m_mode);
}

Doc::Mode Doc::mode() const
{
    return m_mode;
}

/*****************************************************************************
 * Fixture definition cache
 *****************************************************************************/

const QLCFixtureDefCache& Doc::fixtureDefCache() const
{
    return m_fixtureDefCache;
}

/*****************************************************************************
 * Fixtures
 *****************************************************************************/

quint32 Doc::createFixtureId()
{
    /* This results in an endless loop if there are UINT_MAX-1 fixtures. That,
       however, seems a bit unlikely. Are there even 4294967295-1 fixtures in
       total in the whole world? */
    while (m_fixtures.contains(m_latestFixtureId) == true ||
           m_latestFixtureId == Fixture::invalidId())
    {
        m_latestFixtureId++;
    }

    return m_latestFixtureId;
}

bool Doc::addFixture(Fixture* fixture, quint32 id)
{
    Q_ASSERT(fixture != NULL);

    // No ID given, this method can assign one
    if (id == Fixture::invalidId())
        id = createFixtureId();

    if (m_fixtures.contains(id) == true || id == Fixture::invalidId())
    {
        qWarning() << Q_FUNC_INFO << "a fixture with ID" << id << "already exists!";
        return false;
    }
    else
    {
        /* Patch fixture change signals thru Doc */
        connect(fixture, SIGNAL(changed(quint32)),
                this, SLOT(slotFixtureChanged(quint32)));

        fixture->setID(id);
        m_fixtures[id] = fixture;
        emit fixtureAdded(id);
        setModified();

        return true;
    }
}

bool Doc::deleteFixture(quint32 id)
{
    if (m_fixtures.contains(id) == true)
    {
        Fixture* fxi = m_fixtures.take(id);
        Q_ASSERT(fxi != NULL);

        emit fixtureRemoved(id);
        setModified();
        delete fxi;

        return true;
    }
    else
    {
        qWarning() << Q_FUNC_INFO << "No fixture with id" << id;
        return false;
    }
}

QList <Fixture*> Doc::fixtures() const
{
    return m_fixtures.values();
}

Fixture* Doc::fixture(quint32 id) const
{
    if (m_fixtures.contains(id) == true)
        return m_fixtures[id];
    else
        return NULL;
}

int Doc::totalPowerConsumption(int& fuzzy) const
{
    int totalPowerConsumption = 0;

    // Make sure fuzzy starts from zero
    fuzzy = 0;

    QListIterator <Fixture*> fxit(fixtures());
    while (fxit.hasNext() == true)
    {
        Fixture* fxi(fxit.next());
        Q_ASSERT(fxi != NULL);

        // Generic dimmer has no mode and physical
        if (fxi->isDimmer() == false && fxi->fixtureMode() != NULL)
        {
            QLCPhysical phys = fxi->fixtureMode()->physical();
            if (phys.powerConsumption() > 0)
                totalPowerConsumption += phys.powerConsumption();
            else
                fuzzy++;
        }
        else
        {
            fuzzy++;
        }
    }

    return totalPowerConsumption;
}

/*****************************************************************************
 * Functions
 *****************************************************************************/

quint32 Doc::createFunctionId()
{
    /* This results in an endless loop if there are UINT_MAX-1 functions. That,
       however, seems a bit unlikely. Are there even 4294967295-1 functions in
       total in the whole world? */
    while (m_functions.contains(m_latestFunctionId) == true ||
           m_latestFunctionId == Fixture::invalidId())
    {
        m_latestFunctionId++;
    }

    return m_latestFunctionId;
}

bool Doc::addFunction(Function* func, quint32 id)
{
    Q_ASSERT(func != NULL);

    if (id == Function::invalidId())
        id = createFunctionId();

    if (m_functions.contains(id) == true || id == Fixture::invalidId())
    {
        qWarning() << Q_FUNC_INFO << "a function with ID" << id << "already exists!";
        return false;
    }
    else
    {
        // Listen to function changes
        connect(func, SIGNAL(changed(quint32)),
                this, SLOT(slotFunctionChanged(quint32)));

        // Make the function listen to fixture removals
        connect(this, SIGNAL(fixtureRemoved(quint32)),
                func, SLOT(slotFixtureRemoved(quint32)));

        // Place the function in the map and assign it the new ID
        m_functions[id] = func;
        func->setID(id);
        emit functionAdded(id);
        setModified();

        return true;
    }
}

QList <Function*> Doc::functions() const
{
    return m_functions.values();
}

bool Doc::deleteFunction(quint32 id)
{
    if (m_functions.contains(id) == true)
    {
        Function* func = m_functions.take(id);
        Q_ASSERT(func != NULL);

        emit functionRemoved(id);
        setModified();
        delete func;

        return true;
    }
    else
    {
        qWarning() << Q_FUNC_INFO << "No function with id" << id;
        return false;
    }
}

Function* Doc::function(quint32 id)
{
    if (m_functions.contains(id) == true)
        return m_functions[id];
    else
        return NULL;
}

/*****************************************************************************
 * Monitoring/listening methods
 *****************************************************************************/

void Doc::slotFunctionChanged(quint32 fid)
{
    setModified();
    emit functionChanged(fid);
}

void Doc::slotFixtureChanged(quint32 id)
{
    setModified();
    emit fixtureChanged(id);
}

void Doc::slotBusNameChanged()
{
    setModified();
}

/*****************************************************************************
 * Load & Save
 *****************************************************************************/

bool Doc::loadXML(const QDomElement* root)
{
    QDomElement tag;
    QDomNode node;

    Q_ASSERT(root != NULL);

    if (root->tagName() != KXMLQLCEngine)
    {
        qWarning() << Q_FUNC_INFO << "Engine node not found";
        return false;
    }

    node = root->firstChild();
    while (node.isNull() == false)
    {
        tag = node.toElement();

        if (tag.tagName() == KXMLFixture)
        {
            Fixture::loader(&tag, this);
        }
        else if (tag.tagName() == KXMLQLCFunction)
        {
            Function::loader(&tag, this);
        }
        else if (tag.tagName() == KXMLQLCBus)
        {
            Bus::instance()->loadXML(&tag);
        }
        else
        {
            qWarning() << Q_FUNC_INFO << "Unknown engine tag:" << tag.tagName();
        }

        node = node.nextSibling();
    }

    return true;
}

bool Doc::saveXML(QDomDocument* doc, QDomElement* wksp_root)
{
    QDomElement root;

    Q_ASSERT(doc != NULL);
    Q_ASSERT(wksp_root != NULL);

    /* Create the master Engine node */
    root = doc->createElement(KXMLQLCEngine);
    wksp_root->appendChild(root);

    /* Write fixtures into an XML document */
    QListIterator <Fixture*> fxit(fixtures());
    while (fxit.hasNext() == true)
    {
        Fixture* fxi(fxit.next());
        Q_ASSERT(fxi != NULL);
        fxi->saveXML(doc, &root);
    }

    /* Write functions into an XML document */
    QListIterator <Function*> funcit(functions());
    while (funcit.hasNext() == true)
    {
        Function* func(funcit.next());
        Q_ASSERT(func != NULL);
        func->saveXML(doc, &root);
    }

    /* Write buses */
    Bus::instance()->saveXML(doc, &root);

    return true;
}
