#ifndef INVENTORYWINDOW_H
#define INVENTORYWINDOW_H
#include <QDialog>
#include "mainwindow.h"

#include "RPGspace/Inventory/inventory.h"
#include "RPGspace/Item/item.h"


namespace Ui {
class InventoryWindow;
}

class InventoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryWindow(QWidget *parent = nullptr,Inventory originventory=Inventory());
    ~InventoryWindow();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::InventoryWindow *ui;
    Inventory inventory;
};

#endif // INVENTORYWINDOW_H
