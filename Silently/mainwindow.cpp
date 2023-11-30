#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Library/library.h"
#include "AddQuest/addquest.h"
#include "ShowInfoQuest/showinfoquest.h"
#include "MoreCharacteristics/morecharacteristics.h"
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


    QPixmap pix(":/icon/img/hamster.jpg");
    int w = ui->character_icon->width();
    int h = ui->character_icon->height();

    ui->character_icon->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    //ТЕСТИРОВАНИЕ
    ui->tags_option->setText("+");
    NoteService noteService;
    Note *firstNote=noteService.getFirstNote();
    //noteService.addNewElementToNameNoteAndNoteID(firstNote->getTitle(),firstNote->getIdNote());
    noteSpaces.push_back(noteService);

    qDebug()<<firstNote->getIdNote();
    qDebug()<<firstNote->getTitle();
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


    //bufferNoteId=firstNote.getIdNote();
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




//Функция создаёт заметку и полностью считывает все данные и возвращает эту заметку
//Функция используеться в saveInfoNote
Note MainWindow::saveInfoInNewNote(){
    QString title=ui->listNote->currentItem()->text();
    Note newNote;//Создаём новую заметку
    newNote.setTitle(title);//Указываем ей заголовок какой считали в начале функции

    // Получение текста из QTextEdit
    QString text = ui->TextNote->toPlainText();

    // Разделение текста на строки (по символу новой строки '\n')
    QStringList lines = text.split('\n');

    // Преобразование QStringList в std::vector<QString>
    std::vector<QString> textLines;
    for (const QString &line : lines) {
    textLines.push_back(line);
    }

    // Передача вектора строк в newNote.setText()
    newNote.setText(textLines);
    //Далее мы считываем время создания заметки, преоброазуем его в std::chrono::system_clock::time_point и так же передаём в newNote


    // Получение текста из QLabel
    QString qTimeString = ui->date_create_note->text();

    // Преобразование QString в std::string
    std::string timeString = qTimeString.toStdString();

    // Преобразование строки в std::tm
    std::tm tmTime = {};
    std::stringstream stream(timeString);
    stream >> std::get_time(&tmTime, "%a %b %d %H:%M:%S %Y"); // Указывайте здесь нужный формат, соответствующий формату времени

    // Преобразование std::tm в std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tmTime));

    newNote.setData_time(timePoint);


    // Предположим, что у вас есть QListWidget с именем listWidget

    // Цикл для считывания текста из всех элементов QListWidget
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
    //Достаём текст где указано время создания заметки и преобразуем ёё в std::chrono::system_clock::time_point
    //чтобы проверить существует ли заметка с таким же временем создания


    // Получение текста из QLabel
    QString qTimeString = ui->date_create_note->text();

    // Преобразование QString в std::string
    std::string timeString = qTimeString.toStdString();

    // Преобразование строки в std::tm
    std::tm tmTime = {};
    std::stringstream stream(timeString);
    stream >> std::get_time(&tmTime, "%a %b %d %H:%M:%S %Y"); // Указывайте здесь нужный формат, соответствующий формату времени

    // Преобразование std::tm в std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tmTime));

    bool noteChecked=noteService->noteExists(timePoint);//Проверяем существует ли такая заметка
    //В зависимости от того что возвращает noteExists выполняем код
    if(noteChecked==true){
    //Если заметка существует уже то мы считываем все данные и заменяем её на новую версию в noteService
    Note changeNote=saveInfoInNewNote();
    noteService->setChangNote(changeNote);
    ui->listNote->currentItem()->setText(changeNote.getTitle());
    std::cout<<"1 \n";

    }else if(noteChecked==false){
    //Если данная заметка ранее не существовала то мы считываем все данные и добавляем её в noteService
    Note newNote=saveInfoInNewNote();
    noteService->addNote(newNote);
    //addNewNoteToList(newNote.getTitle());
    }
}
void MainWindow::savePreviousCurrentNote(QListWidgetItem *previous){
    //Note newNote=returnNoteServicePtr()->getNote(title);//Создаём новую заметку

    //QString title=ui->TitleNote->text();

//    bufferNoteId=findIdNote(ui->listNote->currentItem()->text());
//    qDebug()<<bufferNoteId;
    Note*newNote=returnNoteServicePtr()->getNotePtr(bufferNoteId);

    QString title=ui->TitleNote->text();
    //Note newNote=returnNoteServicePtr()->getNote(title);//Создаём новую заметку
    bufferNoteId=returnNoteServicePtr()->findIdNote(previous->text());
    qDebug()<<"Название предыдущего елемента "<<previous->text();
    qDebug()<<"ID предыдущей заметки в момент сохранения в буффер"<<bufferNoteId;
    //Note* newNote=returnNoteServicePtr()->getNotePtr(title);//Создаём новую заметку
    //bufferNameNote=previous->text();
    //qDebug()<<bufferNoteId;
    previous->setText(title);
    newNote->setTitle(title);//Указываем ей заголовок какой считали в начале функции

    // Получение текста из QTextEdit
    QString text = ui->TextNote->toPlainText();

    // Разделение текста на строки (по символу новой строки '\n')
    QStringList lines = text.split('\n');

    // Преобразование QStringList в std::vector<QString>
    std::vector<QString> textLines;
    for (const QString &line : lines) {
    textLines.push_back(line);
    }

    // Передача вектора строк в newNote.setText()
    newNote->setText(textLines);
    //Далее мы считываем время создания заметки, преоброазуем его в std::chrono::system_clock::time_point и так же передаём в newNote


    // Получение текста из QLabel
    QString qTimeString = ui->date_create_note->text();

    // Преобразование QString в std::string
    std::string timeString = qTimeString.toStdString();

    // Преобразование строки в std::tm
    std::tm tmTime = {};
    std::stringstream stream(timeString);
    stream >> std::get_time(&tmTime, "%a %b %d %H:%M:%S %Y"); // Указывайте здесь нужный формат, соответствующий формату времени

    // Преобразование std::tm в std::chrono::system_clock::time_point
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(std::mktime(&tmTime));

    newNote->setData_time(timePoint);


    // Предположим, что у вас есть QListWidget с именем listWidget

    // Цикл для считывания текста из всех элементов QListWidget
    std::vector<QString> tagNames;
    for (int i = 0; i < ui->listTag->count(); ++i) {

    QListWidgetItem *item = ui->listTag->item(i);
    QString itemText = item->text();

    tagNames.push_back(itemText);
    }

    NoteService *noteService=returnNoteServicePtr();

    noteService->tagsExists(tagNames);
    newNote->addActiveTag(tagNames);
    //noteService->setChangNote(bufferNoteId,newNote);
    previous->setText(newNote->getTitle());
    noteService->changeNameNoteInVector(newNote->getTitle(),bufferNoteId);
    bufferNoteId=returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text());
}

