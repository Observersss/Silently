#ifndef INVENTORY_H
#define INVENTORY_H
#include "RPGspace/Item/item.h"

#include <QVector>

class Inventory {
public:
    Inventory();

    void addItemInInventory(Item* item);

    void removeItemFromInventory(Item* item);

    void deleteItemFromInventory(Item* item);

    void addToEquipment(Item* item);

    void removeFromEquipment(Item* item);

    QVector<Item*> getItemInInventory() const;

    QVector<Item*> getItemEquipment() const;

    size_t getItemInInventoryCount() const;

    size_t getItemInEquipCount() const;

    Item* getItemAtIndex(size_t index) const;
    Item* getItemAtIndexEquip(size_t index) const;

    // Ітератор початку вектора інвентаря
    auto begin() {
        return itemInInventory_.begin();
    }

    // Ітератор кінця вектора інвентаря
    auto end() {
        return itemInInventory_.end();
    }
private:
    QVector<Item*> itemInInventory_;   // Предмети, що знаходяться в інвентарі користувача
    QVector<Item*> itemEquipment_;    // Предмети, що зараз активні (обладнання)
};


#endif // INVENTORY_H
