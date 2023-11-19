#ifndef CHARACTER_H
#define CHARACTER_H
#include"RPGspace/Inventory/inventory.h"
#include "RPGspace/Quest/quest.h"
#include "RPGspace/Item/item.h"
#include "Library/library.h"
class Character
{
private:
    //Добавление новых характеристик(урон, шанс крит.,крит., уворот, сила, ловкость, интелект, удача)
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

    Inventory inventory;
    std::vector<Quest>activeQuest;
    QPixmap characterImage;
public:
    //Конструктор який ініціалізує об'єкт і надає персонажу базові параметри(health,mana,experience,level)
    Character();

    void completeQuest();

    void addActiveQuest(Quest* quest);

    void addItemToInventory(Item item);

    void removeItemFromInventory(Item item);

    //Функції які оновлюють дані про персонажа додаючи до його характреристик характеристики екіпійованих предметів
    void updateCharacteristicsFromInventory();
    void removeCharacteristicsFromUnequippedItems(const Item& item);

    //Пошук квеста у векторі за допомогою порівняння за title через цикл foreach
    //Повертає об'єкт класса Quest
    Quest findQuest(const std::string& title);

    void deleteActiveQuest(Quest& quest);

    //Збільшити досвід на певне значення
    void increaseExperience();

    //Перевірити і оновити рівень персонажа, якщо необхідно
    void updateLevel();

    //Збільшення характеристик на певне значення
    void increaseHealth(int amount);
    void increaseMana(int amount);
    void increaseDamage(int amount);
    void increaseChanceOfCriticalDamade(int amount);
    void increaseCriticalDamage(int amount);
    void increaseDexterity(int amount);
    void increaseForce(int amount);
    void increaseIntelligence(int amount);
    void increaseLuck(int amount);


    //Геттери
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
    Inventory getInventory() const;
    std::vector<Quest> getActiveQuest();
};


#endif // CHARACTER_H
