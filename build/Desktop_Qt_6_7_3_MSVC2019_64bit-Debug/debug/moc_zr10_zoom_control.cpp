/****************************************************************************
** Meta object code from reading C++ file 'zr10_zoom_control.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../zr10_zoom_control.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zr10_zoom_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSZR10WorkerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSZR10WorkerENDCLASS = QtMocHelpers::stringData(
    "ZR10Worker",
    "zoomOperationFinished",
    "",
    "finalZoom",
    "initSocket",
    "ip",
    "sPort",
    "rPort",
    "doSetZoomPosition",
    "targetZoom",
    "doTriggerAutoFocus",
    "doStartManualFocusFar",
    "doStartManualFocusNear",
    "doStopManualFocus",
    "doSetCurrentZoomKnown",
    "zoom"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZR10WorkerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    3,   65,    2, 0x0a,    3 /* Public */,
       8,    1,   72,    2, 0x0a,    7 /* Public */,
      10,    0,   75,    2, 0x0a,    9 /* Public */,
      11,    0,   76,    2, 0x0a,   10 /* Public */,
      12,    0,   77,    2, 0x0a,   11 /* Public */,
      13,    0,   78,    2, 0x0a,   12 /* Public */,
      14,    1,   79,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::UShort,    5,    6,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZR10Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSZR10WorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZR10WorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZR10WorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZR10Worker, std::true_type>,
        // method 'zoomOperationFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'initSocket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'doSetZoomPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'doTriggerAutoFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'doStartManualFocusFar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'doStartManualFocusNear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'doStopManualFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'doSetCurrentZoomKnown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void ZR10Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZR10Worker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->zoomOperationFinished((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 1: _t->initSocket((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 2: _t->doSetZoomPosition((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->doTriggerAutoFocus(); break;
        case 4: _t->doStartManualFocusFar(); break;
        case 5: _t->doStartManualFocusNear(); break;
        case 6: _t->doStopManualFocus(); break;
        case 7: _t->doSetCurrentZoomKnown((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZR10Worker::*)(float );
            if (_t _q_method = &ZR10Worker::zoomOperationFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ZR10Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZR10Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZR10WorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ZR10Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ZR10Worker::zoomOperationFinished(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSZR10ZoomControlENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSZR10ZoomControlENDCLASS = QtMocHelpers::stringData(
    "ZR10ZoomControl",
    "sig_initSocket",
    "",
    "ip",
    "sPort",
    "rPort",
    "sig_setZoomPosition",
    "zoom",
    "sig_setCurrentZoomKnown",
    "sig_triggerAutoFocus",
    "sig_startManualFocusFar",
    "sig_startManualFocusNear",
    "sig_stopManualFocus"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZR10ZoomControlENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   56,    2, 0x06,    1 /* Public */,
       6,    1,   63,    2, 0x06,    5 /* Public */,
       8,    1,   66,    2, 0x06,    7 /* Public */,
       9,    0,   69,    2, 0x06,    9 /* Public */,
      10,    0,   70,    2, 0x06,   10 /* Public */,
      11,    0,   71,    2, 0x06,   11 /* Public */,
      12,    0,   72,    2, 0x06,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::UShort,    3,    4,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZR10ZoomControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSZR10ZoomControlENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZR10ZoomControlENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZR10ZoomControlENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZR10ZoomControl, std::true_type>,
        // method 'sig_initSocket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'sig_setZoomPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'sig_setCurrentZoomKnown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'sig_triggerAutoFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_startManualFocusFar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_startManualFocusNear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_stopManualFocus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ZR10ZoomControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZR10ZoomControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_initSocket((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[3]))); break;
        case 1: _t->sig_setZoomPosition((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 2: _t->sig_setCurrentZoomKnown((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->sig_triggerAutoFocus(); break;
        case 4: _t->sig_startManualFocusFar(); break;
        case 5: _t->sig_startManualFocusNear(); break;
        case 6: _t->sig_stopManualFocus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZR10ZoomControl::*)(const QString & , quint16 , quint16 );
            if (_t _q_method = &ZR10ZoomControl::sig_initSocket; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZR10ZoomControl::*)(float );
            if (_t _q_method = &ZR10ZoomControl::sig_setZoomPosition; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZR10ZoomControl::*)(float );
            if (_t _q_method = &ZR10ZoomControl::sig_setCurrentZoomKnown; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ZR10ZoomControl::*)();
            if (_t _q_method = &ZR10ZoomControl::sig_triggerAutoFocus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ZR10ZoomControl::*)();
            if (_t _q_method = &ZR10ZoomControl::sig_startManualFocusFar; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ZR10ZoomControl::*)();
            if (_t _q_method = &ZR10ZoomControl::sig_startManualFocusNear; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ZR10ZoomControl::*)();
            if (_t _q_method = &ZR10ZoomControl::sig_stopManualFocus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *ZR10ZoomControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZR10ZoomControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZR10ZoomControlENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ZR10ZoomControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ZR10ZoomControl::sig_initSocket(const QString & _t1, quint16 _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZR10ZoomControl::sig_setZoomPosition(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZR10ZoomControl::sig_setCurrentZoomKnown(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ZR10ZoomControl::sig_triggerAutoFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ZR10ZoomControl::sig_startManualFocusFar()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ZR10ZoomControl::sig_startManualFocusNear()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ZR10ZoomControl::sig_stopManualFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
