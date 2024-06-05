QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCDIR = ../../src
INCLUDEPATH += $$INCDIR

HEADERS += $$INCDIR/NOTEspace/NoteService/noteservice.h

SOURCES +=  tst_notespace_test.cpp \
            $$INCDIR/Notespace/NoteService/noteservice.cpp \
            $$INCDIR/NOTEspace/Note/note.cpp \
            $$INCDIR/NOTEspace/Tag/tag.cpp
