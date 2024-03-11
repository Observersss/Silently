#include "addtag_dialogwindow.h"
#include "ui_addtag_dialogwindow.h"
#include <QMessageBox>
AddTag_DialogWindow::AddTag_DialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddTag_DialogWindow)
{
    ui->setupUi(this);
}

AddTag_DialogWindow::~AddTag_DialogWindow()
{
    delete ui;
}

void AddTag_DialogWindow::on_pushButton_clicked()
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

