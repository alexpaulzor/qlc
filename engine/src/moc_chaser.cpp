/****************************************************************************
** Meta object code from reading C++ file 'chaser.h'
**
** Created: Mon Apr 25 20:15:22 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chaser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chaser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Chaser[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,    8,    7,    7, 0x0a,
      44,   41,    7,    7, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Chaser[] = {
    "Chaser\0\0fid\0slotFunctionRemoved(quint32)\0"
    "id\0slotBusTapped(quint32)\0"
};

const QMetaObject Chaser::staticMetaObject = {
    { &Function::staticMetaObject, qt_meta_stringdata_Chaser,
      qt_meta_data_Chaser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Chaser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Chaser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Chaser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Chaser))
        return static_cast<void*>(const_cast< Chaser*>(this));
    return Function::qt_metacast(_clname);
}

int Chaser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Function::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotFunctionRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: slotBusTapped((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE