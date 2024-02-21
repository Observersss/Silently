#include <QtTest>

// add necessary includes here

class NoteService_test : public QObject
{
    Q_OBJECT

public:
    NoteService_test();
    ~NoteService_test();

private slots:
    void test_case1();
};

NoteService_test::NoteService_test() {}

NoteService_test::~NoteService_test() {}

void NoteService_test::test_case1() {}

QTEST_APPLESS_MAIN(NoteService_test)

#include "tst_noteservice_test.moc"
