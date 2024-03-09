#include <QtTest>

// add necessary includes here
#include "../../src/NOTEspace/NoteService/noteservice.h"
class noteservice_test : public QObject
{
    Q_OBJECT

public:
    noteservice_test();
    ~noteservice_test();

private slots:
    void test_case1();
};

noteservice_test::noteservice_test() {
    NoteService notes;

    Note n;
    notes.addNote(n);
}

noteservice_test::~noteservice_test() {}

void noteservice_test::test_case1() {}

QTEST_APPLESS_MAIN(noteservice_test)

#include "tst_noteservice_test.moc"
