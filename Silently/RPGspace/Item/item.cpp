#include "item.h"

int Item::itemCount=0;
Item::Item(){
    itemCount+=1;
    index=itemCount;
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
