#include "item.h"

std::map<QString, QString> Item::itemImages_ = {

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

int Item::itemCount=0;

Item::Item(){

    itemCount+=1;
    index=itemCount;

    generateRandomRank();
    generateCharacteristics();
    generateName();
    //generateType();
    }

void Item::generateRandomRank() {
    int randomRankIndex = arc4random() % 5; // Генеруєм випадкове число від 0 до 4
    //В залежності від значення randomRankIndex обраємо ранг
    switch (randomRankIndex) {
    case 0:
       rank = "S";
       break;
    case 1:
       rank = "A";
        break;
    case 2:
        rank = "B";
        break;
        case 3:
        rank = "C";
        break;
    default:
        rank = "D";
        break;
    }
}

void Item::generateCharacteristics() {

    const std::vector<QString> nameCharacteristic =
    {"health", "mana", "damage", "chanceOfCriticalDamage", "criticalDamage", "dexterity", "force", "intelligence", "luck"};

    int numCharacteristics = arc4random() % 3 + 1; //Генеруємо випадкову кількість характеристик (від 1 до 3)

    for (int i = 0; i < numCharacteristics; i++) {
        int characteristicType = arc4random() % nameCharacteristic.size(); // Вибираємо випадковий тип характеристики
        int characteristicValue;


        //ОШИБКА ГДЕ_ТО ТУТ ЧТО_ТО НЕ ТАК С СОЗДАНИЕМ ЧИСЕЛ ХАРАКТЕрИСТИК
        if (rank == "D") {
            characteristicValue = arc4random() % 3 + 1; // Для ранга D: 1-3
            //characteristicValue = 1;
        } else if (rank == "C") {
            characteristicValue = arc4random() % 4 + 2; // Для ранга C: 2-5
            //characteristicValue = 1;
        } else if (rank == "B") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 5 + 3) : (arc4random() % 3 + 1);            // Для ранга B: 3-7 (damage), 1-3 (chanceOfCriticalDamage)
            //characteristicValue = 1;
        } else if (rank == "A") {
            //characteristicValue = 1;
            characteristicValue = (characteristicType == 0) ? (arc4random() % 5 + 3) : (arc4random() % 4 + 2); // Для ранга A: 3-7 (damage), 2-5 (mana)
        } else if (rank == "S") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 4 + 5) : (characteristicType == 1) ? (arc4random() % 4 + 4) : (arc4random() % 4 + 2); // Для ранга S: 5-8 (health), 4-7 (mana), 2-5 (damage)
            //characteristicValue = 1;
        }

        Characteristics.push_back(std::make_pair(nameCharacteristic[characteristicType], characteristicValue));
        }
}



void Item::generateName() {

    // Генерація імені для предмету
    const std::vector<QString> adjectives = { "Могутній", "Священний", "Забутий", "Магічний", "Легендарний","Заборонений","" };

    const std::vector<QString> nouns =
        { "Катана","Меч квітів", "Перстень","Посох","Посох Архімага","Страшний шолом","Хомяк","Cолом'яний шолом","Wi-Fi","Сендвіч","Факел","Кавун","Молочний продукт",
         "Знак","Онігірі","Бантик","Музичний інструмент","Шолом капітана","Шолом матроса","Небесний знак","Топор","Варварський топор","Дрин","Панда"};

    int adjectiveIndex = arc4random() % adjectives.size();
    int nounIndex = arc4random() % nouns.size();
    generateType(nouns[nounIndex]);
    nameOfItem = adjectives[adjectiveIndex] + " " + nouns[nounIndex];

    generateImage(nouns[nounIndex]);

}

void Item::generateImage(const QString& name) {
    auto it = itemImages_.find(name);
    if (it != itemImages_.end())
        pathToImg = it->second;
    else
        pathToImg =":/icon/img/axe.jpg";
}

void Item::generateType(QString name){
    static std::map<QString,Equipment> name_and_type;
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
            typeItem = it->second;
        else
            throw std::runtime_error("Failed to find type from name in map");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl; // Вывод сообщения об ошибке
    }

}

void Item::setName(QString name){
    nameOfItem=name;
}


void Item::setDiscription(QString discription){
    discriptionOfItem=discription;
}

void Item::setCharacteristics(QString nameCharacteristic,double value){
    Characteristics.push_back({nameCharacteristic,value});
}

void Item::setEqipment(Equipment type){
    typeItem=type;
}

void Item::setPathToImg(QString name){
    pathToImg = name; // Завантаження зображення з файлу
}


//Функції getter для всіх змінних:
QString Item::getRank()const{
    return rank;
}
QString Item::getnameOfitem()const{
    return nameOfItem;
}
QString Item::getdiscriptionOfItem()const{
    return discriptionOfItem;
}
std::vector<std::pair<QString, int>> Item::getCharacteristics()const{
    return Characteristics;
}
Equipment Item::getTypeItem()const{
    return typeItem;
}

QString Item::getPathToImg() const {
    return pathToImg;
}

int Item::getIndex()const{
    return index;
}

