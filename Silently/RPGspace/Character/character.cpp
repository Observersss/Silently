#include "character.h"
//#include"RPGspace/Inventory/inventory.h"
//#include "RPGspace/Quest/quest.h"

Character::Character(){
    health = 100;
    mana = 100;
    experience = 0;
    level = 1;
}

void Character::addActiveQuest(Quest* quest) {
    Quest newQuest = *quest; // Создайте копию объекта Quest
    activeQuest.push_back(newQuest); // Добавьте копию в вектор activeQuest
}

void Character::increaseExperience(){
    experience+=10;
    if(experience==100){
        updateLevel();
    }
}

void Character::updateLevel(){
    level+=1;
    experience=0;
    increaseHealth(10);
    increaseMana(5);
}

void Character::increaseHealth(int amount){
    health+=amount;
}

void Character::increaseMana(int amount){
    mana+=amount;
}

int Character::getHealth()const{
    return health;
}
int Character::getMana()const{
    return mana;
}
int Character::getLevel()const{
    return level;
}
int Character::getExperience()const{
    return experience;
}
std::vector<Quest> Character::getActiveQuest(){
    return activeQuest;
}
