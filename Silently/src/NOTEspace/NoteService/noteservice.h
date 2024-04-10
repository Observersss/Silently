#ifndef NOTESERVICE_H
#define NOTESERVICE_H

#include "NOTEspace/Note/note.h"


class NoteService
{
    QString nameSpaceNote;
    std::vector<Note> notes;
    std::vector<std::pair<QString,int>> NameNoteAndNoteID;
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

    Note* getFirstNote();

    bool noteExists(QDateTime  noteTime);
    bool noteExists(QString noteTitle);
    bool noteExists(int noteID);


    void tagsExists(const std::vector<QString> &tagNames);

    void setNameSpaceNote(QString name);

    void addToAllTag(QString tagName);

    std::vector<Note> getAllNotes()const;
    std::vector<Note>* getAllNotesPtr();

    QString getNameSpaceNote()const;

    Note* getNotePtr(const QString& title);
    Note* getNotePtr(const int& id);
    Note* getNotePtr(const QDateTime& data_create);

    int findIdNote(QString nameNote);
    void changeNameNoteInVector(QString newName,int oldID);

    void removeNoteFromVector(int oldID);

    void addNewElementToNameNoteAndNoteID(QString title,int id);

    std::vector<std::pair<QString,int>> returnNameNoteAndNoteID()const;

    static std::vector<Tag> getAllTags() {
        return allTag;
    }

};

#endif // NOTESERVICE_H
