/********************************************************************************
** Form generated from reading UI file 'inventorywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYWINDOW_H
#define UI_INVENTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InventoryWindow
{
public:
    QGridLayout *gridLayout_2;
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
    QLabel *label;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QPushButton *Equip;
    QPushButton *Delete;

    void setupUi(QDialog *InventoryWindow)
    {
        if (InventoryWindow->objectName().isEmpty())
            InventoryWindow->setObjectName("InventoryWindow");
        InventoryWindow->resize(830, 589);
        gridLayout_2 = new QGridLayout(InventoryWindow);
        gridLayout_2->setObjectName("gridLayout_2");
        textOption_3 = new QFrame(InventoryWindow);
        textOption_3->setObjectName("textOption_3");
        textOption_3->setMinimumSize(QSize(200, 200));
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


        gridLayout_2->addWidget(textOption_3, 2, 0, 1, 1);

        frame = new QFrame(InventoryWindow);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName("gridLayout_4");
        Equip_Item = new QListWidget(frame);
        Equip_Item->setObjectName("Equip_Item");
        Equip_Item->setMinimumSize(QSize(0, 150));

        gridLayout_4->addWidget(Equip_Item, 0, 0, 1, 2);

        take_off = new QPushButton(frame);
        take_off->setObjectName("take_off");

        gridLayout_4->addWidget(take_off, 1, 0, 1, 1);

        Delete_2 = new QPushButton(frame);
        Delete_2->setObjectName("Delete_2");

        gridLayout_4->addWidget(Delete_2, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame, 2, 1, 1, 1);

        label = new QLabel(InventoryWindow);
        label->setObjectName("label");
        label->setMinimumSize(QSize(300, 300));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        frame_2 = new QFrame(InventoryWindow);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(0, 300));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName("gridLayout");
        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(300, 240));

        gridLayout->addWidget(listWidget, 0, 0, 1, 2);

        Equip = new QPushButton(frame_2);
        Equip->setObjectName("Equip");

        gridLayout->addWidget(Equip, 1, 0, 1, 1);

        Delete = new QPushButton(frame_2);
        Delete->setObjectName("Delete");

        gridLayout->addWidget(Delete, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame_2, 1, 1, 1, 1);


        retranslateUi(InventoryWindow);

        QMetaObject::connectSlotsByName(InventoryWindow);
    } // setupUi

    void retranslateUi(QDialog *InventoryWindow)
    {
        InventoryWindow->setWindowTitle(QCoreApplication::translate("InventoryWindow", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("InventoryWindow", "Option 3", nullptr));
        Option3->setText(QCoreApplication::translate("InventoryWindow", "TextLabel", nullptr));
        textOption->setText(QCoreApplication::translate("InventoryWindow", "Option 1", nullptr));
        Option1->setText(QCoreApplication::translate("InventoryWindow", "TextLabel", nullptr));
        textOption_2->setText(QCoreApplication::translate("InventoryWindow", "Option 2", nullptr));
        Option2->setText(QCoreApplication::translate("InventoryWindow", "TextLabel", nullptr));
        textRank->setText(QCoreApplication::translate("InventoryWindow", "Rank", nullptr));
        Rank->setText(QCoreApplication::translate("InventoryWindow", "Rank:", nullptr));
        take_off->setText(QCoreApplication::translate("InventoryWindow", "take off", nullptr));
        Delete_2->setText(QCoreApplication::translate("InventoryWindow", "Delete", nullptr));
        label->setText(QString());
        Equip->setText(QCoreApplication::translate("InventoryWindow", "Equip", nullptr));
        Delete->setText(QCoreApplication::translate("InventoryWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InventoryWindow: public Ui_InventoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYWINDOW_H
