#ifndef SHOWINFOQUEST_DIALOGWINDOW_H
#define SHOWINFOQUEST_DIALOGWINDOW_H

#include "RPGspace/Quest/quest.h"
#include "mainwindow.h"

#include <QDialog>


namespace Ui {
class ShowInfoQuest_DialogWindow;
}

class ShowInfoQuest_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShowInfoQuest_DialogWindow(QWidget *parent = nullptr,std::shared_ptr<Quest> quest = nullptr);
    ~ShowInfoQuest_DialogWindow();
private slots:
    void on_pushButton_save_changes_clicked();

    void on_pushButton_delete_Quest_clicked();

    void on_pushButton_complete_Quest_clicked();

private:
    Ui::ShowInfoQuest_DialogWindow *ui;
    std::shared_ptr<Quest> quest_;

    MainWindow* getMainWindow();
};

#endif // SHOWINFOQUEST_DIALOGWINDOW_H
