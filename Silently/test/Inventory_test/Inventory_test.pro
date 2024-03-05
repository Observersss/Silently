QT += testlib
QT += gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/RPGspace/Inventory/inventory.h \
           $$INCDIR/RPGspace/Item/item.h

SOURCES +=  tst_inventory_test.cpp \
            $$INCDIR/RPGspace/Inventory/inventory.cpp \
            $$INCDIR/RPGspace/Item/item.cpp
