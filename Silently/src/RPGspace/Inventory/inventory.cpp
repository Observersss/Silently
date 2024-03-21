#include "inventory.h"


Inventory::Inventory() {}

void Inventory::addItemInInventory(Item item) {
    // Додавання предмету в інвентар
    itemInInventory.push_back(item);
}

void Inventory::deleteItemInInventory(Item item) {
    // Видалення предмету з інвентаря
    for (auto it = itemInInventory.begin(); it != itemInInventory.end(); ++it) {
        if (it->getIndex() == item.getIndex()) {
            itemInInventory.erase(it);
            break;
        }
    }
}

void Inventory::deleteItemEuipment(Item item) {
    // Видалення предмету з обладнання
    for (auto it = itemEquipment.begin(); it != itemEquipment.end(); ++it) {
        if (it->getIndex() == item.getIndex()) {

            itemEquipment.erase(it);
            break;
        }
    }
}

void Inventory::addToEquipment(const Item& item) {
    for (const Item& existingItem : itemEquipment) {
        if (existingItem.getIndex() == item.getIndex()) {
            // Якщо предмет вже є у спорядженні, повертаємося без змін
            return;
        }
    }

    // Якщо предмет не є активним, додаємо його у спорядження та видаляємо з інвентаря
    deleteItemInInventory(item);
    itemEquipment.push_back(item);
}

void Inventory::removeFromEquipment(Item item) {
    // Видалення предмету з обладнання та повернення у інвентар
    for (auto it = itemEquipment.begin(); it != itemEquipment.end(); ++it) {
        if (it->getIndex() == item.getIndex()) {
            itemEquipment.erase(it);
            itemInInventory.push_back(item);
            break;
        }
    }
}

std::vector<Item> Inventory::getItemInInventory() const {
    // Повернення вектора предметів у інвентарі
    return itemInInventory;
}

std::vector<Item> Inventory::getItemEquipment() const {
    // Повернення вектора активного спорядження
    return itemEquipment;
}

size_t Inventory::getItemInInventoryCount() const {
    // Повернення кількості предметів у інвентарі
    return itemInInventory.size();
}

size_t Inventory::getItemInEquipCount() const {
    // Повернення кількості активного спорядження
    return itemEquipment.size();
}

const Item& Inventory::getItemAtIndex(size_t index) const {
    if (index < itemInInventory.size()) {
        // Повернення предмету за вказаним індексом
        return itemInInventory[index];
    }
    // Якщо індекс за межами діапазону, генеруємо помилку
    throw std::out_of_range("Індекс вийшов за межі");
}
const Item& Inventory::getItemAtIndexEquip(size_t index) const{
    if (index < itemEquipment.size()) {
        // Повернення предмету за вказаним індексом
        return itemEquipment[index];
    }
    // Якщо індекс за межами діапазону, генеруємо помилку
    throw std::out_of_range("Індекс вийшов за межі");
}

