#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "RPGspace/Character/character.h"
#include "NOTEspace/Note/note.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addActiveQuest(Quest* quest);

    void updateInfoOnCharacter();

    void updateInfoOnQuest();

    void handleQuestInfoClosed();

    void deleteQuest();

    void questComplete();

    void addTag(QString nametag);

    void updateInfoTag();

    void deleteTag();

    ~MainWindow();
private slots:
    void on_change_space_clicked();

    void on_AddingQuest_clicked();

    void on_QuestList_itemDoubleClicked(QListWidgetItem *item);

    void on_more_characteristics_clicked();

    void on_Test1_clicked();

    void on_pTest2_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);


    void on_tags_option_clicked();

    void on_listTag_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    Character character;
    Quest quest;
    Note note;

};
#endif // MAINWINDOW_H
