#ifndef CREATENEWNOTESPACEWINDOW_H
#define CREATENEWNOTESPACEWINDOW_H

#include <QDialog>

namespace Ui {
class CreateNewNoteSpaceWindow;
}

class CreateNewNoteSpaceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewNoteSpaceWindow(QWidget *parent = nullptr);
    ~CreateNewNoteSpaceWindow();

private:
    Ui::CreateNewNoteSpaceWindow *ui;
};

#endif // CREATENEWNOTESPACEWINDOW_H
