/********************************************************************************
** Form generated from reading UI file 'showinfoquest.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWINFOQUEST_H
#define UI_SHOWINFOQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ShowInfoQuest
{
public:

    void setupUi(QDialog *ShowInfoQuest)
    {
        if (ShowInfoQuest->objectName().isEmpty())
            ShowInfoQuest->setObjectName("ShowInfoQuest");
        ShowInfoQuest->resize(320, 240);

        retranslateUi(ShowInfoQuest);

        QMetaObject::connectSlotsByName(ShowInfoQuest);
    } // setupUi

    void retranslateUi(QDialog *ShowInfoQuest)
    {
        ShowInfoQuest->setWindowTitle(QCoreApplication::translate("ShowInfoQuest", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowInfoQuest: public Ui_ShowInfoQuest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINFOQUEST_H
