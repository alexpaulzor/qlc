/****************************************************************************
** Meta object code from reading C++ file 'function_test.h'
**
** Created: Mon Apr 25 20:16:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "function_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'function_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Function_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      30,   14,   14,   14, 0x08,
      40,   14,   14,   14, 0x08,
      51,   14,   14,   14, 0x08,
      66,   14,   14,   14, 0x08,
      76,   14,   14,   14, 0x08,
      92,   14,   14,   14, 0x08,
     106,   14,   14,   14, 0x08,
     124,   14,   14,   14, 0x08,
     142,   14,   14,   14, 0x08,
     163,   14,   14,   14, 0x08,
     175,   14,   14,   14, 0x08,
     188,   14,   14,   14, 0x08,
     203,   14,   14,   14, 0x08,
     218,   14,   14,   14, 0x08,
     237,   14,   14,   14, 0x08,
     256,   14,   14,   14, 0x08,
     276,   14,   14,   14, 0x08,
     296,   14,   14,   14, 0x08,
     314,   14,   14,   14, 0x08,
     330,   14,   14,   14, 0x08,
     344,   14,   14,   14, 0x08,
     359,   14,   14,   14, 0x08,
     378,   14,   14,   14, 0x08,
     390,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Function_Test[] = {
    "Function_Test\0\0initTestCase()\0initial()\0"
    "copyFrom()\0flashUnflash()\0elapsed()\0"
    "preRunPostRun()\0stopAndWait()\0"
    "stopAndWaitFail()\0adjustIntensity()\0"
    "slotFixtureRemoved()\0invalidId()\0"
    "typeString()\0typeToString()\0stringToType()\0"
    "runOrderToString()\0stringToRunOrder()\0"
    "directionToString()\0stringToDirection()\0"
    "loaderWrongRoot()\0loaderWrongID()\0"
    "loaderScene()\0loaderChaser()\0"
    "loaderCollection()\0loaderEFX()\0"
    "loaderUnknownType()\0"
};

const QMetaObject Function_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Function_Test,
      qt_meta_data_Function_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Function_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Function_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Function_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Function_Test))
        return static_cast<void*>(const_cast< Function_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int Function_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: initial(); break;
        case 2: copyFrom(); break;
        case 3: flashUnflash(); break;
        case 4: elapsed(); break;
        case 5: preRunPostRun(); break;
        case 6: stopAndWait(); break;
        case 7: stopAndWaitFail(); break;
        case 8: adjustIntensity(); break;
        case 9: slotFixtureRemoved(); break;
        case 10: invalidId(); break;
        case 11: typeString(); break;
        case 12: typeToString(); break;
        case 13: stringToType(); break;
        case 14: runOrderToString(); break;
        case 15: stringToRunOrder(); break;
        case 16: directionToString(); break;
        case 17: stringToDirection(); break;
        case 18: loaderWrongRoot(); break;
        case 19: loaderWrongID(); break;
        case 20: loaderScene(); break;
        case 21: loaderChaser(); break;
        case 22: loaderCollection(); break;
        case 23: loaderEFX(); break;
        case 24: loaderUnknownType(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
