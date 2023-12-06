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
    QFrame *frame_2;
    QFrame *frame;
    QLabel *info;
    QPushButton *change_space;
    QStackedWidget *spaces;
    QWidget *RPG_space;
    QGridLayout *gridLayout_4;
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QPushButton *AddingQuest;
    QListWidget *QuestList;
    QPushButton *Open_inventory;
    QFrame *infoCharacter;
    QGridLayout *gridLayout;
    QLabel *ManaLabel;
    QLabel *LevelLabel;
    QLabel *HealthLabel;
    QLabel *ExperienceLabel;
    QPushButton *more_characteristics;
    QLabel *character_icon;
    QWidget *Note_space;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *createNewNoteSpace;
    QPushButton *delete_Note_Service;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *NoteSpaces;
    QListWidget *listNote;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *delete_Note;
    QFrame *frame_7;
    QGridLayout *gridLayout_3;
    QTextEdit *TextNote;
    QHBoxLayout *horizontalLayout;
    QListWidget *listTag;
    QPushButton *tags_option;
    QLabel *date_create_note;
    QLineEdit *TitleNote;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(875, 661);
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
        AddingQuest = new QPushButton(frame_3);
        AddingQuest->setObjectName("AddingQuest");
        AddingQuest->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_5->addWidget(AddingQuest, 2, 1, 1, 1);

        QuestList = new QListWidget(frame_3);
        QuestList->setObjectName("QuestList");
        QuestList->setMinimumSize(QSize(0, 0));
        QuestList->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_5->addWidget(QuestList, 1, 1, 1, 1);

        Open_inventory = new QPushButton(frame_3);
        Open_inventory->setObjectName("Open_inventory");
        Open_inventory->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_5->addWidget(Open_inventory, 3, 1, 1, 1);


        gridLayout_4->addWidget(frame_3, 2, 1, 1, 1);

        infoCharacter = new QFrame(RPG_space);
        infoCharacter->setObjectName("infoCharacter");
        infoCharacter->setMinimumSize(QSize(160, 201));
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


        gridLayout_4->addWidget(infoCharacter, 0, 2, 3, 1);

        character_icon = new QLabel(RPG_space);
        character_icon->setObjectName("character_icon");
        character_icon->setMinimumSize(QSize(135, 199));
        character_icon->setMaximumSize(QSize(16777215, 16777215));
        character_icon->setStyleSheet(QString::fromUtf8(""));
        character_icon->setInputMethodHints(Qt::ImhNone);

        gridLayout_4->addWidget(character_icon, 2, 0, 1, 1);

        spaces->addWidget(RPG_space);
        Note_space = new QWidget();
        Note_space->setObjectName("Note_space");
        gridLayout_6 = new QGridLayout(Note_space);
        gridLayout_6->setObjectName("gridLayout_6");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        createNewNoteSpace = new QPushButton(Note_space);
        createNewNoteSpace->setObjectName("createNewNoteSpace");
        createNewNoteSpace->setMaximumSize(QSize(60, 16777215));
        QFont font;
        font.setPointSize(10);
        createNewNoteSpace->setFont(font);
        createNewNoteSpace->setStyleSheet(QString::fromUtf8("background-color:black;\n"
""));

        horizontalLayout_4->addWidget(createNewNoteSpace);

        delete_Note_Service = new QPushButton(Note_space);
        delete_Note_Service->setObjectName("delete_Note_Service");
        delete_Note_Service->setMaximumSize(QSize(66, 16777215));
        delete_Note_Service->setFont(font);
        delete_Note_Service->setStyleSheet(QString::fromUtf8("background-color:black;"));

        horizontalLayout_4->addWidget(delete_Note_Service);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        NoteSpaces = new QComboBox(Note_space);
        NoteSpaces->setObjectName("NoteSpaces");
        NoteSpaces->setMaximumSize(QSize(25987, 16777215));

        horizontalLayout_3->addWidget(NoteSpaces);


        verticalLayout->addLayout(horizontalLayout_3);

        listNote = new QListWidget(Note_space);
        listNote->setObjectName("listNote");
        listNote->setMinimumSize(QSize(0, 0));
        listNote->setMaximumSize(QSize(168, 16777215));
        listNote->setStyleSheet(QString::fromUtf8("border-color:black;\n"
"margin:0;\n"
""));

        verticalLayout->addWidget(listNote);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(Note_space);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(60, 16777215));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"margin:0;"));

        horizontalLayout_2->addWidget(pushButton);

        delete_Note = new QPushButton(Note_space);
        delete_Note->setObjectName("delete_Note");
        delete_Note->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"margin:0;"));

        horizontalLayout_2->addWidget(delete_Note);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_6->addLayout(verticalLayout, 0, 0, 1, 1);

        frame_7 = new QFrame(Note_space);
        frame_7->setObjectName("frame_7");
        frame_7->setMinimumSize(QSize(520, 0));
        frame_7->setStyleSheet(QString::fromUtf8("border:none;"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_7);
        gridLayout_3->setObjectName("gridLayout_3");
        TextNote = new QTextEdit(frame_7);
        TextNote->setObjectName("TextNote");
        TextNote->setMinimumSize(QSize(0, 430));
        TextNote->setMaximumSize(QSize(16777215, 185245));
        TextNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
""));

        gridLayout_3->addWidget(TextNote, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        listTag = new QListWidget(frame_7);
        listTag->setObjectName("listTag");
        listTag->setMinimumSize(QSize(0, 0));
        listTag->setMaximumSize(QSize(100, 30));
        listTag->setStyleSheet(QString::fromUtf8("margin:0;\n"
"background-color:black;\n"
"color:white;"));

        horizontalLayout->addWidget(listTag);

        tags_option = new QPushButton(frame_7);
        tags_option->setObjectName("tags_option");
        tags_option->setMinimumSize(QSize(30, 30));
        tags_option->setMaximumSize(QSize(30, 30));
        tags_option->setStyleSheet(QString::fromUtf8("background-color:green;\n"
"color:black;\n"
"margin:0;"));

        horizontalLayout->addWidget(tags_option);

        date_create_note = new QLabel(frame_7);
        date_create_note->setObjectName("date_create_note");
        date_create_note->setMinimumSize(QSize(15, 15));
        date_create_note->setMaximumSize(QSize(123545, 30));
        date_create_note->setStyleSheet(QString::fromUtf8("font-size:10px;\n"
"padding-top:5px;\n"
"margin:0;"));

        horizontalLayout->addWidget(date_create_note);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        TitleNote = new QLineEdit(frame_7);
        TitleNote->setObjectName("TitleNote");
        TitleNote->setMinimumSize(QSize(0, 30));
        TitleNote->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"color:black;\n"
"margin:0;"));

        gridLayout_3->addWidget(TitleNote, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_7, 0, 1, 1, 1);

        spaces->addWidget(Note_space);

        gridLayout_2->addWidget(spaces, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 875, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(change_space, QuestList);
        QWidget::setTabOrder(QuestList, AddingQuest);
        QWidget::setTabOrder(AddingQuest, Open_inventory);
        QWidget::setTabOrder(Open_inventory, more_characteristics);
        QWidget::setTabOrder(more_characteristics, TitleNote);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        info->setText(QCoreApplication::translate("MainWindow", "Space", nullptr));
        change_space->setText(QCoreApplication::translate("MainWindow", "Change space", nullptr));
        AddingQuest->setText(QCoreApplication::translate("MainWindow", "Add Quest", nullptr));
        Open_inventory->setText(QCoreApplication::translate("MainWindow", "Open inventory", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MainWindow", "Mana", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MainWindow", "Health", nullptr));
        ExperienceLabel->setText(QCoreApplication::translate("MainWindow", "Exp", nullptr));
        more_characteristics->setText(QCoreApplication::translate("MainWindow", "More", nullptr));
#if QT_CONFIG(tooltip)
        character_icon->setToolTip(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        character_icon->setWhatsThis(QCoreApplication::translate("MainWindow", "\320\246\320\265 \321\202\320\262\321\226\320\271 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266", nullptr));
#endif // QT_CONFIG(whatsthis)
        character_icon->setText(QString());
        createNewNoteSpace->setText(QCoreApplication::translate("MainWindow", "New  space", nullptr));
        delete_Note_Service->setText(QCoreApplication::translate("MainWindow", "delete space", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "add note", nullptr));
        delete_Note->setText(QCoreApplication::translate("MainWindow", "delete note", nullptr));
        TextNote->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tags_option->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        date_create_note->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
