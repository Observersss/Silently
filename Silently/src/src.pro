QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddQuest/addquest.cpp \
    InventoryWindow/inventorywindow.cpp \
    MoreCharacteristics/morecharacteristics.cpp \
    NOTEspace/Note/note.cpp \
    NOTEspace/NoteService/noteservice.cpp \
    NOTEspace/Tag/tag.cpp \
    RPGspace/Character/character.cpp \
    RPGspace/Inventory/inventory.cpp \
    RPGspace/Item/item.cpp \
    RPGspace/Quest/quest.cpp \
    ShowInfoQuest/showinfoquest.cpp \
    addTag/addtag.cpp \
    createNewNoteSpaceWindow/createnewnotespacewindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AddQuest/addquest.h \
    InventoryWindow/inventorywindow.h \
    Library/library.h \
    MoreCharacteristics/morecharacteristics.h \
    NOTEspace/Note/note.h \
    NOTEspace/NoteService/noteservice.h \
    NOTEspace/Tag/tag.h \
    RPGspace/Character/character.h \
    RPGspace/Inventory/inventory.h \
    RPGspace/Item/item.h \
    RPGspace/Quest/quest.h \
    ShowInfoQuest/showinfoquest.h \
    addTag/addtag.h \
    createNewNoteSpaceWindow/createnewnotespacewindow.h \
    mainwindow.h

FORMS += \
    AddQuest/addquest.ui \
    InventoryWindow/inventorywindow.ui \
    MoreCharacteristics/morecharacteristics.ui \
    ShowInfoQuest/showinfoquest.ui \
    addTag/addtag.ui \
    createNewNoteSpaceWindow/createnewnotespacewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico-img.qrc
