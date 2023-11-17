#include "inventorywindow.h"
#include "ui_inventorywindow.h"

InventoryWindow::InventoryWindow(QWidget *parent,Inventory originventory):
    QDialog(parent),
    ui(new Ui::InventoryWindow),
    inventory(originventory)
{
    ui->setupUi(this);

    std::vector<Item> itemInInventory=inventory.getItemInInventory();
    std::vector<Item> equipItem=inventory.getItemEquipment();
    if(!itemInInventory.empty()){

    for(auto &item : itemInInventory){
        QString name = QString::fromStdString(item.getnameOfitem());
        // Вывод информации о предмете
        ui->listWidget->addItem(name);
    }

    }

    if(!equipItem.empty()){

    for(auto &item : equipItem){
        QString name = QString::fromStdString(item.getnameOfitem());
        // Вывод информации о предмете
        ui->Equip_Item->addItem(name);
    }

    }
}

InventoryWindow::~InventoryWindow()
{
    delete ui;
}

void InventoryWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    // Получаем индекс выбранного элемента
    int selectedIndex = ui->listWidget->currentRow();

    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInInventoryCount()) {
        // Получаем объект Inventory по индексу
        try {
            const Item& selectedItem = inventory.getItemAtIndex(selectedIndex);
            // Используйте selectedItem для выполнения нужных действий с выбранным элементом

            QString rank=QString::fromStdString(selectedItem.getRank());
            ui->Rank->setText(rank);

            std::vector<std::pair<std::string, int>> characteristics = selectedItem.getCharacteristics();

            QPixmap image=selectedItem.getImageOfItem();

            if (rank == "D" || rank == "C") {
                ui->Option1->setText(QString::fromStdString(characteristics[0].first) + ":  " + QString::number(characteristics[0].second));
                ui->Option2->setText("0");
                ui->Option3->setText("0");
            } else if (rank == "A" || rank == "B") {
                ui->Option1->setText(QString::fromStdString(characteristics[0].first) + ":  " + QString::number(characteristics[0].second));
                ui->Option2->setText(QString::fromStdString(characteristics[1].first) + ":  " + QString::number(characteristics[1].second));
                ui->Option3->setText("0");
            } else if (rank == "S") {
                ui->Option1->setText(QString::fromStdString(characteristics[0].first) + ":  " + QString::number(characteristics[0].second));
                ui->Option2->setText(QString::fromStdString(characteristics[1].first) + ":  " + QString::number(characteristics[1].second));
                ui->Option3->setText(QString::fromStdString(characteristics[2].first) + ":  " + QString::number(characteristics[2].second));
            }
            // Отображение изображения предмета
            int w = ui->label->width();
            int h = ui->label->height();
            ui->label->setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));

        } catch (const std::out_of_range& e) {
            // Обработайте ситуацию, когда индекс недопустим
            // Например, выведите сообщение об ошибке
            qDebug() << "Error: " << e.what();
        }

    }
}

Item* InventoryWindow::findItemByName(const QString& itemName, const std::vector<Item>& items) {
//    for (size_t i = 0; i < items.size(); ++i) {
//        if (QString::fromStdString(items[i].getnameOfitem()) == itemName) {
//            std::cout<<"1\n";
//            return const_cast<Item*>(&items[i]);
//        }
//    }
//    return nullptr;

    for (const Item& item : items) {
        if (QString::fromStdString(item.getnameOfitem()) == itemName) {
            std::cout << "1\n";
            return item; // Возвращаем копию объекта Item
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
    int selectedIndex = ui->listWidget->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInInventoryCount()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();
            ui->Equip_Item->addItem(selectedName);

            Item* foundItem = findItemByName(selectedName, inventory.getItemInInventory());
            std::cout<<foundItem->getnameOfitem();
            if (foundItem) {
                inventory.addToEquipment(*foundItem);
                removeItemFromListWidget(ui->listWidget, selectedIndex);
            }
        }
    }
}

void InventoryWindow::on_take_off_clicked() {
    int selectedIndex = ui->Equip_Item->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInEquipCount()) {
        QListWidgetItem* selectedItemWidget = ui->Equip_Item->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();
            ui->listWidget->addItem(selectedName);

            Item* foundItem = findItemByName(selectedName, inventory.getItemEquipment());
            std::cout<<"2\n";
            if (foundItem) {
                std::cout<<"3\n";
                inventory.removeFromEquipment(*foundItem);
                removeItemFromListWidget(ui->Equip_Item, selectedIndex);
            }
        }
    }
}

void InventoryWindow::on_Delete_clicked() {
    int selectedIndex = ui->listWidget->currentRow();
    if (selectedIndex >= 0 && selectedIndex < inventory.getItemInInventoryCount()) {
        QListWidgetItem* selectedItemWidget = ui->listWidget->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();

            Item* foundItem = findItemByName(selectedName, inventory.getItemInInventory());
            if (foundItem) {
                inventory.deleteItemInInventory(*foundItem);
                removeItemFromListWidget(ui->listWidget, selectedIndex);
            }
        }
    }
}

void InventoryWindow::on_Delete_2_clicked() {
    int selectedIndex = ui->Equip_Item->currentRow();
    if (selectedIndex >= 0 && selectedIndex <= inventory.getItemInEquipCount()) {
        QListWidgetItem* selectedItemWidget = ui->Equip_Item->item(selectedIndex);
        if (selectedItemWidget) {
            QString selectedName = selectedItemWidget->text();

            Item* foundItem = findItemByName(selectedName, inventory.getItemEquipment());
            if (foundItem) {
                inventory.removeFromEquipment(*foundItem);
                removeItemFromListWidget(ui->Equip_Item, selectedIndex);
            }
        }
    }
}
