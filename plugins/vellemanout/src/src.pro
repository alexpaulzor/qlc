include(../../../variables.pri)
include(../../../coverage.pri)

TEMPLATE = lib
LANGUAGE = C++
TARGET   = vellemanout
CONFIG  += plugin
win32:DEFINES += QLC_EXPORT

INCLUDEPATH += ../../interfaces

win32: {
    # K8062D is a proprietary interface by Velleman and would therefore taint the
    # 100% FLOSS codebase of QLC if distributed along with QLC sources. Download
    # the package from http://www.box.net/shared/2l0b2tk8e1 and
    # extract its contents under K8062DDIR below to compile this plugin.
    K8062DDIR    = C:/K8062D
    LIBS        += -L$$K8062DDIR -lK8062D
}

HEADERS += vellemanout.h
SOURCES += vellemanout.cpp
HEADERS += ../../interfaces/qlcoutplugin.h

PRO_FILE = src.pro
TRANSLATIONS += Velleman_Output_fi_FI.ts
TRANSLATIONS += Velleman_Output_de_DE.ts
include(../../../i18n.pri)

target.path = $$INSTALLROOT/$$OUTPUTPLUGINDIR
INSTALLS   += target
