#include "item.h"

std::map<std::string, QString> Item::itemImages_ = {

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

    }

void Item::generateRandomRank() {

    int randomRankIndex = arc4random() % 5; // Генерируем случайное число от 0 до 4


        // В зависимости от значения randomRankIndex выбираем ранг
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

    const std::vector<std::string> nameCharacteristic =
    {"health", "mana", "damage", "chanceOfCriticalDamage", "criticalDamage", "dexterity", "force", "intelligence", "luck"};

    int numCharacteristics = arc4random() % 3 + 1; // Генерируем случайное количество характеристик (от 1 до 3)

    for (int i = 0; i < numCharacteristics; i++) {
        int characteristicType = arc4random() % nameCharacteristic.size(); // Выбираем случайный тип характеристики
        int characteristicValue;

        if (rank == "D") {
            characteristicValue = arc4random() % 3 + 1; // Для ранга D: 1-3
        } else if (rank == "C") {
            characteristicValue = arc4random() % 4 + 2; // Для ранга C: 2-5
        } else if (rank == "B") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 5 + 3) : (arc4random() % 3 + 1); // Для ранга B: 3-7 (damage), 1-3 (chanceOfCriticalDamage)
        } else if (rank == "A") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 5 + 3) : (arc4random() % 4 + 2); // Для ранга A: 3-7 (damage), 2-5 (mana)
        } else if (rank == "S") {
            characteristicValue = (characteristicType == 0) ? (arc4random() % 4 + 5) : (characteristicType == 1) ? (arc4random() % 4 + 4) : (arc4random() % 4 + 2); // Для ранга S: 5-8 (health), 4-7 (mana), 2-5 (damage)
        }

        Characteristics.push_back(std::make_pair(nameCharacteristic[characteristicType], characteristicValue));
        }
}



void Item::generateName() {

    // Генерація імені для предмету
    const std::vector<std::string> adjectives = { "Могутній", "Священний", "Забутий", "Магічний", "Легендарний","Заборонений","" };

    const std::vector<std::string> nouns =
    { "Катана","Меч квітів", "Перстень","Посох","Посох Архімага","Страшний шолом","Хомяк","Cолом'яний шолом","Wi-Fi","Сендвіч","Факел","Кавун","Молочний продукт",
    "Знак","Онігірі","Бантик","Музичний інструмент","Шолом капітана","Шолом матроса","Небесний знак","Топор","Варварський топор","Дрин","Панда"};

    int adjectiveIndex = arc4random() % adjectives.size();
    int nounIndex = arc4random() % nouns.size();
    nameOfItem = adjectives[adjectiveIndex] + " " + nouns[nounIndex];

    generateImage(nouns[nounIndex]);

}

void Item::generateImage(const std::string& name) {

    auto it = itemImages_.find(name);
    if (it != itemImages_.end()) {

        imageOfItem = QPixmap(it->second);

    } else {

        imageOfItem = QPixmap(":/icon/img/axe.jpg");

    }
}

void Item::setName(std::string name){
    nameOfItem=name;
}


void Item::setDiscription(std::string discription){
    discriptionOfItem=discription;
}

void Item::setCharacteristics(std::string nameCharacteristic,double value){
    Characteristics.push_back({nameCharacteristic,value});
}

void Item::setEqipment(Equipment type){
    typeItem=type;
}

void Item::setImage(std::string name){
    QString fileName = QString::fromStdString(name);
    QPixmap imageOfItem(fileName); // Загрузка изображения из файла
}


//Функції getter для всіх змінних:
std::string Item::getRank()const{
    return rank;
}
std::string Item::getnameOfitem()const{
    return nameOfItem;
}
std::string Item::getdiscriptionOfItem()const{
    return discriptionOfItem;
}
std::vector<std::pair<std::string, int>> Item::getCharacteristics()const{
    return Characteristics;
}
Equipment Item::getTypeItem()const{
    return typeItem;
}

QPixmap Item::getImageOfItem() const {
    return imageOfItem;
}

int Item::getIndex()const{
    return index;
}

