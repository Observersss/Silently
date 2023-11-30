#ifndef CREATENEWNOTESPACEWINDOW_H
#define CREATENEWNOTESPACEWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class CreateNewNoteSpaceWindow;
}

class CreateNewNoteSpaceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewNoteSpaceWindow(QWidget *parent = nullptr);
    ~CreateNewNoteSpaceWindow();

private slots:
    void on_pushButton_Add_clicked();

private:
    Ui::CreateNewNoteSpaceWindow *ui;
};

#endif // CREATENEWNOTESPACEWINDOW_H
