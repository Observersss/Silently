#ifndef INVENTORY_H
#define INVENTORY_H
#include "RPGspace/Item/item.h"

#include <QVector>

class Inventory{
public:
    Inventory() = default;

    void addItem(std::shared_ptr<Item> item);
    void removeItem(const std::shared_ptr<Item>& item);

    bool check_if_it_contains(std::shared_ptr<Item> item);

    QVector<std::shared_ptr<Item>> getItems() const;

    size_t getSize() const;

    std::shared_ptr<Item> getItemAtIndex(size_t index) const;
    std::shared_ptr<Item> getItemAtName(const QString& name) const;
private:
    int indexOfItem(const QString& name) const;

    QVector<std::shared_ptr<Item>> items_;
};


#endif // INVENTORY_H
