// customlineeditmanager.h
#ifndef CUSTOMLINEEDITMANAGER_H
#define CUSTOMLINEEDITMANAGER_H

#include <QObject>
#include <QVector>
#include <QLayout>
#include <QScrollArea>
#include "../CustomLineEdit/customlineedit.h"

class CustomLineEditManager : public QObject
{
    Q_OBJECT
public:
    static CustomLineEditManager *getInstance(QObject *parent = nullptr);

    void setLayoutAndScroolArea(QLayout* layout,QScrollArea* scroolArea);
    void create_CustomLineEdit();
    void clearLayout();
    void setTextForCustomLineEdit(QVector<QString> text);
    void setStyleForCustomLineEdit(QVector<QString> styles);
    void setTextWithStylesForCustomLineEdit(std::pair<QVector<QString>,QVector<QString>> vectors);
    QVector<QString> getTextFromLineEdits()const;
    QVector<QString> getStylesFromLineEdits()const;
    std::pair<QVector<QString>,QVector<QString>> getTextWithStyles();

private:
    explicit CustomLineEditManager(QObject *parent = nullptr);
    static CustomLineEditManager *instance;
    QLayout* layout; // Layout для размещения CustomLineEdit
    QScrollArea* scroolArea;
    QVector<CustomLineEdit*> lineEdits; // Вектор CustomLineEdit

    void create_CustomLineEdit_with_Text(QString text);
    void create_CustomLineEdit_with_Style(QString style);
    void create_CustomLineEdit_with_Text_and_Style(QString text,QString style);
    void delete_CustomLineEdit(CustomLineEdit* currentLineEdit);
    void focusNextCustomLineEdit(CustomLineEdit *currentLineEdit);
    void focusPrevCustomLineEdit(CustomLineEdit* currentLineEdit);
};

#endif // CUSTOMLINEEDITMANAGER_H
