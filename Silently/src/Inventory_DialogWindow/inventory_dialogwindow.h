#ifndef INVENTORY_DIALOGWINDOW_H
#define INVENTORY_DIALOGWINDOW_H

#include <QDialog>
#include "mainwindow.h"

#include "RPGspace/Inventory/inventory.h"
#include "RPGspace/Item/item.h"

namespace Ui {
class Inventory_DialogWindow;
}

class Inventory_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Inventory_DialogWindow(QWidget *parent = nullptr, Character *playerCharacter = nullptr);

    void showItemDetails(const Item& selectedItem);

    bool checkTypeCount(Equipment equipment);
    bool EquipmentAddToEquipment(Equipment equipment);
    bool EquipmentRemoveFromEquipment(Equipment equipment);

    ~Inventory_DialogWindow();
private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_Equip_clicked();
    void on_take_off_clicked();
    void on_Delete_clicked();
    void on_Delete_2_clicked();

    void on_Equip_Item_itemClicked(QListWidgetItem *item);

private:
    Ui::Inventory_DialogWindow *ui;
    Character *character;
    std::map<Equipment,int> typeCount;

    void addItemToListWidget(const QString &itemName, QListWidget *listWidget);
    void removeItemFromListWidget(QListWidget *listWidget, int selectedIndex);
    Item findItemByName(const QString &itemName, const std::vector<Item> &items);
    void updateCharacterFromInventory();
    void removeCharacteristicsFromItems(const std::vector<Item> &items);
};

#endif // INVENTORY_DIALOGWINDOW_H
