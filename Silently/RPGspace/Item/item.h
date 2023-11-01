#ifndef ITEM_H
#define ITEM_H
#include "Library/library.h"
//Перечислення можливих варіантів спорядження, буде використовуватись для классу активного спорядження
enum Equipment{
    WEAPON,
    PETS,
    HELMET,
    LEGGINGS,
    BOOTS,
    CHESTPLATE,
    RING,
    GLOVES,
    CLOAKS
};

//место сравнения индексов в целом можна просто сравнивать сами обьекты
//или создать компараторы для сравнения чтобы сравнение ишло быстрее
class Item{
private:
    std::string rank;
    std::string nameOfItem;
    std::string discriptionOfItem;
    std::vector<std::pair<std::string ,int>> Characteristics;
    Equipment typeItem;
    QPixmap imageOfItem;
    static int itemCount; // Статична змінна для підрахунку елементів
    int index; // Індекс предмета
    //static std::map<std::string, QPixmap> itemImages_;


public:
    //Пустий базовий конструктор
    Item();

    void generateRandomRank();

    void generateCharacteristics();

    void generateName();

    void generateImage(const std::string& name);



    //Задання рангу предмета
    void setRank();


    //задання ім'я предмету
    //Прймае string (звичану назву) і передає у nameOfItem
    void setName(std::string name);


    //Задання опису
    //Приймає string і передає у  discriptionOfItem
    void setDiscription(std::string discription);


    //Задання бонусів які надає предмет
    //Приймає string(назва характеристики) і double(значення)
    //Передає у вектор Characteristics у вигляді пари
    void setCharacteristics(std::string nameCharacteristic,double value);

    //Задання типу предмета
    //Приймає int і передає у typeItem
    void setEqipment(Equipment type);

    //Задання зображення предмету
    //Приймає string(повний шлях до зображення і передає у imageOfItem
    void setImage(std::string name);


    //Геттери
    std::string getnameOfitem()const;
    std::string getdiscriptionOfItem()const;
    std::vector<std::pair<std::string, int>> getCharacteristics() const;
    Equipment getTypeItem()const;
    QPixmap getImageOfItem() const;
    int getIndex()const;
};


#endif // ITEM_H
