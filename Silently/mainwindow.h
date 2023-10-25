#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "RPGspace/Character/character.h"
//include "addquest.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addActiveQuest(Quest* quest);
    bool applicationSupportsSecureRestorableState() const {
        return true;
    }
    ~MainWindow();
private slots:
    void on_change_space_clicked();

    void on_button_update_clicked();




    void on_AddingQuest_clicked();

private:
    Ui::MainWindow *ui;
    Character character;
    Quest quest;

};
#endif // MAINWINDOW_H
