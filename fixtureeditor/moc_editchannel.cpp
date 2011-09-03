/****************************************************************************
** Meta object code from reading C++ file 'editchannel.h'
**
** Created: Fri Sep 2 17:15:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editchannel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editchannel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditChannel[] = {

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
      18,   13,   12,   12, 0x09,
      49,   43,   12,   12, 0x09,
      85,   77,   12,   12, 0x09,
     111,   77,   12,   12, 0x09,
     144,  137,   12,   12, 0x09,
     178,  173,   12,   12, 0x09,
     231,   12,   12,   12, 0x09,
     258,   12,   12,   12, 0x09,
     288,   12,   12,   12, 0x09,
     316,   12,   12,   12, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_EditChannel[] = {
    "EditChannel\0\0name\0slotNameChanged(QString)\0"
    "group\0slotGroupActivated(QString)\0"
    "toggled\0slotMsbRadioToggled(bool)\0"
    "slotLsbRadioToggled(bool)\0colour\0"
    "slotColourActivated(QString)\0item\0"
    "slotCapabilityListSelectionChanged(QTreeWidgetItem*)\0"
    "slotAddCapabilityClicked()\0"
    "slotRemoveCapabilityClicked()\0"
    "slotEditCapabilityClicked()\0"
    "slotWizardClicked()\0"
};

const QMetaObject EditChannel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditChannel,
      qt_meta_data_EditChannel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditChannel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditChannel))
        return static_cast<void*>(const_cast< EditChannel*>(this));
    if (!strcmp(_clname, "Ui_EditChannel"))
        return static_cast< Ui_EditChannel*>(const_cast< EditChannel*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: slotGroupActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: slotMsbRadioToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: slotLsbRadioToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: slotColourActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: slotCapabilityListSelectionChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 6: slotAddCapabilityClicked(); break;
        case 7: slotRemoveCapabilityClicked(); break;
        case 8: slotEditCapabilityClicked(); break;
        case 9: slotWizardClicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
