/****************************************************************************
** Meta object code from reading C++ file 'DatabaseHandler.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../DatabaseHandler.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DatabaseHandler.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15DatabaseHandlerE_t {};
} // unnamed namespace

template <> constexpr inline auto DatabaseHandler::qt_create_metaobjectdata<qt_meta_tag_ZN15DatabaseHandlerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DatabaseHandler",
        "loadAllNotes",
        "QSqlQuery",
        "",
        "updateNote",
        "id",
        "title",
        "desc",
        "text",
        "color",
        "typeId",
        "typeName",
        "date",
        "renameNoteType",
        "oldName",
        "newName",
        "updateNoteFavorite",
        "isFavorite",
        "removeNote",
        "connectToDatabase",
        "addNote"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'loadAllNotes'
        QtMocHelpers::SlotData<QSqlQuery()>(1, 3, QMC::AccessPublic, 0x80000000 | 2),
        // Slot 'updateNote'
        QtMocHelpers::SlotData<bool(int, const QString &, const QString &, const QString &, const QString &, int, const QString &, const QString &)>(4, 3, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 5 }, { QMetaType::QString, 6 }, { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
            { QMetaType::QString, 9 }, { QMetaType::Int, 10 }, { QMetaType::QString, 11 }, { QMetaType::QString, 12 },
        }}),
        // Slot 'renameNoteType'
        QtMocHelpers::SlotData<bool(const QString &, const QString &, const QString &)>(13, 3, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 15 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'updateNoteFavorite'
        QtMocHelpers::SlotData<bool(int, bool)>(16, 3, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 5 }, { QMetaType::Bool, 17 },
        }}),
        // Slot 'removeNote'
        QtMocHelpers::SlotData<bool(int)>(18, 3, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'connectToDatabase'
        QtMocHelpers::SlotData<void()>(19, 3, QMC::AccessPublic, QMetaType::Void),
        // Slot 'addNote'
        QtMocHelpers::SlotData<int(const QString &, const QString &, const QString &, const QString &, int, const QString &, const QString &)>(20, 3, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 6 }, { QMetaType::QString, 7 }, { QMetaType::QString, 8 }, { QMetaType::QString, 9 },
            { QMetaType::Int, 10 }, { QMetaType::QString, 11 }, { QMetaType::QString, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DatabaseHandler, qt_meta_tag_ZN15DatabaseHandlerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DatabaseHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DatabaseHandlerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DatabaseHandlerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15DatabaseHandlerE_t>.metaTypes,
    nullptr
} };

void DatabaseHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DatabaseHandler *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QSqlQuery _r = _t->loadAllNotes();
            if (_a[0]) *reinterpret_cast< QSqlQuery*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->updateNote((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->renameNoteType((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->updateNoteFavorite((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->removeNote((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->connectToDatabase(); break;
        case 6: { int _r = _t->addNote((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *DatabaseHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DatabaseHandlerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DatabaseHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
