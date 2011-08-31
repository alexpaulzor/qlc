/*
  Q Light Controller
  vcxypadproperties.h

  Copyright (c) Stefan Krumm, Heikki Junnila

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

#ifndef VCXYPADPROPERTIES_H
#define VCXYPADPROPERTIES_H

#include <QDialog>

#include "ui_vcxypadproperties.h"
#include "vcxypadfixture.h"

class VCXYPad;
class Doc;

class VCXYPadProperties : public QDialog, public Ui_VCXYPadProperties
{
    Q_OBJECT
    Q_DISABLE_COPY(VCXYPadProperties)

    /********************************************************************
     * Initialization
     ********************************************************************/
public:
    VCXYPadProperties(VCXYPad* xypad, Doc* doc);
    ~VCXYPadProperties();

    /********************************************************************
     * Tree
     ********************************************************************/
protected:
    void fillTree();
    QList <quint32> selectedFixtureIDs() const;
    QList <VCXYPadFixture> selectedFixtures() const;
    QTreeWidgetItem* fixtureItem(const VCXYPadFixture& fxi);

    void updateFixtureItem(QTreeWidgetItem* item, const VCXYPadFixture& fxi);
    void removeFixtureItem(quint32 fxi_id);

protected slots:
    void slotAddClicked();
    void slotRemoveClicked();
    void slotEditClicked();
    void slotSelectionChanged(QTreeWidgetItem* item);

    void accept();

private:
    VCXYPad* m_xypad;
    Doc* m_doc;
};

#endif
