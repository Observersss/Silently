#include "inventory.h"

void Inventory::addItem(std::shared_ptr<Item> item){
    if(!items_.contains(item))
        items_.push_back(item);
}
void Inventory::removeItem(const std::shared_ptr<Item>& item){
    if(items_.contains(item))
        items_.removeAt(items_.indexOf(item));
}

bool Inventory::check_if_it_contains(std::shared_ptr<Item> item){
    return items_.contains(item);
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
