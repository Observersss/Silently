#include <QCoreApplication>
#include <QtTest>

// add necessary includes here

#include "../../src/RPGspace/Inventory/inventory.h"

class inventory_test : public QObject
{
    Q_OBJECT

public:
    inventory_test();
    ~inventory_test();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testAddItemToInventory();
    void testRemoveItemFromInventory();
    void testAddItemToEquipment();
    void testRemoveItemFromEquipment();
};

inventory_test::inventory_test() {}

inventory_test::~inventory_test() {}

void inventory_test::initTestCase() {}

void inventory_test::cleanupTestCase() {}


void inventory_test::testAddItemToInventory() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);

    QCOMPARE(inventory.getItemInInventoryCount(), size_t(1));
}

// Тестирование удаления предмета из инвентаря
void inventory_test::testRemoveItemFromInventory() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    inventory.deleteItemInInventory(item);

    QCOMPARE(inventory.getItemInInventoryCount(), size_t(0));
}

// Тестирование добавления предмета в снаряжение
void inventory_test::testAddItemToEquipment() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);

    QCOMPARE(inventory.getItemInEquipCount(), size_t(1));
}

// Тестирование удаления предмета из снаряжения
void inventory_test::testRemoveItemFromEquipment() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);
    inventory.removeFromEquipment(item);

    QCOMPARE(inventory.getItemInEquipCount(), size_t(0));
}

QTEST_MAIN(inventory_test)

#include "tst_inventory_test.moc"
