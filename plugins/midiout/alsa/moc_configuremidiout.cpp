/****************************************************************************
** Meta object code from reading C++ file 'configuremidiout.h'
**
** Created: Fri Sep 2 17:15:35 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../common/configuremidiout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configuremidiout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigureMIDIOut[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x09,
      39,   17,   17,   17, 0x09,
      64,   57,   17,   17, 0x09,
      93,   57,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ConfigureMIDIOut[] = {
    "ConfigureMIDIOut\0\0slotRefreshClicked()\0"
    "slotEditClicked()\0device\0"
    "slotDeviceAdded(MIDIDevice*)\0"
    "slotDeviceRemoved(MIDIDevice*)\0"
};

const QMetaObject ConfigureMIDIOut::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigureMIDIOut,
      qt_meta_data_ConfigureMIDIOut, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigureMIDIOut::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigureMIDIOut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigureMIDIOut::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigureMIDIOut))
        return static_cast<void*>(const_cast< ConfigureMIDIOut*>(this));
    if (!strcmp(_clname, "Ui_ConfigureMIDIOut"))
        return static_cast< Ui_ConfigureMIDIOut*>(const_cast< ConfigureMIDIOut*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigureMIDIOut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotRefreshClicked(); break;
        case 1: slotEditClicked(); break;
        case 2: slotDeviceAdded((*reinterpret_cast< MIDIDevice*(*)>(_a[1]))); break;
        case 3: slotDeviceRemoved((*reinterpret_cast< MIDIDevice*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
