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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QFrame *frame;
    QLabel *info;
    QPushButton *change_space;
    QPushButton *Test1;
    QPushButton *pTest2;
    QPushButton *pushButton;
    QStackedWidget *spaces;
    QWidget *RPG_space;
    QGridLayout *gridLayout_4;
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QListWidget *QuestList;
    QPushButton *AddingQuest;
    QLabel *character_icon;
    QFrame *active_item;
    QPushButton *Open_inventory;
    QLabel *label;
    QFrame *infoCharacter;
    QGridLayout *gridLayout;
    QLabel *ManaLabel;
    QLabel *LevelLabel;
    QLabel *HealthLabel;
    QLabel *ExperienceLabel;
    QPushButton *more_characteristics;
    QWidget *Note_space;
    QTextEdit *TextNote;
    QLineEdit *TitleNote;
    QListWidget *listTag;
    QLabel *NoteTime;
    QPushButton *tags_option;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(720, 515);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(131, 431));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame = new QFrame(frame_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 131, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        info = new QLabel(frame);
        info->setObjectName("info");
        info->setGeometry(QRect(10, 10, 101, 16));
        change_space = new QPushButton(frame);
        change_space->setObjectName("change_space");
        change_space->setGeometry(QRect(10, 30, 100, 32));
        Test1 = new QPushButton(frame_2);
        Test1->setObjectName("Test1");
        Test1->setGeometry(QRect(10, 100, 100, 32));
        pTest2 = new QPushButton(frame_2);
        pTest2->setObjectName("pTest2");
        pTest2->setGeometry(QRect(10, 150, 100, 32));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 200, 100, 32));

        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        spaces = new QStackedWidget(centralwidget);
        spaces->setObjectName("spaces");
        spaces->setStyleSheet(QString::fromUtf8("background-color:silver;"));
        RPG_space = new QWidget();
        RPG_space->setObjectName("RPG_space");
        gridLayout_4 = new QGridLayout(RPG_space);
        gridLayout_4->setObjectName("gridLayout_4");
        frame_3 = new QFrame(RPG_space);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(210, 201));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setObjectName("gridLayout_5");
        QuestList = new QListWidget(frame_3);
        QuestList->setObjectName("QuestList");
        QuestList->setMinimumSize(QSize(0, 0));
        QuestList->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_5->addWidget(QuestList, 1, 0, 1, 1);

        AddingQuest = new QPushButton(frame_3);
        AddingQuest->setObjectName("AddingQuest");
        AddingQuest->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_5->addWidget(AddingQuest, 2, 0, 1, 1);


        gridLayout_4->addWidget(frame_3, 1, 1, 1, 1);

        character_icon = new QLabel(RPG_space);
        character_icon->setObjectName("character_icon");
        character_icon->setMinimumSize(QSize(135, 199));
        character_icon->setMaximumSize(QSize(16777215, 16777215));
        character_icon->setStyleSheet(QString::fromUtf8(""));
        character_icon->setInputMethodHints(Qt::ImhNone);

        gridLayout_4->addWidget(character_icon, 0, 1, 1, 1);

        active_item = new QFrame(RPG_space);
        active_item->setObjectName("active_item");
        active_item->setMinimumSize(QSize(135, 398));
        active_item->setStyleSheet(QString::fromUtf8("background-color:black;"));
        active_item->setFrameShape(QFrame::StyledPanel);
        active_item->setFrameShadow(QFrame::Raised);
        Open_inventory = new QPushButton(active_item);
        Open_inventory->setObjectName("Open_inventory");
        Open_inventory->setGeometry(QRect(0, 380, 131, 32));
        label = new QLabel(active_item);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 131, 16));

        gridLayout_4->addWidget(active_item, 0, 3, 2, 1);

        infoCharacter = new QFrame(RPG_space);
        infoCharacter->setObjectName("infoCharacter");
        infoCharacter->setMinimumSize(QSize(136, 201));
        infoCharacter->setFrameShape(QFrame::StyledPanel);
        infoCharacter->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(infoCharacter);
        gridLayout->setObjectName("gridLayout");
        ManaLabel = new QLabel(infoCharacter);
        ManaLabel->setObjectName("ManaLabel");
        ManaLabel->setStyleSheet(QString::fromUtf8("color:black;\n"
""));

        gridLayout->addWidget(ManaLabel, 3, 1, 1, 1);

        LevelLabel = new QLabel(infoCharacter);
        LevelLabel->setObjectName("LevelLabel");
        LevelLabel->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(LevelLabel, 0, 1, 1, 1);

        HealthLabel = new QLabel(infoCharacter);
        HealthLabel->setObjectName("HealthLabel");
        HealthLabel->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(HealthLabel, 2, 1, 1, 1);

        ExperienceLabel = new QLabel(infoCharacter);
        ExperienceLabel->setObjectName("ExperienceLabel");
        ExperienceLabel->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(ExperienceLabel, 1, 1, 1, 1);

        more_characteristics = new QPushButton(infoCharacter);
        more_characteristics->setObjectName("more_characteristics");
        more_characteristics->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout->addWidget(more_characteristics, 4, 1, 1, 1);


        gridLayout_4->addWidget(infoCharacter, 0, 2, 2, 1);

        spaces->addWidget(RPG_space);
        Note_space = new QWidget();
        Note_space->setObjectName("Note_space");
        TextNote = new QTextEdit(Note_space);
        TextNote->setObjectName("TextNote");
        TextNote->setGeometry(QRect(100, 50, 451, 391));
        TextNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
