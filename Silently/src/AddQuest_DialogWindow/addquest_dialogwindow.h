#ifndef ADDQUEST_DIALOGWINDOW_H
#define ADDQUEST_DIALOGWINDOW_H

#include <QDialog>
#include "RPGspace/Quest/quest.h"
#include "mainwindow.h"

/*
 * To-Do list addQuest_DialogWindow:
 * update functional for new Quest
 */
namespace Ui {
class addQuest_DialogWindow;
}

class addQuest_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addQuest_DialogWindow(QWidget *parent = nullptr);
    ~addQuest_DialogWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::addQuest_DialogWindow *ui;
};

#endif // ADDQUEST_DIALOGWINDOW_H
