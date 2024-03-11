#ifndef ADDTAG_DIALOGWINDOW_H
#define ADDTAG_DIALOGWINDOW_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class AddTag_DialogWindow;
}

class AddTag_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddTag_DialogWindow(QWidget *parent = nullptr);
    ~AddTag_DialogWindow();
private slots:
    void on_pushButton_clicked();
private:
    Ui::AddTag_DialogWindow *ui;
};

#endif // ADDTAG_DIALOGWINDOW_H
