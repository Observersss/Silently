#include "item.h"
#include <qDebug>

int Item::itemCount_=0;


QString Item::getRank() const{
    return rank_;
}
QString Item::getnameOfitem() const{
    return nameOfItem_;
}
QString Item::getdescriptionOfItem() const{
    return descriptionOfItem_;
}
std::map<QString,int> Item::getCharacteristics() const{
    return characteristics_;
}
Equipment Item::getTypeItem() const{
    return typeItem_;
}

QString Item::getPathToImg() const {
    return pathToImg_;
}

int Item::getIndex()const{
    return index_;
}

Item::~Item(){

}

Item::Item(){
    itemCount_ +=1;
    index_ = itemCount_;
}

void Item::setRank(const QString &rank){
    rank_ = rank;
}

void Item::setName(const QString& name){
    nameOfItem_ = name;
}

void Item::setDescription(const QString& description){
    descriptionOfItem_ = description;
}

void Item::setCharacteristics(const std::map<QString,int>& characteristics){
    characteristics_ = characteristics;
}

void Item::setTypeOfItem(const Equipment& type){
    typeItem_=type;
}

void Item::setPathToImg(const QString& name){
    pathToImg_ = name;
}



QString ItemGeneratorStrategy::generateRank() {
    int randomRankIndex = arc4random() % 5; // Генеруєм випадкове число від 0 до 4
    switch (randomRankIndex) {
    case 0:
        return QString("S");
    case 1:
        return QString("A");
    case 2:
        return QString("B");
    case 3:
        return QString("C");
    default:
        return QString("D");
    }
}

std::map<QString,int> ItemGeneratorStrategy::generateCharacteristics(const QString &rank) {

    const std::vector<QString> nameCharacteristic =
        {"health", "mana", "damage", "chanceOfCriticalDamage", "criticalDamage", "dexterity", "force", "intelligence", "luck"};

    int numCharacteristics = arc4random() % 3 + 1; //Генеруємо випадкову кількість характеристик (від 1 до 3)
    std::map<QString,int> characteristic;
    qDebug()<<rank<<'\n';
    for (int i = 0; i < numCharacteristics; i++) {
        qDebug()<<'\n'<<"Run generate \n";
        int characteristicType = arc4random() % nameCharacteristic.size(); // Вибираємо випадковий тип характеристики
        int characteristicValue;
        if (rank == "D") {
            characteristicValue = arc4random() % 3 + 1; // Для ранга D: 1-3

        } else if (rank == "C") {
            characteristicValue = arc4random() % 4 + 2; // Для ранга C: 2-5

        } else if (rank == "B") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 5 + 3) : (arc4random() % 3 + 1);            // Для ранга B: 3-7 (damage), 1-3 (chanceOfCriticalDamage)

        } else if (rank == "A") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 5 + 3) : (arc4random() % 4 + 2); // Для ранга A: 3-7 (damage), 2-5 (mana)

        } else if (rank == "S") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 4 + 5) : (characteristicType == 1) ? (arc4random() % 4 + 4) : (arc4random() % 4 + 2); // Для ранга S: 5-8 (health), 4-7 (mana), 2-5 (damage)
        }

        qDebug()<<nameCharacteristic[characteristicType]<<" "<<characteristicValue<<'\n';
        characteristic[nameCharacteristic[characteristicType]] = characteristicValue;
    }
    return characteristic;
}



std::pair<QString,QString> ItemGeneratorStrategy::generateName() {
    const std::vector<QString> adjectives = { "Могутній", "Священний", "Забутий", "Магічний", "Легендарний","Заборонений","" };

    const std::vector<QString> nouns =
        { "Катана","Меч квітів", "Перстень","Посох","Посох Архімага","Страшний шолом","Хомяк","Cолом'яний шолом","Wi-Fi","Сендвіч","Факел","Кавун","Молочний продукт",
         "Знак","Онігірі","Бантик","Музичний інструмент","Шолом капітана","Шолом матроса","Небесний знак","Топор","Варварський топор","Дрин","Панда"};

    int adjectiveIndex = arc4random() % adjectives.size();
    int nounIndex = arc4random() % nouns.size();
    QString nameOfItem = adjectives[adjectiveIndex] + " " + nouns[nounIndex];

    return std::make_pair(nameOfItem,nouns[nounIndex]);
}

