#include "addquest.h"
#include "ui_addquest.h"
#include "Library/library.h"
AddQuest::AddQuest(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AddQuest)
{
    ui->setupUi(this);
    //Спочатку frame_2 де знаходиться ввід дати і часу дедлайну скритий
    ui->frame_2->hide();
}


AddQuest::~AddQuest()
{
    delete ui;
}

void AddQuest::on_pushButton_clicked()
{
    Quest* quest = new Quest;

    QString title = ui->Title->text();
    std::string stdTitle = title.toStdString();
    quest->setTitle(stdTitle);

    QString discription = ui->Discription->text();
    std::string stdDiscription = discription.toStdString();
    quest->setDiscription(stdDiscription);

    quest->setDifficulti(0);

    if(ui->easy->isChecked()==true){
        quest->setDifficulti(1);
    }
    if (ui->meduim->isChecked()==true){
        quest->setDifficulti(2);
    }
    if(ui->hard->isChecked()==true){
        quest->setDifficulti(3);
    }
    if(ui->dead->isChecked()==true){
        quest->setDifficulti(4);
    }

    QDateTime selectedDateTime = ui->dateTimeEdit->dateTime();
    if(ui->dateTimeEdit->YearSection==00&&ui->dateTimeEdit->MonthSection==00&&ui->dateTimeEdit->DaySection==00){

    }else{
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::from_time_t(selectedDateTime.toSecsSinceEpoch());
    quest->setDeadline(timePoint);
    }
    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {

        w->addActiveQuest(quest);//Додоємо до вектора квестів персонажа
        w->updateInfoOnQuest();  //Відображаємо назву квесту у QListWidget

        hide();
    } else {
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Предупреждение", "Невдалося передати квест");
    }
}

void AddQuest::on_pushButton_2_clicked()
{
    //Якщо юзер натиснув кнопку Set deadline то frame_2 де знаходиться DateTimeEdit відображається
    //І задається дата і час актуальні
    ui->frame_2->show();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

