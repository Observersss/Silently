#ifndef MORECHARACTERISTICS_DIALOGWINDOW_H
#define MORECHARACTERISTICS_DIALOGWINDOW_H

#include <QDialog>
#include "RPGspace/Character/character.h"
#include <map>
#include <QSpinBox>
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
    void changeValueEvent();
public slots:
    void on_spinBox_valueChanged(int arg1);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MoreCharacteristics_DialogWindow *ui;
    Character* character;
    int countPoint = 12;
    std::map<QSpinBox*,int> boxes;
};

#endif // MORECHARACTERISTICS_DIALOGWINDOW_H
