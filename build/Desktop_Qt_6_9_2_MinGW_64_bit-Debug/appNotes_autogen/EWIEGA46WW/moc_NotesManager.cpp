/****************************************************************************
** Meta object code from reading C++ file 'NotesManager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NotesManager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NotesManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
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
struct qt_meta_tag_ZN12NotesManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto NotesManager::qt_create_metaobjectdata<qt_meta_tag_ZN12NotesManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "NotesManager",
        "NameOfNoteChanged",
        "",
        "DescriptionChanged",
        "TextChanged",
        "LastDateOfRedactChanged",
        "NameOfNote",
        "Description",
        "Text",
        "LastDateOfRedact"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'NameOfNoteChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'DescriptionChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'TextChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'LastDateOfRedactChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'NameOfNote'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 0),
        // property 'Description'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 1),
        // property 'Text'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 2),
        // property 'LastDateOfRedact'
        QtMocHelpers::PropertyData<int>(9, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NotesManager, qt_meta_tag_ZN12NotesManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject NotesManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12NotesManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12NotesManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12NotesManagerE_t>.metaTypes,
    nullptr
} };

void NotesManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NotesManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->NameOfNoteChanged(); break;
        case 1: _t->DescriptionChanged(); break;
        case 2: _t->TextChanged(); break;
        case 3: _t->LastDateOfRedactChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NotesManager::*)()>(_a, &NotesManager::NameOfNoteChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotesManager::*)()>(_a, &NotesManager::DescriptionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotesManager::*)()>(_a, &NotesManager::TextChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotesManager::*)()>(_a, &NotesManager::LastDateOfRedactChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->NameOfNote(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->Description(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->Text(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->LastDateOfRedact(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNameOfNote(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setDescription(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setText(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setLastDateOfRedact(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *NotesManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotesManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12NotesManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NotesManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NotesManager::NameOfNoteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NotesManager::DescriptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NotesManager::TextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NotesManager::LastDateOfRedactChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
