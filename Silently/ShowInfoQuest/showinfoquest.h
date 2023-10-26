#ifndef SHOWINFOQUEST_H
#define SHOWINFOQUEST_H

#include <QDialog>

namespace Ui {
class ShowInfoQuest;
}

class ShowInfoQuest : public QDialog
{
    Q_OBJECT

public:
    explicit ShowInfoQuest(QWidget *parent = nullptr);
    ~ShowInfoQuest();

private:
    Ui::ShowInfoQuest *ui;
};

#endif // SHOWINFOQUEST_H
