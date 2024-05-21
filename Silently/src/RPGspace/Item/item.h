#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <QString>
#include <map>

//Перечислення можливих варіантів спорядження, буде використовуватись для классу активного спорядження
enum Equipment{
    WEAPON = 0,
    PETS = 1,
    HELMET = 2,
    LEGGINGS = 3,
    BOOTS = 4,
    CHESTPLATE = 5,
    RING = 6,
    GLOVES = 7,
    ANOTHER = 8
};

class Item{
public:

    QString getRank()const;
    QString getnameOfitem()const;
    QString getdescriptionOfItem()const;
    std::map<QString,int> getCharacteristics() const;
    Equipment getTypeItem()const;
    QString getPathToImg() const;
    int getIndex()const;
    ~Item();

protected:
    Item();
    void setRank(const QString& rank);
    void setName(const QString& name);
    void setDescription(const QString& description);
    void setCharacteristics(const std::map<QString,int>& characteristics);
    void setTypeOfItem(const Equipment& type);
    void setPathToImg(const QString& name);

private:
    QString rank_;
    QString nameOfItem_;
    QString descriptionOfItem_;
    std::map<QString,int> characteristics_;
    Equipment typeItem_;
    QString pathToImg_;
    int index_;
    static int itemCount_;

    friend class DefaultItemGenerator;
};



class ItemGeneratorStrategy{
protected:
    virtual Item* generateItem() = 0;
    virtual ~ItemGeneratorStrategy() = default;

    //Basic
    QString generateRank();
    std::map<QString,int> generateCharacteristics(const QString &rank);
    QString generatePathToImg(const QString& name);
    Equipment generateTypeOfItem(const QString& name);
    //first - fullname, second - basic name
    std::pair<QString,QString> generateName();

    //if needs new generate...

};

class DefaultItemGenerator: public ItemGeneratorStrategy{
protected:
    Item* generateItem() override;

    friend class ItemFactory;
};

class ItemFactory{
    static Item* create_by_default(){
        DefaultItemGenerator generator;
        return generator.generateItem();
    }
};


#endif // ITEM_H
