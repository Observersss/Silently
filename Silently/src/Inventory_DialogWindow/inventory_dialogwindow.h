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

    void showItemDetails(std::shared_ptr<Item> selectedItem);

    bool checkTypeCount(Equipment equipment);
    bool EquipmentAddToEquipment(Equipment equipment);
    bool EquipmentRemoveFromEquipment(Equipment equipment);

    ~Inventory_DialogWindow();
private slots:

    void on_listWidget_Inventory_Items_itemClicked(QListWidgetItem *item);

    void on_listWidget_Equip_Items_itemClicked(QListWidgetItem *item);

    void on_pushButton_Equip_current_item_clicked();

    void on_pushButton_take_off_current_item_clicked();

    void on_pushButton_delete_current_Item_clicked();

private:
    Ui::Inventory_DialogWindow *ui;
    Character *character;
    std::map<Equipment,int> typeCount;

    void addItemToListWidget(const QString &itemName, QListWidget *listWidget);
    void removeItemFromListWidget(QListWidget *listWidget, int selectedIndex);
    Item* findItemByName(const QString &itemName, const QVector<Item*>& items);
    void updateCharacterFromInventory();
    void removeCharacteristicsFromItems(const std::vector<Item> &items);
};

#endif // INVENTORY_DIALOGWINDOW_H
