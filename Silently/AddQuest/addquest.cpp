#include "addquest.h"
#include "ui_addquest.h"
#include "QMessageBox"
AddQuest::AddQuest(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AddQuest)
{
    ui->setupUi(this);
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
    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {
        w->addActiveQuest(quest);
        hide();
    } else {
        // Обработка ошибки - не удалось получить указатель на MainWindow
        // Можно вывести сообщение об ошибке или выполнить другие действия
        QMessageBox::warning(this, "Предупреждение", "Неудалось передать квест");
    }
}
