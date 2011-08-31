/****************************************************************************
** Meta object code from reading C++ file 'consolechannel.h'
**
** Created: Mon Apr 25 20:18:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "consolechannel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consolechannel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConsoleChannel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      38,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   71,   15,   15, 0x09,
     118,  113,   15,   15, 0x0a,
     149,  143,   15,   15, 0x0a,
     180,  170,   15,   15, 0x0a,
     214,  208,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ConsoleChannel[] = {
    "ConsoleChannel\0\0channel,value,enabled\0"
    "valueChanged(quint32,uchar,bool)\0"
    "action\0slotContextMenuTriggered(QAction*)\0"
    "text\0slotValueEdited(QString)\0value\0"
    "slotValueChange(int)\0fixtureID\0"
    "slotFixtureChanged(quint32)\0state\0"
    "slotToggled(bool)\0"
};

const QMetaObject ConsoleChannel::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_ConsoleChannel,
      qt_meta_data_ConsoleChannel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConsoleChannel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConsoleChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConsoleChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConsoleChannel))
        return static_cast<void*>(const_cast< ConsoleChannel*>(this));
    if (!strcmp(_clname, "DMXSource"))
        return static_cast< DMXSource*>(const_cast< ConsoleChannel*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int ConsoleChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< uchar(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: slotContextMenuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: slotValueEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: slotValueChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: slotFixtureChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: slotToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ConsoleChannel::valueChanged(quint32 _t1, uchar _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
