/****************************************************************************
** Meta object code from reading C++ file 'efx_test.h'
**
** Created: Mon Apr 25 20:16:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "efx_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'efx_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EFX_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      25,    9,    9,    9, 0x08,
      32,    9,    9,    9, 0x08,
      42,    9,    9,    9, 0x08,
      52,    9,    9,    9, 0x08,
      69,    9,    9,    9, 0x08,
      77,    9,    9,    9, 0x08,
      86,    9,    9,    9, 0x08,
      97,    9,    9,    9, 0x08,
     107,    9,    9,    9, 0x08,
     117,    9,    9,    9, 0x08,
     130,    9,    9,    9, 0x08,
     143,    9,    9,    9, 0x08,
     152,    9,    9,    9, 0x08,
     161,    9,    9,    9, 0x08,
     172,    9,    9,    9, 0x08,
     190,    9,    9,    9, 0x08,
     206,    9,    9,    9, 0x08,
     221,    9,    9,    9, 0x08,
     235,    9,    9,    9, 0x08,
     252,    9,    9,    9, 0x08,
     271,    9,    9,    9, 0x08,
     288,    9,    9,    9, 0x08,
     308,    9,    9,    9, 0x08,
     319,    9,    9,    9, 0x08,
     332,    9,    9,    9, 0x08,
     344,    9,    9,    9, 0x08,
     356,    9,    9,    9, 0x08,
     377,    9,    9,    9, 0x08,
     392,    9,    9,    9, 0x08,
     406,    9,    9,    9, 0x08,
     422,    9,    9,    9, 0x08,
     438,    9,    9,    9, 0x08,
     461,    9,    9,    9, 0x08,
     468,    9,    9,    9, 0x08,
     481,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EFX_Test[] = {
    "EFX_Test\0\0initTestCase()\0init()\0"
    "cleanup()\0initial()\0algorithmNames()\0"
    "width()\0height()\0rotation()\0xOffset()\0"
    "yOffset()\0xFrequency()\0yFrequency()\0"
    "xPhase()\0yPhase()\0fixtures()\0"
    "propagationMode()\0previewCircle()\0"
    "previewEight()\0previewLine()\0"
    "previewDiamond()\0previewLissajous()\0"
    "rotateAndScale()\0widthHeightOffset()\0"
    "copyFrom()\0createCopy()\0loadXAxis()\0"
    "loadYAxis()\0loadYAxisWrongRoot()\0"
    "loadAxisNoXY()\0loadSuccess()\0"
    "loadWrongType()\0loadWrongRoot()\0"
    "loadDuplicateFixture()\0save()\0"
    "armSuccess()\0armMissingFixture()\0"
};

const QMetaObject EFX_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EFX_Test,
      qt_meta_data_EFX_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EFX_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EFX_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EFX_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EFX_Test))
        return static_cast<void*>(const_cast< EFX_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int EFX_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: algorithmNames(); break;
        case 5: width(); break;
        case 6: height(); break;
        case 7: rotation(); break;
        case 8: xOffset(); break;
        case 9: yOffset(); break;
        case 10: xFrequency(); break;
        case 11: yFrequency(); break;
        case 12: xPhase(); break;
        case 13: yPhase(); break;
        case 14: fixtures(); break;
        case 15: propagationMode(); break;
        case 16: previewCircle(); break;
        case 17: previewEight(); break;
        case 18: previewLine(); break;
        case 19: previewDiamond(); break;
        case 20: previewLissajous(); break;
        case 21: rotateAndScale(); break;
        case 22: widthHeightOffset(); break;
        case 23: copyFrom(); break;
        case 24: createCopy(); break;
        case 25: loadXAxis(); break;
        case 26: loadYAxis(); break;
        case 27: loadYAxisWrongRoot(); break;
        case 28: loadAxisNoXY(); break;
        case 29: loadSuccess(); break;
        case 30: loadWrongType(); break;
        case 31: loadWrongRoot(); break;
        case 32: loadDuplicateFixture(); break;
        case 33: save(); break;
        case 34: armSuccess(); break;
        case 35: armMissingFixture(); break;
        default: ;
        }
        _id -= 36;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
