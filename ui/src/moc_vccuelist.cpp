/****************************************************************************
** Meta object code from reading C++ file 'vccuelist.h'
**
** Created: Mon Apr 25 20:18:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vccuelist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vccuelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VCCueList[] = {

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
      15,   11,   10,   10, 0x09,
      44,   11,   10,   10, 0x09,
      73,   10,   10,   10, 0x09,
      87,   10,   10,   10, 0x09,
     116,  105,   10,   10, 0x09,
     149,  144,   10,   10, 0x09,
     197,  185,   10,   10, 0x09,
     249,  226,   10,   10, 0x09,
     298,  226,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_VCCueList[] = {
    "VCCueList\0\0fid\0slotFunctionRemoved(quint32)\0"
    "slotFunctionChanged(quint32)\0slotNextCue()\0"
    "slotPreviousCue()\0stepNumber\0"
    "slotCurrentStepChanged(int)\0item\0"
    "slotItemActivated(QTreeWidgetItem*)\0"
    "keySequence\0slotKeyPressed(QKeySequence)\0"
    "universe,channel,value\0"
    "slotNextInputValueChanged(quint32,quint32,uchar)\0"
    "slotPreviousInputValueChanged(quint32,quint32,uchar)\0"
};

const QMetaObject VCCueList::staticMetaObject = {
    { &VCWidget::staticMetaObject, qt_meta_stringdata_VCCueList,
      qt_meta_data_VCCueList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VCCueList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VCCueList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VCCueList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VCCueList))
        return static_cast<void*>(const_cast< VCCueList*>(this));
    if (!strcmp(_clname, "DMXSource"))
        return static_cast< DMXSource*>(const_cast< VCCueList*>(this));
    return VCWidget::qt_metacast(_clname);
}

int VCCueList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VCWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotFunctionRemoved((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: slotFunctionChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: slotNextCue(); break;
        case 3: slotPreviousCue(); break;
        case 4: slotCurrentStepChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: slotItemActivated((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 6: slotKeyPressed((*reinterpret_cast< const QKeySequence(*)>(_a[1]))); break;
        case 7: slotNextInputValueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        case 8: slotPreviousInputValueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
