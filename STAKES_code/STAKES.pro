QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
ICON = :/images/STAKES_LOGO.png

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ARREST.h \
    BASIC_VARIABLES.h \
    COURT_STATUS.h \
    CRYPTO_MANAGEMENT.h \
    DATA_STAKES.h \
    DIPLOMACY_MANAGEMENT.h \
    FUNCTION_STAKES.h \
    LOAN_MANAGEMENT.h \
    NEXT_DAY_MANAGEMENT.h \
    PORTFOLIO.h \
    QUIT_RESTART.h \
    REAL_ESTATE_MANAGEMENT.h \
    SAVE_LOAD_BUTTONS.h \
    SAVE_LOAD_GAME.h \
    STOCK_MANAGEMENT.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RESOURCE_PICS.qrc
