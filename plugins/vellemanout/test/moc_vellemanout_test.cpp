/****************************************************************************
** Meta object code from reading C++ file 'vellemanout_test.h'
**
** Created: Fri Sep 2 17:15:46 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vellemanout_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vellemanout_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VellemanOut_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      28,   17,   17,   17, 0x08,
      40,   17,   17,   17, 0x08,
      51,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VellemanOut_Test[] = {
    "VellemanOut_Test\0\0initial()\0openClose()\0"
    "infoText()\0outputDMX()\0"
};

const QMetaObject VellemanOut_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VellemanOut_Test,
      qt_meta_data_VellemanOut_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VellemanOut_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VellemanOut_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VellemanOut_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VellemanOut_Test))
        return static_cast<void*>(const_cast< VellemanOut_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int VellemanOut_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initial(); break;
        case 1: openClose(); break;
        case 2: infoText(); break;
        case 3: outputDMX(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
