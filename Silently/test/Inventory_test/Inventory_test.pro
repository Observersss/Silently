QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/RPGspace/Inventory/Inventory.h

SOURCES +=  tst_inventory_test.cpp \
            $$INCDIR/RPGspace/Inventory/Inventory.cpp
