#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <sstream>
#include <iomanip>
#include <QMessageBox>
#include <QRandomGenerator>

#include "AddQuest/addquest.h"
#include "ShowInfoQuest/showinfoquest.h"
#include "MoreCharacteristics/morecharacteristics.h"
#include "InventoryWindow/inventorywindow.h"
#include "addTag/addtag.h"
#include "createNewNoteSpaceWindow/createnewnotespacewindow.h"
int MainWindow::noteCounter=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //СДЕЛАЙ СРАВНЕНИЕ ПО СЕКУНДАМ В SETCHANGENOTE

    //ПОИСК СРЕДИ  ЗАМЕТКО ПРОИСХОДИТ ЛОМАЕТЬСЯ ИБО ОНО ИЩЕТ НОВОЕ НАЗВАНИЕ СРЕДИ СТАРЫХ НАЗВАНИЙ

    //Чтоби пофиксить баг с внезапным завершением програмы нужно правильно настроить когда и как нужно запустить сохранение
    //заметки перед сменой пространства(Note Spaces)

    //Оновлення інформації про персонажа
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

//    qDebug()<<firstNote->getIdNote();
//    qDebug()<<firstNote->getTitle();
    bufferNoteId=firstNote->getIdNote();

    QString title=firstNote->getTitle()/*"Your first note"*/;
    ui->listNote->addItem(title);
    std::chrono::system_clock::time_point data_time=firstNote->getDataTime();
    std::time_t time = std::chrono::system_clock::to_time_t(data_time);
    std::stringstream stream;
    stream << std::ctime(&time);
    std::string timeString = stream.str();
    QString qTimeString = QString::fromStdString(timeString);

    QListWidget *listWidget=ui->listNote;
    listWidget->setCurrentRow(1);

    QString nameSpaceNote=noteService.getNameSpaceNote();
    ui->NoteSpaces->addItem(nameSpaceNote);
    // Установка строки в QLabel
    ui->date_create_note->setText(qTimeString);
    ui->date_create_note->setStyleSheet("QLabel { padding-top: 10px; font-size:11px; }");


    //bufferNoteId=firstNote->getIdNote();
    //qDebug()<<bufferNoteId;



    //unloadInfoNote();
    //////////////////////////////////////////////
    //NameNoteAndNoteID.push_back(std::pair(firstNote.getTitle(),firstNote.getIdNote()));
    /////////////////////////////////////////////////
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
/*-----------------------------------------------------------*/




