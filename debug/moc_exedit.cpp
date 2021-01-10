/****************************************************************************
** Meta object code from reading C++ file 'exedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../exedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExEdit_t {
    QByteArrayData data[17];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExEdit_t qt_meta_stringdata_ExEdit = {
    {
QT_MOC_LITERAL(0, 0, 6), // "ExEdit"
QT_MOC_LITERAL(1, 7, 11), // "removeEvent"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "QWidget*"
QT_MOC_LITERAL(4, 29, 1), // "m"
QT_MOC_LITERAL(5, 31, 10), // "sendChange"
QT_MOC_LITERAL(6, 42, 4), // "type"
QT_MOC_LITERAL(7, 47, 5), // "value"
QT_MOC_LITERAL(8, 53, 19), // "on_delete_2_clicked"
QT_MOC_LITERAL(9, 73, 31), // "on_exSelect_currentIndexChanged"
QT_MOC_LITERAL(10, 105, 5), // "index"
QT_MOC_LITERAL(11, 111, 17), // "on_isShow_clicked"
QT_MOC_LITERAL(12, 129, 2), // "is"
QT_MOC_LITERAL(13, 132, 18), // "on_exA_textChanged"
QT_MOC_LITERAL(14, 151, 18), // "on_exW_textChanged"
QT_MOC_LITERAL(15, 170, 18), // "on_exC_textChanged"
QT_MOC_LITERAL(16, 189, 18) // "on_exH_textChanged"

    },
    "ExEdit\0removeEvent\0\0QWidget*\0m\0"
    "sendChange\0type\0value\0on_delete_2_clicked\0"
    "on_exSelect_currentIndexChanged\0index\0"
    "on_isShow_clicked\0is\0on_exA_textChanged\0"
    "on_exW_textChanged\0on_exC_textChanged\0"
    "on_exH_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    3,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   69,    2, 0x08 /* Private */,
       9,    1,   70,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,
      13,    1,   76,    2, 0x08 /* Private */,
      14,    1,   79,    2, 0x08 /* Private */,
      15,    1,   82,    2, 0x08 /* Private */,
      16,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Double,    4,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void ExEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ExEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeEvent((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->sendChange((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->on_delete_2_clicked(); break;
        case 3: _t->on_exSelect_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_isShow_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_exA_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_exW_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_exC_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_exH_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ExEdit::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExEdit::removeEvent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ExEdit::*)(QWidget * , int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ExEdit::sendChange)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ExEdit::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ExEdit.data,
    qt_meta_data_ExEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ExEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ExEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ExEdit::removeEvent(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ExEdit::sendChange(QWidget * _t1, int _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