void MainWindow::unloadInfoNote(){
    NoteService *noteService=returnNoteServicePtr();
    if(noteService->getNameSpaceNote()==nullptr){
    std::cout<<"LOX\n";
    }

    //QListWidgetItem *currentItem = ui->listNote->currentItem();
    //QString titleNote = ui->listNote->currentItem()->text();
    //qDebug()<<"Название заметки в момент проверки на пустоту"<<bufferNoteId;
//    bufferNoteId=findIdNote(ui->listNote->currentItem()->text());
//    qDebug()<<bufferNoteId;
//    bufferNoteId=findIdNote(ui->listNote->currentItem()->text());
    qDebug()<<"Название заметки в момент проверки на пустоту"<<bufferNoteId;
    //bufferNoteId=findIdNote(ui->listNote->currentItem()->text());
    bool noteChecked=noteService->noteExists(bufferNoteId);//Проверяем существует ли такая заметка
    //В зависимости от того что возвращает noteExists выполняем код
    if(noteChecked==true){
    //QString titleNote = ui->listNote->currentItem()->text();
    //bufferNoteId=findIdNote(ui->listNote->currentItem()->text());
    Note note=noteService->getNote(bufferNoteId);

    ui->TitleNote->setText(note.getTitle());
//    Основной текст заметки храниться в векторе из QString надо либо изменить класс Note либо реализовать считываение из вектора в TextNote
    std::vector<QString> textNote=note.getText();
    QString text;
    for (const QString& line : textNote) {
        text += line + "\n"; // Добавляем каждую строку и символ новой строки "\n"
    }
    ui->TextNote->setPlainText(text);

    std::chrono::system_clock::time_point data_time=note.getDataTime();
    std::time_t time = std::chrono::system_clock::to_time_t(data_time);
    std::stringstream stream;
    stream << std::ctime(&time);
    std::string timeString = stream.str();
    QString qTimeString = QString::fromStdString(timeString);


    updateInfoTag();
//  Установка строки в QLabel
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
    // Получаем  заметку
    Note *note = returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()));

    // Проверяем, есть ли заголовок
    if (note->getTitle().isEmpty()) {
        // Если заголовок пустой, получаем заметку по умолчанию
        return;
        qDebug()<<"Заголовок заметки пустой mainwindow.h/on_tags_option_clicked";
    }
    //deleteTag(note); // Передаем заметку на удаление тега
   }

}



