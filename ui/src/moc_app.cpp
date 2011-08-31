/****************************************************************************
** Meta object code from reading C++ file 'app.h'
**
** Created: Mon Apr 25 20:18:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "app.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'app.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_App[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    5,    4,    4, 0x0a,
      45,   39,    4,    4, 0x09,
      80,    4,    4,    4, 0x09,
     109,   39,    4,    4, 0x09,
     131,    4,    4,    4, 0x0a,
     149,    4,    4,    4, 0x0a,
     166,    4,    4,    4, 0x0a,
     188,  183,    4,    4, 0x0a,
     220,    4,  215,    4, 0x0a,
     251,    4,  234,    4, 0x0a,
     266,    4,  234,    4, 0x0a,
     281,    4,  234,    4, 0x0a,
     298,    4,    4,    4, 0x0a,
     313,    4,    4,    4, 0x0a,
     334,    4,    4,    4, 0x0a,
     356,    4,    4,    4, 0x0a,
     373,    4,    4,    4, 0x0a,
     393,    4,    4,    4, 0x0a,
     412,    4,    4,    4, 0x0a,
     428,    4,    4,    4, 0x0a,
     449,    4,    4,    4, 0x0a,
     473,    4,    4,    4, 0x0a,
     489,    4,    4,    4, 0x0a,
     505,    4,    4,    4, 0x0a,
     523,    4,    4,    4, 0x0a,
     562,    4,    4,    4, 0x0a,
     587,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_App[] = {
    "App\0\0text\0slotSetProgressText(QString)\0"
    "state\0slotOutputMapBlackoutChanged(bool)\0"
    "slotFlashBlackoutIndicator()\0"
    "slotDocModified(bool)\0slotModeOperate()\0"
    "slotModeDesign()\0slotModeToggle()\0"
    "mode\0slotModeChanged(Doc::Mode)\0bool\0"
    "slotFileNew()\0QFile::FileError\0"
    "slotFileOpen()\0slotFileSave()\0"
    "slotFileSaveAs()\0slotFileQuit()\0"
    "slotFixtureManager()\0slotFunctionManager()\0"
    "slotBusManager()\0slotOutputManager()\0"
    "slotInputManager()\0slotControlVC()\0"
    "slotControlMonitor()\0slotControlFullScreen()\0"
    "slotHelpIndex()\0slotHelpAbout()\0"
    "slotHelpAboutQt()\0"
    "slotCustomContextMenuRequested(QPoint)\0"
    "slotSetBackgroundImage()\0"
    "slotClearBackgroundImage()\0"
};

const QMetaObject App::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_App,
      qt_meta_data_App, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &App::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *App::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *App::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_App))
        return static_cast<void*>(const_cast< App*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int App::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotSetProgressText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: slotOutputMapBlackoutChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: slotFlashBlackoutIndicator(); break;
        case 3: slotDocModified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: slotModeOperate(); break;
        case 5: slotModeDesign(); break;
        case 6: slotModeToggle(); break;
        case 7: slotModeChanged((*reinterpret_cast< Doc::Mode(*)>(_a[1]))); break;
        case 8: { bool _r = slotFileNew();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { QFile::FileError _r = slotFileOpen();
            if (_a[0]) *reinterpret_cast< QFile::FileError*>(_a[0]) = _r; }  break;
        case 10: { QFile::FileError _r = slotFileSave();
            if (_a[0]) *reinterpret_cast< QFile::FileError*>(_a[0]) = _r; }  break;
        case 11: { QFile::FileError _r = slotFileSaveAs();
            if (_a[0]) *reinterpret_cast< QFile::FileError*>(_a[0]) = _r; }  break;
        case 12: slotFileQuit(); break;
        case 13: slotFixtureManager(); break;
        case 14: slotFunctionManager(); break;
        case 15: slotBusManager(); break;
        case 16: slotOutputManager(); break;
        case 17: slotInputManager(); break;
        case 18: slotControlVC(); break;
        case 19: slotControlMonitor(); break;
        case 20: slotControlFullScreen(); break;
        case 21: slotHelpIndex(); break;
        case 22: slotHelpAbout(); break;
        case 23: slotHelpAboutQt(); break;
        case 24: slotCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 25: slotSetBackgroundImage(); break;
        case 26: slotClearBackgroundImage(); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
