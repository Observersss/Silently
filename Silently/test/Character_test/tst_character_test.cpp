#include <QCoreApplication>
#include <QtTest>

// add necessary includes here
#include "../../src/RPGspace/Character/character.h"
class character_test : public QObject
{
    Q_OBJECT

public:
    character_test();
    ~character_test();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testAddActiveQuest();
    void testDeleteActiveQuest();
    void testAddItemToInventory();
    void testRemoveItemFromInventory();
    void testUpdateCharacteristicsFromNewLevel();
};

character_test::character_test() {}

character_test::~character_test() {}

void character_test::initTestCase() {}

void character_test::cleanupTestCase() {}

// Test adding a quest to active quests
void character_test::testAddActiveQuest() {
    Character character;
    Quest quest;
    character.addActiveQuest(&quest);

    QCOMPARE(character.getActiveQuest().size(), size_t(1));
}

// Test deleting a quest from active quests
void character_test::testDeleteActiveQuest() {
    Character character;
    Quest quest;
    character.addActiveQuest(&quest);
    character.deleteActiveQuest(quest);

    QCOMPARE(character.getActiveQuest().size(), size_t(0));
}

// Test adding an item to the inventory
void character_test::testAddItemToInventory() {
    Character character;
    Item item;
    character.addItemToInventory(item);

    QCOMPARE(character.getInventory().getItemInInventoryCount(), size_t(1));
}

// Test removing an item from the inventory
void character_test::testRemoveItemFromInventory() {
    Character character;
    Item item;
    character.addItemToInventory(item);
    character.removeItemFromInventory(item);

    QCOMPARE(character.getInventory().getItemInInventoryCount(), size_t(0));
}

void character_test::testUpdateCharacteristicsFromNewLevel() {
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

QTEST_MAIN(character_test)

#include "tst_character_test.moc"
