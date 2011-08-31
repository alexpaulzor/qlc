include(../../../variables.pri)
include(../../../coverage.pri)

TEMPLATE = app
LANGUAGE = C++
TARGET   = addfixture_test

QT      += testlib
QT      += gui
QT      += xml

INCLUDEPATH += ../../src
INCLUDEPATH += ../../../engine/src
DEPENDPATH  += ../../src
LIBS        += -L../../../engine/src -lqlcengine

# Test sources
SOURCES += addfixture_test.cpp
HEADERS += addfixture_test.h

# Sources to test
SOURCES += ../../src/addfixture.cpp
HEADERS += ../../src/addfixture.h
FORMS   += ../../src/addfixture.ui

# Dependencies
SOURCES += ../../src/apputil.cpp
HEADERS += ../../src/apputil.h
