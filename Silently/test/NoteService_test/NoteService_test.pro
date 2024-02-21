QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/NoteSpace/NoteService/NoteService.h

SOURCES +=  tst_noteservice_test.cpp \
            $$INCDIR/NoteSpace/NoteService/NoteService.cpp
