#include "note.h"

std::vector<Tag> Note::allTag;

Note::Note(){
    data_time = std::chrono::system_clock::now();
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

void Note::addActiveTag(Tag newActiveTag){
    activeTag.push_back(newActiveTag);

    allTag.push_back(newActiveTag);
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