QString ItemGeneratorStrategy::generatePathToImg(const QString& name) {
    static std::map<QString, QString> itemImages;
    if(itemImages.empty()){
        itemImages = {
            {"Катана", ":/icon/img/katana.jpg"},
            {"Меч квітів",":/icon/img/katana_2.jpg"},
            {"Перстень",":/icon/img/magical-ring.jpg"},
            {"Посох",":/icon/img/magical-staff.jpg"},
            {"Страшний шолом",":/icon/img/creepy-mask.jpg"},
            {"Хомяк", ":/icon/img/hamster.jpg"},
            {"Cолом'яний шолом", ":/icon/img/beach-hat.jpg"},
            {"Wi-Fi", ":/icon/img/wifi-icon.jpg"},
            {"Сендвіч", ":/icon/img/sandwich.jpg"},
            {"Зірка", ":/icon/img/star.jpg"},
            {"Факел", ":/icon/img/torch.jpg"},
            {"Кавун", ":/icon/img/watermelon.jpg"},
            {"Молочний продукт", ":/icon/img/milk.jpg"},
            {"Знак",":/icon/img/parking-sign.jpg"},
            {"Онігірі", ":/icon/img/onigiri.jpg"},
            {"Бантик", ":/icon/img/ribbon.jpg"},
            {"Музичний інструмент", ":/icon/img/violin.jpg"},
            {"Шолом капітана", ":/icon/img/sailor-hat-2.jpg"},
            {"Шолом матроса", ":/icon/img/sailor-hat.jpg"},
            {"Топор", ":/icon/img/axe.jpg"},
            {"Варварський топор", ":/icon/img/axe_2.jpg"},
            {"Небесний знак", ":/icon/img/star.jpg"},
            {"Дрин", ":/icon/img/chainsaw.jpg"},
            {"Панда",":/icon/img/panda.jpg"},
            {"Посох Архімага",":/icon/img/magical-staff-2.jpg"}

        };
    }

    return itemImages[name];
}

Equipment ItemGeneratorStrategy::generateTypeOfItem(const QString& name){
    static std::map<QString,Equipment> name_and_type;
    Equipment typeItem;
    if(name_and_type.empty()){
        name_and_type["Катана"] = WEAPON;
        name_and_type["Меч квітів"] = WEAPON;
        name_and_type["Перстень"] = RING;
        name_and_type["Посох"] = WEAPON;
        name_and_type["Посох Архімага"] = WEAPON;
        name_and_type["Страшний шолом"] = HELMET;
        name_and_type["Хомяк"] = PETS;
        name_and_type["Cолом'яний шолом"] = HELMET;
        name_and_type["Wi-Fi"] = PETS;
        name_and_type["Сендвіч"] = ANOTHER;
        name_and_type["Факел"]  = WEAPON;
        name_and_type["Кавун"] = ANOTHER;
        name_and_type["Молочний продукт"] = ANOTHER;
        name_and_type["Знак"] = WEAPON;
        name_and_type["Онігірі"] = ANOTHER;
        name_and_type["Бантик"]  = HELMET;
        name_and_type["Музичний інструмент"] = WEAPON;
        name_and_type["Шолом капітана"] = HELMET;
        name_and_type["Шолом матроса"] = HELMET;
        name_and_type["Небесний знак"] = ANOTHER;
        name_and_type["Топор"] = WEAPON;
        name_and_type["Варварський топор"] = WEAPON;
        name_and_type["Дрин"] = WEAPON;
        name_and_type["Панда"] = PETS;
    }

    try {
        auto it = name_and_type.find(name);
        if (it != name_and_type.end())
            return it->second;
        else
            throw std::runtime_error("Failed to find type from name in map");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl; // Вывод сообщения об ошибке
        return ANOTHER;
    }
}

Item* DefaultItemGenerator::generateItem(){
    Item* item = new Item();
    QString rank = generateRank();
    std::pair<QString,QString> fullName_and_basicName = generateName();
    item->setRank(rank);
    item->setName(fullName_and_basicName.first);
    item->setTypeOfItem(generateTypeOfItem(fullName_and_basicName.second)); // Передаем базовое имя
    item->setPathToImg(generatePathToImg(fullName_and_basicName.second)); // Передаем базовое имя
    item->setCharacteristics(generateCharacteristics(rank));
    return item;
}
