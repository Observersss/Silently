/********************************************************************************
** Form generated from reading UI file 'addtag.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTAG_H
#define UI_ADDTAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddTag
{
public:
    QLineEdit *tagName;
    QPushButton *pushButton;

    void setupUi(QDialog *AddTag)
    {
        if (AddTag->objectName().isEmpty())
            AddTag->setObjectName("AddTag");
        AddTag->resize(240, 320);
        tagName = new QLineEdit(AddTag);
        tagName->setObjectName("tagName");
        tagName->setGeometry(QRect(40, 120, 113, 21));
        tagName->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));
        pushButton = new QPushButton(AddTag);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 220, 100, 32));

        retranslateUi(AddTag);

        QMetaObject::connectSlotsByName(AddTag);
    } // setupUi

    void retranslateUi(QDialog *AddTag)
    {
        AddTag->setWindowTitle(QCoreApplication::translate("AddTag", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("AddTag", "Add tag", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTag: public Ui_AddTag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTAG_H
