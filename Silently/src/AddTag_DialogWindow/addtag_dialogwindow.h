#ifndef ADDTAG_DIALOGWINDOW_H
#define ADDTAG_DIALOGWINDOW_H

#include "mainwindow.h"
#include "NOTEspace/Tag/tag.h"

#include <QDialog>


namespace Ui {
class AddTag_DialogWindow;
}

class AddTag_DialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddTag_DialogWindow(QWidget *parent = nullptr,const QVector<Tag>* tags = nullptr);
    ~AddTag_DialogWindow();
private slots:
    void on_pushButton_clicked();
    void on_button_option_clicked();

private:
    Ui::AddTag_DialogWindow *ui;
    const QVector<Tag>* _tags;
    bool select_tag_frame_hide = false;
    bool create_tag_frame_hide = false;

};

#endif // ADDTAG_DIALOGWINDOW_H
