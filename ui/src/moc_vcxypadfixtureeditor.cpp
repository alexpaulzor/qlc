/****************************************************************************
** Meta object code from reading C++ file 'vcxypadfixtureeditor.h'
**
** Created: Mon Apr 25 20:19:00 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vcxypadfixtureeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vcxypadfixtureeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VCXYPadFixtureEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x09,
      37,   31,   21,   21, 0x09,
      58,   31,   21,   21, 0x09,
      79,   31,   21,   21, 0x09,
     100,   31,   21,   21, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VCXYPadFixtureEditor[] = {
    "VCXYPadFixtureEditor\0\0accept()\0value\0"
    "slotXMinChanged(int)\0slotXMaxChanged(int)\0"
    "slotYMinChanged(int)\0slotYMaxChanged(int)\0"
};

const QMetaObject VCXYPadFixtureEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VCXYPadFixtureEditor,
      qt_meta_data_VCXYPadFixtureEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VCXYPadFixtureEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VCXYPadFixtureEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VCXYPadFixtureEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VCXYPadFixtureEditor))
        return static_cast<void*>(const_cast< VCXYPadFixtureEditor*>(this));
    if (!strcmp(_clname, "Ui_VCXYPadFixtureEditor"))
        return static_cast< Ui_VCXYPadFixtureEditor*>(const_cast< VCXYPadFixtureEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int VCXYPadFixtureEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: slotXMinChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: slotXMaxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: slotYMinChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: slotYMaxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
