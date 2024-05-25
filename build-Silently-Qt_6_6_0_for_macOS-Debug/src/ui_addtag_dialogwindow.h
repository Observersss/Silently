/********************************************************************************
** Form generated from reading UI file 'addtag_dialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTAG_DIALOGWINDOW_H
#define UI_ADDTAG_DIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTag_DialogWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *select_tag_frame;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *comboBox;
    QFrame *create_tag_frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *tagName;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_option;
    QPushButton *pushButton;

    void setupUi(QDialog *AddTag_DialogWindow)
    {
        if (AddTag_DialogWindow->objectName().isEmpty())
            AddTag_DialogWindow->setObjectName("AddTag_DialogWindow");
        AddTag_DialogWindow->resize(350, 356);
        AddTag_DialogWindow->setStyleSheet(QString::fromUtf8("background-color:white;"));
        verticalLayout = new QVBoxLayout(AddTag_DialogWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddTag_DialogWindow);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:orange;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        select_tag_frame = new QFrame(AddTag_DialogWindow);
        select_tag_frame->setObjectName("select_tag_frame");
        select_tag_frame->setStyleSheet(QString::fromUtf8("border:none"));
        select_tag_frame->setFrameShape(QFrame::StyledPanel);
        select_tag_frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(select_tag_frame);
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(select_tag_frame);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(60, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("color:black;			"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        comboBox = new QComboBox(select_tag_frame);
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"        border: 3px solid silver;\n"
"        border-radius: 10px;/* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"        background-color: white;\n"
"        color: black;\n"
"        }\n"
"        QComboBox::down-arrow {\n"
"        background-color: orange;\n"
"        color: white;\n"
"        border-radius: 6px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\270\320\265 \321\203\320\263\320\273\320\276\320\262 */\n"
"       \n"
"        width: 18px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 */\n"
"        height: 18px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 */\n"
"        }\n"
"        QComboBox::down-arrow:disabled {\n"
"        background-color: lightgray;\n"
"       "
                        " color: darkgray;\n"
"        }\n"
"        QComboBox::down-arrow:pressed {\n"
"        background-color: darkorange;\n"
"        }\n"
"        QComboBox::drop-down {\n"
"        border: none;\n"
"        width: 20px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"        height: 20px; /* \320\222\321\213\321\201\320\276\321\202\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"        }\n"
"        QComboBox QAbstractItemView {\n"
"        background-color: white; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"        color: black; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\274 \321\201\320\277\320\270\321\201\320\272\320\265 */\n"
"        borde"
                        "r: 1px solid silver;  /* \320\223\321\200\320\260\320\275\320\270\321\206\320\260 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"        }"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);


        verticalLayout->addWidget(select_tag_frame);

        create_tag_frame = new QFrame(AddTag_DialogWindow);
        create_tag_frame->setObjectName("create_tag_frame");
        create_tag_frame->setStyleSheet(QString::fromUtf8("border:none;"));
        create_tag_frame->setFrameShape(QFrame::StyledPanel);
        create_tag_frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(create_tag_frame);
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(create_tag_frame);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        tagName = new QLineEdit(create_tag_frame);
        tagName->setObjectName("tagName");
        tagName->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;\n"
"border-radius:10px;\n"
"border:3px solid silver;"));

        gridLayout_2->addWidget(tagName, 0, 1, 1, 1);


        verticalLayout->addWidget(create_tag_frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        button_option = new QPushButton(AddTag_DialogWindow);
        button_option->setObjectName("button_option");
        button_option->setMinimumSize(QSize(100, 30));
        button_option->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"color:white;\n"
"background-color:orange;"));

        horizontalLayout_2->addWidget(button_option);

        pushButton = new QPushButton(AddTag_DialogWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(100, 30));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"color:white;\n"
"background-color:orange;"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddTag_DialogWindow);

        QMetaObject::connectSlotsByName(AddTag_DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *AddTag_DialogWindow)
    {
        AddTag_DialogWindow->setWindowTitle(QCoreApplication::translate("AddTag_DialogWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddTag_DialogWindow", "Tag manege", nullptr));
        label_3->setText(QCoreApplication::translate("AddTag_DialogWindow", "Select tag:", nullptr));
        label_2->setText(QCoreApplication::translate("AddTag_DialogWindow", "Name of tag:", nullptr));
        button_option->setText(QCoreApplication::translate("AddTag_DialogWindow", "Need new tag", nullptr));
        pushButton->setText(QCoreApplication::translate("AddTag_DialogWindow", "Add tag", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTag_DialogWindow: public Ui_AddTag_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTAG_DIALOGWINDOW_H
