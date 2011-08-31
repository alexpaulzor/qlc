include(../../../variables.pri)
include(../../../coverage.pri)

TEMPLATE = app
LANGUAGE = C++
TARGET   = vcwidgetproperties_test

QT += testlib
QT += xml

INCLUDEPATH += ../../../plugins/interfaces
INCLUDEPATH += ../../src
DEPENDPATH  += ../../src

# Test sources
SOURCES += vcwidgetproperties_test.cpp
HEADERS += vcwidgetproperties_test.h

# Sources to test
SOURCES += ../../src/vcwidgetproperties.cpp
HEADERS += ../../src/vcwidgetproperties.h
