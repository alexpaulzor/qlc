/****************************************************************************
** Meta object code from reading C++ file 'addfixture_test.h'
**
** Created: Mon Apr 25 20:19:15 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addfixture_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addfixture_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddFixture_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      32,   16,   16,   16, 0x08,
      46,   16,   16,   16, 0x08,
      65,   16,   16,   16, 0x08,
      81,   16,   16,   16, 0x08,
      98,   16,   16,   16, 0x08,
     117,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddFixture_Test[] = {
    "AddFixture_Test\0\0initTestCase()\0"
    "findAddress()\0initialNoFixture()\0"
    "initialDimmer()\0initialScanner()\0"
    "selectionNothing()\0selectionGeneric()\0"
};

const QMetaObject AddFixture_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AddFixture_Test,
      qt_meta_data_AddFixture_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddFixture_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddFixture_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddFixture_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddFixture_Test))
        return static_cast<void*>(const_cast< AddFixture_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int AddFixture_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: findAddress(); break;
        case 2: initialNoFixture(); break;
        case 3: initialDimmer(); break;
        case 4: initialScanner(); break;
        case 5: selectionNothing(); break;
        case 6: selectionGeneric(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
