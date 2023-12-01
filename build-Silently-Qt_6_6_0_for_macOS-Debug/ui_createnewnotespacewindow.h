/********************************************************************************
** Form generated from reading UI file 'createnewnotespacewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWNOTESPACEWINDOW_H
#define UI_CREATENEWNOTESPACEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateNewNoteSpaceWindow
{
public:
    QLabel *label;
    QLineEdit *lineEdit_NoteServiceName;
    QPushButton *pushButton_Add;

    void setupUi(QDialog *CreateNewNoteSpaceWindow)
    {
        if (CreateNewNoteSpaceWindow->objectName().isEmpty())
            CreateNewNoteSpaceWindow->setObjectName("CreateNewNoteSpaceWindow");
        CreateNewNoteSpaceWindow->resize(240, 320);
        label = new QLabel(CreateNewNoteSpaceWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 201, 31));
        lineEdit_NoteServiceName = new QLineEdit(CreateNewNoteSpaceWindow);
        lineEdit_NoteServiceName->setObjectName("lineEdit_NoteServiceName");
        lineEdit_NoteServiceName->setGeometry(QRect(60, 100, 113, 21));
        pushButton_Add = new QPushButton(CreateNewNoteSpaceWindow);
        pushButton_Add->setObjectName("pushButton_Add");
        pushButton_Add->setGeometry(QRect(70, 160, 100, 32));

        retranslateUi(CreateNewNoteSpaceWindow);

        QMetaObject::connectSlotsByName(CreateNewNoteSpaceWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateNewNoteSpaceWindow)
    {
        CreateNewNoteSpaceWindow->setWindowTitle(QCoreApplication::translate("CreateNewNoteSpaceWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CreateNewNoteSpaceWindow", "Enter name for new Note Service", nullptr));
        pushButton_Add->setText(QCoreApplication::translate("CreateNewNoteSpaceWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNewNoteSpaceWindow: public Ui_CreateNewNoteSpaceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWNOTESPACEWINDOW_H
