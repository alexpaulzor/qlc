/****************************************************************************
** Meta object code from reading C++ file 'ewinginput.h'
**
** Created: Fri Sep 2 17:15:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ewinginput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ewinginput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EWingInput[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   12,   11,   11, 0x05,
      67,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      90,   11,   11,   11, 0x09,
     121,  107,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_EWingInput[] = {
    "EWingInput\0\0line,channel,value\0"
    "valueChanged(quint32,quint32,uchar)\0"
    "configurationChanged()\0slotReadSocket()\0"
    "channel,value\0slotValueChanged(quint32,uchar)\0"
};

const QMetaObject EWingInput::staticMetaObject = {
    { &QLCInPlugin::staticMetaObject, qt_meta_stringdata_EWingInput,
      qt_meta_data_EWingInput, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EWingInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EWingInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EWingInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EWingInput))
        return static_cast<void*>(const_cast< EWingInput*>(this));
    if (!strcmp(_clname, "QLCInPlugin"))
        return static_cast< QLCInPlugin*>(const_cast< EWingInput*>(this));
    return QLCInPlugin::qt_metacast(_clname);
}

int EWingInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLCInPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        case 1: configurationChanged(); break;
        case 2: slotReadSocket(); break;
        case 3: slotValueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< uchar(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void EWingInput::valueChanged(quint32 _t1, quint32 _t2, uchar _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EWingInput::configurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE