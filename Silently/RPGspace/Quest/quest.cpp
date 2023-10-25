#include "quest.h"
Quest::Quest(){}

bool Quest::checkDeadline()const{
    return deadline==std::chrono::system_clock::now();
}


void Quest::setTitle(std::string newTitle){
    title=newTitle;
}


void Quest::setDiscription(std::string newDiscription){
    discription=newDiscription;
}


void Quest::setDifficulti(int newDifficulty){
    difficulty=newDifficulty;
}


void Quest::setDeadline(std::chrono::system_clock::time_point newDeadline){
    deadline=newDeadline;
}


std::string Quest::getTitle()const{
    return title;
}
std::string Quest::getDiscription()const{
    return discription;
}
int Quest::getDifficulty()const{
    return difficulty;
}
std::chrono::system_clock::time_point Quest::getDeadline()const{
    return deadline;
}
