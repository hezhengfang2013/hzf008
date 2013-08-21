/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created: Tue Aug 20 23:54:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SelectDialog[] = {

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
      20,   14,   13,   13, 0x08,
      43,   14,   13,   13, 0x08,
      66,   13,   13,   13, 0x08,
      71,   14,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SelectDialog[] = {
    "SelectDialog\0\0value\0bAlgorithmChanged(int)\0"
    "wAlgorithmChanged(int)\0OK()\0"
    "currentTimesChanged(int)\0"
};

void SelectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SelectDialog *_t = static_cast<SelectDialog *>(_o);
        switch (_id) {
        case 0: _t->bAlgorithmChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->wAlgorithmChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OK(); break;
        case 3: _t->currentTimesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SelectDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SelectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectDialog,
      qt_meta_data_SelectDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SelectDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SelectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SelectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectDialog))
        return static_cast<void*>(const_cast< SelectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SelectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
