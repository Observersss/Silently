/********************************************************************************
** Form generated from reading UI file 'addquest.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDQUEST_H
#define UI_ADDQUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AddQuest
{
public:
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QRadioButton *dead;
    QLabel *label;
    QRadioButton *meduim;
    QRadioButton *easy;
    QRadioButton *hard;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QLabel *label_Title;
    QLineEdit *Title;
    QLabel *label_Discription;
    QLineEdit *Discription;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *AddQuest)
    {
        if (AddQuest->objectName().isEmpty())
            AddQuest->setObjectName("AddQuest");
        AddQuest->resize(406, 454);
        AddQuest->setStyleSheet(QString::fromUtf8("background-color:white;"));
        gridLayout_4 = new QGridLayout(AddQuest);
        gridLayout_4->setObjectName("gridLayout_4");
        pushButton_2 = new QPushButton(AddQuest);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 20));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        gridLayout_4->addWidget(pushButton_2, 4, 0, 1, 1);

        frame = new QFrame(AddQuest);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("border:none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        dead = new QRadioButton(frame);
        dead->setObjectName("dead");
        dead->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_2->addWidget(dead, 2, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        meduim = new QRadioButton(frame);
        meduim->setObjectName("meduim");
        meduim->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_2->addWidget(meduim, 2, 1, 1, 1);

        easy = new QRadioButton(frame);
        easy->setObjectName("easy");
        easy->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_2->addWidget(easy, 1, 1, 1, 1);

        hard = new QRadioButton(frame);
        hard->setObjectName("hard");
        hard->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_2->addWidget(hard, 1, 2, 1, 1);


        gridLayout_4->addWidget(frame, 2, 0, 1, 2);

        frame_2 = new QFrame(AddQuest);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName("gridLayout_3");
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(frame_2);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));

        gridLayout_3->addWidget(dateTimeEdit, 1, 0, 1, 1);


        gridLayout_4->addWidget(frame_2, 3, 0, 1, 1);

        frame_3 = new QFrame(AddQuest);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName("gridLayout");
        label_Title = new QLabel(frame_3);
        label_Title->setObjectName("label_Title");
        label_Title->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(label_Title, 0, 0, 1, 1);

        Title = new QLineEdit(frame_3);
        Title->setObjectName("Title");
        Title->setMinimumSize(QSize(0, 20));
        Title->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;\n"
"color:black;\n"
"border:3px solid silver;"));

        gridLayout->addWidget(Title, 0, 1, 1, 2);

        label_Discription = new QLabel(frame_3);
        label_Discription->setObjectName("label_Discription");
        label_Discription->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(label_Discription, 1, 0, 1, 2);

        Discription = new QLineEdit(frame_3);
        Discription->setObjectName("Discription");
        Discription->setMinimumSize(QSize(0, 20));
        Discription->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;\n"
"color:black;\n"
"border:3px solid silver;"));

        gridLayout->addWidget(Discription, 1, 2, 1, 1);


        gridLayout_4->addWidget(frame_3, 1, 0, 1, 2);

        pushButton = new QPushButton(AddQuest);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 20));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        gridLayout_4->addWidget(pushButton, 4, 1, 1, 1);

        label_3 = new QLabel(AddQuest);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:orange;"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 0, 1, 2);


        retranslateUi(AddQuest);

        QMetaObject::connectSlotsByName(AddQuest);
    } // setupUi

    void retranslateUi(QDialog *AddQuest)
    {
        AddQuest->setWindowTitle(QCoreApplication::translate("AddQuest", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddQuest", "Set deadline", nullptr));
        dead->setText(QCoreApplication::translate("AddQuest", "dead", nullptr));
        label->setText(QCoreApplication::translate("AddQuest", "Difficulty", nullptr));
        meduim->setText(QCoreApplication::translate("AddQuest", "meduim", nullptr));
        easy->setText(QCoreApplication::translate("AddQuest", "easy", nullptr));
        hard->setText(QCoreApplication::translate("AddQuest", "hard", nullptr));
        label_2->setText(QCoreApplication::translate("AddQuest", "Set deadline(yy.mm.dd.hh.mm):", nullptr));
        label_Title->setText(QCoreApplication::translate("AddQuest", "Title", nullptr));
        label_Discription->setText(QCoreApplication::translate("AddQuest", "Discription", nullptr));
        pushButton->setText(QCoreApplication::translate("AddQuest", "Add Quest", nullptr));
        label_3->setText(QCoreApplication::translate("AddQuest", "Add new Quest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddQuest: public Ui_AddQuest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDQUEST_H
