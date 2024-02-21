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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *spaces;
    QWidget *RPG_space;
    QGridLayout *gridLayout_4;
    QFrame *infoCharacter;
    QGridLayout *gridLayout;
    QLabel *ExperienceLabel;
    QLabel *HealthLabel;
    QLabel *LevelLabel;
    QLabel *ManaLabel;
    QLabel *character_icon;
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QListWidget *QuestList;
    QWidget *Note_space;
    QGridLayout *gridLayout_6;
    QFrame *frame_7;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QListWidget *listTag;
    QPushButton *tags_option;
    QLabel *date_create_note;
    QLineEdit *TitleNote;
    QTextEdit *TextNote;
    QFrame *frame_2;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *info;
    QPushButton *change_space;
    QStackedWidget *tools_of_Spaces;
    QWidget *Note_tools;
    QListWidget *listNote;
    QComboBox *NoteSpaces;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *delete_Note;
    QWidget *layoutWidget2;
    QFormLayout *formLayout;
    QPushButton *createNewNoteSpace;
    QPushButton *delete_Note_Service;
    QWidget *RPG_tools;
    QPushButton *Open_inventory;
    QPushButton *AddingQuest;
    QPushButton *more_characteristics;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(875, 672);
        MainWindow->setStyleSheet(QString::fromUtf8("margin:0;\n"
"padding:0;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        spaces = new QStackedWidget(centralwidget);
        spaces->setObjectName("spaces");
        spaces->setStyleSheet(QString::fromUtf8("background-color:silver;\n"
"margin:0;"));
        RPG_space = new QWidget();
        RPG_space->setObjectName("RPG_space");
        gridLayout_4 = new QGridLayout(RPG_space);
        gridLayout_4->setObjectName("gridLayout_4");
        infoCharacter = new QFrame(RPG_space);
        infoCharacter->setObjectName("infoCharacter");
        infoCharacter->setMinimumSize(QSize(160, 201));
        QFont font;
        font.setFamilies({QString::fromUtf8("Big Caslon")});
        infoCharacter->setFont(font);
        infoCharacter->setStyleSheet(QString::fromUtf8("background-color:rgb(54, 88, 255);\n"
"color:orange;\n"
"border-radius:10px;"));
        infoCharacter->setFrameShape(QFrame::StyledPanel);
        infoCharacter->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(infoCharacter);
        gridLayout->setObjectName("gridLayout");
        ExperienceLabel = new QLabel(infoCharacter);
        ExperienceLabel->setObjectName("ExperienceLabel");
        ExperienceLabel->setStyleSheet(QString::fromUtf8("color:white;"));

        gridLayout->addWidget(ExperienceLabel, 1, 1, 1, 1);

        HealthLabel = new QLabel(infoCharacter);
        HealthLabel->setObjectName("HealthLabel");
        HealthLabel->setStyleSheet(QString::fromUtf8("color:white;"));

        gridLayout->addWidget(HealthLabel, 2, 1, 1, 1);

        LevelLabel = new QLabel(infoCharacter);
        LevelLabel->setObjectName("LevelLabel");
        LevelLabel->setStyleSheet(QString::fromUtf8("color:white;"));

        gridLayout->addWidget(LevelLabel, 0, 1, 1, 1);

        ManaLabel = new QLabel(infoCharacter);
        ManaLabel->setObjectName("ManaLabel");
        ManaLabel->setStyleSheet(QString::fromUtf8("color:white;\n"
""));

        gridLayout->addWidget(ManaLabel, 3, 1, 1, 1);


        gridLayout_4->addWidget(infoCharacter, 0, 2, 3, 1);

        character_icon = new QLabel(RPG_space);
        character_icon->setObjectName("character_icon");
        character_icon->setMinimumSize(QSize(135, 199));
        character_icon->setMaximumSize(QSize(16777215, 16777215));
        character_icon->setStyleSheet(QString::fromUtf8(""));
        character_icon->setInputMethodHints(Qt::ImhNone);

        gridLayout_4->addWidget(character_icon, 0, 3, 2, 1);

        frame_3 = new QFrame(RPG_space);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(210, 550));
        frame_3->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setObjectName("gridLayout_5");
        QuestList = new QListWidget(frame_3);
        QuestList->setObjectName("QuestList");
        QuestList->setMinimumSize(QSize(0, 0));
        QuestList->setMouseTracking(false);
        QuestList->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;\n"
"border:none;\n"
"border-radius:10px;"));

        gridLayout_5->addWidget(QuestList, 1, 1, 1, 1);


        gridLayout_4->addWidget(frame_3, 0, 0, 1, 1);

        spaces->addWidget(RPG_space);
        Note_space = new QWidget();
        Note_space->setObjectName("Note_space");
        gridLayout_6 = new QGridLayout(Note_space);
        gridLayout_6->setObjectName("gridLayout_6");
        frame_7 = new QFrame(Note_space);
        frame_7->setObjectName("frame_7");
        frame_7->setMinimumSize(QSize(520, 0));
        frame_7->setStyleSheet(QString::fromUtf8("border:none;\n"
"margin:0;"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_7);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        listTag = new QListWidget(frame_7);
        listTag->setObjectName("listTag");
        listTag->setMinimumSize(QSize(0, 0));
        listTag->setMaximumSize(QSize(100, 30));
        listTag->setStyleSheet(QString::fromUtf8("margin:0;\n"
"background-color:white;\n"
"color:black;\n"
"border-radius:5px;"));

        horizontalLayout->addWidget(listTag);

        tags_option = new QPushButton(frame_7);
        tags_option->setObjectName("tags_option");
        tags_option->setMinimumSize(QSize(30, 30));
        tags_option->setMaximumSize(QSize(30, 30));
        tags_option->setStyleSheet(QString::fromUtf8(" background-color: orange;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    border-radius: 0.5em; /* \320\224\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\275\320\265\320\274\320\275\320\276\320\263\320\276 \320\276\320\262\320\260\320\273\321\214\320\275\320\276\320\271 \321\204\320\276\321\200\320\274\321\213 */\n"
"    box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); /* \320\242\320\265\320\275\321\214 \320\262\320\275\320\270\320\267\321\203 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"font-size:0.8em;\n"
"margin: 1px 5px 2px 5px;"));

        horizontalLayout->addWidget(tags_option);

        date_create_note = new QLabel(frame_7);
        date_create_note->setObjectName("date_create_note");
        date_create_note->setMinimumSize(QSize(15, 15));
        date_create_note->setMaximumSize(QSize(123545, 30));
        date_create_note->setStyleSheet(QString::fromUtf8("font-size:10px;\n"
"padding-top:5px;\n"
"margin:0;\n"
"color:black;"));

        horizontalLayout->addWidget(date_create_note);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        TitleNote = new QLineEdit(frame_7);
        TitleNote->setObjectName("TitleNote");
        TitleNote->setMinimumSize(QSize(0, 30));
        TitleNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"margin:0;\n"
"border-radius:5px;"));

        gridLayout_3->addWidget(TitleNote, 0, 0, 1, 1);

        TextNote = new QTextEdit(frame_7);
        TextNote->setObjectName("TextNote");
        TextNote->setMinimumSize(QSize(0, 430));
        TextNote->setMaximumSize(QSize(16777215, 185245));
        TextNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"border-radius:5px;\n"
