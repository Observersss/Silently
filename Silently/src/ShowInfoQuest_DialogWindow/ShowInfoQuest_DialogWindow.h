#ifndef SHOWINFOQUEST_DIALOGWINDOW_H
#define SHOWINFOQUEST_DIALOGWINDOW_H

#include <QDialog>
#include "RPGspace/Quest/quest.h"
namespace Ui {
class ShowInfoQuest_DialogWindow;
}

class ShowInfoQuest_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShowInfoQuest_DialogWindow(QWidget *parent = nullptr,Quest* mainQuest = nullptr);
    ~ShowInfoQuest_DialogWindow();
private slots:
    void on_change_button_clicked();

    void on_Delete_Quest_clicked();

    void on_Quest_complete_clicked();

private:
    Ui::ShowInfoQuest_DialogWindow *ui;
    Quest* quest;
};

#endif // SHOWINFOQUEST_DIALOGWINDOW_H
