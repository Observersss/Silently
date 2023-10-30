#ifndef QUEST_H
#define QUEST_H
#include "Library/library.h"
class Quest{
private:
    std::string title;
    std::string discription;
    int difficulty;
    std::chrono::system_clock::time_point deadline;
public:
    //Пустий базовий конструктор
    Quest();

    //Перевірка дедлайну
    //Повертає true або false в залежності від того чи пройшов час дедлайну чи ні
    bool checkDeadline()const;

    //Сеттер для назви
    void setTitle(std::string newTitle);

    //Сеттер для опису
    void setDiscription(std::string newDiscription);

    //Сеттер для складності
    void setDifficulti(int newDifficulty);

    //Сеттер для часу дедлайну
    void setDeadline(std::chrono::system_clock::time_point newDeadline);

    //Геттери
    std::string getTitle()const;
    std::string getDiscription()const;
    int getDifficulty()const;
    std::chrono::system_clock::time_point getDeadline()const;



};

#endif // QUEST_H
