#include "addquest_dialogwindow.h"
#include "ui_addquest_dialogwindow.h"

addQuest_DialogWindow::addQuest_DialogWindow(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::addQuest_DialogWindow)
{
    ui->setupUi(this);
    //Спочатку frame_2 де знаходиться ввід дати і часу дедлайну скритий
    ui->frame_2->hide();

}


addQuest_DialogWindow::~addQuest_DialogWindow()
{
    delete ui;
}

void addQuest_DialogWindow::on_pushButton_clicked()
{
    // Quest* quest = QuestFactory::create();

    // QString title = ui->Title->text();
    // quest->setTitle(title);

    // QString discription = ui->Discription->text();
    // quest->setDiscription(discription);

    // quest->setDifficulti(0);

    // if(ui->easy->isChecked()==true){
    //     quest->setDifficulti(1);
    // }
    // if (ui->meduim->isChecked()==true){
    //     quest->setDifficulti(2);
    // }
    // if(ui->hard->isChecked()==true){
    //     quest->setDifficulti(3);
    // }
    // if(ui->dead->isChecked()==true){
    //     quest->setDifficulti(4);
    // }

    // QDateTime selectedDateTime = ui->dateTimeEdit->dateTime();
    // if(ui->dateTimeEdit->YearSection==00&&ui->dateTimeEdit->MonthSection==00&&ui->dateTimeEdit->DaySection==00){

    // }else{
    //     quest->setDeadline(selectedDateTime);

    // }
    // // Создаем MainWindow
    // MainWindow* w = dynamic_cast<MainWindow*>(parent());

    // if (w) {

    //     w->addActiveQuest(quest);//Додоємо до вектора квестів персонажа
    //     w->updateInfoOnQuest();  //Відображаємо назву квесту у QListWidget

    //     hide();
    // } else {
    //     //Вивід повідомлення що не вдалося передати квест
    //     qDebug()<<"Невдалося передати квест \n";
    // }
}

void addQuest_DialogWindow::on_pushButton_2_clicked()
{
    //Якщо юзер натиснув кнопку Set deadline то frame_2 де знаходиться DateTimeEdit відображається
    //І задається дата і час актуальні
    ui->frame_2->show();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}
