/****************************************************************************
** Meta object code from reading C++ file 'NotesManager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NotesManager.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

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
        "noteListChanged",
        "",
        "deletemodeChanged",
        "typeModelChanged",
        "addNote",
        "name",
        "description",
        "text",
        "id",
        "changeNote",
        "NoteItem*",
        "item",
        "nameOfColor",
        "color",
        "deleteSelectedNotes",
        "addSelectedNote",
        "removeSelectedNote",
        "sortByType",
        "idOfType",
        "getOrCreateTypeId",
        "getTypeColor",
        "noteList",
        "QList<QObject*>",
        "deletemode",
        "typeModel",
        "QList<Type*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'noteListChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'deletemodeChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'typeModelChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'addNote'
        QtMocHelpers::SlotData<void(const QString &, const QString &, const QString &, const int &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { QMetaType::QString, 7 }, { QMetaType::QString, 8 }, { QMetaType::Int, 9 },
        }}),
        // Slot 'changeNote'
        QtMocHelpers::SlotData<void(NoteItem *, const QString &, const QString &, const QString &, const QString &, const QColor &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 }, { QMetaType::QString, 6 }, { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
            { QMetaType::QString, 13 }, { QMetaType::QColor, 14 },
        }}),
        // Slot 'deleteSelectedNotes'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'addSelectedNote'
        QtMocHelpers::SlotData<void(NoteItem *)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'removeSelectedNote'
        QtMocHelpers::SlotData<void(NoteItem *)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'sortByType'
        QtMocHelpers::SlotData<void(int)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 19 },
        }}),
        // Slot 'getOrCreateTypeId'
        QtMocHelpers::SlotData<int(const QString &, const QColor &)>(20, 2, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 6 }, { QMetaType::QColor, 14 },
        }}),
        // Method 'getTypeColor'
        QtMocHelpers::MethodData<QColor(NoteItem *)>(21, 2, QMC::AccessPublic, QMetaType::QColor, {{
            { 0x80000000 | 11, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'noteList'
        QtMocHelpers::PropertyData<QList<QObject*>>(22, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Final, 0),
        // property 'deletemode'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 1),
        // property 'typeModel'
        QtMocHelpers::PropertyData<QList<Type*>>(25, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Final, 2),
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
        case 0: _t->noteListChanged(); break;
        case 1: _t->deletemodeChanged(); break;
        case 2: _t->typeModelChanged(); break;
        case 3: _t->addNote((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 4: _t->changeNote((*reinterpret_cast< std::add_pointer_t<NoteItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[6]))); break;
        case 5: _t->deleteSelectedNotes(); break;
        case 6: _t->addSelectedNote((*reinterpret_cast< std::add_pointer_t<NoteItem*>>(_a[1]))); break;
        case 7: _t->removeSelectedNote((*reinterpret_cast< std::add_pointer_t<NoteItem*>>(_a[1]))); break;
        case 8: _t->sortByType((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: { int _r = _t->getOrCreateTypeId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { QColor _r = _t->getTypeColor((*reinterpret_cast< std::add_pointer_t<NoteItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< NoteItem* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< NoteItem* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< NoteItem* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< NoteItem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NotesManager::*)()>(_a, &NotesManager::noteListChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotesManager::*)()>(_a, &NotesManager::deletemodeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotesManager::*)()>(_a, &NotesManager::typeModelChanged, 2))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Type*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<QObject*>*>(_v) = _t->noteList(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->deletemode(); break;
        case 2: *reinterpret_cast<QList<Type*>*>(_v) = _t->typeModel(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setDeletemode(*reinterpret_cast<bool*>(_v)); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void NotesManager::noteListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NotesManager::deletemodeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NotesManager::typeModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
