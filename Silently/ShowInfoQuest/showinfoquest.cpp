#include "showinfoquest.h"
#include "ui_showinfoquest.h"

ShowInfoQuest::ShowInfoQuest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowInfoQuest)
{
    ui->setupUi(this);
}

ShowInfoQuest::~ShowInfoQuest()
{
    delete ui;
}
