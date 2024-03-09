#include "createnewnotespacewindow.h"
#include "ui_createnewnotespacewindow.h"
#include <QMessageBox>
CreateNewNoteSpaceWindow::CreateNewNoteSpaceWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewNoteSpaceWindow)
{
    ui->setupUi(this);
}

CreateNewNoteSpaceWindow::~CreateNewNoteSpaceWindow()
{
    delete ui;
}

void CreateNewNoteSpaceWindow::on_pushButton_Add_clicked()
{
    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {

        w->createNewNoteSpace(ui->lineEdit_NoteServiceName->text());


        hide();
    } else {
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Предупреждение", "Невдалося передати квест");
    }
}

