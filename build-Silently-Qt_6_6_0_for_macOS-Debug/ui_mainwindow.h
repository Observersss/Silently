/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *info;
    QPushButton *change_space;
    QPushButton *button_update;
    QStackedWidget *spaces;
    QWidget *RPG_space;
    QFrame *infoCharacter;
    QGridLayout *gridLayout;
    QLabel *HealthLabel;
    QLabel *ManaLabel;
    QLabel *LevelLabel;
    QLabel *ExperienceLabel;
    QFrame *frame_3;
    QListWidget *QuestList;
    QPushButton *AddingQuest;
    QPushButton *InfoQuest;
    QFrame *active_item;
    QFrame *inventory_items;
    QFrame *character_img;
    QWidget *Note_space;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 141, 101));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        info = new QLabel(frame);
        info->setObjectName("info");
        info->setGeometry(QRect(10, 10, 101, 16));
        change_space = new QPushButton(frame);
        change_space->setObjectName("change_space");
        change_space->setGeometry(QRect(10, 30, 100, 32));
        button_update = new QPushButton(frame);
        button_update->setObjectName("button_update");
        button_update->setGeometry(QRect(10, 70, 100, 32));
        spaces = new QStackedWidget(centralwidget);
        spaces->setObjectName("spaces");
        spaces->setGeometry(QRect(130, 0, 651, 431));
        spaces->setStyleSheet(QString::fromUtf8("background-color:silver;"));
        RPG_space = new QWidget();
        RPG_space->setObjectName("RPG_space");
        infoCharacter = new QFrame(RPG_space);
        infoCharacter->setObjectName("infoCharacter");
        infoCharacter->setGeometry(QRect(0, 0, 161, 231));
        infoCharacter->setFrameShape(QFrame::StyledPanel);
        infoCharacter->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(infoCharacter);
        gridLayout->setObjectName("gridLayout");
        HealthLabel = new QLabel(infoCharacter);
        HealthLabel->setObjectName("HealthLabel");
        HealthLabel->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(HealthLabel, 0, 0, 1, 1);

        ManaLabel = new QLabel(infoCharacter);
        ManaLabel->setObjectName("ManaLabel");
        ManaLabel->setStyleSheet(QString::fromUtf8("color:black;\n"
""));

        gridLayout->addWidget(ManaLabel, 1, 0, 1, 1);

        LevelLabel = new QLabel(infoCharacter);
        LevelLabel->setObjectName("LevelLabel");
        LevelLabel->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(LevelLabel, 2, 0, 1, 1);

        ExperienceLabel = new QLabel(infoCharacter);
        ExperienceLabel->setObjectName("ExperienceLabel");
        ExperienceLabel->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(ExperienceLabel, 3, 0, 1, 1);

        frame_3 = new QFrame(RPG_space);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(0, 230, 301, 201));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        QuestList = new QListWidget(frame_3);
        QuestList->setObjectName("QuestList");
        QuestList->setGeometry(QRect(0, 0, 301, 161));
        QuestList->setStyleSheet(QString::fromUtf8("color:black;"));
        AddingQuest = new QPushButton(frame_3);
        AddingQuest->setObjectName("AddingQuest");
        AddingQuest->setGeometry(QRect(0, 160, 100, 32));
        AddingQuest->setStyleSheet(QString::fromUtf8("color:black;"));
        InfoQuest = new QPushButton(frame_3);
        InfoQuest->setObjectName("InfoQuest");
        InfoQuest->setGeometry(QRect(120, 160, 171, 32));
        InfoQuest->setStyleSheet(QString::fromUtf8("color:black;"));
        active_item = new QFrame(RPG_space);
        active_item->setObjectName("active_item");
        active_item->setGeometry(QRect(300, 0, 161, 431));
        active_item->setStyleSheet(QString::fromUtf8("background-color:black;"));
        active_item->setFrameShape(QFrame::StyledPanel);
        active_item->setFrameShadow(QFrame::Raised);
        inventory_items = new QFrame(RPG_space);
        inventory_items->setObjectName("inventory_items");
        inventory_items->setGeometry(QRect(460, 0, 191, 431));
        inventory_items->setStyleSheet(QString::fromUtf8("background-color:orange;"));
        inventory_items->setFrameShape(QFrame::StyledPanel);
        inventory_items->setFrameShadow(QFrame::Raised);
        character_img = new QFrame(RPG_space);
        character_img->setObjectName("character_img");
        character_img->setGeometry(QRect(160, 0, 141, 231));
        character_img->setStyleSheet(QString::fromUtf8("background-color:pink;"));
        character_img->setFrameShape(QFrame::StyledPanel);
        character_img->setFrameShadow(QFrame::Raised);
        spaces->addWidget(RPG_space);
        Note_space = new QWidget();
        Note_space->setObjectName("Note_space");
        spaces->addWidget(Note_space);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        info->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        change_space->setText(QCoreApplication::translate("MainWindow", "Change space", nullptr));
        button_update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ExperienceLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        AddingQuest->setText(QCoreApplication::translate("MainWindow", "Add Quest", nullptr));
        InfoQuest->setText(QCoreApplication::translate("MainWindow", "Show info quest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
