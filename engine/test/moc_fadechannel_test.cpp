/****************************************************************************
** Meta object code from reading C++ file 'fadechannel_test.h'
**
** Created: Mon Apr 25 20:16:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fadechannel_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fadechannel_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FadeChannel_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      28,   17,   17,   17, 0x08,
      36,   17,   17,   17, 0x08,
      44,   17,   17,   17, 0x08,
      53,   17,   17,   17, 0x08,
      63,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FadeChannel_Test[] = {
    "FadeChannel_Test\0\0address()\0group()\0"
    "start()\0target()\0current()\0"
    "calculateCurrent()\0"
};

const QMetaObject FadeChannel_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FadeChannel_Test,
      qt_meta_data_FadeChannel_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FadeChannel_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FadeChannel_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FadeChannel_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FadeChannel_Test))
        return static_cast<void*>(const_cast< FadeChannel_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int FadeChannel_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: address(); break;
        case 1: group(); break;
        case 2: start(); break;
        case 3: target(); break;
        case 4: current(); break;
        case 5: calculateCurrent(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE