/****************************************************************************
** Meta object code from reading C++ file 'function_stub.h'
**
** Created: Mon Apr 25 20:16:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "function_stub.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'function_stub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Function_Stub[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   15,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Function_Stub[] = {
    "Function_Stub\0\0id\0slotFixtureRemoved(quint32)\0"
};

const QMetaObject Function_Stub::staticMetaObject = {
    { &Function::staticMetaObject, qt_meta_stringdata_Function_Stub,
      qt_meta_data_Function_Stub, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Function_Stub::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Function_Stub::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Function_Stub::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Function_Stub))
        return static_cast<void*>(const_cast< Function_Stub*>(this));
    return Function::qt_metacast(_clname);
}

int Function_Stub::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Function::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotFixtureRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE