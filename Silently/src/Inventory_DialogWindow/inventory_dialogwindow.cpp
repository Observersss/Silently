#include "inventory_dialogwindow.h"
#include "ui_inventory_dialogwindow.h"

#include <QMessageBox>
Inventory_DialogWindow::Inventory_DialogWindow(QWidget *parent, Character *playerCharacter) :
    QDialog(parent),
    ui(new Ui::Inventory_DialogWindow),
    character(playerCharacter)
{
    ui->setupUi(this);

    typeCount[WEAPON] = 2;
    typeCount[PETS] = 2;
    typeCount[HELMET] = 1;
    typeCount[LEGGINGS] = 1;
    typeCount[BOOTS] = 1;
    typeCount[CHESTPLATE] = 1;
    typeCount[RING] = 1;
    typeCount[GLOVES] = 1;
    typeCount[ANOTHER] = 3;

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

bool Inventory_DialogWindow::checkTypeCount(Equipment equipment){
    auto it = typeCount.find(equipment);

    if(it==typeCount.end()){
        qDebug()<<"Equipment type:"<<equipment<<" not found \n";
        return false;
    }
    return true;
}
bool Inventory_DialogWindow::EquipmentAddToEquipment(Equipment equipment){
    if(!checkTypeCount(equipment)){
        return false;
    }

    auto it = typeCount.find(equipment);
    qDebug()<<"Emum: "<<equipment<<" find enum: "<< it->second <<'\n';
    if(it->second == 0){
        qDebug()<<"Cannot add quipment to active inventory \n";
        return false;
    }else{
    it->second -= 1;
        return true;
    }
}
bool Inventory_DialogWindow::EquipmentRemoveFromEquipment(Equipment equipment){
    if(!checkTypeCount(equipment)){
        return false;
    }

    auto it = typeCount.find(equipment);

    it->second += 1;

    return true;
}

Inventory_DialogWindow::~Inventory_DialogWindow()
{
    delete ui;
}

void Inventory_DialogWindow::showItemDetails(const Item& selectedItem) {
    QString rank = selectedItem.getRank();
    ui->Rank->setText(rank);
    std::vector<std::pair<QString, int>> characteristics = selectedItem.getCharacteristics();
    QPixmap image(selectedItem.getPathToImg());
    // Встановлення тексту із характеристиками предмета
    ui->Option1->setText("0");
    ui->Option2->setText("0");
    ui->Option3->setText("0");
    if (characteristics.size() >= 1) {
        ui->Option1->setText(characteristics[0].first + ":  " + QString::number(characteristics[0].second));
    }
    if (characteristics.size() >= 2) {
        ui->Option2->setText(characteristics[1].first + ":  " + QString::number(characteristics[1].second));
    }
    if (characteristics.size() >= 3) {
        ui->Option3->setText(characteristics[2].first + ":  " + QString::number(characteristics[2].second));
    }


    // Встановлення зображення предмета
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));
}

void Inventory_DialogWindow::on_Equip_Item_itemClicked(QListWidgetItem *item) {
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
        qDebug() << "Індекс за межами вектора Inventory_DialogWindow.cpp/on_Equip_Item_itemClicked";
    }
}

void Inventory_DialogWindow::on_listWidget_itemClicked(QListWidgetItem *item) {
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
        qDebug() << "Індекс за межами вектора Inventory_DialogWindow.cpp/on_listWidget_itemClicked";
    }
}


Item Inventory_DialogWindow::findItemByName(const QString& itemName, const std::vector<Item>& items) {
    for (const Item& item : items) {
        if (item.getnameOfitem() == itemName) {
            return item;
        }
    }
    return Item();
}

void Inventory_DialogWindow::addItemToListWidget(const QString& itemName, QListWidget* listWidget) {
    QListWidgetItem* newItem = new QListWidgetItem(itemName);
    listWidget->addItem(newItem);
}

void Inventory_DialogWindow::removeItemFromListWidget(QListWidget* listWidget, int selectedIndex) {
    QListWidgetItem* item = listWidget->takeItem(selectedIndex);
    delete item;
}

void Inventory_DialogWindow::on_Equip_clicked() {
    Inventory inventory=character->getInventory();
    int selectedIndex = ui->listWidget->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInInventoryCount()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();

            Item foundItem = findItemByName(selectedName, inventory.getItemInInventory());

            if(!EquipmentAddToEquipment(foundItem.getTypeItem())){
                QMessageBox::warning(this,"Error","Cannot add this item to inventory");
                return;
            }

            ui->Equip_Item->addItem(selectedName);
            if ((!foundItem.getnameOfitem().isEmpty())) {
                inventory.addToEquipment(foundItem);
                removeItemFromListWidget(ui->listWidget, selectedIndex);
                character->setInventory(inventory);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора Inventory_DialogWindow.cpp/on_Equip_clicked \n";
    }
}

void Inventory_DialogWindow::on_take_off_clicked() {
    Inventory inventory=character->getInventory();

    int selectedIndex = ui->Equip_Item->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInEquipCount()) {
        QListWidgetItem* selectedItemWidget = ui->Equip_Item->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();

            Item foundItem = findItemByName(selectedName, inventory.getItemEquipment());
            if(!EquipmentRemoveFromEquipment(foundItem.getTypeItem())){
                QMessageBox::warning(this,"Error","Cannot add this item to inventory");
                return;
            }
            ui->listWidget->addItem(selectedName);
            if ((!foundItem.getnameOfitem().isEmpty())) {
                inventory.removeFromEquipment(foundItem);
                removeItemFromListWidget(ui->Equip_Item, selectedIndex);
                character->removeCharacteristicsFromUnequippedItems(foundItem);
                character->setInventory(inventory);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора Inventory_DialogWindow.cpp/on_take_off_clicked \n";
    }
}

void Inventory_DialogWindow::on_Delete_clicked()
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
        qDebug()<<"Індекс за межами вектора Inventory_DialogWindow.cpp/on_Delete_clicked \n";
    }
}

void Inventory_DialogWindow::on_Delete_2_clicked()
{
    Inventory inventory=character->getInventory();

    int selectedIndex = ui->Equip_Item->currentRow();
    if (selectedIndex >= 0 && selectedIndex <= inventory.getItemInEquipCount()) {
        QListWidgetItem* selectedItemWidget = ui->Equip_Item->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();
            Item foundItem = findItemByName(selectedName, inventory.getItemInInventory());
            if ((!foundItem.getnameOfitem().isEmpty())) {
                if(!EquipmentRemoveFromEquipment(foundItem.getTypeItem())){
                    QMessageBox::warning(this,"Error","Cannot add this item to inventory");
                    return;
                }
                inventory.deleteItemEuipment(foundItem);
                removeItemFromListWidget(ui->listWidget, selectedIndex);
                character->setInventory(inventory);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора Inventory_DialogWindow.cpp/on_Delete_2_clicked \n";
    }
}

