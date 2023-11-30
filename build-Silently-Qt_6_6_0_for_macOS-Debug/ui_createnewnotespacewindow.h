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

QT_BEGIN_NAMESPACE

class Ui_CreateNewNoteSpaceWindow
{
public:

    void setupUi(QDialog *CreateNewNoteSpaceWindow)
    {
        if (CreateNewNoteSpaceWindow->objectName().isEmpty())
            CreateNewNoteSpaceWindow->setObjectName("CreateNewNoteSpaceWindow");
        CreateNewNoteSpaceWindow->resize(240, 320);

        retranslateUi(CreateNewNoteSpaceWindow);

        QMetaObject::connectSlotsByName(CreateNewNoteSpaceWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateNewNoteSpaceWindow)
    {
        CreateNewNoteSpaceWindow->setWindowTitle(QCoreApplication::translate("CreateNewNoteSpaceWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNewNoteSpaceWindow: public Ui_CreateNewNoteSpaceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWNOTESPACEWINDOW_H
