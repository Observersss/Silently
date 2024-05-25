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

                /*Функції для роботи з квестами*/
void Character::addActiveQuest(Quest* quest) {
    activeQuest.push_back(quest);
}

//Треба виправити функцію проблема з пошуком(класс буде переписано тому зміниться пошук)
void Character::deleteActiveQuest(const Quest* quest) {
    activeQuest.removeAt(activeQuest.indexOf(quest));
}

Quest* Character::findQuest(const QString& title){
    for (Quest* quest : activeQuest) {
        if (quest->getTitle() == title) {
            return quest; // Якщо квест знайшли то виходимо з функції
        }
    }

    //Квест не знайдемо виведеться помилка при перевірці чи повернуло квест
    Quest* quest_eror = QuestFactory::create();
    quest_eror->setTitle(nullptr);
    return quest_eror;
}
Quest* Character::findQuest(const int id){
    for( Quest* quest : activeQuest){
        if(quest->getId() == id){
            return quest;
        }
    }
}

                /*Функції для роботи з інвентарем*/
void Character::addItemToInventory(Item* item){
    inventory.addItemInInventory(item);
}

void Character::removeItemFromInventory(Item* item){
    inventory.deleteItemFromInventory(item);
}

void Character::setInventory(Inventory value){
    inventory=value;
}

                /*Функції для оновлення характеристик персонажа на основі екіпірованих предметів*/
void Character::updateCharacteristicsFromInventory() {
    QVector<Item*> activeItems = inventory.getItemEquipment();

    for (const auto& item : activeItems) {
        std::map<QString, int> itemCharacteristics = item->getCharacteristics();

        /*
        * Застосовуємо характеристики предмета до характеристик персонажа
        * Збільшуємо характеристики на певне значення предмету
        */
        for (const auto& characteristic : itemCharacteristics) {
            if (characteristic.first == "health") {
                health+=(characteristic.second);
            } else if (characteristic.first == "mana") {
                mana+=(characteristic.second);
            } else if (characteristic.first == "damage") {
                damage += characteristic.second;
            } else if (characteristic.first == "chanceOfCriticalDamage") {
                chanceOfCriticalDamade += characteristic.second;
            } else if (characteristic.first == "criticalDamage") {
                criticalDamage += characteristic.second;
            } else if (characteristic.first == "dexterity") {
                dexterity += characteristic.second;
            } else if (characteristic.first == "force") {
                force += characteristic.second;
            } else if (characteristic.first == "intelligence") {
                intelligence += characteristic.second;
            } else if (characteristic.first == "luck") {
                luck += characteristic.second;
            }else {
                std::cout<<"Something wrond in character.cpp/updateCharacteristicsFromInventory\n";
            }
        }
    }
}


void Character::removeCharacteristicsFromUnequippedItems(const Item* item) {
    std::map<QString, int> itemCharacteristics = item->getCharacteristics();

    /*
     * Застосовуємо характеристики предмета до характеристик персонажа
     * Зменшуємо характеристики на зворотне значення
    */
    for (const auto& characteristic : itemCharacteristics) {
        if (characteristic.first == "health") {
            health-=characteristic.second;
        } else if (characteristic.first == "mana") {
            mana-=characteristic.second;
        } else if(characteristic.first=="damage"){
            damage-=characteristic.second;
        } else if(characteristic.first=="chanceOfCriticalDamage"){
            chanceOfCriticalDamade-=characteristic.second;
        } else if(characteristic.first=="criticalDamage"){
            criticalDamage-=characteristic.second;
        } else if (characteristic.first=="dexterity"){
            dexterity-=characteristic.second;
        } else if(characteristic.first=="force"){
            force-=characteristic.second;
        } else if(characteristic.first=="intelligence"){
            intelligence-=characteristic.second;
        } else if(characteristic.first=="luck"){
            luck-=characteristic.second;
        } else {
            std::cout<<"Something wrond in character.cpp/removeCharacteristicsFromUnequippedItems\n";
        }
    }
}



                /*Функції для збільшення показників характеристик персонажа*/
void Character::setExperience(){
    experience+=10;
    if(experience==100){
        updateLevel();
    }
}

void Character::updateLevel(){
    level+=1;
    experience=0;
}

void Character::setHealth(int amount){
    health = amount;
}

void Character::setMana(int amount){
    mana = amount;
}

void Character::setDamage(int amount){
    damage = amount;
}
void Character::setChanceOfCriticalDamade(int amount){
    chanceOfCriticalDamade = amount;
}
void Character::setCriticalDamage(int amount){
    criticalDamage = amount;
}
void Character::setDexterity(int amount){
    dexterity = amount;
}
void Character::setForce(int amount){
    force = amount;
}
void Character::setIntelligence(int amount){
    intelligence = amount;
}
void Character::setLuck(int amount){
    luck = amount;
}

                /*Геттери*/
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
Inventory Character::getInventory() {
    return inventory;
}

QVector<Quest*> Character::getActiveQuest(){
    return activeQuest;
}


