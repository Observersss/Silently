#ifndef TAG_H
#define TAG_H

#include <QString>

class Tag{
private:
    QString tagName;

public:
    //базовий пустий конструктор
    Tag(QString new_name_tag){tagName=new_name_tag;}

    QString getNameTag()const{
        return tagName;
    }


};

#endif // TAG_H
