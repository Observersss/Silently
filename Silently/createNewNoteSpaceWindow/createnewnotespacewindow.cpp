#include "createnewnotespacewindow.h"
#include "ui_createnewnotespacewindow.h"

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
