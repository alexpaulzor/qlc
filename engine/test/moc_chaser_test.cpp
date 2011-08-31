/****************************************************************************
** Meta object code from reading C++ file 'chaser_test.h'
**
** Created: Mon Apr 25 20:16:42 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chaser_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chaser_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Chaser_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      28,   12,   12,   12, 0x08,
      35,   12,   12,   12, 0x08,
      45,   12,   12,   12, 0x08,
      55,   12,   12,   12, 0x08,
      75,   12,   12,   12, 0x08,
      83,   12,   12,   12, 0x08,
      91,   12,   12,   12, 0x08,
     109,   12,   12,   12, 0x08,
     120,   12,   12,   12, 0x08,
     133,   12,   12,   12, 0x08,
     149,   12,   12,   12, 0x08,
     163,   12,   12,   12, 0x08,
     179,   12,   12,   12, 0x08,
     195,   12,   12,   12, 0x08,
     202,   12,   12,   12, 0x08,
     208,   12,   12,   12, 0x08,
     214,   12,   12,   12, 0x08,
     223,   12,   12,   12, 0x08,
     231,   12,   12,   12, 0x08,
     241,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Chaser_Test[] = {
    "Chaser_Test\0\0initTestCase()\0init()\0"
    "cleanup()\0initial()\0directionRunOrder()\0"
    "steps()\0clear()\0functionRemoval()\0"
    "copyFrom()\0createCopy()\0stepFunctions()\0"
    "loadSuccess()\0loadWrongType()\0"
    "loadWrongRoot()\0save()\0arm()\0tap()\0"
    "preRun()\0write()\0postRun()\0adjustIntensity()\0"
};

const QMetaObject Chaser_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Chaser_Test,
      qt_meta_data_Chaser_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Chaser_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Chaser_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Chaser_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Chaser_Test))
        return static_cast<void*>(const_cast< Chaser_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int Chaser_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: init(); break;
        case 2: cleanup(); break;
        case 3: initial(); break;
        case 4: directionRunOrder(); break;
        case 5: steps(); break;
        case 6: clear(); break;
        case 7: functionRemoval(); break;
        case 8: copyFrom(); break;
        case 9: createCopy(); break;
        case 10: stepFunctions(); break;
        case 11: loadSuccess(); break;
        case 12: loadWrongType(); break;
        case 13: loadWrongRoot(); break;
        case 14: save(); break;
        case 15: arm(); break;
        case 16: tap(); break;
        case 17: preRun(); break;
        case 18: write(); break;
        case 19: postRun(); break;
        case 20: adjustIntensity(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
