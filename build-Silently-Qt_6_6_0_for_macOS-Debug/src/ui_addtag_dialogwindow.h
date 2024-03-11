/********************************************************************************
** Form generated from reading UI file 'addtag_dialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTAG_DIALOGWINDOW_H
#define UI_ADDTAG_DIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddTag_DialogWindow
{
public:
    QPushButton *pushButton;
    QLineEdit *tagName;

    void setupUi(QDialog *AddTag_DialogWindow)
    {
        if (AddTag_DialogWindow->objectName().isEmpty())
            AddTag_DialogWindow->setObjectName("AddTag_DialogWindow");
        AddTag_DialogWindow->resize(240, 320);
        pushButton = new QPushButton(AddTag_DialogWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 250, 100, 32));
        tagName = new QLineEdit(AddTag_DialogWindow);
        tagName->setObjectName("tagName");
        tagName->setGeometry(QRect(120, 150, 113, 21));
        tagName->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));

        retranslateUi(AddTag_DialogWindow);

        QMetaObject::connectSlotsByName(AddTag_DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *AddTag_DialogWindow)
    {
        AddTag_DialogWindow->setWindowTitle(QCoreApplication::translate("AddTag_DialogWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("AddTag_DialogWindow", "Add tag", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTag_DialogWindow: public Ui_AddTag_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTAG_DIALOGWINDOW_H
