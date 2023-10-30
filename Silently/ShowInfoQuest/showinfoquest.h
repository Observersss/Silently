#ifndef SHOWINFOQUEST_H
#define SHOWINFOQUEST_H

#include <QDialog>
#include "RPGspace/Quest/quest.h"
namespace Ui {
class ShowInfoQuest;
}

class ShowInfoQuest : public QDialog
{
    Q_OBJECT

public:
    explicit ShowInfoQuest(QWidget *parent = nullptr,Quest mainQuest=Quest());


    ~ShowInfoQuest();
signals:
    void questInfoClosed();
private slots:
    void on_change_button_clicked();

    void on_Delete_Quest_clicked();

    void on_Quest_complete_clicked();

private:
    Ui::ShowInfoQuest *ui;
    Quest quest;
};

#endif // SHOWINFOQUEST_H
