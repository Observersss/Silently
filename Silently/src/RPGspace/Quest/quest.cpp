#include "quest.h"
int Quest::idCount_ = -1;
Quest::Quest(){
    idCount_++;
    id_ = idCount_;
}

bool Quest::checkDeadline(){
    return deadline_ < QDateTime::currentDateTime();
}


void Quest::setTitle(const QString& newTitle){
    title_=newTitle;
}


void Quest::setDiscription(const QString& newDiscription){
    discription_=newDiscription;
}


void Quest::setDifficulti(const int& newDifficulty){
    difficulty_=newDifficulty;
}


void Quest::setDeadline(const QDateTime& newDeadline){
    deadline_=newDeadline;
}


int Quest::getId() const{
    return id_;
}
QString Quest::getTitle()const{
    return title_;
}
QString Quest::getDiscription()const{
    return discription_;
}
int Quest::getDifficulty()const{
    return difficulty_;
}
QDateTime Quest::getDeadline()const{
    return deadline_;
}
