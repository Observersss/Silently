/********************************************************************************
** Form generated from reading UI file 'addnotespace_dialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOTESPACE_DIALOGWINDOW_H
#define UI_ADDNOTESPACE_DIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddNoteSpace_DialogWindow
{
public:
    QLabel *label;
    QLineEdit *lineEdit_NoteServiceName;
    QPushButton *pushButton_Add;

    void setupUi(QDialog *AddNoteSpace_DialogWindow)
    {
        if (AddNoteSpace_DialogWindow->objectName().isEmpty())
            AddNoteSpace_DialogWindow->setObjectName("AddNoteSpace_DialogWindow");
        AddNoteSpace_DialogWindow->resize(240, 320);
        label = new QLabel(AddNoteSpace_DialogWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 201, 31));
        lineEdit_NoteServiceName = new QLineEdit(AddNoteSpace_DialogWindow);
        lineEdit_NoteServiceName->setObjectName("lineEdit_NoteServiceName");
        lineEdit_NoteServiceName->setGeometry(QRect(50, 120, 113, 21));
        pushButton_Add = new QPushButton(AddNoteSpace_DialogWindow);
        pushButton_Add->setObjectName("pushButton_Add");
        pushButton_Add->setGeometry(QRect(60, 180, 100, 32));

        retranslateUi(AddNoteSpace_DialogWindow);

        QMetaObject::connectSlotsByName(AddNoteSpace_DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *AddNoteSpace_DialogWindow)
    {
        AddNoteSpace_DialogWindow->setWindowTitle(QCoreApplication::translate("AddNoteSpace_DialogWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddNoteSpace_DialogWindow", "Enter name for new Note Service", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("AddNoteSpace_DialogWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNoteSpace_DialogWindow: public Ui_AddNoteSpace_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTESPACE_DIALOGWINDOW_H
