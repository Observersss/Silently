#ifndef NOTE_H
#define NOTE_H

#include <QVector>
#include <QDateTime>
#include <memory>

#include "NOTEspace/Tag/tag.h"
class Note{

public:

    //базовий конструктор, який передає час створення
    Note();

    //задання заголовку
    //приймає string і передає у title
    void setTitle(const QString& newTitle);

    //задання тексту
    //приймає string і передає y text
    void setText(const QString& newText);
    void setText(const QVector<QString>& newText);

    void setStyles(const QVector<QString>& _styles);

    void setTextWithStyles(const std::pair<QVector<QString>,QVector<QString>>& vectors);

    void setData_time(const QDateTime& timePoint);

    void addActiveTag(const QString& newActiveTag);
    void addActiveTag(Tag tag);
    void setNewActiveTags(const QVector<QString>& newActiveTags);

    void deleteTag(const QString& tagName);

    QVector<Tag> getActiveTag()const;

    QString getTitle()const;
    QVector<QString> getText()const;
    QVector<QString> getStyles()const;
    std::pair<QVector<QString>,QVector<QString>> getTextWithStyles() const;
    QDateTime getDataTime()const;
    int getIdNote()const;

    bool operator== (const QString& otherTitle) const {
        return this->title_ == otherTitle;
    }
    bool operator== (const int& otherId) const{
        return this->id_ == otherId;
    }
    bool operator== (const QDateTime& otherDateOfCreation) const{
        return this->dateOfCreation_ == otherDateOfCreation;
    }

    std::shared_ptr<Note>& operator=(const std::shared_ptr<Note>& other) {
        // if (this != &other) {
            this->title_ = other->title_;
            this->dateOfCreation_ = other->dateOfCreation_;
            this->id_ = other->id_;
            this->text_ = other->text_;
            this->styles_ = other->styles_;
            this->activeTag_ = other->activeTag_;
        // }
        // return this;
    }

private:
    QString title_;
    QVector<QString> text_;
    QVector<QString> styles_;
    QDateTime dateOfCreation_;
    QVector<Tag> activeTag_;
    static int idMaxValue_;
    int id_;
};

class NoteFactory{
public:
    static std::shared_ptr<Note> create(){
        return std::make_shared<Note>();
    }
};

#endif // NOTE_H
