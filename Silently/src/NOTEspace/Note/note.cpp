#include "note.h"
int Note::idMaxValue_=0;

Note::Note(){
    dateOfCreation_ = QDateTime::currentDateTime();
    idMaxValue_+=1;
    id_=idMaxValue_;
    text_.push_back(" ");
}

void Note::setTitle(const QString& newTitle){
    title_ = newTitle;
}

void Note::setText(const QString& newText){
    text_.push_back(newText);
}


void Note::setText(const QVector<QString>& newText){
    text_ = newText;
}
void Note::setStyles(const QVector<QString>& _styles){
    styles_ = _styles;
}
void Note::setTextWithStyles(const std::pair<QVector<QString>,QVector<QString>>& vectors){
    text_ = vectors.first;
    styles_ = vectors.second;
}
void Note::setData_time(const QDateTime&  timePoint){
    dateOfCreation_ = timePoint;
}

void Note::addActiveTag(const QString& newActiveTag) {
    activeTag_.push_back(Tag::create(newActiveTag));
}
void Note::addActiveTag(Tag tag){
    activeTag_.push_back(tag);
}
void Note::setNewActiveTags(const QVector<QString>& newActiveTags){
    activeTag_.clear();
    for(const QString& tagname:newActiveTags){
        activeTag_.push_back(Tag::create(tagname));
    }
}

void Note::deleteTag(const QString& tagName) {
    auto it = activeTag_.begin();
    while (it != activeTag_.end()) {
        if (it->getNameTag() == tagName) {
            it = activeTag_.erase(it);
        } else {
            ++it;
        }
    }
}



QVector <Tag> Note::getActiveTag()const{return activeTag_;}

QString Note::getTitle()const{return title_;}

QVector <QString> Note::getText()const{return text_;}

QVector <QString> Note::getStyles()const{return styles_;}

std::pair<QVector<QString>,QVector<QString>> Note::getTextWithStyles()const {
    return std::make_pair(text_,styles_);
}

QDateTime  Note::getDataTime()const{return dateOfCreation_;}

int Note::getIdNote()const{ return id_; }
