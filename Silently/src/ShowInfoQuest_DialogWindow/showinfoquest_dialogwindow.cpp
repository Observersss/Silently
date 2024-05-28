#include "showinfoquest_dialogwindow.h"
#include "ui_showinfoquest_dialogwindow.h"

#include <QMessageBox>


ShowInfoQuest_DialogWindow::ShowInfoQuest_DialogWindow(QWidget *parent,std::shared_ptr<Quest> quest) :

    QDialog(parent),
    ui(new Ui::ShowInfoQuest_DialogWindow),
    quest_(quest)
{
    ui->setupUi(this);


    ui->lineEdit_title->setText(quest->getTitle());
    ui->lineEdit_Description->setText(quest->getDescription());
    ui->spinBox_Complexity->setValue(quest->getComplexity());
    if(quest->get_need_to_follow_the_deadline()){
        ui->dateTimeEdit_deadline->setDateTime(quest->getDeadline());
    }else{
        ui->label_deadline->hide();
        ui->dateTimeEdit_deadline->hide();
    }
}

ShowInfoQuest_DialogWindow::~ShowInfoQuest_DialogWindow()
{
    delete ui;
}



void ShowInfoQuest_DialogWindow::on_pushButton_save_changes_clicked()
{
    quest_->setTitle(ui->lineEdit_title->text());
    quest_->setDescription(ui->lineEdit_Description->text());
    quest_->setComplexity(ui->spinBox_Complexity->value());

    MainWindow* w = getMainWindow();
    if(w){
        w->update_listWidget_Quests();

        close();
    }else{
        QMessageBox::warning(this, "Eror", "Невдалося передати квест");
    }
}


void ShowInfoQuest_DialogWindow::on_pushButton_delete_Quest_clicked()
{
    MainWindow* w = getMainWindow();
    if(w){

        w->deleteQuest(quest_);
        w->handleQuestInfoClosed();

        close();

    }else{
        QMessageBox::warning(this, "Помилка", "Невдалося видалити квест");
    }
}
void ShowInfoQuest_DialogWindow::on_pushButton_complete_Quest_clicked()
{
    MainWindow* w = getMainWindow();
    if(w){
        w->questComplete();
        w->deleteQuest(quest_);
        w->handleQuestInfoClosed();

        close();

    }else{
        QMessageBox::warning(this, "Помилка", "Невдалося завершити квест");
    }
}


MainWindow* ShowInfoQuest_DialogWindow::getMainWindow(){
    MainWindow* w = dynamic_cast<MainWindow*>(parent());
    if(w){
        return w;

    }else{
        qDebug()<<"Failed create MainWindow* w /MainWindow* ShowInfoQuest_DialogWindow::getMainWindow()\n";
        return nullptr;
    }
}


