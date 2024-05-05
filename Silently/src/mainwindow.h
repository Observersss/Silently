#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "RPGspace/Character/character.h"
#include "NOTEspace/NoteService/noteservice.h"
#include <QListWidgetItem>
#include <QTime>
#include <QTimer>
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

    void updateCharacterEquipment(const std::vector<Item>& equipment);

    //void addNewNoteToList(QString nameNote);

    void addTag(QString name,bool needAddToAllTags = true);

    void updateInfoTag();
    //NoteService returnNoteService();
    NoteService* returnNoteServicePtr();
    NoteService* returnNoteServicePtr(QString text);

    void AddNoteSpace(QString nameNoteService);
    void deleteNoteSpace(QString nameNoteService);

    void saveInfoNote(QListWidgetItem *previous);
    void uploadInfoNote(QListWidgetItem *current);

    ~MainWindow();
private slots:
    //void on_change_space_clicked();

    void checkQuestDeadlinePassed();

    void on_AddingQuest_clicked();

    void on_QuestList_itemDoubleClicked(QListWidgetItem *item);

    void on_more_characteristics_clicked();

    void on_Open_inventory_clicked();
    void on_tags_option_clicked();

    void on_listTag_itemClicked(QListWidgetItem *item);

    //void on_pushButton_clicked();

    //void on_delete_Note_clicked();

    //void on_AddNoteSpace_clicked();

    void on_delete_Note_Service_clicked();

    void on_listTag_itemDoubleClicked(QListWidgetItem *item);

    //void on_NoteSpaces_textActivated(const QString &arg1);

    void createNote();

private:
    Ui::MainWindow *ui;
    Character character;
    Quest quest;
    std::vector<NoteService> noteSpaces;
    int bufferNoteId;
    QString bufferNoteSpace;
    static int noteCounter;
    bool showUpdateCharacteristics = false;

};
#endif // MAINWINDOW_H
