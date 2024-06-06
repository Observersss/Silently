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
    void addActiveQuest(std::shared_ptr<Quest> quest);

    void updateInfoOnCharacter();

    void updateInfoOnQuest();

    void handleQuestInfoClosed();

    void deleteQuest(std::shared_ptr<Quest> quest);

    void questComplete();

    void addTag(QString name,bool needAddToAllTags = true);

    void updateInfoTag();

    NoteService* returnNoteServicePtr();
    NoteService* returnNoteServicePtr(QString text);

    void AddNoteSpace(QString nameNoteService);
    void deleteNoteSpace(QString nameNoteService);

    void saveInfoNote(QListWidgetItem *previous);
    void uploadInfoNote(QListWidgetItem *current);

    void update_listWidget_Quests();

    ~MainWindow();
private slots:

    void checkQuestDeadlinePassed();


    void on_delete_Note_Service_clicked();

    void on_listTag_itemDoubleClicked(QListWidgetItem *item);

    void createNote();

    void on_listWidget_Quests_itemDoubleClicked(QListWidgetItem *item);

    void deleteSelectedTag(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;
    Character character;
    std::vector<NoteService> noteSpaces;
    int bufferNoteId;
    QString bufferNoteSpace;
    static int noteCounter;
    bool showUpdateCharacteristics = false;

    void connect_Signals_and_Slots();
    void change_space();

};
#endif // MAINWINDOW_H
