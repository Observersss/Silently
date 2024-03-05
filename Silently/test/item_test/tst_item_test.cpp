#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include "../../src/RPGspace/Item/item.h"

class item_test : public QObject
{
    Q_OBJECT

public:
    item_test();
    ~item_test();

private slots:
    void test_case1();
    void testRankGeneration();
    void testCharacteristicsGeneration();
    void testNameGeneration();
    void testImageLoading();
    void testClassDistribution();
};

item_test::item_test() {}

item_test::~item_test() {}

void item_test::test_case1() {}

void item_test::testRankGeneration() {
    Item item;
    QVERIFY(item.getRank() == "S" || item.getRank() == "A" || item.getRank() == "B" ||
            item.getRank() == "C" || item.getRank() == "D");
}

// Test case to check if item characteristics are generated correctly
void item_test::testCharacteristicsGeneration() {
    Item item;
    auto characteristics = item.getCharacteristics();
    QVERIFY(!characteristics.empty());
    for (const auto& characteristic : characteristics) {
        QVERIFY(characteristic.second >= 1 && characteristic.second <= 8);
    }
}

// Test case to check if item name is generated correctly
void item_test::testNameGeneration() {
    Item item;
    QVERIFY(!item.getnameOfitem().isEmpty());
}

// Test case to check if item image is loaded correctly
void item_test::testImageLoading() {
    Item item;
    QPixmap image = item.getImageOfItem();
    QVERIFY(image.isNull());
}

void item_test::testClassDistribution() {
    const int sampleSize = 100;
    const int expectedCountPerClass = 20;
    const int epsilon = 8; // Прийнятий рівень похибки

    std::vector<Item> sample;
    // Заповнення вибірки з 100 елементів
    for (int i = 0; i < sampleSize; ++i) {
        sample.push_back(Item());
    }

    // Підрахунок кількості елементів у кожному класі
    int countS = 0, countA = 0, countB = 0, countC = 0, countD = 0;
    for (const auto& item : sample) {
        std::string rank = item.getRank().toStdString();
        if (rank == "S") ++countS;
        else if (rank == "A") ++countA;
        else if (rank == "B") ++countB;
        else if (rank == "C") ++countC;
        else if (rank == "D") ++countD;
    }

    // Перевірка з епсілоном
    QVERIFY(qAbs(expectedCountPerClass - countD) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countC) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countB) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countA) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countS) <= epsilon);
}



QTEST_MAIN(item_test)

#include "tst_item_test.moc"
