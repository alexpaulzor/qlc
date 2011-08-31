/****************************************************************************
** Meta object code from reading C++ file 'qlcchannel_test.h'
**
** Created: Mon Apr 25 20:16:34 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qlcchannel_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlcchannel_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QLCChannel_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      29,   16,   16,   16, 0x08,
      36,   16,   16,   16, 0x08,
      44,   16,   16,   16, 0x08,
      58,   16,   16,   16, 0x08,
      71,   16,   16,   16, 0x08,
      80,   16,   16,   16, 0x08,
     106,   16,   16,   16, 0x08,
     131,   16,   16,   16, 0x08,
     147,   16,   16,   16, 0x08,
     166,   16,   16,   16, 0x08,
     185,   16,   16,   16, 0x08,
     192,   16,   16,   16, 0x08,
     199,   16,   16,   16, 0x08,
     215,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QLCChannel_Test[] = {
    "QLCChannel_Test\0\0groupList()\0name()\0"
    "group()\0controlByte()\0colourList()\0"
    "colour()\0searchCapabilityByValue()\0"
    "searchCapabilityByName()\0addCapability()\0"
    "removeCapability()\0sortCapabilities()\0"
    "copy()\0load()\0loadWrongRoot()\0save()\0"
};

const QMetaObject QLCChannel_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QLCChannel_Test,
      qt_meta_data_QLCChannel_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QLCChannel_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QLCChannel_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QLCChannel_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QLCChannel_Test))
        return static_cast<void*>(const_cast< QLCChannel_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int QLCChannel_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: groupList(); break;
        case 1: name(); break;
        case 2: group(); break;
        case 3: controlByte(); break;
        case 4: colourList(); break;
        case 5: colour(); break;
        case 6: searchCapabilityByValue(); break;
        case 7: searchCapabilityByName(); break;
        case 8: addCapability(); break;
        case 9: removeCapability(); break;
        case 10: sortCapabilities(); break;
        case 11: copy(); break;
        case 12: load(); break;
        case 13: loadWrongRoot(); break;
        case 14: save(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
