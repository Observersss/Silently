/********************************************************************************
** Form generated from reading UI file 'showinfoquest_dialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWINFOQUEST_DIALOGWINDOW_H
#define UI_SHOWINFOQUEST_DIALOGWINDOW_H

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

class Ui_ShowInfoQuest_DialogWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Title_label__;
    QLineEdit *Title_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Discription_label_2;
    QLineEdit *Discription_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Difficulty_label_2;
    QLineEdit *Difficulty_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QPushButton *change_button;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *Delete_Quest;
    QPushButton *Quest_complete;

    void setupUi(QDialog *ShowInfoQuest_DialogWindow)
    {
        if (ShowInfoQuest_DialogWindow->objectName().isEmpty())
            ShowInfoQuest_DialogWindow->setObjectName("ShowInfoQuest_DialogWindow");
        ShowInfoQuest_DialogWindow->resize(328, 305);
        ShowInfoQuest_DialogWindow->setStyleSheet(QString::fromUtf8("background-color:white;"));
        gridLayout = new QGridLayout(ShowInfoQuest_DialogWindow);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(ShowInfoQuest_DialogWindow);
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

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        Title_label__ = new QLabel(ShowInfoQuest_DialogWindow);
        Title_label__->setObjectName("Title_label__");
        Title_label__->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_7->addWidget(Title_label__);

        Title_2 = new QLineEdit(ShowInfoQuest_DialogWindow);
        Title_2->setObjectName("Title_2");
        Title_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"color:black;\n"
"border: 3px solid silver;"));

        horizontalLayout_7->addWidget(Title_2);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Discription_label_2 = new QLabel(ShowInfoQuest_DialogWindow);
        Discription_label_2->setObjectName("Discription_label_2");
        Discription_label_2->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_8->addWidget(Discription_label_2);

        Discription_2 = new QLineEdit(ShowInfoQuest_DialogWindow);
        Discription_2->setObjectName("Discription_2");
        Discription_2->setStyleSheet(QString::fromUtf8("color:black;\n"
"border-radius:10px;\n"
"border: 3px solid silver;"));

        horizontalLayout_8->addWidget(Discription_2);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        Difficulty_label_2 = new QLabel(ShowInfoQuest_DialogWindow);
        Difficulty_label_2->setObjectName("Difficulty_label_2");
        Difficulty_label_2->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_9->addWidget(Difficulty_label_2);

        Difficulty_2 = new QLineEdit(ShowInfoQuest_DialogWindow);
        Difficulty_2->setObjectName("Difficulty_2");
        Difficulty_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"color:black;\n"
"border: 3px solid silver;"));

        horizontalLayout_9->addWidget(Difficulty_2);


        gridLayout->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_4 = new QLabel(ShowInfoQuest_DialogWindow);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_10->addWidget(label_4);

        dateTimeEdit_2 = new QDateTimeEdit(ShowInfoQuest_DialogWindow);
        dateTimeEdit_2->setObjectName("dateTimeEdit_2");
        dateTimeEdit_2->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_10->addWidget(dateTimeEdit_2);


        gridLayout->addLayout(horizontalLayout_10, 4, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_5 = new QLabel(ShowInfoQuest_DialogWindow);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color:black;"));

        horizontalLayout_11->addWidget(label_5);

        change_button = new QPushButton(ShowInfoQuest_DialogWindow);
        change_button->setObjectName("change_button");
        change_button->setMinimumSize(QSize(0, 20));
        change_button->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        horizontalLayout_11->addWidget(change_button);


        gridLayout->addLayout(horizontalLayout_11, 5, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        Delete_Quest = new QPushButton(ShowInfoQuest_DialogWindow);
        Delete_Quest->setObjectName("Delete_Quest");
        Delete_Quest->setMinimumSize(QSize(0, 20));
        Delete_Quest->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        horizontalLayout_12->addWidget(Delete_Quest);

        Quest_complete = new QPushButton(ShowInfoQuest_DialogWindow);
        Quest_complete->setObjectName("Quest_complete");
        Quest_complete->setMinimumSize(QSize(0, 20));
        Quest_complete->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        horizontalLayout_12->addWidget(Quest_complete);


        gridLayout->addLayout(horizontalLayout_12, 6, 0, 1, 1);


        retranslateUi(ShowInfoQuest_DialogWindow);

        QMetaObject::connectSlotsByName(ShowInfoQuest_DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *ShowInfoQuest_DialogWindow)
    {
        ShowInfoQuest_DialogWindow->setWindowTitle(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Quest info", nullptr));
        Title_label__->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Title:", nullptr));
        Title_2->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Title", nullptr));
        Discription_label_2->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Discription", nullptr));
        Discription_2->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Discription", nullptr));
        Difficulty_label_2->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Difficulty", nullptr));
        Difficulty_2->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Difficulty", nullptr));
        label_4->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Deadline to:", nullptr));
        label_5->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "If you change info:", nullptr));
        change_button->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Change", nullptr));
        Delete_Quest->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Delete Quest", nullptr));
        Quest_complete->setText(QCoreApplication::translate("ShowInfoQuest_DialogWindow", "Quest complete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowInfoQuest_DialogWindow: public Ui_ShowInfoQuest_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWINFOQUEST_DIALOGWINDOW_H
