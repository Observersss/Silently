#include "quest.h"
int Quest::idCount_ = -1;
Quest::Quest(){
    idCount_++;
    id_ = idCount_;
}

bool Quest::checkDeadline(){
    return deadline_ < QDateTime::currentDateTime();
}


void Quest::setTitle(const QString& title){
    title_ = title;
}


void Quest::setDescription(const QString& description){
    description_ = description;
}


void Quest::setComplexity(const int& complexity){
    complexity_ = complexity;
}


void Quest::setDeadline(const QDateTime& deadline){
    deadline_ = deadline;
}
void Quest::switch_need_to_follow_the_deadline(){
    need_to_follow_the_deadline == true ? false : true;
}

int Quest::getId() const{
    return id_;
}
QString Quest::getTitle()const{
    return title_;
}
QString Quest::getDescription()const{
    return description_;
}
int Quest::getComplexity()const{
    return complexity_;
}
QDateTime Quest::getDeadline()const{
    return deadline_;
}
