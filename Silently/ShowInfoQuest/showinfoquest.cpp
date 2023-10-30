#include "showinfoquest.h"
#include "ui_showinfoquest.h"
#include "mainwindow.h"
ShowInfoQuest::ShowInfoQuest(QWidget *parent,Quest mainQuest) :
    QDialog(parent),
    ui(new Ui::ShowInfoQuest),
    quest(mainQuest)
{
    ui->setupUi(this);

    QString qtitle = QString::fromStdString(quest.getTitle());
    ui->Title->setText(qtitle);

    QString qdiscription = QString::fromStdString(quest.getDiscription());
    ui->Discription->setText(qdiscription);

    int difficulty = quest.getDifficulty();
    QString qdifficulty = QString::number(difficulty);
    ui->Difficulty->setText(qdifficulty);

    //Створюэмо std::chrono::system_clok::time_point для базового випадку "01.01.2000 00:00"
    std::tm timeinfo = {};
    timeinfo.tm_year = 100;  //Рік зміщається на 1900 тому 100 відповідає 2000
    timeinfo.tm_mon = 0;     // Січень (0)
    timeinfo.tm_mday = 1;    // 1-е число
    timeinfo.tm_hour = 0;    // 00 годин
    timeinfo.tm_min = 0;     // 00 хвилин
    std::chrono::system_clock::time_point targetTime = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));

    //Отримаємо deadline з об'єкта Quest
    std::chrono::system_clock::time_point deadline = quest.getDeadline();

    if (deadline == targetTime) {
        //Якщо deadline дорівнює "01.01.2000 00:00", ховаємо віджети які стосуються deadline
        ui->dateTimeEdit->setHidden(true);
        ui->label->setHidden(true);
    } else {
        //Якщо deadline не дорівнює "01.01.2000 00:00", ми їх показуємо і передаємо значення deadline
        ui->dateTimeEdit->setHidden(false);
        ui->label->setHidden(false);

        QDateTime deadlineDateTime = QDateTime::fromSecsSinceEpoch(std::chrono::system_clock::to_time_t(deadline));
        ui->dateTimeEdit->setDateTime(deadlineDateTime);
    }


}

ShowInfoQuest::~ShowInfoQuest()
{
    delete ui;
}

void ShowInfoQuest::on_change_button_clicked()
{
    QString title = ui->Title->text();
    std::string stdTitle = title.toStdString();
    quest.setTitle(stdTitle);

    QString discription = ui->Discription->text();
    std::string stdDiscription = discription.toStdString();
    quest.setDiscription(stdDiscription);

    QString qdifficulty = ui->Difficulty->text();
    int difficulty = qdifficulty.toInt();
    quest.setDifficulti(difficulty);




    //Створюэмо std::chrono::system_clok::time_point для базового випадку "01.01.2000 00:00"
    std::tm timeinfo = {};
    timeinfo.tm_year = 100;  //Рік зміщається на 1900 тому 100 відповідає 2000
    timeinfo.tm_mon = 0;     // Січень (0)
    timeinfo.tm_mday = 1;    // 1-е число
    timeinfo.tm_hour = 0;    // 00 годин
    timeinfo.tm_min = 0;     // 00 хвилин
    std::chrono::system_clock::time_point targetTime = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));

    //Отримаємо deadline з об'єкта Quest
    std::chrono::system_clock::time_point deadline = quest.getDeadline();

    if (deadline == targetTime) {

    }
    else {
        QDateTime selectedDateTime = ui->dateTimeEdit->dateTime();
        auto timePoint = std::chrono::system_clock::from_time_t(selectedDateTime.toSecsSinceEpoch());
        quest.setDeadline(timePoint);
    }




    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {

        w->addActiveQuest(&quest);//Додоємо до вектора квестів персонажа
        w->updateInfoOnQuest();  //Відображаємо назву квесту у QListWidget
        w->handleQuestInfoClosed();//Видаляємо стару версію квеста у QlistWidget

        hide();
    } else {
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Помилка", "Невдалося передати квест");
    }
}


void ShowInfoQuest::on_Delete_Quest_clicked()
{
    MainWindow* w = dynamic_cast<MainWindow*>(parent());
    if(w){

        w->deleteQuest();
        w->handleQuestInfoClosed();

        hide();

    }else{
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Помилка", "Невдалося видалити квест");
    }
}


void ShowInfoQuest::on_Quest_complete_clicked()
{
    MainWindow* w = dynamic_cast<MainWindow*>(parent());
    if(w){
        w->questComplete();
        w->deleteQuest();
        w->handleQuestInfoClosed();

        hide();

    }else{
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Помилка", "Невдалося завершити квест");
    }
}

