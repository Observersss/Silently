#ifndef QUEST_H
#define QUEST_H
#include "Library/library.h"
class Quest{
private:
    QString title;
    QString discription;
    int difficulty;
    std::chrono::system_clock::time_point deadline;
public:
    //Пустий базовий конструктор
    Quest();

    //Перевірка дедлайну
    //Повертає true або false в залежності від того чи пройшов час дедлайну чи ні
    bool checkDeadline()const;

    //Сеттер для назви
    void setTitle(QString newTitle);

    //Сеттер для опису
    void setDiscription(QString newDiscription);

    //Сеттер для складності
    void setDifficulti(int newDifficulty);

    //Сеттер для часу дедлайну
    void setDeadline(std::chrono::system_clock::time_point newDeadline);

    //Геттери
    QString getTitle()const;
    QString getDiscription()const;
    int getDifficulty()const;
    std::chrono::system_clock::time_point getDeadline()const;



};

#endif // QUEST_H
