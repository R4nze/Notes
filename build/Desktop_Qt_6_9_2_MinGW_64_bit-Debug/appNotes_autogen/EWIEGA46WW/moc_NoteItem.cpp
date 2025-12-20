/****************************************************************************
** Meta object code from reading C++ file 'NoteItem.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NoteItem.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NoteItem.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8NoteItemE_t {};
} // unnamed namespace

template <> constexpr inline auto NoteItem::qt_create_metaobjectdata<qt_meta_tag_ZN8NoteItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "NoteItem",
        "NameOfNoteChanged",
        "",
        "DescriptionChanged",
        "TextChanged",
        "LastDateOfRedactChanged",
        "idOfTypeChanged",
        "colorChanged",
        "isFavoriteChanged",
        "NameOfNote",
        "Description",
        "Text",
        "LastDateOfRedact",
        "idOfType",
        "color",
        "id",
        "isFavorite"
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
        // Signal 'idOfTypeChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isFavoriteChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'NameOfNote'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 0),
        // property 'Description'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 1),
        // property 'Text'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 2),
        // property 'LastDateOfRedact'
        QtMocHelpers::PropertyData<QDateTime>(12, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 3),
        // property 'idOfType'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 4),
        // property 'color'
        QtMocHelpers::PropertyData<QColor>(14, QMetaType::QColor, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 5),
        // property 'id'
        QtMocHelpers::PropertyData<int>(15, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'isFavorite'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 6),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NoteItem, qt_meta_tag_ZN8NoteItemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject NoteItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8NoteItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8NoteItemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8NoteItemE_t>.metaTypes,
    nullptr
} };

void NoteItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NoteItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->NameOfNoteChanged(); break;
        case 1: _t->DescriptionChanged(); break;
        case 2: _t->TextChanged(); break;
        case 3: _t->LastDateOfRedactChanged(); break;
        case 4: _t->idOfTypeChanged(); break;
        case 5: _t->colorChanged(); break;
        case 6: _t->isFavoriteChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NoteItem::*)()>(_a, &NoteItem::NameOfNoteChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NoteItem::*)()>(_a, &NoteItem::DescriptionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NoteItem::*)()>(_a, &NoteItem::TextChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NoteItem::*)()>(_a, &NoteItem::LastDateOfRedactChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (NoteItem::*)()>(_a, &NoteItem::idOfTypeChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (NoteItem::*)()>(_a, &NoteItem::colorChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (NoteItem::*)()>(_a, &NoteItem::isFavoriteChanged, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->NameOfNote(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->Description(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->Text(); break;
        case 3: *reinterpret_cast<QDateTime*>(_v) = _t->LastDateOfRedact(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->idOfType(); break;
        case 5: *reinterpret_cast<QColor*>(_v) = _t->color(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->id(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->isFavorite(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNameOfNote(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setDescription(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setText(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setLastDateOfRedact(*reinterpret_cast<QDateTime*>(_v)); break;
        case 4: _t->setIdOfType(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setColor(*reinterpret_cast<QColor*>(_v)); break;
        case 7: _t->setIsFavorite(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *NoteItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NoteItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8NoteItemE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NoteItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void NoteItem::NameOfNoteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NoteItem::DescriptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NoteItem::TextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NoteItem::LastDateOfRedactChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void NoteItem::idOfTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void NoteItem::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void NoteItem::isFavoriteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
