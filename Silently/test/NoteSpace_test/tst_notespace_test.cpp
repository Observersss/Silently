#include <QtTest>

// add necessary includes here

class NoteSpace_test : public QObject
{
    Q_OBJECT

public:
    NoteSpace_test();
    ~NoteSpace_test();

private slots:
    void test_case1();
};

NoteSpace_test::NoteSpace_test() {}

NoteSpace_test::~NoteSpace_test() {}

void NoteSpace_test::test_case1() {}

QTEST_APPLESS_MAIN(NoteSpace_test)

#include "tst_notespace_test.moc"
