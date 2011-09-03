/****************************************************************************
** Meta object code from reading C++ file 'enttecdmxusbout.h'
**
** Created: Fri Sep 2 17:15:16 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "enttecdmxusbout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enttecdmxusbout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EnttecDMXUSBOut[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x09,
      47,   17,   16,   16, 0x09,
      82,   16,   74,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_EnttecDMXUSBOut[] = {
    "EnttecDMXUSBOut\0\0name\0slotDeviceAdded(QString)\0"
    "slotDeviceRemoved(QString)\0QString\0"
    "name()\0"
};

const QMetaObject EnttecDMXUSBOut::staticMetaObject = {
    { &QLCOutPlugin::staticMetaObject, qt_meta_stringdata_EnttecDMXUSBOut,
      qt_meta_data_EnttecDMXUSBOut, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EnttecDMXUSBOut::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EnttecDMXUSBOut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EnttecDMXUSBOut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EnttecDMXUSBOut))
        return static_cast<void*>(const_cast< EnttecDMXUSBOut*>(this));
    if (!strcmp(_clname, "QLCOutPlugin"))
        return static_cast< QLCOutPlugin*>(const_cast< EnttecDMXUSBOut*>(this));
    return QLCOutPlugin::qt_metacast(_clname);
}

int EnttecDMXUSBOut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLCOutPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotDeviceAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: slotDeviceRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { QString _r = name();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
