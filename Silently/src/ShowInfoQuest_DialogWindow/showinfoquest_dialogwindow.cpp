#include "showinfoquest_dialogwindow.h"
#include "ui_showinfoquest_dialogwindow.h"

#include "mainwindow.h"
#include <QMessageBox>

/*
 * To-Do list for ShowInfoQuest_DialogWindow:
 * repair this function:
 *                      constructor
 *                      on_change_button_clicked
 *
*/

ShowInfoQuest_DialogWindow::ShowInfoQuest_DialogWindow(QWidget *parent,Quest* mainQuest) :

    QDialog(parent),
    ui(new Ui::ShowInfoQuest_DialogWindow),
    quest(mainQuest)
{
    ui->setupUi(this);


    ui->Title_2->setText(quest->getTitle());


    int complexity = quest->getComplexity();
    QString qcomplexity = QString::number(complexity);
    ui->Difficulty_2->setText(qcomplexity);
    // if (deadline == targetTime) {
    //     //Якщо deadline дорівнює "01.01.2000 00:00", ховаємо віджети які стосуються deadline
    //     ui->dateTimeEdit_2->setHidden(true);
    //     ui->label_4->setHidden(true);
    // } else {
    //     //Якщо deadline не дорівнює "01.01.2000 00:00", ми їх показуємо і передаємо значення deadline
    //     ui->dateTimeEdit_2->setHidden(false);
    //     ui->label_4->setHidden(false);

        ui->dateTimeEdit_2->setDateTime(quest->getDeadline());
    //}

    // if (deadline == targetTime) {
    //     //Якщо deadline дорівнює "01.01.2000 00:00", ховаємо віджети які стосуються deadline
    //     ui->dateTimeEdit_2->setHidden(true);
    //     ui->label_4->setHidden(true);
    // } else {
    //     //Якщо deadline не дорівнює "01.01.2000 00:00", ми їх показуємо і передаємо значення deadline
    //     ui->dateTimeEdit_2->setHidden(false);
    //     ui->label_4->setHidden(false);

    //     QDateTime deadlineDateTime = QDateTime::fromSecsSinceEpoch(std::chrono::system_clock::to_time_t(deadline));
    //     ui->dateTimeEdit_2->setDateTime(deadlineDateTime);
    // }


}

ShowInfoQuest_DialogWindow::~ShowInfoQuest_DialogWindow()
{
    delete ui;
}

void ShowInfoQuest_DialogWindow::on_change_button_clicked()
{
    QString title = ui->Title_2->text();
    quest->setTitle(title);


    QString qdifficulty = ui->Difficulty_2->text();
    int difficulty = qdifficulty.toInt();
    quest->setComplexity(difficulty);





    // //Створюэмо std::chrono::system_clok::time_point для базового випадку "01.01.2000 00:00"
    // std::tm timeinfo = {};
    // timeinfo.tm_year = 100;  //Рік зміщається на 1900 тому 100 відповідає 2000
    // timeinfo.tm_mon = 0;     // Січень (0)
    // timeinfo.tm_mday = 1;    // 1-е число
    // timeinfo.tm_hour = 0;    // 00 годин
    // timeinfo.tm_min = 0;     // 00 хвилин
    // std::chrono::system_clock::time_point targetTime = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));

    // //Отримаємо deadline з об'єкта Quest
    // std::chrono::system_clock::time_point deadline = quest.getDeadline();

    // if (deadline == targetTime) {

    // }
    // else {
        quest->setDeadline(ui->dateTimeEdit_2->dateTime());
    //}




    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {

        w->addActiveQuest(quest);//Додоємо до вектора квестів персонажа
        w->updateInfoOnQuest();  //Відображаємо назву квесту у QListWidget
        w->handleQuestInfoClosed();//Видаляємо стару версію квеста у QlistWidget

        hide();
    } else {
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Помилка", "Невдалося передати квест");
    }
}


void ShowInfoQuest_DialogWindow::on_Delete_Quest_clicked()
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


void ShowInfoQuest_DialogWindow::on_Quest_complete_clicked()
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

