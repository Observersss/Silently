#ifndef NOTE_H
#define NOTE_H

#include <QVector>
#include <QDateTime>

#include "NOTEspace/Tag/tag.h"
class Note{
    private:
        QString title;
        QVector<QString> text;
        QVector<QString> styles;
        QDateTime data_time;
        QVector<Tag> activeTag;
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

        void setText(QVector<QString> newText);

        void setStyles(QVector<QString> _styles);

        void setTextWithStyles(std::pair<QVector<QString>,QVector<QString>> vectors);

        void setData_time(QDateTime timePoint);


        //додавання тегу
        //приймає Tag і передає у teg
        void addActiveTag(Tag newActiveTag);
        void addActiveTag(const QString& newActiveTag);
        void addActiveTag(QVector<QString> newActiveTags);

        void deleteTag(const QString& tagName);

        QVector<Tag> getActiveTag()const;

        QString getTitle()const;
        QVector<QString> getText()const;
        QVector<QString> getStyles()const;
        std::pair<QVector<QString>,QVector<QString>> getTextWithStyles();
        QDateTime getDataTime()const;
        int getIdNote()const;
};

#endif // NOTE_H