//void MainWindow::deleteTag(Note *note) {
//   QListWidget *currentList = ui->listTag;
//   if (currentList->currentItem() != nullptr) { // Проверка на наличие текущего элемента
//    QString tagName = currentList->currentItem()->text();
//    if (note != nullptr) { // Проверка на наличие заметки
//        note->deleteTag(tagName);
//    } else {
//        // Обработка ситуации, когда заметка пустая или отсутствует
//    }
//   } else {
//    // Обработка ситуации, когда текущий элемент не выбран
//   }
//}


void MainWindow::on_listTag_itemClicked(QListWidgetItem *item)
{
   ui->tags_option->setText("-");
}

NoteService MainWindow::returnNoteService(){
    QString nameNoteService=ui->NoteSpaces->currentText();
    for (const NoteService& value : noteSpaces) {
    if (value.getNameSpaceNote() == nameNoteService) {
        return value; // Якщо квест знайшли то виходимо з функції
    }
    }

    //Квест не знайдемо виведеться помилка при перевірці чи повернуло квест
    NoteService noteSpace_eror;
    noteSpace_eror.setNameSpaceNote(nullptr);
    return noteSpace_eror;
}

NoteService* MainWindow::returnNoteServicePtr() {
    QString nameNoteService = ui->NoteSpaces->currentText();
    qDebug()<<ui->NoteSpaces->currentText();
    for (NoteService& value : noteSpaces) {
    if (value.getNameSpaceNote() == nameNoteService) {
        // Возвращаем указатель на объект NoteService из списка noteSpaces
        qDebug()<<"Елемент какой возвращает поиск returnNoteServicePtr "<<value.getNameSpaceNote();
        return &value;
    }
    }

    // Если квест не найден, возвращаем nullptr или выбрасываем исключение
    return nullptr; // Или выбросить исключение, чтобы обработать ошибку не найденного объекта NoteService
}


void MainWindow::updateListNote(){
    qDebug()<<"Функция запустилась";
    qDebug()<<returnNoteServicePtr()->getNameSpaceNote();
    //ui->listNote->clear();
    //qDebug()<<ui->NoteSpaces->currentText();
//    qDebug()<<returnNoteServicePtr()->getFirstNote()->getTitle();
//    std::vector<Note> notes=returnNoteServicePtr()->getAllNotes();

//    qDebug()<<notes.size();
//    for(const Note& note:notes){
//    ui->listNote->addItem(note.getTitle());
//    }

//    for (const auto& pair : NameNoteAndNoteID) {
//    if (pair.first == nameNote) {
//        qDebug()<<"Название заметки при поиске findIdNote"<<pair.first;
//        qDebug()<<"ID какое возвращает функция поиска findIdNote"<<pair.second;
//        return pair.second; // Возвращаем идентификатор заметки, если найдено соответствие
//    }
//    qDebug()<<"Название заметки при поиске findIdNote"<<pair.first;
//    }
//    return -1; // Возвращаем -1, если заметка не найдена
    //ui->listNote->clear();
    qDebug()<<"Проверка на выполнение";
    std::vector<std::pair<QString,int>> NameNoteAndNoteID=returnNoteServicePtr()->returnNameNoteAndNoteID();
    qDebug()<<"Проверка на выполнение";
    for(const auto& pair : NameNoteAndNoteID){
    QString item=returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(pair.first))->getTitle();
    qDebug()<<returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(pair.first))->getTitle();
    if (item.isEmpty()) {
        ui->listNote->addItem(item);
        qDebug()<<"item  не пустой  mainwindow.h/updateListNote";
    }
    qDebug()<<"item   пустой  mainwindow.h/updateListNote";
    }


    qDebug()<<"Функция закончилась";
}

