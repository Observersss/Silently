#include "note.h"
int Note::idMaxValue=0;

Note::Note(){
    data_time = QDateTime::currentDateTime();
    idMaxValue+=1;
    id=idMaxValue;
    text.push_back("f");
    styles.push_back("QLineEdit {height:20px; border: 1px solid silver; border-radius: 8px; color: black; }");
}

void Note::setTitle(QString newTitle){
    title = newTitle;
}

void Note::setText(QString newText){
    text.push_back(newText);
}


void Note::setText(QVector <QString> newText){
    text = newText;
}
void Note::setStyles(QVector <QString> _styles){
    styles = _styles;
}
void Note::setTextWithStyles(std::pair<QVector<QString>,QVector<QString>> vectors){
    text = vectors.first;
    styles = vectors.second;
}
void Note::setData_time(QDateTime  timePoint){
    data_time = timePoint;
}

void Note::addActiveTag(Tag newActiveTag){
    activeTag.push_back(newActiveTag);
}
void Note::addActiveTag(const QString& newActiveTag) {
    Tag newTag(newActiveTag);
    activeTag.push_back(newTag);
}
void Note::addActiveTag(QVector <QString> newActiveTags){
//    for(QString& tagName:newActiveTags){
//        addActiveTag(tagName);
//    }
    activeTag.clear();
    for(QString& tagname:newActiveTags){
        Tag tag(tagname);
        activeTag.push_back(tag);
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



QVector <Tag> Note::getActiveTag()const{return activeTag;}

QString Note::getTitle()const{return title;}

QVector <QString> Note::getText()const{return text;}

QVector <QString> Note::getStyles()const{return styles;}

std::pair<QVector<QString>,QVector<QString>> Note::getTextWithStyles(){
    return std::make_pair(text,styles);
}

QDateTime  Note::getDataTime()const{return data_time;}

int Note::getIdNote()const{ return id; }
