/****************************************************************************
** Meta object code from reading C++ file 'configurehidinput.h'
**
** Created: Fri Sep 2 17:16:36 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "configurehidinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configurehidinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigureHIDInput[] = {

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
      19,   18,   18,   18, 0x09,
      47,   40,   18,   18, 0x09,
      75,   40,   18,   18, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ConfigureHIDInput[] = {
    "ConfigureHIDInput\0\0slotRefreshClicked()\0"
    "device\0slotDeviceAdded(HIDDevice*)\0"
    "slotDeviceRemoved(HIDDevice*)\0"
};

const QMetaObject ConfigureHIDInput::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigureHIDInput,
      qt_meta_data_ConfigureHIDInput, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigureHIDInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigureHIDInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigureHIDInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigureHIDInput))
        return static_cast<void*>(const_cast< ConfigureHIDInput*>(this));
    if (!strcmp(_clname, "Ui_ConfigureHIDInput"))
        return static_cast< Ui_ConfigureHIDInput*>(const_cast< ConfigureHIDInput*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigureHIDInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotRefreshClicked(); break;
        case 1: slotDeviceAdded((*reinterpret_cast< HIDDevice*(*)>(_a[1]))); break;
        case 2: slotDeviceRemoved((*reinterpret_cast< HIDDevice*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