""));

        gridLayout_3->addWidget(TextNote, 2, 0, 1, 1);


        gridLayout_6->addWidget(frame_7, 0, 0, 1, 1);

        spaces->addWidget(Note_space);

        gridLayout_2->addWidget(spaces, 0, 1, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(145, 431));
        frame_2->setStyleSheet(QString::fromUtf8("margin:0;\n"
"z-index:1;\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame = new QFrame(frame_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 141, 81));
        frame->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"margin:0;\n"
"padding:0;\n"
"border-radius:5px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1, 1, 141, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        info = new QLabel(layoutWidget);
        info->setObjectName("info");
        info->setMaximumSize(QSize(16777215, 30));
        info->setStyleSheet(QString::fromUtf8("margin:0;\n"
"padding:10px 0 0 0 ;\n"
"padding-top:5px;\n"
"text-align:center;\n"
""));

        verticalLayout_2->addWidget(info);

        change_space = new QPushButton(layoutWidget);
        change_space->setObjectName("change_space");
        change_space->setStyleSheet(QString::fromUtf8(" background-color: orange;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    border-radius: 4px; /* \320\224\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\275\320\265\320\274\320\275\320\276\320\263\320\276 \320\276\320\262\320\260\320\273\321\214\320\275\320\276\320\271 \321\204\320\276\321\200\320\274\321\213 */\n"
"    box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); /* \320\242\320\265\320\275\321\214 \320\262\320\275\320\270\320\267\321\203 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"font-size:0.8em;\n"
"margin: 1px 5px 2px 5px;"));

        verticalLayout_2->addWidget(change_space);

        tools_of_Spaces = new QStackedWidget(frame_2);
        tools_of_Spaces->setObjectName("tools_of_Spaces");
        tools_of_Spaces->setGeometry(QRect(0, 80, 151, 451));
        tools_of_Spaces->setStyleSheet(QString::fromUtf8("height:70%;"));
        Note_tools = new QWidget();
        Note_tools->setObjectName("Note_tools");
        listNote = new QListWidget(Note_tools);
        listNote->setObjectName("listNote");
        listNote->setGeometry(QRect(0, 100, 141, 221));
        listNote->setMinimumSize(QSize(0, 0));
        listNote->setMaximumSize(QSize(168, 16777215));
        listNote->setStyleSheet(QString::fromUtf8("background-color:silver;\n"
"color:black;\n"
"margin:0;\n"
"border-radius:5px;"));
        NoteSpaces = new QComboBox(Note_tools);
        NoteSpaces->setObjectName("NoteSpaces");
        NoteSpaces->setGeometry(QRect(0, 60, 141, 51));
        NoteSpaces->setMaximumSize(QSize(189, 16777215));
        QFont font1;
        font1.setPointSize(11);
        font1.setStyleStrategy(QFont::PreferAntialias);
        NoteSpaces->setFont(font1);
        NoteSpaces->setStyleSheet(QString::fromUtf8("margin:5px;\n"
"color:white;"));
        layoutWidget1 = new QWidget(Note_tools);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 320, 148, 47));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(66, 35));
        QFont font2;
        font2.setPointSize(10);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: black;\n"
