/****************************************************************************
** Meta object code from reading C++ file 'showinfoquest.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Silently/src/ShowInfoQuest/showinfoquest.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showinfoquest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
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
struct qt_meta_stringdata_CLASSShowInfoQuestENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSShowInfoQuestENDCLASS = QtMocHelpers::stringData(
    "ShowInfoQuest",
    "questInfoClosed",
    "",
    "on_change_button_clicked",
    "on_Delete_Quest_clicked",
    "on_Quest_complete_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSShowInfoQuestENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[14];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[24];
    char stringdata5[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSShowInfoQuestENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSShowInfoQuestENDCLASS_t qt_meta_stringdata_CLASSShowInfoQuestENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ShowInfoQuest"
        QT_MOC_LITERAL(14, 15),  // "questInfoClosed"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 24),  // "on_change_button_clicked"
        QT_MOC_LITERAL(56, 23),  // "on_Delete_Quest_clicked"
        QT_MOC_LITERAL(80, 25)   // "on_Quest_complete_clicked"
    },
    "ShowInfoQuest",
    "questInfoClosed",
    "",
    "on_change_button_clicked",
    "on_Delete_Quest_clicked",
    "on_Quest_complete_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSShowInfoQuestENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ShowInfoQuest::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSShowInfoQuestENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSShowInfoQuestENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSShowInfoQuestENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ShowInfoQuest, std::true_type>,
        // method 'questInfoClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_change_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Delete_Quest_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Quest_complete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ShowInfoQuest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowInfoQuest *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->questInfoClosed(); break;
        case 1: _t->on_change_button_clicked(); break;
        case 2: _t->on_Delete_Quest_clicked(); break;
        case 3: _t->on_Quest_complete_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShowInfoQuest::*)();
            if (_t _q_method = &ShowInfoQuest::questInfoClosed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *ShowInfoQuest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowInfoQuest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSShowInfoQuestENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ShowInfoQuest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ShowInfoQuest::questInfoClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