void MainWindow::addNewNoteToList(QString nameNote){
    ui->listNote->addItem(nameNote);
}

void MainWindow::addTag(QString name) {

    // Проверяем, есть ли выбранный элемент в списке заметок
    if (ui->listNote->currentItem() == nullptr) {
    // Если выбранного элемента нет, выходим из функции или обрабатываем эту ситуацию
    std::cout<<"Проблема \n";
    return; // Можно выбрать другое действие или вывести сообщение об ошибке
    }

    // Получаем текущий заголовок заметки из списка заметок
    QString title = ui->listNote->currentItem()->text();

    // Получаем заметку по выбранному заголовку
    //Note note = returnNoteService().getNote(title);
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
    //saveInfoNote();
    if(ui->listNote->count()<=1)
        saveInfoNote();
//    if(ui->NoteSpaces->count()>1)
//        savePreviousCurrentNote(current);


    ui->TitleNote->clear();
    ui->TextNote->clear();
    unloadInfoNote();
}


void MainWindow::on_pushButton_clicked()
{
    NoteService *noteService=returnNoteServicePtr();
    if(noteService==nullptr){
        std::cout<<"BLYA \n";
    } else{
    Note note;
    QString nameNote="Your new Note"+QString::number(noteCounter);
    noteCounter+=1;
    note.setTitle(nameNote);

    //savePreviousCurrentNote( ui->listNote->currentItem());

    addNewNoteToList(nameNote);
//  Получение указателя на последний элемент
    //QListWidgetItem *lastItem = ui->listNote->item(ui->listNote->count()-1);

    // Установка последнего элемента в качестве текущего
    //if (lastItem) {
        //ui->listNote->setCurrentItem(lastItem);
        noteService->addNote(note);
        noteService->addNewElementToNameNoteAndNoteID(note.getTitle(),note.getIdNote());
        qDebug()<<"ID только что созданой заметки"<<note.getIdNote();
   // }

    }
}



void MainWindow::on_delete_Note_clicked()
{
    /*
     * данная строка работает по принципу:
     * в функцию findIdNote передаёться текст текущего елемента в listNote
     * и найденый индекс какой возвращает функция передаёться в removeNoteFromVector
     * для удаления из вектора NameNoteAndNoteID
    */
    returnNoteServicePtr()->removeNoteFromVector(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()));
    QListWidgetItem *current=ui->listNote->currentItem();
    delete current;
}

void MainWindow::createNewNoteSpace(QString nameNoteService){
    NoteService noteService;
    noteService.setNameSpaceNote(nameNoteService);
    qDebug()<<noteService.getNameSpaceNote();

    //updateListNote();
    qDebug()<<noteSpaces.size();
    noteSpaces.push_back(noteService);
    qDebug() << noteSpaces.back().getNameSpaceNote();
    ui->NoteSpaces->addItem(nameNoteService);
}
void MainWindow::deleteNoteSpace(QString nameNoteService){
    noteSpaces.erase(std::remove_if(noteSpaces.begin(), noteSpaces.end(),
                                    [&nameNoteService](const NoteService& note) { return note.getNameSpaceNote() == nameNoteService; }),
                     noteSpaces.end());
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
    if(ui->NoteSpaces->count()>=1){
    QListWidget *listWidget = ui->listNote; // Замените "yourListWidget" на имя вашего QListWidget

    while (listWidget->count() > 1) {
        QListWidgetItem *item = listWidget->takeItem(0); // Удаление элемента из индекса 0
        delete item; // Освобождение памяти, занятой элементом
    }
    }

        bufferNoteId=returnNoteServicePtr()->getFirstNote()->getIdNote();
        qDebug()<<"Id первой созданой заметки нового пространства "<<returnNoteServicePtr()->getFirstNote()->getIdNote();
        qDebug()<<returnNoteServicePtr()->getNameSpaceNote();
        updateListNote();

    qDebug()<<ui->NoteSpaces->currentText();
}



void MainWindow::on_listTag_itemDoubleClicked(QListWidgetItem *item)
{
    returnNoteServicePtr()->getNotePtr(returnNoteServicePtr()->findIdNote(ui->listNote->currentItem()->text()))->deleteTag(item->text());
    updateInfoTag();
}

