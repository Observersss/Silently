QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/RPGspace/Character/character.h \
           $$INCDIR/RPGspace/Quest/quest.h

SOURCES +=  tst_character_test.cpp \
            $$INCDIR/RPGspace/Character/character.cpp \
            $$INCDIR/RPGspace/Quest/quest.cpp
