/****************************************************************************
** Meta object code from reading C++ file 'Elec.h'
**
** Created: Mon Sep 23 18:08:42 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Elec.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Elec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Elec[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      17,    5,    5,    5, 0x08,
      27,    5,    5,    5, 0x08,
      36,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Elec[] = {
    "Elec\0\0onConfig()\0onQuery()\0onUser()\0"
    "onQuit()\0"
};

void Elec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Elec *_t = static_cast<Elec *>(_o);
        switch (_id) {
        case 0: _t->onConfig(); break;
        case 1: _t->onQuery(); break;
        case 2: _t->onUser(); break;
        case 3: _t->onQuit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Elec::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Elec::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Elec,
      qt_meta_data_Elec, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Elec::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Elec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Elec::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Elec))
        return static_cast<void*>(const_cast< Elec*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Elec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
