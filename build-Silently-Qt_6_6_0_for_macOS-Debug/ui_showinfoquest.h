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
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ShowInfoQuest
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Title_label;
    QLineEdit *Title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Discription_label;
    QLineEdit *Discription;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Difficulty_label;
    QLineEdit *Difficulty;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QPushButton *change_button;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Delete_Quest;
    QPushButton *Quest_complete;

    void setupUi(QDialog *ShowInfoQuest)
    {
        if (ShowInfoQuest->objectName().isEmpty())
            ShowInfoQuest->setObjectName("ShowInfoQuest");
        ShowInfoQuest->resize(328, 382);
        gridLayout = new QGridLayout(ShowInfoQuest);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(ShowInfoQuest);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Title_label = new QLabel(ShowInfoQuest);
        Title_label->setObjectName("Title_label");

        horizontalLayout->addWidget(Title_label);

        Title = new QLineEdit(ShowInfoQuest);
        Title->setObjectName("Title");

        horizontalLayout->addWidget(Title);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Discription_label = new QLabel(ShowInfoQuest);
        Discription_label->setObjectName("Discription_label");

        horizontalLayout_2->addWidget(Discription_label);

        Discription = new QLineEdit(ShowInfoQuest);
        Discription->setObjectName("Discription");

        horizontalLayout_2->addWidget(Discription);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Difficulty_label = new QLabel(ShowInfoQuest);
        Difficulty_label->setObjectName("Difficulty_label");

        horizontalLayout_3->addWidget(Difficulty_label);

        Difficulty = new QLineEdit(ShowInfoQuest);
        Difficulty->setObjectName("Difficulty");

        horizontalLayout_3->addWidget(Difficulty);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(ShowInfoQuest);
        label->setObjectName("label");

        horizontalLayout_4->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(ShowInfoQuest);
        dateTimeEdit->setObjectName("dateTimeEdit");

        horizontalLayout_4->addWidget(dateTimeEdit);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(ShowInfoQuest);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        change_button = new QPushButton(ShowInfoQuest);
        change_button->setObjectName("change_button");

        horizontalLayout_5->addWidget(change_button);


        gridLayout->addLayout(horizontalLayout_5, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        Delete_Quest = new QPushButton(ShowInfoQuest);
        Delete_Quest->setObjectName("Delete_Quest");

        horizontalLayout_6->addWidget(Delete_Quest);

        Quest_complete = new QPushButton(ShowInfoQuest);
        Quest_complete->setObjectName("Quest_complete");

        horizontalLayout_6->addWidget(Quest_complete);


        gridLayout->addLayout(horizontalLayout_6, 6, 0, 1, 1);


        retranslateUi(ShowInfoQuest);

        QMetaObject::connectSlotsByName(ShowInfoQuest);
    } // setupUi

    void retranslateUi(QDialog *ShowInfoQuest)
    {
        ShowInfoQuest->setWindowTitle(QCoreApplication::translate("ShowInfoQuest", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("ShowInfoQuest", "Quest info", nullptr));
        Title_label->setText(QCoreApplication::translate("ShowInfoQuest", "Title:", nullptr));
        Title->setText(QCoreApplication::translate("ShowInfoQuest", "Title", nullptr));
        Discription_label->setText(QCoreApplication::translate("ShowInfoQuest", "Discription", nullptr));
        Discription->setText(QCoreApplication::translate("ShowInfoQuest", "Discription", nullptr));
        Difficulty_label->setText(QCoreApplication::translate("ShowInfoQuest", "Difficulty", nullptr));
        Difficulty->setText(QCoreApplication::translate("ShowInfoQuest", "Difficulty", nullptr));
        label->setText(QCoreApplication::translate("ShowInfoQuest", "Deadline to:", nullptr));
        label_3->setText(QCoreApplication::translate("ShowInfoQuest", "If you change info:", nullptr));
        change_button->setText(QCoreApplication::translate("ShowInfoQuest", "Change", nullptr));
        Delete_Quest->setText(QCoreApplication::translate("ShowInfoQuest", "Delete Quest", nullptr));
        Quest_complete->setText(QCoreApplication::translate("ShowInfoQuest", "Quest complete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowInfoQuest: public Ui_ShowInfoQuest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINFOQUEST_H
