#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <sstream>
#include <iomanip>
#include <QMessageBox>

#include "addQuest_DialogWindow/addQuest_DialogWindow.h"
#include "ShowInfoQuest_DialogWindow/ShowInfoQuest_DialogWindow.h"
#include "MoreCharacteristics_DialogWindow/MoreCharacteristics_DialogWindow.h"
#include "Inventory_DialogWindow/Inventory_DialogWindow.h"
#include "AddTag_DialogWindow/AddTag_dialogwindow.h"
#include "AddNoteSpace_DialogWindow/addnotespace_dialogwindow.h"
#include "NOTEspace/CustomLineEditManager/customlineeditmanager.h"

/* To-Do list for MainWindow:
* set normal naming with GUI objects/methods/atributes
* move short function( < 5 string of code, if more use function) in connect(...)
* update functional for new RPG_space code
* re-write :
*           checkQuestDeadlinePassed
*           questComplete
*           deleteQuest
*           on_Open_inventory_clicked
*/


int MainWindow::noteCounter=0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set note space
    change_space();

    connect_Signals_and_Slots();
    updateInfoOnQuest();
    updateInfoOnCharacter();

    QPixmap pix(":/icon/img/Character.jpg");
    int w = ui->label_CharacterIcon->width();
    int h = ui->label_CharacterIcon->height();
    ui->label_CharacterIcon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->button_tagsOption->setText("+");


    NoteService noteService = NoteServiceFactory::create();
    Note *firstNote=noteService.getFirstNote();
    noteSpaces.push_back(noteService);
    bufferNoteId=firstNote->getIdNote();
    bufferNoteSpace = noteService.getNameSpaceNote();

    ui->QListWidget_Notes->addItem(firstNote->getTitle());
    ui->QComboBox_NoteSpaces->addItem(noteService.getNameSpaceNote());


    //select first note for upload
    ui->QListWidget_Notes->setCurrentRow(ui->QListWidget_Notes->count() - 1);
    uploadInfoNote(ui->QListWidget_Notes->currentItem());

    //First declaration CustomLineEditManager for work width layout and scrollArea
    CustomLineEditManager* manager = CustomLineEditManager::getInstance(this);
    manager->setLayoutAndScroolArea(ui->verticalLayout_for_CustomLineEditManager, ui->scrollArea_for_CustomLineEdit);
    manager->create_CustomLineEdit();
}

void MainWindow::checkQuestDeadlinePassed() {
    qDebug() << "Checking quest deadlines...";

    QDateTime currentTime = QDateTime::currentDateTime();

    foreach(std::shared_ptr<Quest> quest, character.getActiveQuest()){
        if(quest->get_need_to_follow_the_deadline()){
            if (currentTime >= quest->getDeadline()) {
                qDebug() << "Deadline passed!";
                QMessageBox::warning(this, "Quest Deadline Passed", "The deadline for the quest '" + quest->getTitle() + "' has passed.");
                character.deleteActiveQuest(quest);

                QString title ="ID:"+QString::number(quest->getId())+" " + quest->getTitle();
                for (int i = 0; i < ui->QuestList->count(); ++i) {
                    QListWidgetItem *item = ui->QuestList->item(i);
                    if (item->text() == title) {
                        delete ui->QuestList->takeItem(i);
                        break;
                    }
                }
            }
        }
    }

    QTimer::singleShot(60 * 1000, this, &MainWindow::checkQuestDeadlinePassed);
}


