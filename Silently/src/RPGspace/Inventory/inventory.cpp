#include "inventory.h"


Inventory::Inventory() {}

void Inventory::addItemInInventory(Item* item) {
    if(itemInInventory_.contains(item))
        return;

    itemInInventory_.push_back(item);
}

void Inventory::removeItemFromInventory(Item *item){
    if(itemInInventory_.contains(item))
        itemInInventory_.removeAt(itemInInventory_.indexOf(item));
        return;
}

void Inventory::deleteItemFromInventory(Item* item) {
    itemInInventory_.removeAt(itemInInventory_.indexOf(item));
}

void Inventory::addToEquipment(Item* item) {
    if (itemEquipment_.contains(item))
        return;

    itemEquipment_.push_back(item);
    removeItemFromInventory(item);
}

void Inventory::removeFromEquipment(Item* item) {
    if(itemEquipment_.contains(item)){
        itemEquipment_.removeAt(itemEquipment_.indexOf(item));
        return;
    }
}

QVector<Item*> Inventory::getItemInInventory() const {
    return itemInInventory_;
}

QVector<Item*> Inventory::getItemEquipment() const {
    return itemEquipment_;
}

size_t Inventory::getItemInInventoryCount() const {
    return itemInInventory_.size();
}

size_t Inventory::getItemInEquipCount() const {
    return itemEquipment_.size();
}

Item* Inventory::getItemAtIndex(size_t index) const {
    if (index < itemInInventory_.size()) {
        return itemInInventory_[index];
    }
    throw std::out_of_range("Індекс вийшов за межі");
}
Item* Inventory::getItemAtIndexEquip(size_t index) const{
    if (index < itemEquipment_.size()) {
        return itemEquipment_[index];
    }
    throw std::out_of_range("Індекс вийшов за межі");
}

