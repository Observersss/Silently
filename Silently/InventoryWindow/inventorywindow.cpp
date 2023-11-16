#include "inventorywindow.h"
#include "ui_inventorywindow.h"

InventoryWindow::InventoryWindow(QWidget *parent,Inventory originventory):
    QDialog(parent),
    ui(new Ui::InventoryWindow),
    inventory(originventory)
{
    ui->setupUi(this);
    for(auto &item : inventory){
        QString name = QString::fromStdString(item.getnameOfitem());

        //QPixmap image = item.getImageOfItem();

        // Вывод информации о предмете
        ui->listWidget->addItem(name);


        // Отображение изображения предмета
        int w = ui->label->width();
        int h = ui->label->height();
        //ui->label->setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));
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

