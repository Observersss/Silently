#ifndef CHARACTER_H
#define CHARACTER_H

#include"RPGspace/Inventory/inventory.h"
#include "RPGspace/Quest/quest.h"
#include <QPixmap>

#include <QVector>

//To-Do list in Character:
//select new naming(must be easy for reading)
//Write new functional for Character for work with new Inventory(because Inventory it`s basic class for items and active items)
//Getters needs return const objects(?)
//need read and re-write name for functions and atributes



class Character
{
private:
    /*Основні характеристики персонажа:
     *Здоров'я
     *Мана
     *Рівень
     *Досвід
     *
     *Урон
     *Шанс крит.
     *Крит. урон
     *Спритність
     *Сила
     *Інтелект
     *Удача
 */
    int health;
    int mana;
    int experience;
    int level;
    int damage;
    int chanceOfCriticalDamade;
    int criticalDamage;
    int dexterity;
    int force;
    int intelligence;
    int luck;

    /*Інвентар персонажа(складається з вектора активних предметів та неактивних)
     *Вектор з створених користувачем квестів
     *Зображення самого персонажа
    */
    Inventory inventory;
    Inventory equipment;
    QVector<Quest*>activeQuest;
    QPixmap characterImage;
public:
    //Конструктор який ініціалізує об'єкт і надає персонажу базові дані про параметри
    Character();

                /*Функції для роботи з квестами*/

    void addActiveQuest(Quest* quest);
    void deleteActiveQuest(const Quest* quest);

    //Пошук квеста у векторі за допомогою порівняння за title через цикл foreach
    //Повертає об'єкт класса Quest
    Quest* findQuest(const QString& title);
    Quest* findQuest(const int id);

                /*Функції для роботи з інвентарем*/

    void addItemToInventory(Item* item);
    void removeItemFromInventory(Item* item);
    void setInventory(Inventory value);

                /*Функції для оновлення характеристик персонажа на основі екіпірованих предметів*/

    void updateCharacteristicsFromInventory();
    void removeCharacteristicsFromUnequippedItems(const Item* item);


                /*Функції для збільшення показників характеристик персонажа*/

    void setExperience();
    void updateLevel();
    void setHealth(int amount);
    void setMana(int amount);
    void setDamage(int amount);
    void setChanceOfCriticalDamade(int amount);
    void setCriticalDamage(int amount);
    void setDexterity(int amount);
    void setForce(int amount);
    void setIntelligence(int amount);
    void setLuck(int amount);


                /*Геттери*/

    int getHealth() const;
    int getMana() const;
    int getLevel() const;
    int getExperience() const;
    int getDamage() const;
    int getChanceOfCriticalDamade() const;
    int getCriticalDamage() const;
    int getDexterity() const;
    int getForce() const;
    int getIntelligence() const;
    int getLuck() const;
    Inventory* getInventory();
    Inventory* getEquipment();
    QVector<Quest*> getActiveQuest();
};


#endif // CHARACTER_H
