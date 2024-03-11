/********************************************************************************
** Form generated from reading UI file 'inventory_dialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORY_DIALOGWINDOW_H
#define UI_INVENTORY_DIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Inventory_DialogWindow
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QPushButton *Equip;
    QPushButton *Delete;
    QFrame *textOption_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *Option3;
    QLabel *textOption;
    QLabel *Option1;
    QLabel *textOption_2;
    QLabel *Option2;
    QLabel *textRank;
    QLabel *Rank;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QListWidget *Equip_Item;
    QPushButton *take_off;
    QPushButton *Delete_2;

    void setupUi(QDialog *Inventory_DialogWindow)
    {
        if (Inventory_DialogWindow->objectName().isEmpty())
            Inventory_DialogWindow->setObjectName("Inventory_DialogWindow");
        Inventory_DialogWindow->resize(831, 587);
        Inventory_DialogWindow->setStyleSheet(QString::fromUtf8("background-color:silver;"));
        gridLayout_2 = new QGridLayout(Inventory_DialogWindow);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(Inventory_DialogWindow);
        label->setObjectName("label");
        label->setMinimumSize(QSize(300, 300));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        frame_2 = new QFrame(Inventory_DialogWindow);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(0, 300));
        frame_2->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName("gridLayout");
        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(300, 240));
        listWidget->setStyleSheet(QString::fromUtf8("border-radius:18px;\n"
"background-color:white;\n"
"color:black;"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        Equip = new QPushButton(frame_2);
        Equip->setObjectName("Equip");
        Equip->setMinimumSize(QSize(0, 20));
        Equip->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        gridLayout->addWidget(Equip, 1, 0, 1, 1);

        Delete = new QPushButton(frame_2);
        Delete->setObjectName("Delete");
        Delete->setMinimumSize(QSize(0, 20));
        Delete->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        gridLayout->addWidget(Delete, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame_2, 0, 1, 1, 1);

        textOption_3 = new QFrame(Inventory_DialogWindow);
        textOption_3->setObjectName("textOption_3");
        textOption_3->setMinimumSize(QSize(200, 200));
        textOption_3->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"color:white;\n"
"background-color:rgb(0, 150, 255);"));
        textOption_3->setFrameShape(QFrame::StyledPanel);
        textOption_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(textOption_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label_5 = new QLabel(textOption_3);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 5, 0, 1, 1);

        Option3 = new QLabel(textOption_3);
        Option3->setObjectName("Option3");

        gridLayout_3->addWidget(Option3, 5, 1, 1, 1);

        textOption = new QLabel(textOption_3);
        textOption->setObjectName("textOption");

        gridLayout_3->addWidget(textOption, 1, 0, 1, 1);

        Option1 = new QLabel(textOption_3);
        Option1->setObjectName("Option1");

        gridLayout_3->addWidget(Option1, 1, 1, 1, 1);

        textOption_2 = new QLabel(textOption_3);
        textOption_2->setObjectName("textOption_2");

        gridLayout_3->addWidget(textOption_2, 3, 0, 1, 1);

        Option2 = new QLabel(textOption_3);
        Option2->setObjectName("Option2");

        gridLayout_3->addWidget(Option2, 3, 1, 1, 1);

        textRank = new QLabel(textOption_3);
        textRank->setObjectName("textRank");

        gridLayout_3->addWidget(textRank, 0, 0, 1, 1);

        Rank = new QLabel(textOption_3);
        Rank->setObjectName("Rank");

        gridLayout_3->addWidget(Rank, 0, 1, 1, 1);


        gridLayout_2->addWidget(textOption_3, 1, 0, 1, 1);

        frame = new QFrame(Inventory_DialogWindow);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("border:none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName("gridLayout_4");
        Equip_Item = new QListWidget(frame);
        Equip_Item->setObjectName("Equip_Item");
        Equip_Item->setMinimumSize(QSize(0, 150));
        Equip_Item->setStyleSheet(QString::fromUtf8("border-radius:18px;\n"
"background-color:white;\n"
"color:black;"));

        gridLayout_4->addWidget(Equip_Item, 0, 0, 1, 2);

        take_off = new QPushButton(frame);
        take_off->setObjectName("take_off");
        take_off->setMinimumSize(QSize(0, 20));
        take_off->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        gridLayout_4->addWidget(take_off, 1, 0, 1, 1);

        Delete_2 = new QPushButton(frame);
        Delete_2->setObjectName("Delete_2");
        Delete_2->setMinimumSize(QSize(0, 20));
        Delete_2->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));

        gridLayout_4->addWidget(Delete_2, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame, 1, 1, 1, 1);


        retranslateUi(Inventory_DialogWindow);

        QMetaObject::connectSlotsByName(Inventory_DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *Inventory_DialogWindow)
    {
        Inventory_DialogWindow->setWindowTitle(QCoreApplication::translate("Inventory_DialogWindow", "Dialog", nullptr));
        label->setText(QString());
        Equip->setText(QCoreApplication::translate("Inventory_DialogWindow", "Equip", nullptr));
        Delete->setText(QCoreApplication::translate("Inventory_DialogWindow", "Delete", nullptr));
        label_5->setText(QCoreApplication::translate("Inventory_DialogWindow", "Option 3", nullptr));
        Option3->setText(QCoreApplication::translate("Inventory_DialogWindow", "TextLabel", nullptr));
        textOption->setText(QCoreApplication::translate("Inventory_DialogWindow", "Option 1", nullptr));
        Option1->setText(QCoreApplication::translate("Inventory_DialogWindow", "TextLabel", nullptr));
        textOption_2->setText(QCoreApplication::translate("Inventory_DialogWindow", "Option 2", nullptr));
        Option2->setText(QCoreApplication::translate("Inventory_DialogWindow", "TextLabel", nullptr));
        textRank->setText(QCoreApplication::translate("Inventory_DialogWindow", "Rank", nullptr));
        Rank->setText(QCoreApplication::translate("Inventory_DialogWindow", "Rank:", nullptr));
        take_off->setText(QCoreApplication::translate("Inventory_DialogWindow", "take off", nullptr));
        Delete_2->setText(QCoreApplication::translate("Inventory_DialogWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inventory_DialogWindow: public Ui_Inventory_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORY_DIALOGWINDOW_H