void MainWindow::addActiveQuest(std::shared_ptr<Quest> quest){
    try{
        character.addActiveQuest(quest);
        checkQuestDeadlinePassed();
    }catch(std::runtime_error& e){
        QMessageBox::warning(this,"Eror!","Failed to add new quest, try again");
            qDebug()<<"Runtime error: "<<e.what()<<'\n';
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


// void MainWindow::on_AddingQuest_clicked()
// {
//     // addQuest_DialogWindow window(this);
//     // window.exec();
// }

void MainWindow::on_QuestList_itemDoubleClicked(QListWidgetItem *item)
{
    // QString titleName = item->text(); // Получаем название квеста
    // int startIndex = titleName.indexOf(":") + 1; // Ищем начало числовой части после "ID:"
    // int endIndex = titleName.indexOf(" ", startIndex); // Ищем конец числовой части перед первым пробелом

    // if (startIndex != -1 && endIndex != -1) {
    //     QString idString = titleName.mid(startIndex, endIndex - startIndex); // Извлекаем числовую часть
    //     bool conversionOK;
    //     int id = idString.toInt(&conversionOK);

    //     if (conversionOK) {
    //         qDebug() << "ID:" << id;
    //         Quest* quest = character.findQuest(id); // Передаем в функцию findQuest для поиска по ID

    //         // Проверка на ошибку, если квест не был найден
    //         if (quest->getTitle() == "0") {
    //             qDebug() << "Квест не найден в mainwindow.cpp/on_QuestList_itemDoubleClicked";
    //         } else {
    //             // Если проверка пройдена, запускаем новое окно ShowInfoQuest_DialogWindow
    //             ShowInfoQuest_DialogWindow window(this, quest);
    //             window.exec();
    //         }
    //     } else {
    //         // Обработка случая, если не удалось преобразовать строку в числовой ID
    //         qDebug() << "Не удалось преобразовать в числовой ID";
    //     }
    // } else {
    //     // Обработка случая, если строка не соответствует ожидаемому формату "ID:id name"
    //     qDebug() << "Строка не содержит ID в ожидаемом формате";
    // }
}
void MainWindow::on_listWidget_Quests_itemDoubleClicked(QListWidgetItem *item)
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
            std::shared_ptr<Quest> quest = character.findQuest(id);

            // Проверка на ошибку, если квест не был найден
            if (quest == nullptr) {
                qDebug() << "Quest not found mainwindow.cpp/on_QuestList_itemDoubleClicked";
                QMessageBox::warning(this,"Eror","Sory but quest not found... maybe problem with him id");
            } else {

                // ShowInfoQuest_DialogWindow window(this, quest);
                // window.exec();
            }
        } else {
            // Обработка случая, если не удалось преобразовать строку в числовой ID
            qDebug() << "Не удалось преобразовать в числовой ID";
        }
    } else {
        // Обработка случая, если строка не соответствует ожидаемому формату "ID:id name"
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
    QVector<std::shared_ptr<Quest>> quests = character.getActiveQuest();

    if (!quests.empty()) {
        std::shared_ptr<Quest> quest = quests.back();
        QString title ="ID:"+QString::number(quest->getId())+" " + quest->getTitle();
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
    //character.deleteActiveQuest(quest);
}

void MainWindow::questComplete(){
    // int levelNow= character.getLevel();
    // character.setExperience();
    // int levelAfter= character.getLevel();

    // if(levelNow<levelAfter){
    // QMessageBox::information(this,"New level","New Level");
    //     showUpdateCharacteristics = true;
    // }


    // //Налаштування псевдо генератора випадкових чисел
    // QRandomGenerator randomGenerator(static_cast<quint32>(std::time(nullptr)));

    // //Генерація випадкового числа від 0 до 99
    // int randomNumber = randomGenerator.bounded(100);

    // //Перевірка на виконання функції з 30% вірогідністю(від 0 до 19)
    // if (randomNumber < 20) {
    //     Item* item = ItemFactory::create_by_default();
    //     QMessageBox::information(this,"New Item","You find new Item");
    //     character.addItemToInventory(item);
    // }

    // updateInfoOnCharacter();
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
    // Inventory inventory=character.getInventory();

    // // После закрытия окна обновите экипировку персонажа
    // updateCharacterEquipment(inventory.getItemsEquipment());
    // updateInfoOnCharacter();
}

void MainWindow::updateCharacterEquipment(const QVector<Item*>& equipment) {
    character.updateCharacteristicsFromInventory(); // Подобная функция должна быть в классе Character
    // Обновите представление персонажа в соответствии с изменениями
}


/*-----------------------------------------------------------*/
//                      Note space

// void MainWindow::on_tags_option_clicked()
// {
//     if (ui->button_tagsOption->text() == "+") {
//         QVector<Tag>tags = returnNoteServicePtr()->getAllTags();
//         AddTag_DialogWindow window(this,&tags);

//         window.exec();
//     }
//     else if (ui->button_tagsOption->text() == "-") {
//     Note *note = returnNoteServicePtr()->getNote(returnNoteServicePtr()->findIdNote(ui->QListWidget_Notes->currentItem()->text()));
//     if (note->getTitle().isEmpty()) {
//         throw std::runtime_error("Title of note is empty /MainWindow::on_tags_option_clicked()");
//         return;
//     }
//    }

// }




// void MainWindow::on_listTag_itemClicked(QListWidgetItem *item)
// {
//    ui->button_tagsOption->setText("-");
// }


NoteService* MainWindow::returnNoteServicePtr() {
    QString nameNoteService = ui->QComboBox_NoteSpaces->currentText();
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

void MainWindow::addTag(QString name,bool needAddToAllTags) {

    if (ui->QListWidget_Notes->currentItem() == nullptr) {
        throw std::runtime_error("Fail! ui->listNote->currentItem() == nullptr /MainWindow::addTag(QString name,bool needAddToAllTags)");
        return;
    }

    QString title = ui->QListWidget_Notes->currentItem()->text();

    Note *note = returnNoteServicePtr()->getNote(returnNoteServicePtr()->findIdNote(title));
    note->addActiveTag(name);

    if(needAddToAllTags)
    returnNoteServicePtr()->addToAllTag(name);

}


void MainWindow::updateInfoTag() {
    ui->QListWidget_tags->clear();
    QVector<Tag> tags = returnNoteServicePtr()->getNote(ui->QListWidget_Notes->currentItem()->text())->getActiveTag();

    if(!tags.isEmpty()){

        for(const Tag& tag:tags){
            ui->QListWidget_tags->addItem(tag.getNameTag());
        }

    }
}




void MainWindow::AddNoteSpace(QString nameNoteService){
    // NoteService noteService;
    // noteService.setNameSpaceNote(nameNoteService);
    // noteSpaces.push_back(noteService);
    // ui->QComboBox_NoteSpaces->addItem(nameNoteService);
}
void MainWindow::deleteNoteSpace(QString nameNoteService){
    noteSpaces.erase(std::remove_if(noteSpaces.begin(), noteSpaces.end(),[&nameNoteService](const NoteService& note)
                                   { return note.getNameSpaceNote() == nameNoteService; }),noteSpaces.end());
}


void MainWindow::on_delete_Note_Service_clicked()
{
    deleteNoteSpace(ui->QComboBox_NoteSpaces->currentText());
}

void MainWindow::on_listTag_itemDoubleClicked(QListWidgetItem *item)
{
    returnNoteServicePtr()->getNote(returnNoteServicePtr()->findIdNote(ui->QListWidget_Notes->currentItem()->text()))->deleteTag(item->text());
    updateInfoTag();
}
void MainWindow::saveInfoNote(QListWidgetItem *previous){
    QString title = ui->QLineEdit_TitleNote->text();
    if(title.isEmpty()){
        QMessageBox::warning(this, "Warning", "Title cannot be empty.");
        return;
    }
    if (!previous)
        return;

    CustomLineEditManager* manager = CustomLineEditManager::getInstance(this);
    QVector<QString> text = manager->getTextFromLineEdits();

    Note* note = nullptr;
    if (bufferNoteSpace == ui->QComboBox_NoteSpaces->currentText()) {
        note = returnNoteServicePtr()->getNote(previous->text());
    } else {
        QString dateTimeString = ui->label_DateOfCreation->text();
        note = returnNoteServicePtr(bufferNoteSpace)->getNote(QDateTime::fromString(dateTimeString, "dd.MM.yyyy hh:mm:ss"));
    }

    if (note) {
        note->setTitle(title);
        note->setText(text);

       previous->setText(title);
    }
}

void MainWindow::uploadInfoNote(QListWidgetItem *current){
    if (!current)
        return;

    Note* note = returnNoteServicePtr()->getNote(current->text());
    if (!note)
        return;

    ui->QLineEdit_TitleNote->setText(note->getTitle());

    CustomLineEditManager* manager = CustomLineEditManager::getInstance(this);
    manager->clearLayout();
    QVector<QString> text = note->getText();
    manager->setTextForCustomLineEdit(text);

    ui->label_DateOfCreation->setText(note->getDataTime().toString("dd.MM.yyyy hh:mm:ss"));

    updateInfoTag();
    bufferNoteId = note->getIdNote();
    bufferNoteSpace = ui->QComboBox_NoteSpaces->currentText();
}
void MainWindow::createNote(){
    if(returnNoteServicePtr()==nullptr){
        throw std::runtime_error("Fail! noteService == nullptr /MainWindow::on_pushButton_clicked()");
        return;
    } else{
        Note* note = NoteFactory::create();
        noteCounter+=1;
        QString nameNote="Your new Note "+QString::number(noteCounter);
        note->setTitle(nameNote);

        ui->QListWidget_Notes->addItem(nameNote);
        returnNoteServicePtr()->addNote(note);
    }
}

void MainWindow::connect_Signals_and_Slots(){

    connect(ui->pushButton_show_AddQuest_DialogWindow,&QPushButton::clicked,this,[this]{
        addQuest_DialogWindow(this).exec();
    });

    //For save previous note and upload selected
    connect(ui->QListWidget_Notes,&QListWidget::currentItemChanged,this, [this](QListWidgetItem *current, QListWidgetItem *previous){
        if(previous)
            saveInfoNote(previous);

        uploadInfoNote(current);
    });

    //If button clicked create new note
    connect(ui->button_addNote, &QPushButton::clicked, this, &MainWindow::createNote);
    //If button clicked delete active note
    connect(ui->button_deleteNote, &QPushButton::clicked, this, [this]{
        QListWidgetItem* currentItem = ui->QListWidget_Notes->currentItem();
        if (currentItem) {
            if(ui->QListWidget_Notes->count() == 1){
                QMessageBox::warning(this,"Error","You not can delete this note, please create new and delete this");
                return;
            }

            int currentIndex = ui->QListWidget_Notes->row(currentItem);
            ui->QListWidget_Notes->takeItem(currentIndex);

            returnNoteServicePtr()->deleteNote(currentItem->text());
            delete currentItem;

            if (ui->QListWidget_Notes->count() > 0) {
                int newIndex = qMax(0, currentIndex - 1);
                ui->QListWidget_Notes->setCurrentRow(newIndex);
            }
        }
    });


    // If button clicked show AddNoteSpace_DialogWindow for create new NoteSpace
    connect(ui->button_AddNoteSpace,&QPushButton::clicked,this,[this]{
        AddNoteSpace_DialogWindow window(this);
        window.exec();
    });

    // If current NoteSpace changed update QListWidget_Notes for this NoteSpace
    connect(ui->QComboBox_NoteSpaces,&QComboBox::textActivated,this,[this]{
        ui->QListWidget_Notes->clear();
        QVector <Note*> notes = returnNoteServicePtr()->getAllNotes();
        for (Note* note : notes) {
            ui->QListWidget_Notes->addItem(note->getTitle());
        }
        ui->QListWidget_Notes->setCurrentRow(0);
    });

    //connect for control visiable element program in space
    connect(ui->button_change_space,&QPushButton::clicked,this,&MainWindow::change_space);

    connect(ui->QListWidget_tags, &QListWidget::itemClicked, this, [this](QListWidgetItem *item){
        // if(item){
        //     ui->button_tagsOption->setText("-");
        // }else{
        //     ui->button_tagsOption->setText("+");
        // }
    });

    connect(ui->button_tagsOption,&QPushButton::clicked,this,[this](){
        if (ui->button_tagsOption->text() == "+") {
            QVector<Tag>tags = returnNoteServicePtr()->getAllTags();
            AddTag_DialogWindow window(this,&tags);

            window.exec();
        }
        // else if (ui->button_tagsOption->text() == "-") {
        //     Note *note = returnNoteServicePtr()->getNote(ui->QListWidget_Notes->currentItem()->text());
        //     if (note == nullptr) {
        //         throw std::runtime_error("Title of note is empty /MainWindow::on_tags_option_clicked()");
        //         return;
        //     }
        //     note->deleteTag(ui->QListWidget_tags->currentItem()->text());
        //     QListWidgetItem* current = ui->QListWidget_tags->currentItem();
        //     delete current;
        // }
    });
}
void MainWindow::change_space(){
    if(ui->spaces->currentIndex()==1)
    {
        ui->spaces->setCurrentIndex(0);
        ui->button_change_space->setText("Go Notes");
        ui->label_InfoSpace->setText("Space now: RPG");
        updateInfoOnQuest();
        updateInfoOnCharacter();
        ui->stackedWidget->setCurrentIndex(1);

    } else
    {
        ui->spaces->setCurrentIndex(1);
        ui->button_change_space->setText("Go RPG");
        ui->label_InfoSpace->setText("Space now: Notes");
        ui->stackedWidget->setCurrentIndex(0);
    }
}


