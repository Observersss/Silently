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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AddQuest
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_Title;
    QLineEdit *Title;
    QLabel *label_Discription;
    QLineEdit *Discription;
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AddQuest)
    {
        if (AddQuest->objectName().isEmpty())
            AddQuest->setObjectName("AddQuest");
        AddQuest->resize(406, 454);
        gridLayout_4 = new QGridLayout(AddQuest);
        gridLayout_4->setObjectName("gridLayout_4");
        groupBox = new QGroupBox(AddQuest);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_Title = new QLabel(groupBox);
        label_Title->setObjectName("label_Title");

        gridLayout->addWidget(label_Title, 0, 0, 1, 1);

        Title = new QLineEdit(groupBox);
        Title->setObjectName("Title");

        gridLayout->addWidget(Title, 0, 1, 1, 2);

        label_Discription = new QLabel(groupBox);
        label_Discription->setObjectName("label_Discription");

        gridLayout->addWidget(label_Discription, 1, 0, 1, 2);

        Discription = new QLineEdit(groupBox);
        Discription->setObjectName("Discription");

        gridLayout->addWidget(Discription, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 2);

        frame = new QFrame(AddQuest);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        dead = new QRadioButton(frame);
        dead->setObjectName("dead");

        gridLayout_2->addWidget(dead, 2, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        meduim = new QRadioButton(frame);
        meduim->setObjectName("meduim");

        gridLayout_2->addWidget(meduim, 2, 1, 1, 1);

        easy = new QRadioButton(frame);
        easy->setObjectName("easy");

        gridLayout_2->addWidget(easy, 1, 1, 1, 1);

        hard = new QRadioButton(frame);
        hard->setObjectName("hard");

        gridLayout_2->addWidget(hard, 1, 2, 1, 1);


        gridLayout_4->addWidget(frame, 1, 0, 1, 2);

        frame_2 = new QFrame(AddQuest);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName("gridLayout_3");
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(frame_2);
        dateTimeEdit->setObjectName("dateTimeEdit");

        gridLayout_3->addWidget(dateTimeEdit, 1, 0, 1, 1);


        gridLayout_4->addWidget(frame_2, 2, 0, 1, 1);

        pushButton = new QPushButton(AddQuest);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(pushButton, 3, 1, 1, 1);

        pushButton_2 = new QPushButton(AddQuest);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 30));

        gridLayout_4->addWidget(pushButton_2, 3, 0, 1, 1);


        retranslateUi(AddQuest);

        QMetaObject::connectSlotsByName(AddQuest);
    } // setupUi

    void retranslateUi(QDialog *AddQuest)
    {
        AddQuest->setWindowTitle(QCoreApplication::translate("AddQuest", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddQuest", "Adding new Quest", nullptr));
        label_Title->setText(QCoreApplication::translate("AddQuest", "Title", nullptr));
        label_Discription->setText(QCoreApplication::translate("AddQuest", "Description", nullptr));
        dead->setText(QCoreApplication::translate("AddQuest", "dead", nullptr));
        label->setText(QCoreApplication::translate("AddQuest", "Difficulty", nullptr));
        meduim->setText(QCoreApplication::translate("AddQuest", "medium", nullptr));
        easy->setText(QCoreApplication::translate("AddQuest", "easy", nullptr));
        hard->setText(QCoreApplication::translate("AddQuest", "hard", nullptr));
        label_2->setText(QCoreApplication::translate("AddQuest", "Set deadline(yy.mm.dd.hh.mm):", nullptr));
        pushButton->setText(QCoreApplication::translate("AddQuest", "Add Quest", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddQuest", "Set deadline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddQuest: public Ui_AddQuest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDQUEST_H
