/****************************************************************************
** Meta object code from reading C++ file 'midiprotocol_test.h'
**
** Created: Fri Sep 2 17:16:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "midiprotocol_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'midiprotocol_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MIDIProtocol_Test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      28,   18,   18,   18, 0x08,
      42,   18,   18,   18, 0x08,
      66,   18,   18,   18, 0x08,
      94,   18,   18,   18, 0x08,
     124,   18,   18,   18, 0x08,
     136,   18,   18,   18, 0x08,
     162,   18,   18,   18, 0x08,
     190,   18,   18,   18, 0x08,
     221,   18,   18,   18, 0x08,
     235,   18,   18,   18, 0x08,
     252,   18,   18,   18, 0x08,
     276,   18,   18,   18, 0x08,
     293,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MIDIProtocol_Test[] = {
    "MIDIProtocol_Test\0\0macros()\0noteToInput()\0"
    "noteAftertouchToInput()\0"
    "noteToInputAnyMidiChannel()\0"
    "noteToInputWrongMidiChannel()\0ccToInput()\0"
    "ccToInputAnyMidiChannel()\0"
    "ccToInputWrongMidiChannel()\0"
    "singleChannelCommandsToInput()\0"
    "inputToNote()\0inputToControl()\0"
    "inputToNoteAftertouch()\0unknownInputCh()\0"
    "inputToSingleChannelCommands()\0"
};

const QMetaObject MIDIProtocol_Test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MIDIProtocol_Test,
      qt_meta_data_MIDIProtocol_Test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MIDIProtocol_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MIDIProtocol_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MIDIProtocol_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MIDIProtocol_Test))
        return static_cast<void*>(const_cast< MIDIProtocol_Test*>(this));
    return QObject::qt_metacast(_clname);
}

int MIDIProtocol_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: macros(); break;
        case 1: noteToInput(); break;
        case 2: noteAftertouchToInput(); break;
        case 3: noteToInputAnyMidiChannel(); break;
        case 4: noteToInputWrongMidiChannel(); break;
        case 5: ccToInput(); break;
        case 6: ccToInputAnyMidiChannel(); break;
        case 7: ccToInputWrongMidiChannel(); break;
        case 8: singleChannelCommandsToInput(); break;
        case 9: inputToNote(); break;
        case 10: inputToControl(); break;
        case 11: inputToNoteAftertouch(); break;
        case 12: unknownInputCh(); break;
        case 13: inputToSingleChannelCommands(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
