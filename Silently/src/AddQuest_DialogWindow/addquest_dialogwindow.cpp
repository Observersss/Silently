#include "addquest_dialogwindow.h"
#include "ui_addquest_dialogwindow.h"

addQuest_DialogWindow::addQuest_DialogWindow(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::addQuest_DialogWindow)
{
    ui->setupUi(this);
    ui->frame_deadline->hide();

    quest_ = QuestFactory::create();
}


addQuest_DialogWindow::~addQuest_DialogWindow()
{
    delete ui;
}

void addQuest_DialogWindow::on_pushButton_show_deadline_clicked()
{
    if(ui->pushButton_show_deadline->text() == "Set deadline"){
        ui->pushButton_show_deadline->setText("No deadline needed");
        ui->frame_deadline->show();
        ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
        //set true
        quest_->switch_need_to_follow_the_deadline();
    }else if(ui->pushButton_show_deadline->text() == "No deadline needed"){
        ui->frame_deadline->hide();
        ui->pushButton_show_deadline->setText("Set deadline");
        //set false
        quest_->switch_need_to_follow_the_deadline();
    }
}


void addQuest_DialogWindow::on_pushButton_add_quest_clicked()
{
    QString title = ui->lineEdit_Title->text();
    quest_->setTitle(title);

    QString discription = ui->lineEdit_Description->text();
    quest_->setDescription(discription);

    quest_->setComplexity(0);

    if(ui->easy->isChecked()==true){
        quest_->setComplexity(1);
    }
    if (ui->meduim->isChecked()==true){
        quest_->setComplexity(2);
    }
    if(ui->hard->isChecked()==true){
        quest_->setComplexity(3);
    }
    if(ui->dead->isChecked()==true){
        quest_->setComplexity(4);
    }

    QDateTime selectedDateTime = ui->dateTimeEdit->dateTime();
    if(ui->dateTimeEdit->YearSection==00&&ui->dateTimeEdit->MonthSection==00&&ui->dateTimeEdit->DaySection==00){

    }else{
        quest_->setDeadline(selectedDateTime);

    }

    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {

        w->addActiveQuest(quest_);
        w->updateInfoOnQuest();

        hide();
    } else {
        throw std::runtime_error("Failed to cast parent to MainWindow");
    }
}

