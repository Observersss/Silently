#include <QtTest>

// add necessary includes here

class character_test : public QObject
{
    Q_OBJECT

public:
    character_test();
    ~character_test();

private slots:
    void test_case1();
};

character_test::character_test() {}

character_test::~character_test() {}

void character_test::test_case1() {}

QTEST_APPLESS_MAIN(character_test)

#include "tst_character_test.moc"
