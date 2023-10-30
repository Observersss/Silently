#include "character.h"

Character::Character(){
    health = 100;
    mana = 50;
    experience = 0;
    level = 1;

    damage = 15;
    chanceOfCriticalDamade = 5;
    criticalDamage = 50;
    dexterity = 5;
    force = 8;
    intelligence = 7;
    luck = 3;
}


void Character::completeQuest(){

}


void Character::addActiveQuest(Quest* quest) {
    Quest newQuest = *quest; // Створюємо копію об'єкта Quest
    activeQuest.push_back(newQuest); // Додаємо його у вектор
}

Quest Character::findQuest(const std::string& title){
    for (const Quest& quest : activeQuest) {
        if (quest.getTitle() == title) {
            return quest; // Якщо квест знайшли то виходимо з функції
        }
    }

    //Квест не знайдемо виведеться помилка при перевірці чи повернуло квест
    Quest quest_eror;
    quest_eror.setTitle(nullptr);
    return quest_eror;
}

void Character::deleteActiveQuest(Quest& quest) {
    //Використовуюємо цикл foreach для перебору елементів вектора
    for (auto it = activeQuest.begin(); it != activeQuest.end(); ++it) {

        //Порівнюємо назву квеста з getTitile()
        if (it->getTitle() == quest.getTitle()) {

            //Видаляємо квест з вектора
            activeQuest.erase(it);
            break; //Ми знайшли і видалили квест тому виходимо з цикла
        }
    }
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
    increaseDamage(4);
    increaseChanceOfCriticalDamade(1);
    increaseCriticalDamage(2);
    increaseDexterity(1);
    increaseForce(1);
    increaseIntelligence(1);
    increaseLuck(1);
}

void Character::increaseHealth(int amount){
    health+=amount;
}

void Character::increaseMana(int amount){
    mana+=amount;
}

void Character::increaseDamage(int amount){
    damage+=amount;
}
void Character::increaseChanceOfCriticalDamade(int amount){
    chanceOfCriticalDamade+=amount;
}
void Character::increaseCriticalDamage(int amount){
    criticalDamage+=amount;
}
void Character::increaseDexterity(int amount){
    dexterity+=amount;
}
void Character::increaseForce(int amount){
    force+=amount;
}
void Character::increaseIntelligence(int amount){
    intelligence+=amount;
}
void Character::increaseLuck(int amount){
    luck+=amount;
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

int Character::getDamage() const{
    return damage;
}
int Character::getChanceOfCriticalDamade() const{
    return chanceOfCriticalDamade;
}
int Character::getCriticalDamage() const{
    return criticalDamage;
}
int Character::getDexterity() const{
    return dexterity;
}
int Character::getForce() const{
    return force;
}
int Character::getIntelligence() const{
    return intelligence;
}
int Character::getLuck() const{
    return luck;
}

std::vector<Quest> Character::getActiveQuest(){
    return activeQuest;
}
