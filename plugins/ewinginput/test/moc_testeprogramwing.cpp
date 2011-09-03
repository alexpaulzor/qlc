/****************************************************************************
** Meta object code from reading C++ file 'testeprogramwing.h'
**
** Created: Fri Sep 2 17:16:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testeprogramwing.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testeprogramwing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestEProgramWing[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      33,   17,   17,   17, 0x08,
      44,   17,   17,   17, 0x08,
      54,   17,   17,   17, 0x08,
      69,   17,   17,   17, 0x08,
      76,   17,   17,   17, 0x08,
      87,   17,   17,   17, 0x08,
     102,   17,   17,   17, 0x08,
     117,   17,   17,   17, 0x08,
     127,   17,   17,   17, 0x08,
     143,   17,   17,   17, 0x08,
     154,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestEProgramWing[] = {
    "TestEProgramWing\0\0initTestCase()\0"
    "firmware()\0address()\0isOutputData()\0"
    "name()\0infoText()\0tooShortData()\0"
    "buttons_data()\0buttons()\0encoders_data()\0"
    "encoders()\0cleanupTestCase()\0"
};

const QMetaObject TestEProgramWing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestEProgramWing,
      qt_meta_data_TestEProgramWing, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestEProgramWing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestEProgramWing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestEProgramWing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestEProgramWing))
        return static_cast<void*>(const_cast< TestEProgramWing*>(this));
    return QObject::qt_metacast(_clname);
}

int TestEProgramWing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: firmware(); break;
        case 2: address(); break;
        case 3: isOutputData(); break;
        case 4: name(); break;
        case 5: infoText(); break;
        case 6: tooShortData(); break;
        case 7: buttons_data(); break;
        case 8: buttons(); break;
        case 9: encoders_data(); break;
        case 10: encoders(); break;
        case 11: cleanupTestCase(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
