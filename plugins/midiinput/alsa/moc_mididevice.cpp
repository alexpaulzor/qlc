/****************************************************************************
** Meta object code from reading C++ file 'mididevice.h'
**
** Created: Fri Sep 2 17:16:26 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mididevice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mididevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MIDIDevice[] = {

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
      33,   12,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MIDIDevice[] = {
    "MIDIDevice\0\0device,channel,value\0"
    "valueChanged(MIDIDevice*,quint32,uchar)\0"
};

const QMetaObject MIDIDevice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MIDIDevice,
      qt_meta_data_MIDIDevice, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MIDIDevice::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MIDIDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MIDIDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MIDIDevice))
        return static_cast<void*>(const_cast< MIDIDevice*>(this));
    return QObject::qt_metacast(_clname);
}

int MIDIDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< MIDIDevice*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MIDIDevice::valueChanged(MIDIDevice * _t1, quint32 _t2, uchar _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
