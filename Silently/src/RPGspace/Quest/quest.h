#ifndef QUEST_H
#define QUEST_H

#include <QString>
#include <QDateTime>
#include <memory>

class Quest{
public:

    bool checkDeadline();

    void setTitle(const QString& title);

    void setDescription(const QString& description);

    void setComplexity(const int& complexity);

    void setDeadline(const QDateTime& deadline);

    void switch_need_to_follow_the_deadline();

    int getId() const;
    QString getTitle()const;
    QString getDescription()const;
    int getComplexity()const;
    QDateTime getDeadline()const;
    bool get_need_to_follow_the_deadline()const;

    friend class QuestFactory;

protected:
    Quest();

private:
    static int idCount_;
    int id_;
    QString title_;
    QString description_;
    int complexity_;
    QDateTime deadline_;
    bool need_to_follow_the_deadline = false;
};

class QuestFactory{
public:
    static std::shared_ptr<Quest> create(){
        return std::shared_ptr<Quest>(new Quest());
    }
};

#endif // QUEST_H
