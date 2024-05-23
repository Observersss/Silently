#ifndef QUEST_H
#define QUEST_H

#include <QString>
#include <QDateTime>

//To-Do list for Quest functional
//re-write for std::shared_ptr<Quest> (old version Quest*)
// move private section in Quest in end class Quest
// write new truth naming atribute/methods

class Quest{
private:
    static int idCount_;
    int id_;
    QString title_;
    QString discription_;
    int difficulty_;
    QDateTime deadline_;
    bool needDeadLine_ = false;

    Quest();
public:

    bool checkDeadline();

    void setTitle(const QString& newTitle);

    void setDiscription(const QString& newDiscription);

    void setDifficulti(const int& newDifficulty);

    void setDeadline(const QDateTime& newDeadline);

    //Геттери
    int getId() const;
    QString getTitle()const;
    QString getDiscription()const;
    int getDifficulty()const;
    QDateTime getDeadline()const;

    friend class QuestFactory;
};

class QuestFactory{
public:
    static Quest* create(){
        return new Quest();
    }
};

#endif // QUEST_H
