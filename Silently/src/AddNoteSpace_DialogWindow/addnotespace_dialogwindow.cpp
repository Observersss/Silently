#include "addnotespace_dialogwindow.h"
#include "ui_addnotespace_dialogwindow.h"
#include <QMessageBox>
AddNoteSpace_DialogWindow::AddNoteSpace_DialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNoteSpace_DialogWindow)
{
    ui->setupUi(this);
}

AddNoteSpace_DialogWindow::~AddNoteSpace_DialogWindow()
{
    delete ui;
}

void AddNoteSpace_DialogWindow::on_pushButton_Add_clicked()
{
    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {

        w->AddNoteSpace(ui->lineEdit_NoteServiceName->text());


        hide();
    } else {
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Предупреждение", "Невдалося передати квест");
    }
}
