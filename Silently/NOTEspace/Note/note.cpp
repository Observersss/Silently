#include "note.h"
int Note::idMaxValue=0;

Note::Note(){
    data_time = std::chrono::system_clock::now();
    idMaxValue+=1;
    id=idMaxValue;
}

void Note::setTitle(QString newTitle){
    title = newTitle;
}

void Note::setText(QString newText){
    text.push_back(newText);
}


void Note::setText(std::vector<QString> newText){
    text = newText;
}
void Note::setData_time(std::chrono::system_clock::time_point timePoint){
    data_time = timePoint;
}

void Note::addActiveTag(Tag newActiveTag){
    activeTag.push_back(newActiveTag);
}
void Note::addActiveTag(const QString& newActiveTag) {
    Tag newTag(newActiveTag);
    activeTag.push_back(newTag);
}
void Note::addActiveTag(std::vector<QString> newActiveTags){
    for(QString& tagName:newActiveTags){
        addActiveTag(tagName);
    }
}

void Note::deleteTag(const QString& tagName) {
    // Создайте итератор для перебора элементов вектора activeTag
    auto it = activeTag.begin();

    // Используйте цикл для поиска тега с заданным именем
    while (it != activeTag.end()) {
        if (it->getNameTag() == tagName) {
            // Если найден тег с заданным именем, удаляем его из вектора
            it = activeTag.erase(it);
        } else {
            // В противном случае, переходим к следующему элементу вектора
            ++it;
        }
    }
}



std::vector<Tag> Note::getActiveTag()const{return activeTag;}

QString Note::getTitle()const{return title;}

std::vector<QString> Note::getText()const{return text;}

std::chrono::system_clock::time_point Note::getDataTime()const{return data_time;}
int Note::getIdNote()const{
    return id;
}
