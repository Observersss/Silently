//#include <QCoreApplication>
//#include <QtTest>

//// add necessary includes here

//class inventory_test : public QObject
//{
//    Q_OBJECT

//public:
//    inventory_test();
//    ~inventory_test();

//private slots:
//    void test_case1();
//};

//inventory_test::inventory_test() {}

//inventory_test::~inventory_test() {}

//void inventory_test::test_case1() {}

//QTEST_MAIN(inventory_test)

//#include "tst_inventory_test.moc"

#include <QCoreApplication>
#include <QtTest>

// Add necessary includes here
#include "../../src/RPGspace/Inventory/inventory.h"

class inventory_test : public QObject
{
    Q_OBJECT

public:
    inventory_test(); // Constructor declaration
    ~inventory_test(); // Destructor declaration

private slots:
    // Test cases declarations
    void testAddItemInInventory();
    void testDeleteItemInInventory();
    void testDeleteItemEquipment();
    void testAddToEquipment();
    void testRemoveFromEquipment();
    void testGetItemInInventory();
    void testGetItemEquipment();
    void testGetItemInInventoryCount();
    void testGetItemInEquipCount();
    void testGetItemAtIndex();
    void testGetItemAtIndexEquip();
};

inventory_test::inventory_test() {} // Constructor definition

inventory_test::~inventory_test() {} // Destructor definition

// Test case to verify adding an item to the inventory
void inventory_test::testAddItemInInventory() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    QCOMPARE(inventory.getItemInInventoryCount(), 1);
}

// Test case to verify deleting an item from the inventory
void inventory_test::testDeleteItemInInventory() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    inventory.deleteItemInInventory(item);
    QCOMPARE(inventory.getItemInInventoryCount(), 0);
}

// Test case to verify deleting an item from the equipment
void inventory_test::testDeleteItemEquipment() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);
    inventory.deleteItemEuipment(item);
    QCOMPARE(inventory.getItemInEquipCount(), 0);
}

// Test case to verify adding an item to the equipment
void inventory_test::testAddToEquipment() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    inventory.addToEquipment(item);
    QCOMPARE(inventory.getItemInInventoryCount(), 0);
    QCOMPARE(inventory.getItemInEquipCount(), 1);
}

// Test case to verify removing an item from the equipment
void inventory_test::testRemoveFromEquipment() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);
    inventory.removeFromEquipment(item);
    QCOMPARE(inventory.getItemInEquipCount(), 0);
    QCOMPARE(inventory.getItemInInventoryCount(), 1);
}

// Test case to verify getting items in the inventory
void inventory_test::testGetItemInInventory() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    QCOMPARE(inventory.getItemInInventory().size(), 1);
}

// Test case to verify getting items in the equipment
void inventory_test::testGetItemEquipment() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);
    QCOMPARE(inventory.getItemEquipment().size(), 1);
}

// Test case to verify getting the count of items in the inventory
void inventory_test::testGetItemInInventoryCount() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    QCOMPARE(inventory.getItemInInventoryCount(), 1);
}

// Test case to verify getting the count of items in the equipment
void inventory_test::testGetItemInEquipCount() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);
    QCOMPARE(inventory.getItemInEquipCount(), 1);
}

// Test case to verify getting an item at a specific index in the inventory
void inventory_test::testGetItemAtIndex() {
    Inventory inventory;
    Item item;
    inventory.addItemInInventory(item);
    QCOMPARE(&inventory.getItemAtIndex(0), &item);
}

// Test case to verify getting an item at a specific index in the equipment
void inventory_test::testGetItemAtIndexEquip() {
    Inventory inventory;
    Item item;
    inventory.addToEquipment(item);
    QCOMPARE(&inventory.getItemAtIndexEquip(0), &item);
}

QTEST_MAIN(inventory_test) // Define the test runner

#include "tst_inventory_test.moc" // Include the generated moc file

