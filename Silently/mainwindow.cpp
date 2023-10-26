#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Library/library.h"
#include "AddQuest/addquest.h"
#include "ShowInfoQuest/showinfoquest.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Оновлення інформації про персонажа
    on_change_space_clicked();
    on_button_update_clicked();



   ui->QuestList->addItem("test");
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
        ui->button_update->show();
        on_button_update_clicked();

    } else
    {
        ui->spaces->setCurrentIndex(1);
        ui->change_space->setText("Go RPG");
        ui->info->setText("Space now: Notes");
        ui->button_update->hide();
    }
}



void MainWindow::on_button_update_clicked()
{
    //Оновлення інформації про характеристики персонажа
    {
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
    std::vector<Quest> quests = character.getActiveQuest();

    if (!quests.empty()) {
    // Вектор не пустой, можно получить доступ к элементам
    Quest quest = quests[0];
    QString title = QString::fromStdString(quest.getTitle());
    ui->QuestList->addItem(title);

    } /*else {
    QMessageBox::warning(this, "Предупреждение", "Вектор квестов пустой");

    }*/

}


void MainWindow::on_AddingQuest_clicked()
{
    AddQuest window(this);
    window.show();
    window.exec();
}


void MainWindow::on_QuestList_itemDoubleClicked(QListWidgetItem *item)
{
    ShowInfoQuest window(this);
    window.show();
    window.exec();
}

