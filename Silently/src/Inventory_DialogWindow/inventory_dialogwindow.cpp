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


    if(character->getInventory()->getSize() > 0){
        foreach(std::shared_ptr<Item> item , character->getInventory()->getItems()){
            ui->listWidget_Inventory_Items->addItem(item->getnameOfitem());
        };
    }
    if(character->getEquipment()->getSize() > 0){
        foreach(std::shared_ptr<Item> item , character->getEquipment()->getItems()){
            ui->listWidget_Equip_Items->addItem(item->getnameOfitem());
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

void Inventory_DialogWindow::showItemDetails(std::shared_ptr<Item> selectedItem) {

    ui->Rank->setText(selectedItem->getRank());
    std::map<QString, int> characteristics = selectedItem->getCharacteristics();
    QPixmap image(selectedItem->getPathToImg());

    QLabel* optionLabels[] = { ui->Option1, ui->Option2, ui->Option3 };


    for (QLabel* label : optionLabels) {
        label->setText("0");
    }

    int i = 0;
    for (const auto& characteristic : characteristics) {
        if (i >= 3) break;
        optionLabels[i]->setText(characteristic.first + ": " + QString::number(characteristic.second));
        ++i;
    }

    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));

}

void Inventory_DialogWindow::removeItemFromListWidget(QListWidget* listWidget, int selectedIndex) {
    QListWidgetItem* item = listWidget->takeItem(selectedIndex);
    delete item;
}


void Inventory_DialogWindow::on_listWidget_Inventory_Items_itemClicked(QListWidgetItem *item)
{

    int selectedIndex = ui->listWidget_Inventory_Items->currentRow();
    if (selectedIndex >= 0 && selectedIndex < character->getInventory()->getSize()) {
        try {
            std::shared_ptr<Item> selectedItem = character->getInventory()->getItemAtIndex(selectedIndex);
            showItemDetails(selectedItem);
        } catch (const std::out_of_range& e) {
            qDebug() << "Error: " << e.what();
        }
    } else {
        qDebug() << "Індекс за межами вектора Inventory_DialogWindow.cpp/on_listWidget_itemClicked";
    }

}


void Inventory_DialogWindow::on_listWidget_Equip_Items_itemClicked(QListWidgetItem *item)
{
    int selectedIndex = ui->listWidget_Equip_Items->currentRow();
    if (selectedIndex >= 0 && selectedIndex < character->getEquipment()->getSize()) {
        try {
            std::shared_ptr<Item> selectedItem = character->getEquipment()->getItemAtIndex(selectedIndex);
            showItemDetails(selectedItem);
        } catch (const std::out_of_range& e) {
            qDebug() << "Error: " << e.what();
        }
    } else {
        qDebug() << "Індекс за межами вектора Inventory_DialogWindow.cpp/on_listWidget_itemClicked";
    }
}


void Inventory_DialogWindow::on_pushButton_Equip_current_item_clicked()
{
    Inventory* inventory=character->getInventory();
    int selectedIndex = ui->listWidget_Inventory_Items->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory->getSize()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget_Inventory_Items->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();

            std::shared_ptr<Item> foundItem = inventory->getItemAtName(selectedName);

            if(!EquipmentAddToEquipment(foundItem->getTypeItem())){
                QMessageBox::warning(this,"Error","Cannot add this item to inventory");
                return;
            }

            ui->listWidget_Equip_Items->addItem(selectedName);
            if ((!foundItem->getnameOfitem().isEmpty())) {
                character->addItemToEquipment(foundItem);
                removeItemFromListWidget(ui->listWidget_Inventory_Items, selectedIndex);
                EquipmentAddToEquipment(foundItem->getTypeItem());
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора Inventory_DialogWindow.cpp/on_Equip_clicked \n";
    }
}


void Inventory_DialogWindow::on_pushButton_take_off_current_item_clicked()
{
    Inventory* equipment=character->getEquipment();

    int selectedIndex = ui->listWidget_Equip_Items->currentRow();
    if (selectedIndex >= 0 && selectedIndex < equipment->getSize()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget_Equip_Items->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();

            std::shared_ptr<Item> foundItem = equipment->getItemAtName(selectedName);
            if(!EquipmentRemoveFromEquipment(foundItem->getTypeItem())){
                QMessageBox::warning(this,"Error","Cannot add this item to inventory");
                return;
            }
            ui->listWidget_Inventory_Items->addItem(selectedName);
            if ((!foundItem->getnameOfitem().isEmpty())) {
                character->removeItemFromEquipment(foundItem);
                removeItemFromListWidget(ui->listWidget_Equip_Items, selectedIndex);
                EquipmentRemoveFromEquipment(foundItem->getTypeItem());
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора Inventory_DialogWindow.cpp/on_take_off_clicked \n";
    }
}


void Inventory_DialogWindow::on_pushButton_delete_current_Item_clicked()
{
    Inventory* inventory=character->getInventory();

    int selectedIndex = ui->listWidget_Inventory_Items->currentRow();
    if (selectedIndex >= 0 && selectedIndex <= inventory->getSize()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget_Inventory_Items->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();
            std::shared_ptr<Item> foundItem = inventory->getItemAtName(selectedName);
            if ((!foundItem->getnameOfitem().isEmpty())) {
                inventory->removeItem(foundItem);
                removeItemFromListWidget(ui->listWidget_Inventory_Items, selectedIndex);
            }
        }
    }else{
        qDebug()<<"Індекс за межами вектора Inventory_DialogWindow.cpp/on_Delete_2_clicked \n";
    }
}

