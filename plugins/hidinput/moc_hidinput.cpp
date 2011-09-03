/****************************************************************************
** Meta object code from reading C++ file 'hidinput.h'
**
** Created: Fri Sep 2 17:16:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hidinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hidinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HIDInput[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   10,    9,    9, 0x05,
      65,    9,    9,    9, 0x05,
      95,   88,    9,    9, 0x05,
     119,   88,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_HIDInput[] = {
    "HIDInput\0\0line,channel,value\0"
    "valueChanged(quint32,quint32,uchar)\0"
    "configurationChanged()\0device\0"
    "deviceAdded(HIDDevice*)\0"
    "deviceRemoved(HIDDevice*)\0"
};

const QMetaObject HIDInput::staticMetaObject = {
    { &QLCInPlugin::staticMetaObject, qt_meta_stringdata_HIDInput,
      qt_meta_data_HIDInput, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HIDInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HIDInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HIDInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HIDInput))
        return static_cast<void*>(const_cast< HIDInput*>(this));
    if (!strcmp(_clname, "QLCInPlugin"))
        return static_cast< QLCInPlugin*>(const_cast< HIDInput*>(this));
    return QLCInPlugin::qt_metacast(_clname);
}

int HIDInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLCInPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        case 1: configurationChanged(); break;
        case 2: deviceAdded((*reinterpret_cast< HIDDevice*(*)>(_a[1]))); break;
        case 3: deviceRemoved((*reinterpret_cast< HIDDevice*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void HIDInput::valueChanged(quint32 _t1, quint32 _t2, uchar _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HIDInput::configurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void HIDInput::deviceAdded(HIDDevice * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HIDInput::deviceRemoved(HIDDevice * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
