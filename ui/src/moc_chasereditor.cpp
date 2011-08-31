/****************************************************************************
** Meta object code from reading C++ file 'chasereditor.h'
**
** Created: Mon Apr 25 20:18:23 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chasereditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chasereditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChaserEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x09,
      28,   23,   13,   13, 0x09,
      52,   13,   13,   13, 0x09,
      69,   13,   13,   13, 0x09,
      89,   13,   13,   13, 0x09,
     108,   13,   13,   13, 0x09,
     127,   13,   13,   13, 0x09,
     144,   13,   13,   13, 0x09,
     162,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ChaserEditor[] = {
    "ChaserEditor\0\0accept()\0text\0"
    "slotNameEdited(QString)\0slotAddClicked()\0"
    "slotRemoveClicked()\0slotRaiseClicked()\0"
    "slotLowerClicked()\0slotCutClicked()\0"
    "slotCopyClicked()\0slotPasteClicked()\0"
};

const QMetaObject ChaserEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChaserEditor,
      qt_meta_data_ChaserEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChaserEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChaserEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChaserEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChaserEditor))
        return static_cast<void*>(const_cast< ChaserEditor*>(this));
    if (!strcmp(_clname, "Ui_ChaserEditor"))
        return static_cast< Ui_ChaserEditor*>(const_cast< ChaserEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChaserEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: slotNameEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: slotAddClicked(); break;
        case 3: slotRemoveClicked(); break;
        case 4: slotRaiseClicked(); break;
        case 5: slotLowerClicked(); break;
        case 6: slotCutClicked(); break;
        case 7: slotCopyClicked(); break;
        case 8: slotPasteClicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
