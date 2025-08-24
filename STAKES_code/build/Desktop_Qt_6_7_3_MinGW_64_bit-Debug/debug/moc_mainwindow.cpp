/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSLoadingScreenENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSLoadingScreenENDCLASS = QtMocHelpers::stringData(
    "LoadingScreen"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLoadingScreenENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject LoadingScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSLoadingScreenENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLoadingScreenENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLoadingScreenENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LoadingScreen, std::true_type>
    >,
    nullptr
} };

void LoadingScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *LoadingScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoadingScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLoadingScreenENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LoadingScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_pushButton_clicked",
    "",
    "on_SELL_BUTTON_clicked",
    "on_BUY_BUTTON_clicked",
    "on_BUY_CRYPTO_clicked",
    "on_SELL_CRYPTO_clicked",
    "calculateLoan",
    "loanAmount",
    "selectedDuration",
    "QDialog*",
    "dialog",
    "on_loanButton_clicked",
    "on_BUY_REAL_ESTATE_clicked",
    "on_SELL_REAL_ESTATE_clicked",
    "on_REAPYMENT_clicked",
    "on_DIPLOMACY_clicked",
    "on_STCOK_HOLDINGS_clicked",
    "on_CRYPTO_HOLDINGS_clicked",
    "on_REAL_ESTAT_HOLDINGS_clicked",
    "on_COURT_STATUS_clicked",
    "on_RESTART_clicked",
    "on_QUIT_GAME_clicked",
    "on_SAVE_clicked",
    "on_LOAD_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x08,    1 /* Private */,
       3,    0,  129,    2, 0x08,    2 /* Private */,
       4,    0,  130,    2, 0x08,    3 /* Private */,
       5,    0,  131,    2, 0x08,    4 /* Private */,
       6,    0,  132,    2, 0x08,    5 /* Private */,
       7,    3,  133,    2, 0x08,    6 /* Private */,
      12,    0,  140,    2, 0x08,   10 /* Private */,
      13,    0,  141,    2, 0x08,   11 /* Private */,
      14,    0,  142,    2, 0x08,   12 /* Private */,
      15,    0,  143,    2, 0x08,   13 /* Private */,
      16,    0,  144,    2, 0x08,   14 /* Private */,
      17,    0,  145,    2, 0x08,   15 /* Private */,
      18,    0,  146,    2, 0x08,   16 /* Private */,
      19,    0,  147,    2, 0x08,   17 /* Private */,
      20,    0,  148,    2, 0x08,   18 /* Private */,
      21,    0,  149,    2, 0x08,   19 /* Private */,
      22,    0,  150,    2, 0x08,   20 /* Private */,
      23,    0,  151,    2, 0x08,   21 /* Private */,
      24,    0,  152,    2, 0x08,   22 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::QString, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SELL_BUTTON_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BUY_BUTTON_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BUY_CRYPTO_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SELL_CRYPTO_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'calculateLoan'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDialog *, std::false_type>,
        // method 'on_loanButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BUY_REAL_ESTATE_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SELL_REAL_ESTATE_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_REAPYMENT_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DIPLOMACY_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_STCOK_HOLDINGS_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CRYPTO_HOLDINGS_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_REAL_ESTAT_HOLDINGS_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_COURT_STATUS_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RESTART_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_QUIT_GAME_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SAVE_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_LOAD_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_SELL_BUTTON_clicked(); break;
        case 2: _t->on_BUY_BUTTON_clicked(); break;
        case 3: _t->on_BUY_CRYPTO_clicked(); break;
        case 4: _t->on_SELL_CRYPTO_clicked(); break;
        case 5: _t->calculateLoan((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QDialog*>>(_a[3]))); break;
        case 6: _t->on_loanButton_clicked(); break;
        case 7: _t->on_BUY_REAL_ESTATE_clicked(); break;
        case 8: _t->on_SELL_REAL_ESTATE_clicked(); break;
        case 9: _t->on_REAPYMENT_clicked(); break;
        case 10: _t->on_DIPLOMACY_clicked(); break;
        case 11: _t->on_STCOK_HOLDINGS_clicked(); break;
        case 12: _t->on_CRYPTO_HOLDINGS_clicked(); break;
        case 13: _t->on_REAL_ESTAT_HOLDINGS_clicked(); break;
        case 14: _t->on_COURT_STATUS_clicked(); break;
        case 15: _t->on_RESTART_clicked(); break;
        case 16: _t->on_QUIT_GAME_clicked(); break;
        case 17: _t->on_SAVE_clicked(); break;
        case 18: _t->on_LOAD_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDialog* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
