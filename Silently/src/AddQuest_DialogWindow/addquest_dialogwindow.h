#ifndef ADDQUEST_DIALOGWINDOW_H
#define ADDQUEST_DIALOGWINDOW_H

#include <QDialog>
#include "RPGspace/Quest/quest.h"
#include "mainwindow.h"


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
    void on_pushButton_show_deadline_clicked();

    void on_pushButton_add_quest_clicked();

private:
    Ui::addQuest_DialogWindow *ui;
    std::shared_ptr<Quest> quest_;
};

#endif // ADDQUEST_DIALOGWINDOW_H
