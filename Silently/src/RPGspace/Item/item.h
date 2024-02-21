#ifndef ITEM_H
#define ITEM_H

#include<QString>
#include <QPixmap>
#include <map>

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

class Item{
private:
    QString rank;
    QString nameOfItem;
    QString discriptionOfItem;
    std::vector<std::pair<QString ,int>> Characteristics;
    Equipment typeItem;
    QPixmap imageOfItem;
    static int itemCount; // Статична змінна для підрахунку елементів
    int index; // Індекс предмета
    static std::map<QString, QString> itemImages_;


public:

    //Пустий базовий конструктор
    Item();

    void generateRandomRank();

    void generateCharacteristics();

    void generateName();

    void generateImage(const QString& name);



    //Задання рангу предмета
    void setRank();


    //задання ім'я предмету
    //Прймае string (звичану назву) і передає у nameOfItem
    void setName(QString name);


    //Задання опису
    //Приймає string і передає у  discriptionOfItem
    void setDiscription(QString discription);


    //Задання бонусів які надає предмет
    //Приймає string(назва характеристики) і double(значення)
    //Передає у вектор Characteristics у вигляді пари
    void setCharacteristics(QString nameCharacteristic,double value);

    //Задання типу предмета
    //Приймає int і передає у typeItem
    void setEqipment(Equipment type);

    //Задання зображення предмету
    //Приймає string(повний шлях до зображення і передає у imageOfItem
    void setImage(QString name);


    //Геттери
    QString getRank()const;
    QString getnameOfitem()const;
    QString getdiscriptionOfItem()const;
    std::vector<std::pair<QString, int>> getCharacteristics() const;
    Equipment getTypeItem()const;
    QPixmap getImageOfItem() const;
    int getIndex()const;
};


#endif // ITEM_H
