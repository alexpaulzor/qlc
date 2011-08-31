include(../../../variables.pri)

TEMPLATE = app
LANGUAGE = C++
TARGET   = vellemanout_test

QT      += core testlib
QT      -= gui
LIBS    += -L../src -lvellemanout

INCLUDEPATH += ../../interfaces
INCLUDEPATH += ../src
DEPENDPATH  += ../src

# Test sources
HEADERS += vellemanout_test.h ../../interfaces/qlcoutplugin.h
SOURCES += vellemanout_test.cpp
