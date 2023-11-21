#ifndef INVENTORYWINDOW_H
#define INVENTORYWINDOW_H
#include <QDialog>
#include "mainwindow.h"

#include "RPGspace/Inventory/inventory.h"
#include "RPGspace/Item/item.h"


namespace Ui {
class InventoryWindow;
}

class InventoryWindow : public QDialog {
    Q_OBJECT

public:
    explicit InventoryWindow(QWidget *parent = nullptr, Character *playerCharacter = nullptr);
    ~InventoryWindow();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_Equip_clicked();
    void on_take_off_clicked();
    void on_Delete_clicked();
    void on_Delete_2_clicked();

private:
    Ui::InventoryWindow *ui;
    Character *character;

    void addItemToListWidget(const QString &itemName, QListWidget *listWidget);
    void removeItemFromListWidget(QListWidget *listWidget, int selectedIndex);
    Item findItemByName(const QString &itemName, const std::vector<Item> &items);
    void updateCharacterFromInventory();
    void removeCharacteristicsFromItems(const std::vector<Item> &items);
};




#endif // INVENTORYWINDOW_H
