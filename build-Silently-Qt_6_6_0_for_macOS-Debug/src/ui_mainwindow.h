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
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QListWidget *QuestList;
    QLabel *character_icon;
    QFrame *infoCharacter;
    QGridLayout *gridLayout;
    QLabel *ExperienceLabel;
    QLabel *LevelLabel;
    QLabel *HealthLabel;
    QLabel *ManaLabel;
    QWidget *Note_space;
    QGridLayout *gridLayout_6;
    QFrame *frame_7;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QListWidget *listTag;
    QPushButton *tags_option;
    QLabel *date_create_note;
    QTextEdit *TextNote;
    QLineEdit *TitleNote;
    QFrame *frame_2;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QLabel *info;
    QPushButton *change_space;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *AddNoteSpace;
    QPushButton *delete_Note_Service;
    QComboBox *NoteSpaces;
    QListWidget *listNote;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *delete_Note;
    QWidget *page_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *AddingQuest;
    QPushButton *more_characteristics;
    QPushButton *Open_inventory;
    QPushButton *guideForUser_button;
    QPushButton *guideForDeveloper_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(744, 705);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        spaces = new QStackedWidget(centralwidget);
        spaces->setObjectName("spaces");
        spaces->setStyleSheet(QString::fromUtf8("background-color:silver;\n"
"border-radius:10px;"));
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
        QuestList->setStyleSheet(QString::fromUtf8("border-radius:18px;\n"
"background-color:white;\n"
"color:black;"));

        gridLayout_5->addWidget(QuestList, 1, 1, 1, 1);


        gridLayout_4->addWidget(frame_3, 0, 0, 2, 1);

        character_icon = new QLabel(RPG_space);
        character_icon->setObjectName("character_icon");
        character_icon->setMinimumSize(QSize(135, 199));
        character_icon->setMaximumSize(QSize(16777215, 16777215));
        character_icon->setStyleSheet(QString::fromUtf8(""));
        character_icon->setInputMethodHints(Qt::ImhNone);

        gridLayout_4->addWidget(character_icon, 0, 1, 1, 1);

        infoCharacter = new QFrame(RPG_space);
        infoCharacter->setObjectName("infoCharacter");
        infoCharacter->setMinimumSize(QSize(160, 201));
        infoCharacter->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"color:white;\n"
"background-color:rgb(0, 150, 255);"));
        infoCharacter->setFrameShape(QFrame::StyledPanel);
        infoCharacter->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(infoCharacter);
        gridLayout->setObjectName("gridLayout");
        ExperienceLabel = new QLabel(infoCharacter);
        ExperienceLabel->setObjectName("ExperienceLabel");
        ExperienceLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ExperienceLabel, 1, 1, 1, 1);

        LevelLabel = new QLabel(infoCharacter);
        LevelLabel->setObjectName("LevelLabel");
        LevelLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(LevelLabel, 0, 1, 1, 1);

        HealthLabel = new QLabel(infoCharacter);
        HealthLabel->setObjectName("HealthLabel");
        HealthLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(HealthLabel, 2, 1, 1, 1);

        ManaLabel = new QLabel(infoCharacter);
        ManaLabel->setObjectName("ManaLabel");
        ManaLabel->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ManaLabel, 3, 1, 1, 1);


        gridLayout_4->addWidget(infoCharacter, 1, 1, 1, 1);

        spaces->addWidget(RPG_space);
        Note_space = new QWidget();
        Note_space->setObjectName("Note_space");
        gridLayout_6 = new QGridLayout(Note_space);
        gridLayout_6->setObjectName("gridLayout_6");
        frame_7 = new QFrame(Note_space);
        frame_7->setObjectName("frame_7");
        frame_7->setMinimumSize(QSize(520, 0));
        frame_7->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:10px;"));
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
"border-radius:9px;"));

        horizontalLayout->addWidget(listTag);

        tags_option = new QPushButton(frame_7);
        tags_option->setObjectName("tags_option");
        tags_option->setMinimumSize(QSize(30, 30));
        tags_option->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setBold(true);
        tags_option->setFont(font);
        tags_option->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"margin:0;\n"
"border-radius:15px;"));

        horizontalLayout->addWidget(tags_option);

        date_create_note = new QLabel(frame_7);
        date_create_note->setObjectName("date_create_note");
        date_create_note->setMinimumSize(QSize(15, 15));
        date_create_note->setMaximumSize(QSize(123545, 30));
        date_create_note->setStyleSheet(QString::fromUtf8("font-size:10px;\n"
"padding-top:5px;\n"
"margin:0;\n"
"color:white"));

        horizontalLayout->addWidget(date_create_note);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        TextNote = new QTextEdit(frame_7);
        TextNote->setObjectName("TextNote");
        TextNote->setMinimumSize(QSize(0, 500));
        TextNote->setMaximumSize(QSize(16777215, 185245));
        TextNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"border-radius:10px;\n"
""));

        gridLayout_3->addWidget(TextNote, 2, 0, 1, 1);

        TitleNote = new QLineEdit(frame_7);
        TitleNote->setObjectName("TitleNote");
        TitleNote->setMinimumSize(QSize(0, 30));
        TitleNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"margin:0;\n"
"border-radius:10px;"));

        gridLayout_3->addWidget(TitleNote, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_7, 0, 1, 1, 1);

        spaces->addWidget(Note_space);

        gridLayout_2->addWidget(spaces, 0, 1, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setMinimumSize(QSize(160, 431));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame = new QFrame(frame_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 161, 101));
        frame->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setObjectName("gridLayout_8");
        info = new QLabel(frame);
        info->setObjectName("info");
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        info->setFont(font1);
        info->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_8->addWidget(info, 0, 0, 1, 1);

        change_space = new QPushButton(frame);
        change_space->setObjectName("change_space");
        change_space->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setPointSize(15);
        change_space->setFont(font2);
        change_space->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"margin:5px;\n"
