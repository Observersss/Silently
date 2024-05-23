#ifndef INVENTORY_H
#define INVENTORY_H
#include "RPGspace/Item/item.h"

#include <QVector>

// class Inventory {
// public:
//     Inventory();

//     void addItemInInventory(Item* item);

//     void removeItemFromInventory(Item* item);

//     void addToEquipment(Item* item);

//     void removeFromEquipment(Item* item);

//     QVector<Item*> getItemsInInventory() const;

//     QVector<Item*> getItemsEquipment() const;

//     size_t getItemInInventoryCount() const;

//     size_t getItemInEquipCount() const;

//     Item* getItemAtIndex(size_t index) const;
//     Item* getItemAtIndexEquip(size_t index) const;


//     // Ітератор початку вектора інвентаря
//     auto begin() {
//         return itemInInventory_.begin();
//     }

//     // Ітератор кінця вектора інвентаря
//     auto end() {
//         return itemInInventory_.end();
//     }
// private:
//     QVector<Item*> itemInInventory_;   // Предмети, що знаходяться в інвентарі користувача
//     QVector<Item*> itemEquipment_;    // Предмети, що зараз активні (обладнання)
// };

class Inventory{
public:
    Inventory() = default;

    void addItem(std::shared_ptr<Item> item);
    void removeItem(const std::shared_ptr<Item>& item);

    QVector<std::shared_ptr<Item>> getItems() const;

    size_t getSize() const;

    std::shared_ptr<Item> getItemAtIndex(size_t index) const;
    std::shared_ptr<Item> getItemAtName(const QString& name) const;
private:
    int indexOfItem(const QString& name) const;

    QVector<std::shared_ptr<Item>> items_;
};
// class Equipment_test{
// public:
//     Equipment_test() = default;

//     void addItemInEquipment(std::shared_ptr<Item> item);
//     void removeItemFromEquipment(const std::shared_ptr<Item>& item);

//     QVector<std::shared_ptr<Item>> getItemsInEquipment() const;
//     size_t getSizeEquipment() const;

//     std::shared_ptr<Item> getItemAtIndex(const size_t& index) const;
//     std::shared_ptr<Item> getItemAtName(const QString& name) const;
// private:
//     int indexOfItem(const QString& name) const;

//     QVector<std::shared_ptr<Item>> itemInEquipment_;
// };


#endif // INVENTORY_H
