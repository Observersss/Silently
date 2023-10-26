QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddQuest/addquest.cpp \
    RPGspace/Character/character.cpp \
    RPGspace/Inventory/inventory.cpp \
    RPGspace/Item/item.cpp \
    RPGspace/Quest/quest.cpp \
    ShowInfoQuest/showinfoquest.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AddQuest/addquest.h \
    Library/library.h \
    RPGspace/Character/character.h \
    RPGspace/Inventory/inventory.h \
    RPGspace/Item/item.h \
    RPGspace/Quest/quest.h \
    ShowInfoQuest/showinfoquest.h \
    mainwindow.h

FORMS += \
    AddQuest/addquest.ui \
    ShowInfoQuest/showinfoquest.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
