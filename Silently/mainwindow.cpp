#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Library/library.h"
#include "AddQuest/addquest.h"
#include "ShowInfoQuest/showinfoquest.h"
#include "MoreCharacteristics/morecharacteristics.h"
#include "addTag/addtag.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Оновлення інформації про персонажа
    on_change_space_clicked();
    updateInfoOnQuest();
    updateInfoOnCharacter();


    QPixmap pix(":/icon/img/hamster.jpg");
    int w = ui->character_icon->width();
    int h = ui->character_icon->height();

    ui->character_icon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    //ТЕСТИРОВАНИЕ
    ui->tags_option->setText("+");
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
    std::string titleString = titleName.toStdString(); // перетворили у string
    quest = character.findQuest(titleString); // І передали у функцію findQuest для пошуку по назві

    //Перевірка на quest_eror якщо квест не був знайдений
    if(quest.getTitle()=="0"){
    QMessageBox::warning(this,"Помилка","Квест не знайдено");
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
}

void MainWindow::updateInfoOnQuest(){
    std::vector<Quest> quests = character.getActiveQuest();

    if (!quests.empty()) {
    // Вектор не пустой, можно получить доступ к элементам
    Quest quest = quests.back();
    QString title = QString::fromStdString(quest.getTitle());
    ui->QuestList->addItem(title);

    } /*else {
    QMessageBox::warning(this, "Предупреждение", "Вектор квестов пустой");

    }*/
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

    updateInfoOnCharacter();
}




void MainWindow::on_more_characteristics_clicked()
{
    MoreCharacteristics window(this,character);
    window.show();
    window.exec();
}

/*-----------------------------------------------------------*/


void MainWindow::on_Test1_clicked()
{

    QString title = ui ->TitleNote ->text();
    std::vector<QString> noteTag;

    std::vector<QString> noteText;
    QString text = ui ->TextNote ->toPlainText();
    QStringList lines = text.split(QChar('\n'), Qt::KeepEmptyParts);
    for(const QString& line:lines){
    noteText.push_back(line);

    }

    note.setText(noteText);
    note.setTitle(title);

}


void MainWindow::on_pTest2_clicked()
{
    QString title = note.getTitle();
    std::vector<QString> noteText = note.getText();
    for(const QString& line:noteText){
    ui ->TextNote ->append(line);
    }


}



void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QMessageBox::warning(this,"Помилка","Теги не знайдено");
}






void MainWindow::on_tags_option_clicked()
{
    if(ui->tags_option->text()=="+"){
    AddTag window(this);
    window.show();
    window.exec();
    }
    if(ui->tags_option->text()=="-"){
      deleteTag();
    }
}

void MainWindow::addTag(QString nametag){
    Tag tag(nametag);
    note.addActiveTag(tag);
}

void MainWindow::updateInfoTag(){

    std::vector<Tag> activetags=note.getActiveTag();

    if(!activetags.empty()){

    Tag tag=activetags.back();
    QString tagname=tag.getNameTag();
    ui->listTag->addItem(tagname);

    }
}


void MainWindow::on_listTag_itemClicked(QListWidgetItem *item)
{
    ui->tags_option->setText("-");
}

void MainWindow::deleteTag(){
    std::vector<Tag> activetag=note.getActiveTag();
}

