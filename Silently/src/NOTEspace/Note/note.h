#ifndef NOTE_H
#define NOTE_H

#include "NOTEspace/Tag/tag.h"


class Note{
    private:
        QString title;
        std::vector<QString> text;
        std::chrono::system_clock::time_point data_time;
        std::vector<Tag> activeTag;
        static int idMaxValue;
        int id;
    public:

        //базовий конструктор, який передає час створення
        Note();

        //задання заголовку
        //приймає string і передає у title
        void setTitle(QString newTitle);

        //задання тексту
        //приймає string і передає y text
        void setText(QString newText);

        void setText(std::vector<QString> newText);

        void setData_time(std::chrono::system_clock::time_point timePoint);


        //додавання тегу
        //приймає Tag і передає у teg
        void addActiveTag(Tag newActiveTag);
        void addActiveTag(const QString& newActiveTag);
        void addActiveTag(std::vector<QString> newActiveTags);

        void deleteTag(const QString& tagName);

        std::vector<Tag> getActiveTag()const;

        QString getTitle()const;
        std::vector<QString> getText()const;
        std::chrono::system_clock::time_point getDataTime()const;
        int getIdNote()const;
};

#endif // NOTE_H
