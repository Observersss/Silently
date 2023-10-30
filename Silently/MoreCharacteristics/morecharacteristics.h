#ifndef MORECHARACTERISTICS_H
#define MORECHARACTERISTICS_H

#include <QDialog>
#include "RPGspace/Character/character.h"
namespace Ui {
class MoreCharacteristics;
}

class MoreCharacteristics : public QDialog
{
    Q_OBJECT

public:
    explicit MoreCharacteristics(QWidget *parent = nullptr,Character maincharacter=Character());
    ~MoreCharacteristics();

private:
    Ui::MoreCharacteristics *ui;
    Character character;
};

#endif // MORECHARACTERISTICS_H