//Функція створює замітку та повністю зчитує всі дані та повертає цю замітку
//Функція використовується в saveInfoNote
Note MainWindow::saveInfoInNewNote(){
    QString title=ui->listNote->currentItem()->text();
    Note newNote;
    newNote.setTitle(title);

    QString text = ui->TextNote->toPlainText();


    QStringList lines = text.split('\n');
    std::vector<QString> textLines;

    for (const QString &line : lines)
        textLines.push_back(line);


    newNote.setText(textLines);
    //Далі ми зчитуємо час створення нотатки, переоснащуємо його в std::chrono::system_clock::time_point і так само передаємо в newNote


    // Отримання тексту з QLabel
    QString qTimeString = ui->date_create_note->text();

    // Перетворення QString на std::string
    std::string timeString = qTimeString.toStdString();

    // Перетворення рядка на std::tm
    std::tm tmTime = {};
    std::stringstream stream(timeString);
    stream >> std::get_time(&tmTime, "%a %b %d %H:%M:%S %Y"); // Вказуйте тут потрібний формат, який відповідає формату часу

    // Перетворення std::tm на std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tmTime));

    newNote.setData_time(timePoint);


    std::vector<QString> tagNames;
    for (int i = 0; i < ui->listTag->count(); ++i) {
    QListWidgetItem *item = ui->listTag->item(i);
    QString itemText = item->text();
    tagNames.push_back(itemText);
    }

    NoteService *noteService=returnNoteServicePtr();
    noteService->tagsExists(tagNames);
    newNote.addActiveTag(tagNames);
    return newNote;
}
void MainWindow::saveInfoNote(){

    NoteService *noteService=returnNoteServicePtr();

    //Далі ми зчитуємо час створення нотатки, переоснащуємо його в std::chrono::system_clock::time_point і так само передаємо в newNote


    // Отримання тексту з QLabel
    QString qTimeString = ui->date_create_note->text();

    // Перетворення QString на std::string
    std::string timeString = qTimeString.toStdString();

    // Перетворення рядка на std::tm
    std::tm tmTime = {};
    std::stringstream stream(timeString);
    stream >> std::get_time(&tmTime, "%a %b %d %H:%M:%S %Y"); // Вказуйте тут потрібний формат, який відповідає формату часу

    // Перетворення std::tm на std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tmTime));

    bool noteChecked=noteService->noteExists(timePoint);

    if(noteChecked==true){
    Note changeNote=saveInfoInNewNote();
    noteService->setChangNote(changeNote);
    ui->listNote->currentItem()->setText(changeNote.getTitle());
    std::cout<<"1 \n";

    }else if(noteChecked==false){
    Note newNote=saveInfoInNewNote();
    noteService->addNote(newNote);
    }
}
void MainWindow::savePreviousCurrentNote(QListWidgetItem *previous){

    bufferNoteId=returnNoteServicePtr()->findIdNote(previous->text());
    Note*newNote=returnNoteServicePtr()->getNotePtr(bufferNoteId);

    QString title=ui->TitleNote->text();

    bufferNoteId=returnNoteServicePtr()->findIdNote(previous->text());
    previous->setText(title);
    newNote->setTitle(title);


    QString text = ui->TextNote->toPlainText();

    QStringList lines = text.split('\n');

    std::vector<QString> textLines;
    for (const QString &line : lines)
    textLines.push_back(line);

    newNote->setText(textLines);

    //Далі ми зчитуємо час створення нотатки, переоснащуємо його в std::chrono::system_clock::time_point і так само передаємо в newNote


    // Отримання тексту з QLabel
    QString qTimeString = ui->date_create_note->text();

    // Перетворення QString на std::string
    std::string timeString = qTimeString.toStdString();

    // Перетворення рядка на std::tm
    std::tm tmTime = {};
    std::stringstream stream(timeString);
    stream >> std::get_time(&tmTime, "%a %b %d %H:%M:%S %Y"); // Вказуйте тут потрібний формат, який відповідає формату часу

    // Перетворення std::tm на std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tmTime));

    newNote->setData_time(timePoint);

    std::vector<QString> tagNames;

    for (int i = 0; i < ui->listTag->count(); ++i) {
    QListWidgetItem *item = ui->listTag->item(i);
    QString itemText = item->text();
    tagNames.push_back(itemText);
    }

    NoteService *noteService=returnNoteServicePtr();

    newNote->addActiveTag(tagNames);

    noteService->tagsExists(tagNames);
    noteService->changeNameNoteInVector(newNote->getTitle(),bufferNoteId);

    previous->setText(newNote->getTitle());

    bufferNoteId=returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text());
}

void MainWindow::unloadInfoNote(){
    NoteService *noteService=returnNoteServicePtr();
    if(noteService->getNameSpaceNote()==nullptr){
    std::cout<<"LOX\n";
    }


    bool noteChecked=noteService->noteExists(bufferNoteId);

    if(noteChecked==true){
    bufferNoteId=returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text());
    Note note=noteService->getNote(bufferNoteId);

    ui->TitleNote->setText(note.getTitle());

    std::vector<QString> textNote=note.getText();
    QString text;
    for (const QString& line : textNote)
        text += line + "\n";

    ui->TextNote->setPlainText(text);

    std::chrono::system_clock::time_point data_time=note.getDataTime();
    std::time_t time = std::chrono::system_clock::to_time_t(data_time);
    std::stringstream stream;
    stream << std::ctime(&time);
    std::string timeString = stream.str();
    QString qTimeString = QString::fromStdString(timeString);


    updateInfoTag();

    ui->date_create_note->setText(qTimeString);
    ui->date_create_note->setStyleSheet("QLabel { padding-top: 7px; font-size:11px; }");

    }else
    std::cout<<"Заметка не найдена что-то не так mainWindow.h/unloadInfoNote \n";
}



