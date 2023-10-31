#include "item.h"

int Item::itemCount=0;
Item::Item(){
    itemCount+=1;
    index=itemCount;

    generateRandomRank();
    generateCharacteristics();
    generateName();

}

void Item::generateRandomRank() {
        int randomRankIndex = std::rand() % 5; // Генерируем случайное число от 0 до 4

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
    // Генерация имени предмета
    const std::vector<std::string> adjectives = { "Могутній", "Священний", "Забутий", "Магічний", "Легендарний","Заборонений" };
        const std::vector<std::string> nouns =
        { "Катана","Меч квітів", "Перстень","Посох","Посох Архімага","Страшний шолом","Хомяк","Cолом'яний шолом","Wi-Fi","Сендвіч","Факел","Кавун","Молочний продукт",
        "Знак","Онігірі","Бантик","Музичний інструмент","Шолом капітана","Шолом матроса","Небесний знак","Топор","Варварський топор","Дрин","Панда"};
//    int adjectiveIndex = rand() % adjectives.size();
//    int nounIndex = rand() % nouns.size();
    int adjectiveIndex = arc4random() % adjectives.size();
    int nounIndex = arc4random() % nouns.size();
    nameOfItem = adjectives[adjectiveIndex] + " " + nouns[nounIndex];

    generateImage(nouns[nounIndex]);
}

void generateImage(const std::string& name) {
    if (itemImages_.find(name) != itemImages_.end()) {
            // Найдено изображение для данного имени
            imageOfItem = itemImages_[name];
    } else {
            // Изображение не найдено, обработайте это по вашему усмотрению
            // Например, установите изображение по умолчанию
            imageOfItem = QPixmap(":/icon/img/level-up-icon.jpg.avif");
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
