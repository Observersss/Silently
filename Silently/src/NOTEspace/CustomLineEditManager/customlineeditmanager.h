// customlineeditmanager.h
#ifndef CUSTOMLINEEDITMANAGER_H
#define CUSTOMLINEEDITMANAGER_H

#include <QObject>
#include <QVector>
#include <QLayout>
#include "../CustomLineEdit/customlineedit.h"

class CustomLineEditManager : public QObject
{
    Q_OBJECT
public:
    static CustomLineEditManager *getInstance(QObject *parent = nullptr);

    void setLayout(QLayout* layout);
    void create_CustomLineEdit();
    void clearLayout();

private:
    explicit CustomLineEditManager(QObject *parent = nullptr);
    static CustomLineEditManager *instance;
    QLayout* layout; // Layout для размещения CustomLineEdit
    QVector<CustomLineEdit*> lineEdits; // Вектор CustomLineEdit

    void delete_CustomLineEdit(CustomLineEdit* currentLineEdit);
    void focusNextCustomLineEdit(CustomLineEdit *currentLineEdit);
    void focusPrevCustomLineEdit(CustomLineEdit* currentLineEdit);
};

#endif // CUSTOMLINEEDITMANAGER_H
