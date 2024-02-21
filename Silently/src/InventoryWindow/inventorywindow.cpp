#include "inventorywindow.h"
#include "ui_inventorywindow.h"

InventoryWindow::InventoryWindow(QWidget *parent, Character *playerCharacter) :
    QDialog(parent),
    ui(new Ui::InventoryWindow),
    character(playerCharacter)
{
    ui->setupUi(this);

    std::vector<Item> itemInInventory = character->getInventory().getItemInInventory();
    std::vector<Item> equipItem = character->getInventory().getItemEquipment();
    if (!itemInInventory.empty()) {
        for (auto &item : itemInInventory) {
            QString name = item.getnameOfitem();

            //Вивід назви предмета
            ui->listWidget->addItem(name);
        }
    }

    if (!equipItem.empty()) {
        for (auto &item : equipItem) {
            QString name =item.getnameOfitem();

            //Вивід назви предмета
            ui->Equip_Item->addItem(name);
        }
    }
}

InventoryWindow::~InventoryWindow()
{
    delete ui;
}

void InventoryWindow::showItemDetails(const Item& selectedItem) {
    QString rank = selectedItem.getRank();
    std::vector<std::pair<QString, int>> characteristics = selectedItem.getCharacteristics();
    QPixmap image = selectedItem.getImageOfItem();
    // Встановлення тексту із характеристиками предмета
    if (rank == "D" || rank == "C") {
        ui->Option1->setText(characteristics[0].first + ":  " + QString::number(characteristics[0].second));
        ui->Option2->setText("0");
        ui->Option3->setText("0");
    } else if (rank == "A" || rank == "B") {
        ui->Option1->setText(characteristics[0].first + ":  " + QString::number(characteristics[0].second));
        ui->Option2->setText(characteristics[1].first + ":  " + QString::number(characteristics[1].second));
        ui->Option3->setText("0");
    } else if (rank == "S") {
        ui->Option1->setText(characteristics[0].first + ":  " + QString::number(characteristics[0].second));
        ui->Option2->setText(characteristics[1].first + ":  " + QString::number(characteristics[1].second));
        ui->Option3->setText(characteristics[2].first + ":  " + QString::number(characteristics[2].second));
    }

    // Встановлення зображення предмета
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));
}

void InventoryWindow::on_Equip_Item_itemClicked(QListWidgetItem *item) {
    Inventory inventory = character->getInventory();
    int selectedIndex = ui->Equip_Item->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInEquipCount()) {
        try {
            const Item& selectedItem = inventory.getItemAtIndexEquip(selectedIndex);
            showItemDetails(selectedItem);
        } catch (const std::out_of_range& e) {
            qDebug() << "Error: " << e.what();
        }
    } else {
        qDebug() << "Індекс за межами вектора inventorywindow.cpp/on_Equip_Item_itemClicked";
    }
}

void InventoryWindow::on_listWidget_itemClicked(QListWidgetItem *item) {
    Inventory inventory = character->getInventory();
    int selectedIndex = ui->listWidget->currentRow();

    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInInventoryCount()) {
        try {
            const Item& selectedItem = inventory.getItemAtIndex(selectedIndex);
            showItemDetails(selectedItem);
        } catch (const std::out_of_range& e) {
            qDebug() << "Error: " << e.what();
        }
    } else {
        qDebug() << "Індекс за межами вектора inventorywindow.cpp/on_listWidget_itemClicked";
    }
}


Item InventoryWindow::findItemByName(const QString& itemName, const std::vector<Item>& items) {
    for (const Item& item : items) {
        if (item.getnameOfitem() == itemName) {
            return item;
        }
    }
    return Item();
}

void InventoryWindow::addItemToListWidget(const QString& itemName, QListWidget* listWidget) {
    QListWidgetItem* newItem = new QListWidgetItem(itemName);
    listWidget->addItem(newItem);
}

void InventoryWindow::removeItemFromListWidget(QListWidget* listWidget, int selectedIndex) {
    QListWidgetItem* item = listWidget->takeItem(selectedIndex);
    delete item;
}

void InventoryWindow::on_Equip_clicked() {
     Inventory inventory=character->getInventory();
    int selectedIndex = ui->listWidget->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInInventoryCount()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();
            ui->Equip_Item->addItem(selectedName);

            Item foundItem = findItemByName(selectedName, inventory.getItemInInventory());
            if ((!foundItem.getnameOfitem().isEmpty())) {
                inventory.addToEquipment(foundItem);
                removeItemFromListWidget(ui->listWidget, selectedIndex);
                character->setInventory(inventory);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора inventorywindow.cpp/on_Equip_clicked \n";
    }
}

void InventoryWindow::on_take_off_clicked() {
     Inventory inventory=character->getInventory();

    int selectedIndex = ui->Equip_Item->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInEquipCount()) {
        QListWidgetItem* selectedItemWidget = ui->Equip_Item->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();
            ui->listWidget->addItem(selectedName);

            Item foundItem = findItemByName(selectedName, inventory.getItemEquipment());
            if ((!foundItem.getnameOfitem().isEmpty())) {
                inventory.removeFromEquipment(foundItem);
                removeItemFromListWidget(ui->Equip_Item, selectedIndex);
                character->removeCharacteristicsFromUnequippedItems(foundItem);
                character->setInventory(inventory);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора inventorywindow.cpp/on_take_off_clicked \n";
    }
}

void InventoryWindow::on_Delete_clicked()
{
    Inventory inventory=character->getInventory();

    int selectedIndex = ui->listWidget->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInInventoryCount()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();

            Item foundItem = findItemByName(selectedName, inventory.getItemInInventory());
            if ((!foundItem.getnameOfitem().isEmpty())) {
                inventory.deleteItemInInventory(foundItem);
                removeItemFromListWidget(ui->listWidget, selectedIndex);
                character->setInventory(inventory);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора inventorywindow.cpp/on_Delete_clicked \n";
    }
}

void InventoryWindow::on_Delete_2_clicked()
{
     Inventory inventory=character->getInventory();

    int selectedIndex = ui->Equip_Item->currentRow();
    if (selectedIndex >= 0 && selectedIndex <= inventory.getItemInEquipCount()) {
        QListWidgetItem* selectedItemWidget = ui->Equip_Item->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();
            Item foundItem = findItemByName(selectedName, inventory.getItemInInventory());
            if ((!foundItem.getnameOfitem().isEmpty())) {
                inventory.deleteItemEuipment(foundItem);
                removeItemFromListWidget(ui->listWidget, selectedIndex);
                character->setInventory(inventory);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора inventorywindow.cpp/on_Delete_2_clicked \n";
    }
}



