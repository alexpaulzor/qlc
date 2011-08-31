/****************************************************************************
** Meta object code from reading C++ file 'vccuelistproperties.h'
**
** Created: Mon Apr 25 20:18:49 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vccuelistproperties.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vccuelistproperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VCCueListProperties[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,
      30,   20,   20,   20, 0x0a,
      47,   20,   20,   20, 0x09,
      64,   20,   20,   20, 0x09,
      84,   20,   20,   20, 0x09,
     103,   20,   20,   20, 0x09,
     122,   20,   20,   20, 0x09,
     139,   20,   20,   20, 0x09,
     157,   20,   20,   20, 0x09,
     176,   20,   20,   20, 0x09,
     200,   20,   20,   20, 0x09,
     224,   20,   20,   20, 0x09,
     259,  253,   20,   20, 0x09,
     303,  296,   20,   20, 0x09,
     346,   20,   20,   20, 0x09,
     374,   20,   20,   20, 0x09,
     402,   20,   20,   20, 0x09,
     435,  253,   20,   20, 0x09,
     476,  296,   20,   20, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VCCueListProperties[] = {
    "VCCueListProperties\0\0accept()\0"
    "slotTabChanged()\0slotAddClicked()\0"
    "slotRemoveClicked()\0slotRaiseClicked()\0"
    "slotLowerClicked()\0slotCutClicked()\0"
    "slotCopyClicked()\0slotPasteClicked()\0"
    "slotNextAttachClicked()\0slotNextDetachClicked()\0"
    "slotNextChooseInputClicked()\0state\0"
    "slotNextAutoDetectInputToggled(bool)\0"
    "uni,ch\0slotNextInputValueChanged(quint32,quint32)\0"
    "slotPreviousAttachClicked()\0"
    "slotPreviousDetachClicked()\0"
    "slotPreviousChooseInputClicked()\0"
    "slotPreviousAutoDetectInputToggled(bool)\0"
    "slotPreviousInputValueChanged(quint32,quint32)\0"
};

const QMetaObject VCCueListProperties::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VCCueListProperties,
      qt_meta_data_VCCueListProperties, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VCCueListProperties::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VCCueListProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VCCueListProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VCCueListProperties))
        return static_cast<void*>(const_cast< VCCueListProperties*>(this));
    if (!strcmp(_clname, "Ui_VCCueListProperties"))
        return static_cast< Ui_VCCueListProperties*>(const_cast< VCCueListProperties*>(this));
    return QDialog::qt_metacast(_clname);
}

int VCCueListProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: accept(); break;
        case 1: slotTabChanged(); break;
        case 2: slotAddClicked(); break;
        case 3: slotRemoveClicked(); break;
        case 4: slotRaiseClicked(); break;
        case 5: slotLowerClicked(); break;
        case 6: slotCutClicked(); break;
        case 7: slotCopyClicked(); break;
        case 8: slotPasteClicked(); break;
        case 9: slotNextAttachClicked(); break;
        case 10: slotNextDetachClicked(); break;
        case 11: slotNextChooseInputClicked(); break;
        case 12: slotNextAutoDetectInputToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: slotNextInputValueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 14: slotPreviousAttachClicked(); break;
        case 15: slotPreviousDetachClicked(); break;
        case 16: slotPreviousChooseInputClicked(); break;
        case 17: slotPreviousAutoDetectInputToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: slotPreviousInputValueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
