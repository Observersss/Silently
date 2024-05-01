#ifndef NOTESERVICE_H
#define NOTESERVICE_H

#include "NOTEspace/Note/note.h"


// class NoteService
// {
//     QString nameSpaceNote;
//     std::vector<Note> notes;
//     std::vector<std::pair<QString,int>> NameNoteAndNoteID;
//     static std::vector<Tag> allTag;
// public:
//     NoteService();
//     NoteService(QString nameSpace);

//     void addNote(Note& note);

//     void deleteNote(QString &noteTitle);

//     Note getNote(QString &noteTitle);
//     Note getNote(int &id);

//     void setChangNote(Note note);
//     void setChangNote(Note note,QString buffer);

//     Note* getFirstNote();

//     bool noteExists(QDateTime  noteTime);
//     bool noteExists(QString noteTitle);
//     bool noteExists(int noteID);


//     void tagsExists(const std::vector<QString> &tagNames);

//     void setNameSpaceNote(QString name);

//     void addToAllTag(QString tagName);

//     std::vector<Note> getAllNotes()const;
//     std::vector<Note>* getAllNotesPtr();

//     QString getNameSpaceNote()const;

//     Note* getNotePtr(const QString& title);
//     Note* getNotePtr(const int& id);
//     Note* getNotePtr(const QDateTime& data_create);

//     int findIdNote(QString nameNote);
//     void changeNameNoteInVector(QString newName,int oldID);

//     void removeNoteFromVector(int oldID);

//     void addNewElementToNameNoteAndNoteID(QString title,int id);

//     std::vector<std::pair<QString,int>> returnNameNoteAndNoteID()const;

//     static std::vector<Tag> getAllTags() {
//         return allTag;
//     }

// };

static const QString BASIC_NAME_NOTE = "Your first Note";

class NoteService{
public:
    void setNameSpaceNote(const QString& name);

    void addNote(Note* note);

    void deleteNote(const QString& noteTitle);

    void addToAllTag(const QString& tagName);

    void setChangeNote(Note* note);

    void setChangeNote(Note *note,const QString& oldName);

    int findIdNote(const QString& nameNote);

    Note* getFirstNote()const;

    Note* getNote(const int& id);
    Note* getNote(const QString& name);
    Note* getNote(const QDateTime& dateOfCreation);

    template <typename T>
    Note* getNote(const T& arg);

    QVector<Note*> getAllNotes()const;

    QVector<Tag> getAllTags()const;

    QString getNameSpaceNote()const;

    std::unordered_map<QString,int> returnNameNoteAndNoteID()const;


protected:
    NoteService ();
    NoteService(const QString& nameSpace);

    template<typename T>
    Note* findNote(const T& value);

    void addNewElement_to_NameNoteAndNoteID(const QString& title,const int& id);

    void changeInfo_into_NameNoteInVector(const QString& newName, const int& oldID);

    void removeElement_from_nameNoteAndNoteID(const int& id);

private:
    QString nameSpaceNote_;
    static QVector<Tag> allTag_;
    QVector<Note*> notes_;
    std::unordered_map <QString,int> nameNoteAndNoteID_;

    friend class NoteServiceFactory;
};

class NoteServiceFactory{
public:
    static NoteService create(){
        return NoteService();
    }
    static NoteService create_with_text(const QString& name){
        return NoteService(name);
    }
};

#endif // NOTESERVICE_H
