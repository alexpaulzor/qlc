/****************************************************************************
** Meta object code from reading C++ file 'fixturemanager.h'
**
** Created: Mon Apr 25 20:18:29 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fixturemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fixturemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FixtureManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   16,   15,   15, 0x0a,
      45,   16,   15,   15, 0x0a,
      78,   73,   15,   15, 0x0a,
     105,   15,   15,   15, 0x09,
     133,  128,   15,   15, 0x09,
     169,   15,   15,   15, 0x09,
     179,   15,   15,   15, 0x09,
     192,   15,   15,   15, 0x09,
     213,  209,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_FixtureManager[] = {
    "FixtureManager\0\0id\0slotFixtureAdded(quint32)\0"
    "slotFixtureRemoved(quint32)\0mode\0"
    "slotModeChanged(Doc::Mode)\0"
    "slotSelectionChanged()\0item\0"
    "slotDoubleClicked(QTreeWidgetItem*)\0"
    "slotAdd()\0slotRemove()\0slotProperties()\0"
    "pos\0slotContextMenuRequested(QPoint)\0"
};

const QMetaObject FixtureManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FixtureManager,
      qt_meta_data_FixtureManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FixtureManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FixtureManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FixtureManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FixtureManager))
        return static_cast<void*>(const_cast< FixtureManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int FixtureManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotFixtureAdded((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: slotFixtureRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: slotModeChanged((*reinterpret_cast< Doc::Mode(*)>(_a[1]))); break;
        case 3: slotSelectionChanged(); break;
        case 4: slotDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 5: slotAdd(); break;
        case 6: slotRemove(); break;
        case 7: slotProperties(); break;
        case 8: slotContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
