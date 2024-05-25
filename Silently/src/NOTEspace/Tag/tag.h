#ifndef TAG_H
#define TAG_H

#include <QString>

class Tag{
private:
    QString tagName_;

    Tag(const QString& new_name_tag):tagName_(new_name_tag){}
public:
    static Tag create(const QString& new_name_tag_){
        return Tag(new_name_tag_);
    }

    QString getNameTag()const{
        return tagName_;
    }
};

#endif // TAG_H