"margin-bottom:5px;\n"
"border-radius:15px;"));

        gridLayout_8->addWidget(change_space, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 110, 150, 371));
        stackedWidget->setMinimumSize(QSize(150, 0));
        page = new QWidget();
        page->setObjectName("page");
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(-10, 30, 161, 314));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(10, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout_3->setSpacing(-1);
#endif
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(6, -1, 4, -1);
        AddNoteSpace = new QPushButton(layoutWidget);
        AddNoteSpace->setObjectName("AddNoteSpace");
        AddNoteSpace->setMinimumSize(QSize(60, 20));
        AddNoteSpace->setMaximumSize(QSize(66, 16777215));
        QFont font3;
        font3.setPointSize(10);
        AddNoteSpace->setFont(font3);
        AddNoteSpace->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"border-radius:5px;"));

        horizontalLayout_3->addWidget(AddNoteSpace);

        delete_Note_Service = new QPushButton(layoutWidget);
        delete_Note_Service->setObjectName("delete_Note_Service");
        delete_Note_Service->setMinimumSize(QSize(60, 20));
        delete_Note_Service->setMaximumSize(QSize(66, 16777215));
        delete_Note_Service->setFont(font3);
        delete_Note_Service->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"border-radius:5px;"));

        horizontalLayout_3->addWidget(delete_Note_Service);


        gridLayout_7->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        NoteSpaces = new QComboBox(layoutWidget);
        NoteSpaces->setObjectName("NoteSpaces");
        NoteSpaces->setMaximumSize(QSize(25987, 16777215));
        NoteSpaces->setEditable(false);

        gridLayout_7->addWidget(NoteSpaces, 1, 0, 1, 1);

        listNote = new QListWidget(layoutWidget);
        listNote->setObjectName("listNote");
        listNote->setMinimumSize(QSize(0, 0));
        listNote->setMaximumSize(QSize(168, 16777215));
        listNote->setStyleSheet(QString::fromUtf8("background-color:silver;\n"
"color:white;\n"
"border-radius:8px;\n"
""));
        listNote->setIconSize(QSize(50, 50));

        gridLayout_7->addWidget(listNote, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 20));
        pushButton->setMaximumSize(QSize(60, 16777215));
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"border-radius:5px;"));

        horizontalLayout_2->addWidget(pushButton);

        delete_Note = new QPushButton(layoutWidget);
        delete_Note->setObjectName("delete_Note");
        delete_Note->setMinimumSize(QSize(0, 20));
        delete_Note->setFont(font3);
        delete_Note->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"border-radius:5px;"));

        horizontalLayout_2->addWidget(delete_Note);


        gridLayout_7->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        layoutWidget1 = new QWidget(page_2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 190, 141, 141));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        AddingQuest = new QPushButton(layoutWidget1);
        AddingQuest->setObjectName("AddingQuest");
        AddingQuest->setMinimumSize(QSize(0, 30));
        AddingQuest->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:15px;"));

        verticalLayout->addWidget(AddingQuest);

        more_characteristics = new QPushButton(layoutWidget1);
        more_characteristics->setObjectName("more_characteristics");
        more_characteristics->setMinimumSize(QSize(0, 30));
        more_characteristics->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:15px;"));

        verticalLayout->addWidget(more_characteristics);

        Open_inventory = new QPushButton(layoutWidget1);
        Open_inventory->setObjectName("Open_inventory");
        Open_inventory->setMinimumSize(QSize(0, 30));
        Open_inventory->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:15px;"));

        verticalLayout->addWidget(Open_inventory);

        stackedWidget->addWidget(page_2);
        guideForUser_button = new QPushButton(frame_2);
        guideForUser_button->setObjectName("guideForUser_button");
        guideForUser_button->setGeometry(QRect(10, 500, 141, 31));
        guideForUser_button->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:15px;"));
        guideForDeveloper_button = new QPushButton(frame_2);
        guideForDeveloper_button->setObjectName("guideForDeveloper_button");
        guideForDeveloper_button->setGeometry(QRect(10, 540, 141, 32));
        guideForDeveloper_button->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:15px;"));

        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 744, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(change_space, QuestList);
        QWidget::setTabOrder(QuestList, TitleNote);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        character_icon->setToolTip(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        character_icon->setWhatsThis(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(whatsthis)
        character_icon->setText(QString());
        ExperienceLabel->setText(QCoreApplication::translate("MainWindow", "Exp", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MainWindow", "Health", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MainWindow", "Mana", nullptr));
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
        AddNoteSpace->setText(QCoreApplication::translate("MainWindow", "New  space", nullptr));
        delete_Note_Service->setText(QCoreApplication::translate("MainWindow", "delete space", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "add note", nullptr));
        delete_Note->setText(QCoreApplication::translate("MainWindow", "delete note", nullptr));
        AddingQuest->setText(QCoreApplication::translate("MainWindow", "Add Quest", nullptr));
        more_characteristics->setText(QCoreApplication::translate("MainWindow", "More", nullptr));
        Open_inventory->setText(QCoreApplication::translate("MainWindow", "Open inventory", nullptr));
        guideForUser_button->setText(QCoreApplication::translate("MainWindow", "Guide for user", nullptr));
        guideForDeveloper_button->setText(QCoreApplication::translate("MainWindow", "Guide for developer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
