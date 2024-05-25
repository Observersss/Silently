#include "character.h"

Character::Character(){
    health_ = 100;
    mana_ = 50;
    experience_ = 0;
    level_ = 1;

    damage_ = 15;
    chanceOfCriticalDamage_ = 5;
    criticalDamage_ = 50;
    dexterity_ = 5;
    force_ = 8;
    intelligence_ = 7;
    luck_ = 3;
}

                /*Функції для роботи з квестами*/
void Character::addActiveQuest(std::shared_ptr<Quest> quest) {
    activeQuests_.push_back(quest);
}

//Треба виправити функцію проблема з пошуком(класс буде переписано тому зміниться пошук)
void Character::deleteActiveQuest(std::shared_ptr<Quest> quest) {
    activeQuests_.removeAt(activeQuests_.indexOf(quest));
}

std::shared_ptr<Quest> Character::findQuest(const QString& title){
    for (std::shared_ptr<Quest> quest : activeQuests_) {
        if (quest->getTitle() == title) {
            return quest; // Якщо квест знайшли то виходимо з функції
        }
    }

    //if not found
    std::shared_ptr<Quest> quest_eror = QuestFactory::create();
    quest_eror->setTitle(nullptr);
    return quest_eror;
}
std::shared_ptr<Quest> Character::findQuest(const int id){
    for(std::shared_ptr<Quest> quest : activeQuests_){
        if(quest->getId() == id){
            return quest;
        }
    }

    //if not found
    std::shared_ptr<Quest> quest_eror = QuestFactory::create();
    quest_eror->setTitle(nullptr);
    return quest_eror;
}

                /*Функції для роботи з інвентарем*/
void Character::addItemToInventory(std::shared_ptr<Item> item){
    inventory_.addItem(item);
}
void Character::addItemToEquipment(std::shared_ptr<Item> item){
    if(inventory_.check_if_it_contains(item)){
        inventory_.removeItem(item);
        equipment_.addItem(item);
    }
}
void Character::removeItemFromEquipment(std::shared_ptr<Item> item){
    if(equipment_.check_if_it_contains(item)){
        equipment_.removeItem(item);
        inventory_.addItem(item);
    }
}

                /*Функції для оновлення характеристик персонажа на основі екіпірованих предметів*/
void Character::updateCharacteristicsFromInventory() {
    QVector<std::shared_ptr<Item>> activeItems = equipment_.getItems();

    for (const auto& item : activeItems) {
        std::map<QString, int> itemCharacteristics = item->getCharacteristics();
        applyCharacteristicsDelta(itemCharacteristics, 1);
    }
}

void Character::removeCharacteristicsFromUnequippedItems(const std::shared_ptr<Item> item) {
    std::map<QString, int> itemCharacteristics = item->getCharacteristics();
    applyCharacteristicsDelta(itemCharacteristics, -1);
}


void Character::applyCharacteristicsDelta(const std::map<QString, int>& itemCharacteristics, int delta) {
    // Карта, связывающая названия характеристик с переменными-членами класса
    std::map<QString, int*> characteristicMap = {
        {"health", &health_},
        {"mana", &mana_},
        {"damage", &damage_},
        {"chanceOfCriticalDamage", &chanceOfCriticalDamage_},
        {"criticalDamage", &criticalDamage_},
        {"dexterity", &dexterity_},
        {"force", &force_},
        {"intelligence", &intelligence_},
        {"luck", &luck_}
    };

    for (const auto& characteristic : itemCharacteristics) {
        auto it = characteristicMap.find(characteristic.first);
        if (it != characteristicMap.end()) {
            *(it->second) += delta * characteristic.second;
        } else {
            // Использование правильного логирования ошибок или обработки исключений
            std::cerr << "Неизвестная характеристика: " << characteristic.first.toStdString() << std::endl;
        }
    }
}



                /*Функції для збільшення показників характеристик персонажа*/
void Character::incrementExperience(){
    QRandomGenerator randomGenerator(static_cast<quint32>(std::time(nullptr)));
    int randomExperience = randomGenerator.bounded(1, 11);
    experience_ += randomExperience;

    if (experience_ >= 100) {
        experience_ -= 100;
        level_ += 1;
    }
}

void Character::setHealth(int amount){
    health_ = amount;
}

void Character::setMana(int amount){
    mana_ = amount;
}

void Character::setDamage(int amount){
    damage_ = amount;
}
void Character::setChanceOfCriticalDamade(int amount){
    chanceOfCriticalDamage_ = amount;
}
void Character::setCriticalDamage(int amount){
    criticalDamage_ = amount;
}
void Character::setDexterity(int amount){
    dexterity_ = amount;
}
void Character::setForce(int amount){
    force_ = amount;
}
void Character::setIntelligence(int amount){
    intelligence_ = amount;
}
void Character::setLuck(int amount){
    luck_ = amount;
}

                /*Геттери*/
int Character::getHealth()const{
    return health_;
}
int Character::getMana()const{
    return mana_;
}
int Character::getLevel()const{
    return level_;
}
int Character::getExperience()const{
    return experience_;
}

int Character::getDamage() const{
    return damage_;
}
int Character::getChanceOfCriticalDamade() const{
    return chanceOfCriticalDamage_;
}
int Character::getCriticalDamage() const{
    return criticalDamage_;
}
int Character::getDexterity() const{
    return dexterity_;
}
int Character::getForce() const{
    return force_;
}
int Character::getIntelligence() const{
    return intelligence_;
}
int Character::getLuck() const{
    return luck_;
}
Inventory* Character::getInventory(){
    return &inventory_;
}
Inventory* Character::getEquipment(){
    return &equipment_;
}

QVector<std::shared_ptr<Quest>> Character::getActiveQuest(){
    return activeQuests_;
}


