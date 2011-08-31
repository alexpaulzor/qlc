/****************************************************************************
** Meta object code from reading C++ file 'function.h'
**
** Created: Mon Apr 25 20:15:24 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "function.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'function.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Function[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x05,
      41,   31,    9,    9, 0x05,
      67,   64,    9,    9, 0x05,
      84,   64,    9,    9, 0x05,
     110,  101,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     141,  134,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Function[] = {
    "Function\0\0fid\0changed(quint32)\0fid,state\0"
    "flashing(quint32,bool)\0id\0running(quint32)\0"
    "stopped(quint32)\0fraction\0"
    "intensityChanged(qreal)\0fxi_id\0"
    "slotFixtureRemoved(quint32)\0"
};

const QMetaObject Function::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Function,
      qt_meta_data_Function, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Function::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Function::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Function::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Function))
        return static_cast<void*>(const_cast< Function*>(this));
    return QObject::qt_metacast(_clname);
}

int Function::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changed((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: flashing((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: running((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 3: stopped((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: intensityChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: slotFixtureRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Function::changed(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Function::flashing(quint32 _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Function::running(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Function::stopped(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Function::intensityChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
