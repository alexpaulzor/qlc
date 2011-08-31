/*
  Q Light Controller
  genericfader.h

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

#ifndef GENERICFADER
#define GENERICFADER

#include <QList>

class UniverseArray;
class FadeChannel;

class GenericFader
{
public:
    GenericFader();
    ~GenericFader();

    /**
     * Add a channel that shall be faded from ch.start() to ch.target() within
     * the time specified by ch.bus(). If ch.target() == 0, the channel will
     * be removed automatically from the fader when done.
     *
     * @param ch The channel to fade
     * @param replace If true, replace an existing channel with the new one
     */
    void add(const FadeChannel& ch, bool replace = true);

    /**
     * Remove the channel specified by $address from the faded channels.
     */
    void remove(quint32 address);

    /**
     * Remove all channels.
     */
    void removeAll();

    /**
     * Run the channels forward by one step and write their current values to
     * the given UniverseArray.
     *
     * @param universes The universe array that receives channel data.
     */
    void write(UniverseArray* universes);

private:
    QHash <quint32,FadeChannel> m_channels;
};

#endif
