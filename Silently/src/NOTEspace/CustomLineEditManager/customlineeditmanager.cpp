// customlineeditmanager.cpp
#include "customlineeditmanager.h"

CustomLineEditManager *CustomLineEditManager::instance = nullptr;

CustomLineEditManager::CustomLineEditManager(QObject *parent) : QObject(parent) {}

CustomLineEditManager *CustomLineEditManager::getInstance(QObject *parent) {
    if (!instance) {
        instance = new CustomLineEditManager(parent);
    }
    return instance;
}

void CustomLineEditManager::setLayout(QLayout* layout){
    this->layout = layout;
}

void CustomLineEditManager::create_CustomLineEdit(){
    if(layout){
        CustomLineEdit* customLineEdit = CustomLineEditFactory::createCustomLineEdit();
        QLineEdit* lineEdit = customLineEdit->getlineEdit();
        connect(lineEdit, &QLineEdit::returnPressed,this,[=]{
            auto it = std::find(lineEdits.begin(), lineEdits.end(), customLineEdit);
            if (it != lineEdits.end() && std::next(it) == lineEdits.end()) {
                focusNextCustomLineEdit(customLineEdit);
                create_CustomLineEdit();
            } else {
                focusNextCustomLineEdit(customLineEdit);
            }
        });
        connect(lineEdit, &QLineEdit::textChanged, this,[=]{
            if(lineEdit->text().isEmpty()){
                focusPrevCustomLineEdit(customLineEdit);
                delete_CustomLineEdit(customLineEdit);
            }
        });
        layout->addWidget(customLineEdit);
        lineEdits.append(customLineEdit);
        lineEdit->setFocus();
    }
}
void CustomLineEditManager::delete_CustomLineEdit(CustomLineEdit* currentLineEdit) {
    if (layout) {
        int index = lineEdits.indexOf(currentLineEdit);
        if (index != -1 && index >= 0 && index < lineEdits.size()) {
            if (currentLineEdit->getlineEdit()->text().isEmpty()) {
                disconnect(currentLineEdit->getlineEdit(), nullptr, this, nullptr);
                layout->removeWidget(currentLineEdit);
                lineEdits.removeAt(index);
                currentLineEdit->deleteLater();
            }
        }
    }
}


void CustomLineEditManager::focusNextCustomLineEdit(CustomLineEdit *currentLineEdit)
{
    int index = lineEdits.indexOf(currentLineEdit);
    if (index != -1 && index + 1 < lineEdits.size()) {
        lineEdits[index + 1]->getlineEdit()->setFocus();
    }
}
void CustomLineEditManager::focusPrevCustomLineEdit(CustomLineEdit* currentLineEdit) {
    int index = lineEdits.indexOf(currentLineEdit);
    if (index != -1 && index != 0) {
        // Перевірка, чи елемент ще існує у списку lineEdits
        if (lineEdits.contains(currentLineEdit)) {
            lineEdits[index - 1]->getlineEdit()->setFocus();
        }
    }
}
void CustomLineEditManager::clearLayout(){
    if(layout){
        for(auto it : lineEdits){
            it->deleteLater();
        }
    }
}
