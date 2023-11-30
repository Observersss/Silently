#include "noteservice.h"

std::vector<Tag> NoteService::allTag;

NoteService::NoteService()
{
    Note note;
    nameSpaceNote="FirstNoteSpace";
    note.setTitle("Your first note");
    notes.push_back(note);
    NameNoteAndNoteID.push_back(std::pair(note.getTitle(),note.getIdNote()));
}
NoteService::NoteService(QString nameSpace):nameSpaceNote(nameSpace){
    Note note;
    note.setTitle("Your first note");
    notes.push_back(note);
}
void NoteService::addNote(Note& note){
    notes.push_back(note);
}
void NoteService::deleteNote(QString &noteTitle){
    //Використовуюємо цикл foreach для перебору елементів вектора
    for (auto it = notes.begin(); it != notes.end(); ++it) {

        //Порівнюємо назву квеста з getTitile()
        if (it->getTitle() == noteTitle) {

            //Видаляємо квест з вектора
            notes.erase(it);
            break; //Ми знайшли і видалили квест тому виходимо з цикла
        }
    }
}
Note NoteService::getNote(QString &noteTitle){
    for (const Note& note : notes) {
        if (note.getTitle() == noteTitle) {
            return note; // Якщо квест знайшли то виходимо з функції
        }
    }

    //Квест не знайдемо виведеться помилка при перевірці чи повернуло квест
    Note note_error;
    note_error.setTitle(nullptr);
    return note_error;
}
Note NoteService::getNote(int &id){
    for (const Note& note : notes) {
        if (note.getIdNote() == id) {
            return note; // Якщо квест знайшли то виходимо з функції
        }
    }

    //Квест не знайдемо виведеться помилка при перевірці чи повернуло квест
    Note note_error;
    note_error.setTitle(nullptr);
    return note_error;
}

void NoteService::setChangNote(Note note){
    for (Note &existingNote : notes) {
        if (existingNote.getDataTime() == note.getDataTime()) {
            existingNote = note; // Заменяем существующий объект новым объектом
            return; // Можно выйти из цикла, так как объект найден и заменен
        }
    }
}

void NoteService::setChangNote(Note note,QString buffer){
    for (Note &existingNote : notes) {
        if (existingNote.getTitle() == buffer) {
            existingNote = note; // Заменяем существующий объект новым объектом
            return; // Можно выйти из цикла, так как объект найден и заменен
        }
    }
}
//void NoteService::setChangNote(int& id,Note &note){
//    for (Note &existingNote : notes) {
//        if (existingNote.getIdNote()==id) {
//            existingNote = note; // Заменяем существующий объект новым объектом
//            return; // Можно выйти из цикла, так как объект найден и заменен
//        }
//    }
//}

Note* NoteService::getFirstNote(){
    return &notes[0];
}

bool NoteService::noteExists(std::chrono::system_clock::time_point noteTime) {
    for (const Note& note : notes) {
        // Предполагаем, что getTime() возвращает время создания заметки типа std::chrono::system_clock::time_point
        if (note.getDataTime() == noteTime) {
            return true; // Если найдена заметка с указанным временем, возвращаем true
        }
    }
    return false; // Если заметка с указанным временем не найдена, возвращаем false
}
bool NoteService::noteExists(QString noteTitle){
    for (const Note& note : notes) {
        if (note.getTitle() == noteTitle) {
            qDebug()<<"Название заметки правильной заметки"<<note.getTitle();
            qDebug()<<"Название заметки"<<noteTitle;
            return true; // Нотатка з таким заголовком існує повертаємо true
        }
        qDebug()<<"Остальные заметки\n";
        qDebug()<<note.getTitle();
        //qDebug()<<"Название заметки"<<noteTitle;
    }
    return false;// Нотатка не існує тому false
}
bool NoteService::noteExists(int noteID){
    for (const Note& note : notes) {
        // Предполагаем, что getTime() возвращает время создания заметки типа std::chrono::system_clock::time_point
        if (note.getIdNote() == noteID) {
            qDebug()<<"ID какое нашло при проверки noteExists"<<note.getIdNote();
            return true; // Если найдена заметка с указанным временем, возвращаем true
        }
    }
    qDebug()<<"ID какое не найдено при проверки noteExists"<<noteID;
    return false; // Если заметка с указанным временем не найдена, возвращаем false
}

void NoteService::tagsExists(const std::vector<QString> &tagNames) {
    bool found = false;

    for (const QString &tagName : tagNames) {
        for (const Tag &tag : allTag) {
            if (tag.getNameTag() == tagName) {
                found = true;
                // Действия при совпадении тегов (можно добавить свой код)
                break;
            }
        }
        if (found) {
            // Если тег найден, можно добавить нужные действия здесь
            found = false; // Сброс флага
        } else {
            addToAllTag(tagName);
        }
    }
}

void NoteService::setNameSpaceNote(QString name){
    nameSpaceNote=name;
}
void NoteService::addToAllTag(QString tagName){
    Tag newTag(tagName);
    allTag.push_back(newTag);
}
std::vector<Note> NoteService::getAllNotes()const{
    return notes;
}
std::vector<Note>* NoteService::getAllNotesPtr(){
    return &notes;
}

QString NoteService::getNameSpaceNote() const{
    return nameSpaceNote;
}

Note* NoteService::getNotePtr(const int &id) {
    for (Note& note : notes) {
        if (note.getIdNote() == id) {
            return &note; // Возвращаем указатель на объект Note из списка notes
        }
    }
    return nullptr; // Если заметка не найдена, возвращаем nullptr
}
//Note* NoteService::getNotePtr(const int& id){
//    for (Note& note : notes) {
//        if (note.getIdNote() == id) {
//            return &note; // Возвращаем указатель на объект Note из списка notes
//        }
//    }
//    return nullptr; // Если заметка не найдена, возвращаем nullptr
//}

int NoteService::findIdNote(QString nameNote){
    for (const auto& pair : NameNoteAndNoteID) {
        if (pair.first == nameNote) {
            qDebug()<<"Название заметки при поиске findIdNote"<<pair.first;
            qDebug()<<"ID какое возвращает функция поиска findIdNote"<<pair.second;
            return pair.second; // Возвращаем идентификатор заметки, если найдено соответствие
        }
        qDebug()<<"Название заметки при поиске findIdNote"<<pair.first;
    }
    return -1; // Возвращаем -1, если заметка не найдена
}
void NoteService::changeNameNoteInVector(QString newName,int oldID){
    for (auto& pair : NameNoteAndNoteID) {
        if (pair.second == oldID) {
            pair.first = newName;
            qDebug()<<"Сохранение прошло успешно";
            return; // Если нашли идентификатор, меняем значение и выходим из цикла
        }
    }
    qDebug()<<"Сохранение не удалось";
}

void NoteService::removeNoteFromVector(int oldID){
    auto it = std::remove_if(NameNoteAndNoteID.begin(), NameNoteAndNoteID.end(),
                             [oldID](const auto& pair) { return pair.second == oldID; });

    if (it != NameNoteAndNoteID.end()) {
        NameNoteAndNoteID.erase(it, NameNoteAndNoteID.end());
    }
}
void NoteService::addNewElementToNameNoteAndNoteID(QString title,int id){
    NameNoteAndNoteID.push_back(std::pair(title,id));
}
std::vector<std::pair<QString,int>> NoteService::returnNameNoteAndNoteID()const{
    return NameNoteAndNoteID;
}

