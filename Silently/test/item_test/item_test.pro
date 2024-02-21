QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/RPGspace/Item/item.h

SOURCES +=  tst_item_test.cpp \
            $$INCDIR/RPGspace/Item/item.cpp
