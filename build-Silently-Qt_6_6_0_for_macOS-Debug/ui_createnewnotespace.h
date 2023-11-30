/********************************************************************************
** Form generated from reading UI file 'createnewnotespace.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWNOTESPACE_H
#define UI_CREATENEWNOTESPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_createNewNoteSpace
{
public:

    void setupUi(QDialog *createNewNoteSpace)
    {
        if (createNewNoteSpace->objectName().isEmpty())
            createNewNoteSpace->setObjectName("createNewNoteSpace");
        createNewNoteSpace->resize(240, 320);

        retranslateUi(createNewNoteSpace);

        QMetaObject::connectSlotsByName(createNewNoteSpace);
    } // setupUi

    void retranslateUi(QDialog *createNewNoteSpace)
    {
        createNewNoteSpace->setWindowTitle(QCoreApplication::translate("createNewNoteSpace", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createNewNoteSpace: public Ui_createNewNoteSpace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWNOTESPACE_H
