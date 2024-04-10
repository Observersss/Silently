#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <sstream>
#include <iomanip>
#include <QMessageBox>
#include <QRandomGenerator>

#include "addQuest_DialogWindow/addQuest_DialogWindow.h"
#include "ShowInfoQuest_DialogWindow/ShowInfoQuest_DialogWindow.h"
#include "MoreCharacteristics_DialogWindow/MoreCharacteristics_DialogWindow.h"
#include "Inventory_DialogWindow/Inventory_DialogWindow.h"
#include "AddTag_DialogWindow/AddTag_dialogwindow.h"
#include "AddNoteSpace_DialogWindow/addnotespace_dialogwindow.h"

#include "NOTEspace/CustomLineEditManager/customlineeditmanager.h"
int MainWindow::noteCounter=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    on_change_space_clicked();
    updateInfoOnQuest();
    updateInfoOnCharacter();


    QPixmap pix(":/icon/img/Character.jpg");
    int w = ui->character_icon->width();
    int h = ui->character_icon->height();

    ui->character_icon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //ТЕСТИРОВАНИЕ
    ui->tags_option->setText("+");
    NoteService noteService;
    Note *firstNote=noteService.getFirstNote();
    //noteService.addNewElementToNameNoteAndNoteID(firstNote->getTitle(),firstNote->getIdNote());
    noteSpaces.push_back(noteService);


    bufferNoteId=firstNote->getIdNote();
    bufferNoteSpace = noteService.getNameSpaceNote();

    QString title=firstNote->getTitle()/*"Your first note"*/;
    ui->listNote->addItem(title);
    //QDateTime data_time=firstNote->getDataTime();

    QString nameSpaceNote=noteService.getNameSpaceNote();
    ui->NoteSpaces->addItem(nameSpaceNote);
    // Установка строки в QLabel
    //ui->date_create_note->setText(data_time.toString("dd.MM.yyyy hh:mm:ss"));
    ui->date_create_note->setStyleSheet("QLabel { padding-top: 10px; font-size:11px; }");


    //unloadInfoNote();
    //////////////////////////////////////////////
    //NameNoteAndNoteID.push_back(std::pair(firstNote.getTitle(),firstNote.getIdNote()));
    /////////////////////////////////////////////////
    //ТЕСТИРОВАНИЕ
    //int newIndex = ui->listNote->count() - 1;

    // Устанавливаем текущий элемент в список по его индексу
    //ui->listNote->setCurrentRow(newIndex);
    //uploadInfoNote(ui->listNote->currentItem());

    CustomLineEditManager* manager = CustomLineEditManager::getInstance(this);
    manager->setLayoutAndScroolArea(ui->verticalLayout_for_CustomLineEditManager, ui->scrollArea_for_CustomLineEdit);
    //manager->create_CustomLineEdit();


    connect(ui->listNote,&QListWidget::currentItemChanged,this, [this](QListWidgetItem *current, QListWidgetItem *previous){
        if(previous)
            saveInfoNote(previous);

        uploadInfoNote(current);
    });
}

void MainWindow::checkQuestDeadlinePassed() {
    qDebug() << "Checking quest deadlines...";

    // Получаем текущее время
    QDateTime  currentTime = QDateTime::currentDateTime();
    qDebug() << "Current time: " << currentTime.toString("dd.MM.yyy hh:mm");

    // Проверяем, достигнут ли дедлайн квеста
    for(Quest& quest : character.getActiveQuest()){
        //Випадково змінила тут вибач
        // QDateTime  deadline = quest.getDeadline();
        // qDebug() << "Quest deadline: " << deadline.toString("dd.MM.yyy hh:mm");;

        // if (currentTime >= deadline) {
        //     qDebug() << "Deadline passed!";
        //     QMessageBox::warning(this, "Quest Deadline Passed", "The deadline for the quest '" + quest.getTitle() + "' has passed.");
        //     character.deleteActiveQuest(quest);
        //     // Действия по обработке прошедшего дедлайна квеста

        //     QString title ="ID:"+QString::number(quest.getId())+" " + quest.getTitle();
        //     for (int i = 0; i < ui->QuestList->count(); ++i) {
        //         QListWidgetItem *item = ui->QuestList->item(i);
        //         if (item->text() == title) {
        //             delete ui->QuestList->takeItem(i);
        //             break;
        //         }
        //     }
        // }
    }
    // Повторно вызываем эту же функцию через минуту
    QTimer::singleShot(60 * 1000, this, &MainWindow::checkQuestDeadlinePassed);
}


