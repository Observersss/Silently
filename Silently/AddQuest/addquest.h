#ifndef ADDQUEST_H
#define ADDQUEST_H

#include <QDialog>
#include "RPGspace/Quest/quest.h"
#include "mainwindow.h"
namespace Ui {
class AddQuest;
}

class AddQuest : public QDialog
{
    Q_OBJECT

public:
    explicit AddQuest(QWidget* parent = nullptr);
    ~AddQuest();

private slots:
    void on_pushButton_clicked();
private:
    Ui::AddQuest *ui;
    Quest quest;
};


#endif // ADDQUEST_H
