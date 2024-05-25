#ifndef CHARACTER_H
#define CHARACTER_H

#include"RPGspace/Inventory/inventory.h"
#include "RPGspace/Quest/quest.h"

#include <QPixmap>
#include <QRandomGenerator>
#include <QVector>


class Character
{
public:
    //Конструктор який ініціалізує об'єкт і надає персонажу базові дані про параметри
    Character();

                /*Функції для роботи з квестами*/

    void addActiveQuest(std::shared_ptr<Quest> quest);
    void deleteActiveQuest(std::shared_ptr<Quest> quest);

    //Пошук квеста у векторі за допомогою порівняння за title через цикл foreach
    //Повертає об'єкт класса Quest
    std::shared_ptr<Quest> findQuest(const QString& title);
    std::shared_ptr<Quest> findQuest(const int id);

                /*Функції для роботи з інвентарем*/
    void addItemToInventory(std::shared_ptr<Item> item);
    void addItemToEquipment(std::shared_ptr<Item> item);
    void removeItemFromEquipment(std::shared_ptr<Item> item);


                /*Функції для оновлення характеристик персонажа на основі екіпірованих предметів*/

    void updateCharacteristicsFromInventory();
    void removeCharacteristicsFromUnequippedItems(const std::shared_ptr<Item> item);


                /*Функції для збільшення показників характеристик персонажа*/

    void incrementExperience();
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
    QVector<std::shared_ptr<Quest>> getActiveQuest();
protected:
    void applyCharacteristicsDelta(const std::map<QString, int>& itemCharacteristics, int delta);

private:
    int health_;
    int mana_;
    int experience_;
    int level_;
    int damage_;
    int chanceOfCriticalDamage_;
    int criticalDamage_;
    int dexterity_;
    int force_;
    int intelligence_;
    int luck_;

    Inventory inventory_;
    Inventory equipment_;
    QVector<std::shared_ptr<Quest>>activeQuests_;
};


#endif // CHARACTER_H
