QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/RPGspace/Character/character.h \

SOURCES +=  tst_rpgspace_test.cpp \
            $$INCDIR/RPGspace/Character/character.cpp \
            $$INCDIR/RPGspace/Quest/quest.cpp \
            $$INCDIR/RPGspace/Inventory/inventory.cpp \
            $$INCDIR/RPGspace/Item/item.cpp
