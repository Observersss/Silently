#include "quest.h"
int Quest::idCount = -1;
Quest::Quest(){
    idCount++;
    id = idCount;
}

bool Quest::checkDeadline()const{
    return deadline==std::chrono::system_clock::now();
}


void Quest::setTitle(QString newTitle){
    title=newTitle;
}


void Quest::setDiscription(QString newDiscription){
    discription=newDiscription;
}


void Quest::setDifficulti(int newDifficulty){
    difficulty=newDifficulty;
}


void Quest::setDeadline(std::chrono::system_clock::time_point newDeadline){
    deadline=newDeadline;
}


int Quest::getId() const{
    return id;
}
QString Quest::getTitle()const{
    return title;
}
QString Quest::getDiscription()const{
    return discription;
}
int Quest::getDifficulty()const{
    return difficulty;
}
std::chrono::system_clock::time_point Quest::getDeadline()const{
    return deadline;
}