void MainWindow::on_tags_option_clicked()
{
    if (ui->tags_option->text() == "+") {
    AddTag window(this);
    window.show();
    window.exec();
    }
    else if (ui->tags_option->text() == "-") {
    Note *note = returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()));
    if (note->getTitle().isEmpty()) {
        // Если заголовок пустой, получаем заметку по умолчанию
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
        return value; // Якщо квест знайшли то виходимо з функції
    }

    //Квест не знайдено виведеться помилка при перевірці чи повернуло квест
    NoteService noteSpace_eror;
    noteSpace_eror.setNameSpaceNote(nullptr);
    return noteSpace_eror;
}

NoteService* MainWindow::returnNoteServicePtr() {
    QString nameNoteService = ui->NoteSpaces->currentText();
    for (NoteService& value : noteSpaces) {
    if (value.getNameSpaceNote() == nameNoteService) {
        // Якщо квест знайшли то виходимо з функції
        return &value;
    }
    }

    //Квест не знайдено виведеться помилка при перевірці чи повернуло квест
    return nullptr;
}


void MainWindow::updateListNote(){

}

void MainWindow::addNewNoteToList(QString nameNote){
    ui->listNote->addItem(nameNote);
}

void MainWindow::addTag(QString name) {

    if (ui->listNote->currentItem() == nullptr) {
    std::cout<<"Проблема \n";
    return;
    }

    QString title = ui->listNote->currentItem()->text();

    Note *note = returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(title));
    note->addActiveTag(name);
}


void MainWindow::updateInfoTag() {
    ui->listTag->clear();
    std::vector<Tag> tags=returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()))->getActiveTag();
    for(const Tag& tag:tags){
    ui->listTag->addItem(tag.getNameTag());
    }
}



void MainWindow::on_listNote_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(ui->listNote->count()<=1)
        saveInfoNote();
    if(previous!=nullptr){
        qDebug()<<"if СРАБОТАЛ";
       savePreviousCurrentNote(previous);
    }

    ui->TitleNote->clear();
    ui->TextNote->clear();

    unloadInfoNote();
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
    qDebug()<<"ID только что созданой заметки"<<note.getIdNote();


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

void MainWindow::createNewNoteSpace(QString nameNoteService){
    NoteService noteService;
    noteService.setNameSpaceNote(nameNoteService);
    noteSpaces.push_back(noteService);
    ui->NoteSpaces->addItem(nameNoteService);
}
void MainWindow::deleteNoteSpace(QString nameNoteService){
    noteSpaces.erase(std::remove_if(noteSpaces.begin(), noteSpaces.end(),[&nameNoteService](const NoteService& note)
                                   { return note.getNameSpaceNote() == nameNoteService; }),noteSpaces.end());
}

void MainWindow::on_createNewNoteSpace_clicked()
{
    CreateNewNoteSpaceWindow window(this);
    window.show();
    window.exec();
}


void MainWindow::on_delete_Note_Service_clicked()
{
    deleteNoteSpace(ui->NoteSpaces->currentText());
}


void MainWindow::on_NoteSpaces_currentIndexChanged(int index)
{
//    if(ui->NoteSpaces->count()>=1){
//    QListWidget *listWidget = ui->listNote; // Замените "yourListWidget" на имя вашего QListWidget

//    while (listWidget->count() > 1) {
//        QListWidgetItem *item = listWidget->takeItem(0); // Удаление элемента из индекса 0
//        delete item; // Освобождение памяти, занятой элементом
//    }
//    }

        bufferNoteId=returnNoteServicePtr()->getFirstNote()->getIdNote();
        //qDebug()<<"Id первой созданой заметки нового пространства "<<returnNoteServicePtr()->getFirstNote()->getIdNote();
        //qDebug()<<returnNoteServicePtr()->getNameSpaceNote();
        updateListNote();

    qDebug()<<ui->NoteSpaces->currentText();
}



void MainWindow::on_listTag_itemDoubleClicked(QListWidgetItem *item)
{
    returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()))->deleteTag(item->text());
    updateInfoTag();
}