""));
        TitleNote = new QLineEdit(Note_space);
        TitleNote->setObjectName("TitleNote");
        TitleNote->setGeometry(QRect(100, 0, 441, 21));
        TitleNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;"));
        listTag = new QListWidget(Note_space);
        listTag->setObjectName("listTag");
        listTag->setGeometry(QRect(100, 20, 221, 31));
        NoteTime = new QLabel(Note_space);
        NoteTime->setObjectName("NoteTime");
        NoteTime->setGeometry(QRect(350, 25, 191, 21));
        tags_option = new QPushButton(Note_space);
        tags_option->setObjectName("tags_option");
        tags_option->setGeometry(QRect(320, 20, 31, 32));
        tags_option->setStyleSheet(QString::fromUtf8("\n"
"color:black;\n"
"background-color:rgb(129, 255, 134);"));
        spaces->addWidget(Note_space);

        gridLayout_2->addWidget(spaces, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 720, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(change_space, Test1);
        QWidget::setTabOrder(Test1, pTest2);
        QWidget::setTabOrder(pTest2, QuestList);
        QWidget::setTabOrder(QuestList, AddingQuest);
        QWidget::setTabOrder(AddingQuest, Open_inventory);
        QWidget::setTabOrder(Open_inventory, more_characteristics);
        QWidget::setTabOrder(more_characteristics, TextNote);
        QWidget::setTabOrder(TextNote, TitleNote);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        info->setText(QCoreApplication::translate("MainWindow", "Space", nullptr));
        change_space->setText(QCoreApplication::translate("MainWindow", "Change space", nullptr));
        Test1->setText(QCoreApplication::translate("MainWindow", "Test1", nullptr));
        pTest2->setText(QCoreApplication::translate("MainWindow", "Test2", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        AddingQuest->setText(QCoreApplication::translate("MainWindow", "Add Quest", nullptr));
#if QT_CONFIG(tooltip)
        character_icon->setToolTip(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        character_icon->setWhatsThis(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(whatsthis)
        character_icon->setText(QString());
        Open_inventory->setText(QCoreApplication::translate("MainWindow", "Open inventory", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Active Item", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MainWindow", "Mana", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MainWindow", "Health", nullptr));
        ExperienceLabel->setText(QCoreApplication::translate("MainWindow", "Exp", nullptr));
        more_characteristics->setText(QCoreApplication::translate("MainWindow", "More", nullptr));
        TextNote->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        NoteTime->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tags_option->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
