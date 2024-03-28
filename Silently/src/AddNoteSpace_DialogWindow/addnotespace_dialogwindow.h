#ifndef ADDNOTESPACE_DIALOGWINDOW_H
#define ADDNOTESPACE_DIALOGWINDOW_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class AddNoteSpace_DialogWindow;
}

class AddNoteSpace_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddNoteSpace_DialogWindow(QWidget *parent = nullptr);
    ~AddNoteSpace_DialogWindow();
private slots:
    void on_pushButton_Add_clicked();
private:
    Ui::AddNoteSpace_DialogWindow *ui;
};

#endif // ADDNOTESPACE_DIALOGWINDOW_H
