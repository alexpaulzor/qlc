/****************************************************************************
** Meta object code from reading C++ file 'midiout.h'
**
** Created: Fri Sep 2 17:15:38 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "midiout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'midiout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MIDIOut[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,    9,    8,    8, 0x05,
      41,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   68,    8,    8, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MIDIOut[] = {
    "MIDIOut\0\0device\0deviceAdded(MIDIDevice*)\0"
    "deviceRemoved(MIDIDevice*)\0name\0"
    "slotDeviceAddedRemoved(QString)\0"
};

const QMetaObject MIDIOut::staticMetaObject = {
    { &QLCOutPlugin::staticMetaObject, qt_meta_stringdata_MIDIOut,
      qt_meta_data_MIDIOut, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MIDIOut::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MIDIOut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MIDIOut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MIDIOut))
        return static_cast<void*>(const_cast< MIDIOut*>(this));
    if (!strcmp(_clname, "QLCOutPlugin"))
        return static_cast< QLCOutPlugin*>(const_cast< MIDIOut*>(this));
    return QLCOutPlugin::qt_metacast(_clname);
}

int MIDIOut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLCOutPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: deviceAdded((*reinterpret_cast< MIDIDevice*(*)>(_a[1]))); break;
        case 1: deviceRemoved((*reinterpret_cast< MIDIDevice*(*)>(_a[1]))); break;
        case 2: slotDeviceAddedRemoved((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MIDIOut::deviceAdded(MIDIDevice * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MIDIOut::deviceRemoved(MIDIDevice * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