"border: none;\n"
"border-radius: 4px; \n"
"box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); \n"
"font-size:0.8em;\n"
"margin: 7px 5px 7px 5px;"));

        horizontalLayout_2->addWidget(pushButton);

        delete_Note = new QPushButton(layoutWidget1);
        delete_Note->setObjectName("delete_Note");
        delete_Note->setMaximumSize(QSize(66, 35));
        delete_Note->setFont(font2);
        delete_Note->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: black;\n"
"border: none;\n"
"border-radius: 4px; \n"
"box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); \n"
"font-size:0.8em;\n"
"margin: 7px 5px 7px 5px;"));

        horizontalLayout_2->addWidget(delete_Note);

        layoutWidget2 = new QWidget(Note_tools);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 30, 151, 37));
        formLayout = new QFormLayout(layoutWidget2);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        createNewNoteSpace = new QPushButton(layoutWidget2);
        createNewNoteSpace->setObjectName("createNewNoteSpace");
        createNewNoteSpace->setMaximumSize(QSize(60, 35));
        createNewNoteSpace->setFont(font2);
        createNewNoteSpace->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: black;\n"
"border: none;\n"
"border-radius: 4px; \n"
"box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); \n"
"\n"
"margin:7px 1px 7px 2px;"));

        formLayout->setWidget(0, QFormLayout::LabelRole, createNewNoteSpace);

        delete_Note_Service = new QPushButton(layoutWidget2);
        delete_Note_Service->setObjectName("delete_Note_Service");
        delete_Note_Service->setMaximumSize(QSize(66, 35));
        delete_Note_Service->setFont(font2);
        delete_Note_Service->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color: black;\n"
