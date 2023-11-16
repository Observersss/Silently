#include "inventory.h"


Inventory::Inventory(){}

void Inventory::addItemInInventory(Item item){
    itemInInventory.push_back(item);
}

void Inventory::deleteItemInInventory(Item item){
    for (auto it = itemInInventory.begin(); it != itemInInventory.end(); ++it) {

        if (it->getIndex() == item.getIndex()) {
            // Используйте метод erase(), чтобы удалить элемент из вектора
            itemInInventory.erase(it);
            // Выход из цикла после удаления элемента (по желанию)
            break;
        }
    }
}

void Inventory::addToEquipment(const Item& item) {

    for (const Item& existingItem : itemEquipment) {
        if (existingItem.getIndex() == item.getIndex()) {
            //            // Предмет с таким же типом уже одет, генерируем ошибку или делаем что-то другое по вашему выбору
            //            // Например, можно выбросить исключение или вернуть ошибку
            //            throw std::runtime_error("Предмет с таким типом уже одет");
            return;
        }
    }

    //якщо предмет пройшов перевірку на тип то ми додаємо його у активне спорядження а з інвентарю прибираємо
    itemEquipment.push_back(item);
    deleteItemInInventory(item);
}

void Inventory::removeFromEquipment(Item item) {
    for (auto it = itemEquipment.begin(); it != itemEquipment.end(); ++it) {
        if (it->getIndex() == item.getIndex()) {
            itemEquipment.erase(it);
            // Після видалення з активного спорадження повератємо предмет в інвентарь
            itemInInventory.push_back(item);
            break;
        }
    }
}


std::vector<Item> Inventory::getItemInInventory() const {
    return itemInInventory;
}
std::vector<Item> Inventory::getItemEquipment()const{
    return itemEquipment;
}
size_t Inventory::getItemInInventoryCount() const{
    return itemInInventory.size();
}
const Item& Inventory::getItemAtIndex(size_t index) const{
    // Реализуйте логику для получения элемента по указанному индексу
    // Например, если внутри Inventory у вас есть вектор items, вы можете обратиться к элементу в этом векторе
    if (index < itemInInventory.size()) {
        return itemInInventory[index];
    }
    // Возвращайте элемент или бросайте исключение в зависимости от вашей логики
    // Например, если элемент с данным индексом не существует, вы можете бросить исключение
    throw std::out_of_range("Index out of range");
}
