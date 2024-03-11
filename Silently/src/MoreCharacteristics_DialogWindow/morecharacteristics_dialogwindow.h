#ifndef MORECHARACTERISTICS_DIALOGWINDOW_H
#define MORECHARACTERISTICS_DIALOGWINDOW_H

#include <QDialog>
#include "RPGspace/Character/character.h"
namespace Ui {
class MoreCharacteristics_DialogWindow;
}

class MoreCharacteristics_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MoreCharacteristics_DialogWindow(QWidget *parent = nullptr,Character* maincharacter=nullptr,bool show=false);
    ~MoreCharacteristics_DialogWindow();

    void updateInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MoreCharacteristics_DialogWindow *ui;
    Character* character;
    int countPoint = 12;
};

#endif // MORECHARACTERISTICS_DIALOGWINDOW_H
