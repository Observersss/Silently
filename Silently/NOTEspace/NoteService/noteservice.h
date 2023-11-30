#ifndef NOTESERVICE_H
#define NOTESERVICE_H
#include "Library/library.h"
#include "NOTEspace/Note/note.h"
class NoteService
{
    QString nameSpaceNote;
    std::vector<Note> notes;
    static std::vector<Tag> allTag;
public:
    NoteService();
    NoteService(QString nameSpace);

    void addNote(Note& note);

    void deleteNote(QString &noteTitle);

    Note getNote(QString &noteTitle);
    Note getNote(int &id);

    void setChangNote(Note note);
    void setChangNote(Note note,QString buffer);
    //void setChangNote(int& id,Note note);

    Note* getFirstNote();

    /*
     * Функция какая принимает std::chrono::system_clock::time_point используеться в случае сохранения заметки
     * т.к сравнивание по заголовку не подходит(его могут изменить в отличии от времени создания на какое пользователь влиять не может)
     * а в случае выгрузки заметки на экран пользователя то подходит проверка по заголовку заметки т.к будут храниться в списке QListWidget
     * где будет храниться их заголовок
    */
    bool noteExists(std::chrono::system_clock::time_point noteTime);
    bool noteExists(QString noteTitle);
    bool noteExists(int noteID);
    //bool tagExists(QString tagName);
    void tagsExists(const std::vector<QString> &tagNames);

    void setNameSpaceNote(QString name);

    void addToAllTag(QString tagName);

    std::vector<Note> getAllNotes()const;

    QString getNameSpaceNote()const;

    Note* getNotePtr(const QString& title);
    Note* getNotePtr(const int& id);

};

#endif // NOTESERVICE_H
