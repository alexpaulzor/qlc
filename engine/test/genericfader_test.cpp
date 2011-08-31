/*
  Q Light Controller - Unit test
  genericfader_test.cpp

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

#include <QtTest>

#include "genericfader_test.h"
#include "universearray.h"
#include "fadechannel.h"
#include "qlcchannel.h"
#include "bus.h"

#define private public
#include "genericfader.h"
#undef private

void GenericFader_Test::initTestCase()
{
    Bus::init(this);
}

void GenericFader_Test::addRemove()
{
    GenericFader fader;

    QCOMPARE(fader.m_channels.count(), 0);
    QVERIFY(fader.m_channels.contains(15) == false);

    FadeChannel ch;
    ch.setAddress(15);
    fader.add(ch);
    QVERIFY(fader.m_channels.contains(15) == true);
    QCOMPARE(fader.m_channels.count(), 1);

    fader.remove(14);
    QVERIFY(fader.m_channels.contains(15) == true);
    QCOMPARE(fader.m_channels.count(), 1);

    fader.remove(0);
    QVERIFY(fader.m_channels.contains(15) == true);
    QCOMPARE(fader.m_channels.count(), 1);

    fader.remove(15);
    QVERIFY(fader.m_channels.contains(15) == false);
    QCOMPARE(fader.m_channels.count(), 0);

    ch.setAddress(0);
    fader.add(ch);
    ch.setAddress(1);
    fader.add(ch);
    ch.setAddress(2);
    fader.add(ch);
    QVERIFY(fader.m_channels.contains(0) == true);
    QVERIFY(fader.m_channels.contains(1) == true);
    QVERIFY(fader.m_channels.contains(2) == true);
    QCOMPARE(fader.m_channels.count(), 3);

    fader.removeAll();
    QVERIFY(fader.m_channels.contains(0) == false);
    QVERIFY(fader.m_channels.contains(1) == false);
    QVERIFY(fader.m_channels.contains(2) == false);
    QCOMPARE(fader.m_channels.count(), 0);

    ch.setAddress(0);
    ch.setTarget(127);
    fader.add(ch);
    QCOMPARE(fader.m_channels[0].target(), uchar(127));
    QCOMPARE(fader.m_channels.count(), 1);

    ch.setAddress(0);
    ch.setTarget(63);
    fader.add(ch);
    QCOMPARE(fader.m_channels[0].target(), uchar(63));
    QCOMPARE(fader.m_channels.count(), 1);
}

void GenericFader_Test::write()
{
    UniverseArray ua(512);
    GenericFader fader;

    Bus::instance()->setValue(Bus::defaultFade(), 255);

    FadeChannel ch;
    ch.setAddress(400);
    ch.setGroup(QLCChannel::Intensity);
    ch.setStart(255);
    ch.setTarget(0);
    ch.setCurrent(255);
    ch.setBus(Bus::defaultFade());
    fader.add(ch);

    for (int i = 255; i >= 0; i--)
    {
        ua.zeroIntensityChannels();
        fader.write(&ua);
        QCOMPARE(uchar(ua.preGMValues()[400]), uchar(i));
    }
}
