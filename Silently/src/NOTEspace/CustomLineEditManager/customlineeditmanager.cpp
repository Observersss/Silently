// customlineeditmanager.cpp
#include "customlineeditmanager.h"
#include <qDebug>

CustomLineEditManager *CustomLineEditManager::instance = nullptr;

CustomLineEditManager::CustomLineEditManager(QObject *parent) : QObject(parent) {}

CustomLineEditManager *CustomLineEditManager::getInstance(QObject *parent) {
    if (!instance) {
        instance = new CustomLineEditManager(parent);
    }
    return instance;
}

void CustomLineEditManager::setLayoutAndScroolArea(QLayout* layout,QScrollArea* scroolArea){
    this->layout = layout;
    this->scroolArea = scroolArea;
}

void CustomLineEditManager::create_CustomLineEdit(){
    if(layout){
        CustomLineEdit* customLineEdit = CustomLineEditFactory::create();
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
        scroolArea->resize(scroolArea->width(),scroolArea->height()+30);
        layout->addWidget(customLineEdit);
        lineEdits.append(customLineEdit);
        lineEdit->setFocus();
    }
}
QVector<QString> CustomLineEditManager::getTextFromLineEdits()const{
    QVector<QString> textFromCustomLineEdits;
    if(layout){
        if(!lineEdits.isEmpty()){
            for(CustomLineEdit* widget : lineEdits){
                textFromCustomLineEdits.push_back(widget->text());
                qDebug()<<"Text from lineEdit: "<<widget->text()<<'\n';
            }
            return textFromCustomLineEdits;
        }else{
            return textFromCustomLineEdits;
        }

    }else{
        return textFromCustomLineEdits;
    }
}
QVector<QString> CustomLineEditManager::getStylesFromLineEdits()const{
    QVector<QString> stylesFromLineEdits;
    if(layout){
        if(!lineEdits.isEmpty()){
            for(CustomLineEdit* widget : lineEdits){
                stylesFromLineEdits.push_back(widget->style());
            }
            return stylesFromLineEdits;
        }else{
            return stylesFromLineEdits;
        }

    }else{
        return stylesFromLineEdits;
    }
}
std::pair<QVector<QString>, QVector<QString>> CustomLineEditManager::getTextWithStyles() {
    QVector<QString> textFromCustomLineEdits;
    QVector<QString> stylesFromLineEdits;

    if (layout) {

        if (lineEdits.isEmpty()) {

            for (CustomLineEdit* widget : lineEdits) {
                textFromCustomLineEdits.push_back(widget->text());
                stylesFromLineEdits.push_back(widget->styleSheet());
                qDebug()<<"getTextWithStyles Line : "<<widget->text()<<' '<<widget->styleSheet()<<'\n';
            }
            return std::make_pair(textFromCustomLineEdits, stylesFromLineEdits);
            qDebug()<<"getTextWithStyles Line : "<<textFromCustomLineEdits.size();

        } else {
            return std::make_pair(textFromCustomLineEdits, stylesFromLineEdits);
            qDebug()<<"getTextWithStyles Line : "<<textFromCustomLineEdits.size();
        }

    } else {
        return std::make_pair(textFromCustomLineEdits, stylesFromLineEdits);
        qDebug()<<"getTextWithStyles Line : "<<textFromCustomLineEdits.size();
    }
    qDebug()<<"getTextWithStyles Line : "<<textFromCustomLineEdits.size();
}

void CustomLineEditManager::setTextForCustomLineEdit(QVector<QString> text){
    if(layout){
        if(lineEdits.isEmpty()){
            for(int i = 0; i < text.size();i++){
                create_CustomLineEdit_with_Text(text[i]);
                qDebug()<<"Text from lineEdit create: "<<text[i]<<'\n';
              }
        }else{
            create_CustomLineEdit();
        }
    }
}
void CustomLineEditManager::setStyleForCustomLineEdit(QVector<QString> styles){
    if(layout){
        if(!lineEdits.isEmpty()){
            for(int i = 0; i < styles.size();i++){
                create_CustomLineEdit_with_Style(styles[i]);
            }
        }else{
            create_CustomLineEdit();
        }
    }
}
void CustomLineEditManager::setTextWithStylesForCustomLineEdit(std::pair<QVector<QString>,QVector<QString>> vectors){
    if(layout){
        if(lineEdits.isEmpty()){
            for(int i = 0; i < vectors.first.size();i++){
                create_CustomLineEdit_with_Text_and_Style(vectors.first[i],vectors.second[i]);
                qDebug()<<"setTextWithStylesForCustomLineEdit Line : "<<vectors.first[i]<<' '<<vectors.second[i]<<'\n';
            }
        }else{
            create_CustomLineEdit();
        }
    }
}
void CustomLineEditManager::create_CustomLineEdit_with_Text(QString text){
    if(layout){
        CustomLineEdit* customLineEdit = CustomLineEditFactory::create_with_text(text);
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
        scroolArea->resize(scroolArea->width(),scroolArea->height()+30);
        layout->addWidget(customLineEdit);
        lineEdits.append(customLineEdit);
        lineEdit->setFocus();
    }
}
void CustomLineEditManager::create_CustomLineEdit_with_Style(QString style){
    if(layout){
        CustomLineEdit* customLineEdit = CustomLineEditFactory::create_with_style(style);
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
        scroolArea->resize(scroolArea->width(),scroolArea->height()+30);
        layout->addWidget(customLineEdit);
        lineEdits.append(customLineEdit);
        lineEdit->setFocus();
    }
}
void CustomLineEditManager::create_CustomLineEdit_with_Text_and_Style(QString text,QString style){
    if(layout){
        CustomLineEdit* customLineEdit = CustomLineEditFactory::create_with_text_and_style(text,style);
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
        lineEdit->setText(text);
        lineEdit->setStyleSheet(style);
        scroolArea->resize(scroolArea->width(),scroolArea->height()+30);
        layout->addWidget(customLineEdit);
        lineEdits.append(customLineEdit);
        lineEdit->setFocus();
    }
}
void CustomLineEditManager::delete_CustomLineEdit(CustomLineEdit* currentLineEdit) {
    if (layout) {
        int index = lineEdits.indexOf(currentLineEdit);
        if (index != -1 && index > 0 && index < lineEdits.size()) {
            if (currentLineEdit->getlineEdit()->text().isEmpty()) {
                disconnect(currentLineEdit->getlineEdit(), nullptr, this, nullptr);
                layout->removeWidget(currentLineEdit);
                lineEdits.removeAt(index);
                currentLineEdit->deleteLater();

                scroolArea->resize(scroolArea->width(),scroolArea->height()-30);
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
            scroolArea->resize(scroolArea->width(),scroolArea->height()-30);
        }
        lineEdits.clear();
        //create_CustomLineEdit();
    }
}
