QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/NOTEspace/NoteService/noteservice.h


SOURCES +=  tst_noteservice_test.cpp \
            $$INCDIR/NOTEspace/NoteService/noteservice.cpp \
            $$INCDIR/NOTEspace/Note/note.cpp
