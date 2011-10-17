/****************************************************************************
** Meta object code from reading C++ file 'Chronos.h'
**
** Created: Sun Oct 16 16:42:21 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Chronos.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chronos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Chronos[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      27,    8,    8,    8, 0x05,
      53,   47,    8,    8, 0x05,
      87,   83,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     105,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Chronos[] = {
    "Chronos\0\0deviceAvailible()\0"
    "deviceUnAvailible()\0x,y,z\0"
    "accDataAvailible(int,int,int)\0msg\0"
    "logEvent(QString)\0timerTick()\0"
};

const QMetaObject Chronos::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Chronos,
      qt_meta_data_Chronos, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Chronos::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Chronos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Chronos::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Chronos))
        return static_cast<void*>(const_cast< Chronos*>(this));
    return QThread::qt_metacast(_clname);
}

int Chronos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: deviceAvailible(); break;
        case 1: deviceUnAvailible(); break;
        case 2: accDataAvailible((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: logEvent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: timerTick(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Chronos::deviceAvailible()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Chronos::deviceUnAvailible()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Chronos::accDataAvailible(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Chronos::logEvent(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