"border: none;\n"
"border-radius: 4px; \n"
"box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); \n"
"font-size:0.8em;\n"
"margin:7px 1px 7px 2px;\n"
""));

        formLayout->setWidget(0, QFormLayout::FieldRole, delete_Note_Service);

        tools_of_Spaces->addWidget(Note_tools);
        RPG_tools = new QWidget();
        RPG_tools->setObjectName("RPG_tools");
        Open_inventory = new QPushButton(RPG_tools);
        Open_inventory->setObjectName("Open_inventory");
        Open_inventory->setGeometry(QRect(10, 390, 121, 41));
        Open_inventory->setFont(font2);
        Open_inventory->setStyleSheet(QString::fromUtf8(" background-color: orange;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    border-radius: 0.5em; /* \320\224\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\275\320\265\320\274\320\275\320\276\320\263\320\276 \320\276\320\262\320\260\320\273\321\214\320\275\320\276\320\271 \321\204\320\276\321\200\320\274\321\213 */\n"
"    box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); /* \320\242\320\265\320\275\321\214 \320\262\320\275\320\270\320\267\321\203 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"font-size:0.8em;\n"
"margin: 1px 5px 2px 5px;"));
        AddingQuest = new QPushButton(RPG_tools);
        AddingQuest->setObjectName("AddingQuest");
        AddingQuest->setGeometry(QRect(10, 310, 121, 31));
        AddingQuest->setFont(font2);
        AddingQuest->setStyleSheet(QString::fromUtf8(" background-color: orange;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    border-radius: 0.5em; /* \320\224\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\275\320\265\320\274\320\275\320\276\320\263\320\276 \320\276\320\262\320\260\320\273\321\214\320\275\320\276\320\271 \321\204\320\276\321\200\320\274\321\213 */\n"
"    box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); /* \320\242\320\265\320\275\321\214 \320\262\320\275\320\270\320\267\321\203 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"font-size:0.8em;\n"
"margin: 1px 5px 2px 5px;"));
        more_characteristics = new QPushButton(RPG_tools);
        more_characteristics->setObjectName("more_characteristics");
        more_characteristics->setGeometry(QRect(10, 350, 121, 31));
        more_characteristics->setFont(font2);
        more_characteristics->setStyleSheet(QString::fromUtf8(" background-color: orange;\n"
"    border: none;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    border-radius: 0.5em; /* \320\224\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\275\320\265\320\274\320\275\320\276\320\263\320\276 \320\276\320\262\320\260\320\273\321\214\320\275\320\276\320\271 \321\204\320\276\321\200\320\274\321\213 */\n"
"    box-shadow: 0px 5px 5px rgba(0, 0, 0, 0.2); /* \320\242\320\265\320\275\321\214 \320\262\320\275\320\270\320\267\321\203 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"font-size:0.8em;\n"
"margin: 1px 5px 2px 5px;"));
        tools_of_Spaces->addWidget(RPG_tools);

        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 875, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(QuestList, TitleNote);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ExperienceLabel->setText(QCoreApplication::translate("MainWindow", "Exp", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MainWindow", "Health", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MainWindow", "Mana", nullptr));
#if QT_CONFIG(tooltip)
        character_icon->setToolTip(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        character_icon->setWhatsThis(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(whatsthis)
        character_icon->setText(QString());
        tags_option->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        date_create_note->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        TextNote->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        info->setText(QCoreApplication::translate("MainWindow", "Space", nullptr));
        change_space->setText(QCoreApplication::translate("MainWindow", "Change space", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "add note", nullptr));
        delete_Note->setText(QCoreApplication::translate("MainWindow", "delete note", nullptr));
        createNewNoteSpace->setText(QCoreApplication::translate("MainWindow", "New  space", nullptr));
        delete_Note_Service->setText(QCoreApplication::translate("MainWindow", "delete space", nullptr));
        Open_inventory->setText(QCoreApplication::translate("MainWindow", "Open inventory", nullptr));
        AddingQuest->setText(QCoreApplication::translate("MainWindow", "Add Quest", nullptr));
        more_characteristics->setText(QCoreApplication::translate("MainWindow", "More", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
