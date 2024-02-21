#ifndef CHARACTER_H
#define CHARACTER_H

#include"RPGspace/Inventory/inventory.h"
#include "RPGspace/Quest/quest.h"

#include <iostream>

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
    std::vector<Quest>activeQuest;
    QPixmap characterImage;
public:
    //Конструктор який ініціалізує об'єкт і надає персонажу базові дані про параметри
    Character();

                /*Функції для роботи з квестами*/

    void addActiveQuest(Quest* quest);
    void deleteActiveQuest(Quest& quest);

    //Пошук квеста у векторі за допомогою порівняння за title через цикл foreach
    //Повертає об'єкт класса Quest
    Quest findQuest(const QString& title);

                /*Функції для роботи з інвентарем*/

    void addItemToInventory(Item item);
    void removeItemFromInventory(Item item);
    void setInventory(Inventory value);

                /*Функції для оновлення характеристик персонажа на основі екіпірованих предметів*/

    void updateCharacteristicsFromInventory();
    void removeCharacteristicsFromUnequippedItems(const Item& item);


                /*Функції для збільшення показників характеристик персонажа*/

    /*Функція додавання досвіду до персонажа
     * Якщо досвід = 100 то запускається updateLevel яка збільшує всі інші характеристики
     * за допомогою функцій типу increase...
    */
    void increaseExperience();
    void updateLevel();
    void increaseHealth(int amount);
    void increaseMana(int amount);
    void increaseDamage(int amount);
    void increaseChanceOfCriticalDamade(int amount);
    void increaseCriticalDamage(int amount);
    void increaseDexterity(int amount);
    void increaseForce(int amount);
    void increaseIntelligence(int amount);
    void increaseLuck(int amount);


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
    Inventory getInventory() ;
    std::vector<Quest> getActiveQuest();
};


#endif // CHARACTER_H
