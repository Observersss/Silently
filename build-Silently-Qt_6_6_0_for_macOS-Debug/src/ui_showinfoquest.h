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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowInfoQuest
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
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
        ShowInfoQuest->setStyleSheet(QString::fromUtf8("background-color:white;"));
        widget = new QWidget(ShowInfoQuest);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(12, 12, 213, 228));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QString::fromUtf8("color:orange;\n"
""));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Title_label = new QLabel(widget);
        Title_label->setObjectName("Title_label");
        Title_label->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout->addWidget(Title_label);

        Title = new QLineEdit(widget);
        Title->setObjectName("Title");
        Title->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"color:black;\n"
"border: 3px solid silver;"));

        horizontalLayout->addWidget(Title);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Discription_label = new QLabel(widget);
        Discription_label->setObjectName("Discription_label");
        Discription_label->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_2->addWidget(Discription_label);

        Discription = new QLineEdit(widget);
        Discription->setObjectName("Discription");
        Discription->setStyleSheet(QString::fromUtf8("color:black;\n"
"border-radius:10px;\n"
"border: 3px solid silver;"));

        horizontalLayout_2->addWidget(Discription);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Difficulty_label = new QLabel(widget);
        Difficulty_label->setObjectName("Difficulty_label");
        Difficulty_label->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_3->addWidget(Difficulty_label);

        Difficulty = new QLineEdit(widget);
        Difficulty->setObjectName("Difficulty");
        Difficulty->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"color:black;\n"
"border: 3px solid silver;"));

        horizontalLayout_3->addWidget(Difficulty);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_4->addWidget(label);

        dateTimeEdit = new QDateTimeEdit(widget);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_4->addWidget(dateTimeEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_5->addWidget(label_3);

        change_button = new QPushButton(widget);
        change_button->setObjectName("change_button");
        change_button->setMinimumSize(QSize(0, 20));
        change_button->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        horizontalLayout_5->addWidget(change_button);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        Delete_Quest = new QPushButton(widget);
        Delete_Quest->setObjectName("Delete_Quest");
        Delete_Quest->setMinimumSize(QSize(0, 20));
        Delete_Quest->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        horizontalLayout_6->addWidget(Delete_Quest);

        Quest_complete = new QPushButton(widget);
        Quest_complete->setObjectName("Quest_complete");
        Quest_complete->setMinimumSize(QSize(0, 20));
        Quest_complete->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        horizontalLayout_6->addWidget(Quest_complete);


        verticalLayout->addLayout(horizontalLayout_6);


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
