/****************************************************************************
** Meta object code from reading C++ file 'doc_test.h'
**
** Created: Mon Apr 25 20:16:47 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "doc_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doc_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Doc_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      25,    9,    9,    9, 0x08,
      36,    9,    9,    9, 0x08,
      54,    9,    9,    9, 0x08,
      67,    9,    9,    9, 0x08,
      83,    9,    9,    9, 0x08,
      93,    9,    9,    9, 0x08,
     117,    9,    9,    9, 0x08,
     131,    9,    9,    9, 0x08,
     148,    9,    9,    9, 0x08,
     159,    9,    9,    9, 0x08,
     166,    9,    9,    9, 0x08,
     182,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Doc_Test[] = {
    "Doc_Test\0\0initTestCase()\0defaults()\0"
    "createFixtureId()\0addFixture()\0"
    "deleteFixture()\0fixture()\0"
    "totalPowerConsumption()\0addFunction()\0"
    "deleteFunction()\0function()\0load()\0"
    "loadWrongRoot()\0save()\0"
};

const QMetaObject Doc_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Doc_Test,
      qt_meta_data_Doc_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Doc_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Doc_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Doc_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Doc_Test))
        return static_cast<void*>(const_cast< Doc_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int Doc_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: defaults(); break;
        case 2: createFixtureId(); break;
        case 3: addFixture(); break;
        case 4: deleteFixture(); break;
        case 5: fixture(); break;
        case 6: totalPowerConsumption(); break;
        case 7: addFunction(); break;
        case 8: deleteFunction(); break;
        case 9: function(); break;
        case 10: load(); break;
        case 11: loadWrongRoot(); break;
        case 12: save(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
