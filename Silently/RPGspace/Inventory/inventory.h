#ifndef INVENTORY_H
#define INVENTORY_H
#include "RPGspace/Item/item.h"
#include "Library/library.h"
class Inventory{
private:
    std::vector<Item> itemInInventory;// Предмети які знаходяться в інвентарі користувача
    std::vector<Item> itemEquipment;//Предмети які зараз активні
        //Якщо предмет активний то він зникає з інветаря
public:
    //Пустий базовий класс
    Inventory();

    //Додавання предмету
    //Приймає об'єкт классу Item і виконуює push_back до вектора
    void addItemInInventory(Item item);

    //Видалення предмату
    //Приймає об'єкт классу Item і видаляє його з вектора itemInInventory
    void deleteItemInInventory(Item item);

    //Додавання предмету який користувач одягає на персонажа
    //Приймає об'єкт класса Item і додає його у itemEquipment
    //Причому з itemInInventory предмет зникає
    void addToEquipment(const Item& item);

    //Зняття активного предмету з персонажу
    //Приймає об'єкт класса Item і додає його у itemInInventory
    //Причому з itemEquipment предмет зникає
    void removeFromEquipment(Item item);

    //Повертає вектор всіх предметів
    std::vector<Item> getItemInInventory() const;
    std::vector<Item> getItemEquipment()const;
};

#endif // INVENTORY_H
