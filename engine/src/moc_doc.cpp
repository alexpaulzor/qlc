/****************************************************************************
** Meta object code from reading C++ file 'doc.h'
**
** Created: Mon Apr 25 20:15:23 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "doc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Doc[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    5,    4,    4, 0x05,
      39,   33,    4,    4, 0x05,
      61,   54,    4,    4, 0x05,
      83,   54,    4,    4, 0x05,
     107,   54,    4,    4, 0x05,
     140,  131,    4,    4, 0x05,
     163,  131,    4,    4, 0x05,
     188,  131,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
     213,   54,    4,    4, 0x0a,
     245,  241,    4,    4, 0x09,
     274,    4,    4,    4, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Doc[] = {
    "Doc\0\0mode\0modeChanged(Doc::Mode)\0state\0"
    "modified(bool)\0fxi_id\0fixtureAdded(quint32)\0"
    "fixtureRemoved(quint32)\0fixtureChanged(quint32)\0"
    "function\0functionAdded(quint32)\0"
    "functionRemoved(quint32)\0"
    "functionChanged(quint32)\0"
    "slotFixtureChanged(quint32)\0fid\0"
    "slotFunctionChanged(quint32)\0"
    "slotBusNameChanged()\0"
};

const QMetaObject Doc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Doc,
      qt_meta_data_Doc, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Doc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Doc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Doc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Doc))
        return static_cast<void*>(const_cast< Doc*>(this));
    return QObject::qt_metacast(_clname);
}

int Doc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: modeChanged((*reinterpret_cast< Doc::Mode(*)>(_a[1]))); break;
        case 1: modified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: fixtureAdded((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 3: fixtureRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: fixtureChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: functionAdded((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 6: functionRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 7: functionChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 8: slotFixtureChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 9: slotFunctionChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 10: slotBusNameChanged(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Doc::modeChanged(Doc::Mode _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Doc::modified(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Doc::fixtureAdded(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Doc::fixtureRemoved(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Doc::fixtureChanged(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Doc::functionAdded(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Doc::functionRemoved(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Doc::functionChanged(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
