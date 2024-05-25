#include "noteservice.h"

QVector<Tag> NoteService::allTag_;


NoteService::NoteService(){
    Note* note  = NoteFactory::create();
    nameSpaceNote_ = "FirstNoteSpace";
    note->setTitle(BASIC_NAME_NOTE);
    addNote(note);
    addNewElement_to_NameNoteAndNoteID(note->getTitle(),note->getIdNote());
}
NoteService::NoteService(const QString& nameSpace){
    nameSpaceNote_ = nameSpace;
    Note* note = NoteFactory::create();
    note->setTitle(BASIC_NAME_NOTE);
    addNote(note);
    addNewElement_to_NameNoteAndNoteID(note->getTitle(),note->getIdNote());
}
void NoteService::setNameSpaceNote(const QString &name){
    nameSpaceNote_ = name;
}

void NoteService::addNote(Note* note){
    if(!note->getTitle().isEmpty()){
        notes_.push_back(note);
        addNewElement_to_NameNoteAndNoteID(note->getTitle(),note->getIdNote());
    }else{
        throw std::runtime_error("Fail! Title is empty /NoteService::addNote(Note* note)");
        return;
    }
}

void NoteService::deleteNote(const QString& noteTitle) {
    Note* find = findNote(noteTitle);
    if (find != nullptr) {
        removeElement_from_nameNoteAndNoteID(find->getIdNote());
        int index = notes_.indexOf(find);
        if (index != -1) {
            notes_.remove(index);
        } else {
            throw std::runtime_error("Failed to find note 1 /NoteService::deleteNote");
        }
        delete find;
    } else {
        throw std::runtime_error("Failed to find note 1.1 /NoteService::deleteNote");
    }
}

void NoteService::addToAllTag(const QString& tagName){
    allTag_.push_back(Tag::create(tagName));
}

void NoteService::setChangeNote(Note *note){
    Note* find = findNote(note->getTitle());

    if(find != nullptr){
        *find = *note;
        changeInfo_into_NameNoteInVector(find->getTitle(),find->getIdNote());
        delete note;
    }else{
        throw std::runtime_error("Faild change note, Note* find == nullptr /NoteService::setChangeNote(Note *note)");
    }
}

void NoteService::setChangeNote(Note* note, const QString& oldName) {
    Note* find = findNote(oldName);

    if(find != nullptr){
        *find = *note;
        changeInfo_into_NameNoteInVector(find->getTitle(),find->getIdNote());
        delete note;
    }else{
        throw std::runtime_error("Faild change note, Note* find == nullptr /NoteService::setChangeNote(Note* note, const QString& oldName)");
    }
}

int NoteService::findIdNote(const QString& nameNote){
    return nameNoteAndNoteID_[nameNote];
}

Note* NoteService::getFirstNote() const{
    if(!notes_.isEmpty()){
        return notes_[0];
    }else{
        throw std::runtime_error("Fail! notes_ is empty /NoteService::getFirstNote()");
        return nullptr;
    }
}

Note* NoteService::getNote(const int& id){
    Note* find = findNote(id);
    if(find != nullptr){
        return find;
    }else{
        throw std::runtime_error("Fail! find is nullptr /NoteService::getNote(const int &id)");
        return nullptr;
    }
}
Note* NoteService::getNote(const QString& name){
    Note* find = findNote(name);
    if(find != nullptr){
        return find;
    }else{
        throw std::runtime_error("Fail! find is nullptr /NoteService::getNote(const QString& name)");
        return nullptr;
    }
}
Note* NoteService::getNote(const QDateTime& dateOfCreation){
    Note* find = findNote(dateOfCreation);
    if(find != nullptr){
        return find;
    }else{
        throw std::runtime_error("Fail! find is nullptr /NoteService::getNote(const QDateTime& dateOfCreation)");
        return nullptr;
    }
}
template <typename T>
Note* NoteService::getNote(const T& arg) {
    static_assert(std::is_same<T, int>::value || std::is_same<T, QString>::value || std::is_same<T, QDateTime>::value,
                  "Function getNote can only be called with int, QString, or QDateTime");
    return nullptr;
}
QVector<Note*> NoteService::getAllNotes()const{
    return notes_;
}
QVector<Tag> NoteService::getAllTags()const{
    return allTag_;
}
QString NoteService::getNameSpaceNote()const{
    return nameSpaceNote_;
}
std::unordered_map<QString,int> NoteService::returnNameNoteAndNoteID()const{
    return nameNoteAndNoteID_;
}
template<typename T>
Note* NoteService::findNote(const T& value){
    auto it = std::find_if(notes_.begin(), notes_.end(), [&value](const Note* note) {
        return *note == value;
    });

    if(it != notes_.end()){
        return *it;
    } else {
        throw std::runtime_error("Failed to find note /NoteService::findNote");
        return nullptr;
    }
}

void NoteService::addNewElement_to_NameNoteAndNoteID(const QString& title,const int& id){
    nameNoteAndNoteID_[title] = id;
}
void NoteService::changeInfo_into_NameNoteInVector(const QString& newName, const int& oldID) {
    auto it = std::find_if(nameNoteAndNoteID_.begin(), nameNoteAndNoteID_.end(),
                           [oldID](const auto& pair) { return pair.second == oldID; });

    if (it != nameNoteAndNoteID_.end()) {
        int value = it->second;
        nameNoteAndNoteID_.erase(it);
        nameNoteAndNoteID_[newName] = value;
    } else {
        //if element not founded
        throw std::runtime_error("Fail! cannot find element /NoteService::changeInfo_into_NameNoteInVector(const QString& newName,const int& oldID)");
    }
}

void NoteService::removeElement_from_nameNoteAndNoteID(const int& id){
    for (auto it = nameNoteAndNoteID_.begin(); it != nameNoteAndNoteID_.end(); ++it) {
        if (it->second == id) {
            nameNoteAndNoteID_.erase(it);
            return;
        }
    }
    //if element not founded
    throw std::runtime_error("Fail! cannot find element /NoteService::removeElement_from_nameNoteAndNoteID(const int& id)");
}
