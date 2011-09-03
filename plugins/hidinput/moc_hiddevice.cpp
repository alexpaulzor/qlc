/****************************************************************************
** Meta object code from reading C++ file 'hiddevice.h'
**
** Created: Fri Sep 2 17:16:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hiddevice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hiddevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HIDDevice[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   11,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_HIDDevice[] = {
    "HIDDevice\0\0device,channel,value\0"
    "valueChanged(HIDDevice*,quint32,uchar)\0"
};

const QMetaObject HIDDevice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HIDDevice,
      qt_meta_data_HIDDevice, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HIDDevice::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HIDDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HIDDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HIDDevice))
        return static_cast<void*>(const_cast< HIDDevice*>(this));
    return QObject::qt_metacast(_clname);
}

int HIDDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< HIDDevice*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void HIDDevice::valueChanged(HIDDevice * _t1, quint32 _t2, uchar _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