void MainWindow::addActiveQuest(Quest* quest){
    character.addActiveQuest(quest);
    checkQuestDeadlinePassed();
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
        ui->stackedWidget->setCurrentIndex(1);

    } else
    {
        ui->spaces->setCurrentIndex(1);
        ui->change_space->setText("Go RPG");
        ui->info->setText("Space now: Notes");
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_AddingQuest_clicked()
{
    addQuest_DialogWindow window(this);

    window.exec();
}

void MainWindow::on_QuestList_itemDoubleClicked(QListWidgetItem *item)
{
    QString titleName = item->text();
    int startIndex = titleName.indexOf(":") + 1;
    int endIndex = titleName.indexOf(" ", startIndex);

    if (startIndex != -1 && endIndex != -1) {
        QString idString = titleName.mid(startIndex, endIndex - startIndex);
        bool conversionOK;
        int id = idString.toInt(&conversionOK);

        if (conversionOK) {
            qDebug() << "ID:" << id;
            Quest quest = character.findQuest(id);

            if (quest.getTitle() == "0") {
                qDebug() << "Квест не найден в mainwindow.cpp/on_QuestList_itemDoubleClicked";
            } else {
                ShowInfoQuest_DialogWindow window(this, quest);
                window.exec();
            }
        } else {
            qDebug() << "Не удалось преобразовать в числовой ID";
        }
    } else {
        qDebug() << "Строка не содержит ID в ожидаемом формате";
    }
}




void MainWindow::updateInfoOnCharacter(){

    int health = character.getHealth();
    QString healthText = QString("Health: %1").arg(health);
    ui->HealthLabel->setText(healthText);

    int mana = character.getMana();
    QString manatext = QString("Mana: %1").arg(mana);
    ui->ManaLabel->setText(manatext);

    int level = character.getLevel();
    QString levelText =QString("Level: %1").arg(level);
    ui->LevelLabel->setText(levelText);

    int experience = character.getExperience();
    QString experinceText =QString("Exp: %1").arg(experience);
    ui->ExperienceLabel->setText(experinceText);

}

void MainWindow::updateInfoOnQuest(){
    std::vector<Quest> quests = character.getActiveQuest();

    if (!quests.empty()) {
    //Вектор не пустий, можна отримати доступ до елементів
    Quest quest = quests.back();
    QString title ="ID:"+QString::number(quest.getId())+" " + quest.getTitle();
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
    character.setExperience();
    int levelAfter= character.getLevel();

    if(levelNow<levelAfter){
    QMessageBox::information(this,"New level","New Level");
        showUpdateCharacteristics = true;
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
    // showUpdateCharacteristics = true;
    MoreCharacteristics_DialogWindow window(this,&character,showUpdateCharacteristics);

    window.exec();

    if(showUpdateCharacteristics){
        updateInfoOnCharacter();
    }
}

void MainWindow::on_Open_inventory_clicked()
{
    Inventory_DialogWindow window(this,&character);

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
/*-----------------------------------------------------------*/

void MainWindow::on_tags_option_clicked()
{
    if (ui->tags_option->text() == "+") {
        std::vector<Tag>tags = returnNoteServicePtr()->getAllTags();
        AddTag_DialogWindow window(this,&tags);

    window.exec();
    }
    else if (ui->tags_option->text() == "-") {
    Note *note = returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()));
    if (note->getTitle().isEmpty()) {
        return;
        qDebug()<<"Заголовок заметки пустой mainwindow.h/on_tags_option_clicked";
    }
   }

}



void MainWindow::on_listTag_itemClicked(QListWidgetItem *item)
{
   ui->tags_option->setText("-");
}

NoteService MainWindow::returnNoteService(){
    QString nameNoteService=ui->NoteSpaces->currentText();
    for (const NoteService& value : noteSpaces) {
    if (value.getNameSpaceNote() == nameNoteService)
        return value;
    }
    NoteService noteSpace_eror;
    noteSpace_eror.setNameSpaceNote(nullptr);
    return noteSpace_eror;
}

NoteService* MainWindow::returnNoteServicePtr() {
    QString nameNoteService = ui->NoteSpaces->currentText();
    for (NoteService& value : noteSpaces) {
    if (value.getNameSpaceNote() == nameNoteService) {
        return &value;
    }
    }
    return nullptr;
}
NoteService* MainWindow::returnNoteServicePtr(QString text){
    for(NoteService& value : noteSpaces){
        if(text == value.getNameSpaceNote()){
            return &value;
        }
    }
    return nullptr;
}

void MainWindow::addNewNoteToList(QString nameNote){
    ui->listNote->addItem(nameNote);
}

void MainWindow::addTag(QString name,bool needAddToAllTags) {

    if (ui->listNote->currentItem() == nullptr) {
    std::cout<<"Проблема \n";
    return;
    }

    QString title = ui->listNote->currentItem()->text();

    Note *note = returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(title));
    note->addActiveTag(name);
    if(needAddToAllTags){
    returnNoteServicePtr()->addToAllTag(name);
    }
}


void MainWindow::updateInfoTag() {
    ui->listTag->clear();
    QVector<Tag> tags=returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()))->getActiveTag();
    if(!tags.isEmpty()){
        for(const Tag& tag:tags){
            ui->listTag->addItem(tag.getNameTag());
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    NoteService *noteService=returnNoteServicePtr();
    if(noteService==nullptr){
       return;
    } else{
    Note note;
    QString nameNote="Your new Note"+QString::number(noteCounter);
    noteCounter+=1;
    note.setTitle(nameNote);

    addNewNoteToList(nameNote);

    noteService->addNote(note);
    noteService->addNewElementToNameNoteAndNoteID(note.getTitle(),note.getIdNote());
    //qDebug()<<"ID только что созданой заметки"<<note.getIdNote();
    }
}



void MainWindow::on_delete_Note_clicked()
{
    /*
     * Цей рядок працює за принципом:
     * у функцію findIdNote передається текст поточного елемента в listNote
     * і знайдений індекс який повертає функція передається в removeNoteFromVector
     * для видалення з вектора NameNoteAndNoteID
    */
    returnNoteServicePtr()->removeNoteFromVector(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()));
    QListWidgetItem *current=ui->listNote->currentItem();
    delete current;
}

