#include "inventory.h"


// Inventory::Inventory() {}

// void Inventory::addItemInInventory(Item* item) {
//     if(!itemInInventory_.contains(item)){
//         itemInInventory_.push_back(item);
//         return;
//     }
// }

// void Inventory::removeItemFromInventory(Item *item){
//     if(itemInInventory_.contains(item)){
//         itemInInventory_.removeAt(itemInInventory_.indexOf(item));
//         return;
//     }
// }

// void Inventory::addToEquipment(Item* item) {
//     if (!itemEquipment_.contains(item)){
//         itemEquipment_.push_back(item);
//         removeItemFromInventory(item);
//         return;
//     }
// }

// void Inventory::removeFromEquipment(Item* item) {
//     if(itemEquipment_.contains(item)){
//         itemEquipment_.removeAt(itemEquipment_.indexOf(item));
//         return;
//     }
// }

// QVector<Item*> Inventory::getItemsInInventory() const {
//     return itemInInventory_;
// }

// QVector<Item*> Inventory::getItemsEquipment() const {
//     return itemEquipment_;
// }

// size_t Inventory::getItemInInventoryCount() const {
//     return itemInInventory_.size();
// }

// size_t Inventory::getItemInEquipCount() const {
//     return itemEquipment_.size();
// }

// Item* Inventory::getItemAtIndex(size_t index) const {
//     if (index < itemInInventory_.size()) {
//         return itemInInventory_[index];
//     }
//     throw std::out_of_range("Індекс вийшов за межі");
// }
// Item* Inventory::getItemAtIndexEquip(size_t index) const{
//     if (index < itemEquipment_.size()) {
//         return itemEquipment_[index];
//     }
//     throw std::out_of_range("Індекс вийшов за межі");
// }


void Inventory::addItem(std::shared_ptr<Item> item){
    if(!items_.contains(item))
        items_.push_back(item);
}
void Inventory::removeItem(const std::shared_ptr<Item>& item){
    if(items_.contains(item))
        items_.removeAt(items_.indexOf(item));
}

QVector<std::shared_ptr<Item>> Inventory::getItems() const{
    return items_;
}

size_t Inventory::getSize() const{
    if(items_.isEmpty()){
        return 0;
    }

    return items_.size();
}

std::shared_ptr<Item> Inventory::getItemAtIndex(size_t index) const{
    if (index < items_.size()) {
        return items_[index];
    }
    throw std::out_of_range("Index out of range");
}
std::shared_ptr<Item> Inventory::getItemAtName(const QString& name) const{
    int index = indexOfItem(name);
    if (index != -1) {
        return items_[index];
    }
    return nullptr;
}

int Inventory::indexOfItem(const QString& name) const{
    for (size_t i = 0; i < items_.size(); ++i) {
        if (items_[i]->getnameOfitem() == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}


// void Equipment_test::addItemInEquipment(std::shared_ptr<Item> item){
//     if(!itemInEquipment_.contains(item))
//         itemInEquipment_.push_back(item);
// }
// void Equipment_test::removeItemFromEquipment(const std::shared_ptr<Item>& item){
//     if(itemInEquipment_.contains(item))
//         itemInEquipment_.removeAt(itemInEquipment_.indexOf(item));
// }

// QVector<std::shared_ptr<Item>> Equipment_test::getItemsInEquipment() const{
//     return itemInEquipment_;
// }
// size_t Equipment_test::getSizeEquipment() const{
//     if(itemInEquipment_.isEmpty()){
//         return 0;
//     }

//     return itemInEquipment_.size();
// }

// std::shared_ptr<Item> Equipment_test::getItemAtIndex(const size_t& index) const{
//     if(index < itemInEquipment_.size()){
//         return itemInEquipment_[index];
//     }

//     return nullptr;
// }
// std::shared_ptr<Item> Equipment_test::getItemAtName(const QString& name) const{
//     int index = indexOfItem(name);
//     if (index != -1) {
//         return itemInEquipment_[index];
//     }
//     return nullptr;
// }

// int Equipment_test::indexOfItem(const QString& name) const{
//     for (size_t i = 0; i < itemInEquipment_.size(); ++i) {
//         if (itemInEquipment_[i]->getnameOfitem() == name) {
//             return static_cast<int>(i);
//         }
//     }
//     return -1;
// }
