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
    void testUpdateCharacteristicsFromNewLevel();

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
    Quest quest;
    character.addActiveQuest(&quest);

    QCOMPARE(character.getActiveQuest().size(), size_t(1));
}

// Test deleting a quest from active quests
void RPGSpace_test::testDeleteActiveQuest() {
    Character character;
    Quest quest;
    character.addActiveQuest(&quest);
    character.deleteActiveQuest(quest);

    QCOMPARE(character.getActiveQuest().size(), size_t(0));
}


void RPGSpace_test::testUpdateCharacteristicsFromNewLevel() {
    Character character;

    // Before updating characteristics
    int healthBefore = character.getHealth();
    int damageBefore = character.getDamage();

    character.updateLevel();
    // After updating characteristics
    int healthAfter = character.getHealth();
    int damageAfter = character.getDamage();

    // Check that characteristics have changed
    QVERIFY(healthAfter > healthBefore);
    QVERIFY(damageAfter > damageBefore);
}

void RPGSpace_test::testAddItemToInventory() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);

    QCOMPARE(inventory.getItemInInventoryCount(), size_t(1));
}

// Тестирование удаления предмета из инвентаря
void RPGSpace_test::testRemoveItemFromInventory() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    inventory.deleteItemInInventory(item);

    QCOMPARE(inventory.getItemInInventoryCount(), size_t(0));
}

// Тестирование добавления предмета в снаряжение
void RPGSpace_test::testAddItemToEquipment() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);

    QCOMPARE(inventory.getItemInEquipCount(), size_t(1));
}

// Тестирование удаления предмета из снаряжения
void RPGSpace_test::testRemoveItemFromEquipment() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);
    inventory.removeFromEquipment(item);

    QCOMPARE(inventory.getItemInEquipCount(), size_t(0));
}

void RPGSpace_test::testRankGeneration() {
    Item item;
    QVERIFY(item.getRank() == "S" || item.getRank() == "A" || item.getRank() == "B" ||
            item.getRank() == "C" || item.getRank() == "D");
}

// Test case to check if item characteristics are generated correctly
void RPGSpace_test::testCharacteristicsGeneration() {
    Item item;
    auto characteristics = item.getCharacteristics();
    QVERIFY(!characteristics.empty());
    for (const auto& characteristic : characteristics) {
        QVERIFY(characteristic.second >= 1 && characteristic.second <= 8);
    }
}

// Test case to check if item name is generated correctly
void RPGSpace_test::testNameGeneration() {
    Item item;
    QVERIFY(!item.getnameOfitem().isEmpty());
}

// Test case to check if item image is loaded correctly
void RPGSpace_test::testImageLoading() {
    Item item;
    QPixmap image = item.getImageOfItem();
    QVERIFY(image.isNull());
}

void RPGSpace_test::testClassDistribution() {
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

QTEST_MAIN(RPGSpace_test)

#include "tst_rpgspace_test.moc"