void MainWindow::AddNoteSpace(QString nameNoteService){
    NoteService noteService;
    noteService.setNameSpaceNote(nameNoteService);
    noteSpaces.push_back(noteService);
    ui->NoteSpaces->addItem(nameNoteService);
}
void MainWindow::deleteNoteSpace(QString nameNoteService){
    noteSpaces.erase(std::remove_if(noteSpaces.begin(), noteSpaces.end(),[&nameNoteService](const NoteService& note)
                                   { return note.getNameSpaceNote() == nameNoteService; }),noteSpaces.end());
}


void MainWindow::on_delete_Note_Service_clicked()
{
    deleteNoteSpace(ui->NoteSpaces->currentText());
}

void MainWindow::on_listTag_itemDoubleClicked(QListWidgetItem *item)
{
    returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()))->deleteTag(item->text());
    updateInfoTag();
}


void MainWindow::on_AddNoteSpace_clicked()
{
    AddNoteSpace_DialogWindow window(this);

    window.exec();
}

void MainWindow::saveInfoNote(QListWidgetItem *previous){
    QString title = ui->TitleNote->text();
    if(title.isEmpty()){
        QMessageBox::warning(this, "Warning", "Title cannot be empty.");
        return;
    }

    if (!previous)
        return;

    CustomLineEditManager* manager = CustomLineEditManager::getInstance(this);
    QVector<QString> text = manager->getTextFromLineEdits();

    Note* note = nullptr;
    if (bufferNoteSpace == ui->NoteSpaces->currentText()) {
        note = returnNoteServicePtr()->getNotePtr(previous->text());
    } else {
        QString dateTimeString = ui->date_create_note->text();
        note = returnNoteServicePtr(bufferNoteSpace)->getNotePtr(QDateTime::fromString(dateTimeString, "dd.MM.yyyy hh:mm:ss"));
    }

    if (note) {
        note->setTitle(title);
        note->setText(text);
    }
}

void MainWindow::uploadInfoNote(QListWidgetItem *current){
    if (!current)
        return;

    Note* note = returnNoteServicePtr()->getNotePtr(current->text());
    if (!note)
        return;

    ui->TitleNote->setText(note->getTitle());

    CustomLineEditManager* manager = CustomLineEditManager::getInstance(this);
    manager->clearLayout();
    QVector<QString> text = note->getText();
    manager->setTextForCustomLineEdit(text);

    updateInfoTag();
    bufferNoteId = note->getIdNote();
    bufferNoteSpace = ui->NoteSpaces->currentText();
}

void MainWindow::on_NoteSpaces_textActivated(const QString &arg1) {

    ui->listNote->clear();
    std::vector<Note> notes = returnNoteServicePtr()->getAllNotes();
    for (Note& note : notes) {
        ui->listNote->addItem(note.getTitle());
    }
    ui->listNote->setCurrentRow(0);
}


