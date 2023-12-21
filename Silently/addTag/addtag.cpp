#include "addtag.h"
#include "ui_addtag.h"

AddTag::AddTag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTag)
{
    ui->setupUi(this);
}

AddTag::~AddTag()
{
    delete ui;
}

void AddTag::on_pushButton_clicked()
{
    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    QString name=ui->tagName->text();

    if (w) {

        w->addTag(name);//Додоємо до вектора квестів персонажа
        w->updateInfoTag();
        close();
    } else {
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Предупреждение", "Невдалося передати квест");
    }
}

