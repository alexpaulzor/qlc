/****************************************************************************
** Meta object code from reading C++ file 'testeshortcutwing.h'
**
** Created: Fri Sep 2 17:16:08 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testeshortcutwing.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testeshortcutwing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestEShortcutWing[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      34,   18,   18,   18, 0x08,
      45,   18,   18,   18, 0x08,
      55,   18,   18,   18, 0x08,
      70,   18,   18,   18, 0x08,
      77,   18,   18,   18, 0x08,
      88,   18,   18,   18, 0x08,
     103,   18,   18,   18, 0x08,
     118,   18,   18,   18, 0x08,
     128,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestEShortcutWing[] = {
    "TestEShortcutWing\0\0initTestCase()\0"
    "firmware()\0address()\0isOutputData()\0"
    "name()\0infoText()\0tooShortData()\0"
    "buttons_data()\0buttons()\0cleanupTestCase()\0"
};

const QMetaObject TestEShortcutWing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestEShortcutWing,
      qt_meta_data_TestEShortcutWing, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestEShortcutWing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestEShortcutWing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestEShortcutWing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestEShortcutWing))
        return static_cast<void*>(const_cast< TestEShortcutWing*>(this));
    return QObject::qt_metacast(_clname);
}

int TestEShortcutWing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 9: cleanupTestCase(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
