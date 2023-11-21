#ifndef INVENTORY_H
#define INVENTORY_H
#include "RPGspace/Item/item.h"
#include "Library/library.h"

class Inventory {
private:
    std::vector<Item> itemInInventory;   // Предмети, що знаходяться в інвентарі користувача
    std::vector<Item> itemEquipment;    // Предмети, що зараз активні (обладнання)

public:
    // Пустий конструктор класу
    Inventory();

    // Додавання предмету в інвентар
    void addItemInInventory(Item item);

    // Видалення предмету з інвентаря
    void deleteItemInInventory(Item item);

    // Видалення предмету з обладнання
    void deleteItemEuipment(Item item);

    // Додавання предмету в обладнання (використовується на персонажі)
    void addToEquipment(const Item& item);

    // Зняття предмету з обладнання
    void removeFromEquipment(Item item);

    // Отримання вектора всіх предметів в інвентарі
    std::vector<Item> getItemInInventory() const;

    // Отримання вектора предметів у обладнанні
    std::vector<Item> getItemEquipment() const;

    // Отримання кількості предметів в інвентарі
    size_t getItemInInventoryCount() const;

    // Отримання кількості предметів у обладнанні
    size_t getItemInEquipCount() const;

    // Отримання предмету за індексом
    const Item& getItemAtIndex(size_t index) const;

    // Ітератор початку вектора інвентаря
    auto begin() {
        return itemInInventory.begin();
    }

    // Ітератор кінця вектора інвентаря
    auto end() {
        return itemInInventory.end();
    }
};


#endif // INVENTORY_H
