#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Library/library.h"
#include "AddQuest/addquest.h"
#include "ShowInfoQuest/showinfoquest.h"
#include "MoreCharacteristics/morecharacteristics.h"
#include "InventoryWindow/inventorywindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Оновлення інформації про персонажа
    on_change_space_clicked();
    updateInfoOnQuest();
    updateInfoOnCharacter();


    QPixmap pix(":/icon/img/Character.jpg");
    int w = ui->character_icon->width();
    int h = ui->character_icon->height();

    ui->character_icon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    //ТЕСТИРОВАНИЕ
    Item item;
    character.addItemToInventory(item);
    //ТЕСТИРОВАНИЕ
}
void MainWindow::addActiveQuest(Quest* quest){
    character.addActiveQuest(quest);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_change_space_clicked()
{
    if(ui->spaces->currentIndex()==1)
    {
        ui->spaces->setCurrentIndex(0);
        ui->change_space->setText("Go Notes");
        ui->info->setText("Space now: RPG");
        updateInfoOnQuest();
        updateInfoOnCharacter();

    } else
    {
        ui->spaces->setCurrentIndex(1);
        ui->change_space->setText("Go RPG");
        ui->info->setText("Space now: Notes");
    }
}


void MainWindow::on_AddingQuest_clicked()
{
    AddQuest window(this);
    window.show();
    window.exec();
}


void MainWindow::on_QuestList_itemDoubleClicked(QListWidgetItem *item)
{
    QString titleName = item->text(); // Отримали назву квесту
    quest = character.findQuest(titleName); // І передали у функцію findQuest для пошуку по назві

    //Перевірка на quest_eror якщо квест не був знайдений
    if(quest.getTitle()=="0"){
//    QMessageBox::warning(this,"Помилка","Квест не знайдено");
    qDebug() << "Квест не знайдено mainwindow.cpp/on_QuestList_itemDoubleClicked";
    }
    else{
    //Якщо перевірку пройдено запускається нове вікно ShowInfoQuest
    ShowInfoQuest window(this,quest);


    window.show();
    window.exec();
    }

}

void MainWindow::updateInfoOnCharacter(){
    //Оновлення інформації про характеристики персонажа

    int health = character.getHealth();
    QString healthText = QString("Здоровье: %1").arg(health);
    ui->HealthLabel->setText(healthText);

    int mana = character.getMana();
    QString manatext = QString("Мана: %1").arg(mana);
    ui->ManaLabel->setText(manatext);

    int level = character.getLevel();
    QString levelText =QString("Рівень: %1").arg(level);
    ui->LevelLabel->setText(levelText);

    int experience = character.getExperience();
    QString experinceText =QString("Досвід: %1").arg(experience);
    ui->ExperienceLabel->setText(experinceText);

}

void MainWindow::updateInfoOnQuest(){
    std::vector<Quest> quests = character.getActiveQuest();

    if (!quests.empty()) {
    //Вектор не пустий, можна отримати доступ до елементів
    Quest quest = quests.back();
    QString title = quest.getTitle();
    ui->QuestList->addItem(title);

    } else {
    qDebug() << "Вектора квестів пустий mainwindow.cpp/updateInfoOnQuest";
    }
}

void MainWindow::handleQuestInfoClosed() {
    int indexToRemove = ui->QuestList->currentRow();
    if (indexToRemove >= 0) {
    QListWidgetItem* item = ui->QuestList->takeItem(indexToRemove);
    delete item;
    }
}

void MainWindow::deleteQuest(){
    character.deleteActiveQuest(quest);
}

void MainWindow::questComplete(){
    int levelNow= character.getLevel();
    character.increaseExperience();
    int levelAfter= character.getLevel();

    if(levelNow<levelAfter){
    QMessageBox::information(this,"New level","New Level");
    }


    //Налаштування псевдо генератора випадкових чисел
    QRandomGenerator randomGenerator(static_cast<quint32>(std::time(nullptr)));

    //Генерація випадкового числа від 0 до 99
    int randomNumber = randomGenerator.bounded(100);

    //Перевірка на виконання функції з 30% вірогідністю(від 0 до 19)
    if (randomNumber < 20) {
    Item item;
    QMessageBox::information(this,"New Item","You find new Item");
    character.addItemToInventory(item);
    }

    updateInfoOnCharacter();
}






void MainWindow::on_more_characteristics_clicked()
{
    MoreCharacteristics window(this,character);
    window.show();
    window.exec();
}


void MainWindow::on_Open_inventory_clicked()
{
    InventoryWindow window(this,&character);
    window.show();
    window.exec();
    Inventory inventory=character.getInventory();

    // После закрытия окна обновите экипировку персонажа
    updateCharacterEquipment(inventory.getItemEquipment());
    updateInfoOnCharacter();
}

void MainWindow::updateCharacterEquipment(const std::vector<Item>& equipment) {
    character.updateCharacteristicsFromInventory(); // Подобная функция должна быть в классе Character
    // Обновите представление персонажа в соответствии с изменениями
}

