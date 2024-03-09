QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddNoteSpace_DialogWindow/addnotespace_dialogwindow.cpp \
    AddQuest_DialogWindow/addquest_dialogwindow.cpp \
    AddTag_DialogWindow/addtag_dialogwindow.cpp \
    Inventory_DialogWindow/inventory_dialogwindow.cpp \
    MoreCharacteristics_DialogWindow/morecharacteristics_dialogwindow.cpp \
    NOTEspace/Note/note.cpp \
    NOTEspace/NoteService/noteservice.cpp \
    NOTEspace/Tag/tag.cpp \
    RPGspace/Character/character.cpp \
    RPGspace/Inventory/inventory.cpp \
    RPGspace/Item/item.cpp \
    RPGspace/Quest/quest.cpp \
    ShowInfoQuest_DialogWindow/showinfoquest_dialogwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AddNoteSpace_DialogWindow/addnotespace_dialogwindow.h \
    AddQuest_DialogWindow/addquest_dialogwindow.h \
    AddTag_DialogWindow/addtag_dialogwindow.h \
    Inventory_DialogWindow/inventory_dialogwindow.h \
    MoreCharacteristics_DialogWindow/morecharacteristics_dialogwindow.h \
    NOTEspace/Note/note.h \
    NOTEspace/NoteService/noteservice.h \
    NOTEspace/Tag/tag.h \
    RPGspace/Character/character.h \
    RPGspace/Inventory/inventory.h \
    RPGspace/Item/item.h \
    RPGspace/Quest/quest.h \
    ShowInfoQuest_DialogWindow/showinfoquest_dialogwindow.h \
    mainwindow.h

FORMS += \
    AddNoteSpace_DialogWindow/addnotespace_dialogwindow.ui \
    AddQuest_DialogWindow/addquest_dialogwindow.ui \
    AddTag_DialogWindow/addtag_dialogwindow.ui \
    Inventory_DialogWindow/inventory_dialogwindow.ui \
    MoreCharacteristics_DialogWindow/morecharacteristics_dialogwindow.ui \
    ShowInfoQuest_DialogWindow/showinfoquest_dialogwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico-img.qrc

STATECHARTS += \
    activiti diagram.scxml
