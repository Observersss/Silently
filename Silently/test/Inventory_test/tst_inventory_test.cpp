#include <QCoreApplication>
#include <QtTest>

// add necessary includes here

class inventory_test : public QObject
{
    Q_OBJECT

public:
    inventory_test();
    ~inventory_test();

private slots:
    void test_case1();
};

inventory_test::inventory_test() {}

inventory_test::~inventory_test() {}

void inventory_test::test_case1() {}

QTEST_MAIN(inventory_test)

#include "tst_inventory_test.moc"
