#ifndef NOTESERVICE_H
#define NOTESERVICE_H

#include "NOTEspace/Note/note.h"

static const QString BASIC_NAME_NOTE = "Your first Note";

class NoteService{
public:
    void setNameSpaceNote(const QString& name);

    void addNote(std::shared_ptr<Note> note);

    void deleteNote(const QString& noteTitle);

    void addToAllTag(const QString& tagName);
    void addToAllTag(Tag tag);

    void setChangeNote(std::shared_ptr<Note> note);

    void setChangeNote(std::shared_ptr<Note> note,const QString& oldName);

    int findIdNote(const QString& nameNote);

    std::shared_ptr<Note> getFirstNote()const;

    std::shared_ptr<Note> getNote(const int& id);
    std::shared_ptr<Note> getNote(const QString& name);
    std::shared_ptr<Note> getNote(const QDateTime& dateOfCreation);

    template <typename T>
    std::shared_ptr<Note> getNote(const T& arg);

    QVector<std::shared_ptr<Note>> getAllNotes()const;

    QVector<Tag> getAllTags()const;

    QString getNameSpaceNote()const;

    std::unordered_map<QString,int> returnNameNoteAndNoteID()const;


protected:
    NoteService ();
    NoteService(const QString& nameSpace);

    template<typename T>
    std::shared_ptr<Note> findNote(const T& value);

    void addNewElement_to_NameNoteAndNoteID(const QString& title,const int& id);

    void changeInfo_into_NameNoteInVector(const QString& newName, const int& oldID);

    void removeElement_from_nameNoteAndNoteID(const int& id);

private:
    QString nameSpaceNote_;
    static QVector<Tag> allTag_;
    QVector<std::shared_ptr<Note>> notes_;
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
