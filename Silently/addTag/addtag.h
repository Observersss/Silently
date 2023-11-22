#ifndef ADDTAG_H
#define ADDTAG_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class AddTag;
}

class AddTag : public QDialog
{
    Q_OBJECT

public:
    explicit AddTag(QWidget *parent = nullptr);
    ~AddTag();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddTag *ui;
};

#endif // ADDTAG_H
