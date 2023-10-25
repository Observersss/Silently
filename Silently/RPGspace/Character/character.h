#ifndef CHARACTER_H
#define CHARACTER_H
#include"RPGspace/Inventory/inventory.h"
#include "RPGspace/Quest/quest.h"

class Character
{
private:
    int health;
    int mana;
    int experience;
    int level;
    Inventory inventory;
    std::vector<Quest>activeQuest;
    QPixmap characterImage;
public:
    //Конструктор який ініціалізує об'єкт і надає персонажу базові параметри(health,mana,experience,level)
    Character();

    void addActiveQuest(Quest* quest);



    //Збільшити досвід на певне значення
    void increaseExperience();

    //Перевірити і оновити рівень персонажа, якщо необхідно
    void updateLevel();

    //Збільшити здоров'я на певне значення
    void increaseHealth(int amount);

    //Збільшити ману на певне значення
    void increaseMana(int mana);

    //Геттери
    int getHealth() const;
    int getMana()const;
    int getLevel() const;
    int getExperience() const;
    std::vector<Quest> getActiveQuest();
};


#endif // CHARACTER_H
