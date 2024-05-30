#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include "../../src/RPGspace/Character/character.h"
class RPGSpace_test : public QObject
{
    Q_OBJECT

public:
    RPGSpace_test();
    ~RPGSpace_test();

private slots:
    void initTestCase();
    void cleanupTestCase();

    //Character test
    void testAddActiveQuest();
    void testDeleteActiveQuest();

    //Inventory test
    void testAddItemToInventory();
    void testRemoveItemFromInventory();
    void testAddItemToEquipment();
    void testRemoveItemFromEquipment();

    //Item test
    void testRankGeneration();
    void testCharacteristicsGeneration();
    void testNameGeneration();
    void testImageLoading();
    void testClassDistribution();
};

RPGSpace_test::RPGSpace_test() {}

RPGSpace_test::~RPGSpace_test() {}

void RPGSpace_test::initTestCase() {}

void RPGSpace_test::cleanupTestCase() {}

// Test adding a quest to active quests
void RPGSpace_test::testAddActiveQuest() {
    Character character;
    std::shared_ptr<Quest> quest = QuestFactory::create();
    character.addActiveQuest(quest);
    QCOMPARE(character.getActiveQuest().size(), size_t(1));
}

// Test deleting a quest from active quests
void RPGSpace_test::testDeleteActiveQuest() {
    Character character;

    std::shared_ptr<Quest> quest = QuestFactory::create();
    character.addActiveQuest(quest);
    character.deleteActiveQuest(quest);

    QCOMPARE(character.getActiveQuest().size(), size_t(0));
}



void RPGSpace_test::testAddItemToInventory() {
    Inventory inventory;
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    inventory.addItem(item);

    QCOMPARE(inventory.getSize(), size_t(1));
}

// Тестирование удаления предмета из инвентаря
void RPGSpace_test::testRemoveItemFromInventory() {
    Inventory inventory;
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    inventory.addItem(item);
    inventory.removeItem(item);

    QCOMPARE(inventory.getSize(), size_t(0));
}

// Тестирование добавления предмета в снаряжение
void RPGSpace_test::testAddItemToEquipment() {
    Character character;
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    character.addItemToInventory(item);
    character.addItemToEquipment(item);

    QCOMPARE(character.getEquipment()->getSize(), size_t(1));
}

// Тестирование удаления предмета из снаряжения
void RPGSpace_test::testRemoveItemFromEquipment() {
    Character character;
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    character.addItemToInventory(item);
    character.addItemToEquipment(item);
    character.removeItemFromEquipment(item);

    QCOMPARE(character.getEquipment()->getSize(),size_t(0));
}

void RPGSpace_test::testRankGeneration() {
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    QVERIFY(item->getRank() == "S" || item->getRank() == "A" || item->getRank() == "B" ||
            item->getRank() == "C" || item->getRank() == "D");
}


// Test case to check if item characteristics are generated correctly
void RPGSpace_test::testCharacteristicsGeneration() {
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    auto characteristics = item->getCharacteristics();
    QVERIFY(!characteristics.empty());
    for (const auto& characteristic : characteristics) {
        QVERIFY(characteristic.second >= 1 && characteristic.second <= 8);
    }
}

// Test case to check if item name is generated correctly
void RPGSpace_test::testNameGeneration() {
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    QVERIFY(!item->getnameOfitem().isEmpty());
}

// Test case to check if item image is loaded correctly
void RPGSpace_test::testImageLoading() {
    std::shared_ptr<Item> item = ItemFactory::create_by_default();
    QString image = item->getPathToImg();
    QVERIFY(!image.isNull());
}

void RPGSpace_test::testClassDistribution() {
    const int sampleSize = 100;
    const int expectedCountPerClass = 20;
    const int epsilon = 8; // Прийнятий рівень похибки

    std::vector<std::shared_ptr<Item>> sample;
    for (int i = 0; i < sampleSize; ++i) {
        sample.push_back(ItemFactory::create_by_default());
    }

    int countS = 0, countA = 0, countB = 0, countC = 0, countD = 0;
    for (const auto& item : sample) {
        QString rank = item->getRank();
        if (rank == "S") ++countS;
        else if (rank == "A") ++countA;
        else if (rank == "B") ++countB;
        else if (rank == "C") ++countC;
        else if (rank == "D") ++countD;
    }

    QVERIFY(qAbs(expectedCountPerClass - countD) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countC) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countB) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countA) <= epsilon);
    QVERIFY(qAbs(expectedCountPerClass - countS) <= epsilon);
}


QTEST_MAIN(RPGSpace_test)

#include "tst_rpgspace_test.moc"
