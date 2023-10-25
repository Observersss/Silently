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
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_Title;
    QLineEdit *Title;
    QLabel *label_Discription;
    QLineEdit *Discription;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QRadioButton *easy;
    QRadioButton *hard;
    QRadioButton *meduim;
    QRadioButton *dead;
    QPushButton *pushButton;

    void setupUi(QDialog *AddQuest)
    {
        if (AddQuest->objectName().isEmpty())
            AddQuest->setObjectName("AddQuest");
        AddQuest->resize(314, 397);
        groupBox = new QGroupBox(AddQuest);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 10, 291, 211));
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

        frame = new QFrame(AddQuest);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 240, 228, 64));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(frame);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        easy = new QRadioButton(frame);
        easy->setObjectName("easy");

        gridLayout_2->addWidget(easy, 0, 1, 1, 1);

        hard = new QRadioButton(frame);
        hard->setObjectName("hard");

        gridLayout_2->addWidget(hard, 0, 2, 1, 1);

        meduim = new QRadioButton(frame);
        meduim->setObjectName("meduim");

        gridLayout_2->addWidget(meduim, 1, 1, 1, 1);

        dead = new QRadioButton(frame);
        dead->setObjectName("dead");

        gridLayout_2->addWidget(dead, 1, 2, 1, 1);

        pushButton = new QPushButton(AddQuest);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 330, 100, 32));

        retranslateUi(AddQuest);

        QMetaObject::connectSlotsByName(AddQuest);
    } // setupUi

    void retranslateUi(QDialog *AddQuest)
    {
        AddQuest->setWindowTitle(QCoreApplication::translate("AddQuest", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddQuest", "Adding new Quest", nullptr));
        label_Title->setText(QCoreApplication::translate("AddQuest", "Title", nullptr));
        label_Discription->setText(QCoreApplication::translate("AddQuest", "Discription", nullptr));
        label->setText(QCoreApplication::translate("AddQuest", "Difficulty", nullptr));
        easy->setText(QCoreApplication::translate("AddQuest", "easy", nullptr));
        hard->setText(QCoreApplication::translate("AddQuest", "hard", nullptr));
        meduim->setText(QCoreApplication::translate("AddQuest", "meduim", nullptr));
        dead->setText(QCoreApplication::translate("AddQuest", "dead", nullptr));
        pushButton->setText(QCoreApplication::translate("AddQuest", "Add Quest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddQuest: public Ui_AddQuest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDQUEST_H
