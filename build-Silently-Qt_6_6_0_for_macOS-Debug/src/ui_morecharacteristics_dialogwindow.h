/********************************************************************************
** Form generated from reading UI file 'morecharacteristics_dialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORECHARACTERISTICS_DIALOGWINDOW_H
#define UI_MORECHARACTERISTICS_DIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MoreCharacteristics_DialogWindow
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *HealthLabel;
    QLabel *Mana;
    QLabel *Luck;
    QLabel *Exp;
    QLabel *LevelLabel;
    QLabel *DexterityLabel;
    QLabel *LucklLabel;
    QLabel *DamageLabel;
    QLabel *ChanceOfCriticalDamage;
    QLabel *IntelligenceLabel;
    QLabel *ManaLabel;
    QLabel *ExperienceLabel;
    QLabel *ChanceLabel;
    QLabel *Dexterity;
    QLabel *Intelligence;
    QLabel *CriticalLabel;
    QLabel *CriticalDamage;
    QLabel *Health;
    QLabel *Damage;
    QLabel *ForceLabel;
    QLabel *Force;
    QLabel *Level;
    QLabel *label_info;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Damage_2;
    QSpinBox *spinBox_damage;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Mana_2;
    QSpinBox *spinBox_mana;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Intelligence_2;
    QSpinBox *spinBox_intelligence;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_point;
    QLabel *label_pointCount;
    QHBoxLayout *horizontalLayout_7;
    QLabel *Force_2;
    QSpinBox *spinBox_force;
    QHBoxLayout *horizontalLayout_4;
    QLabel *ChanceOfCriticalDamage_2;
    QSpinBox *spinBox_chanceOfCriticalDamage;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Dexterity_2;
    QSpinBox *spinBox_dexterity;
    QHBoxLayout *horizontalLayout;
    QLabel *Health_2;
    QSpinBox *spinBox_health;
    QHBoxLayout *horizontalLayout_5;
    QLabel *CriticalDamage_2;
    QSpinBox *spinBox_criticalDamage;
    QHBoxLayout *horizontalLayout_9;
    QLabel *Luck_2;
    QSpinBox *spinBox_luck;
    QPushButton *pushButton;

    void setupUi(QDialog *MoreCharacteristics_DialogWindow)
    {
        if (MoreCharacteristics_DialogWindow->objectName().isEmpty())
            MoreCharacteristics_DialogWindow->setObjectName("MoreCharacteristics_DialogWindow");
        MoreCharacteristics_DialogWindow->resize(638, 636);
        MoreCharacteristics_DialogWindow->setStyleSheet(QString::fromUtf8("background-color:white;"));
        gridLayout_2 = new QGridLayout(MoreCharacteristics_DialogWindow);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(MoreCharacteristics_DialogWindow);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 35));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:orange;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        frame = new QFrame(MoreCharacteristics_DialogWindow);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"color:white;\n"
"background-color:rgb(0, 150, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        HealthLabel = new QLabel(frame);
        HealthLabel->setObjectName("HealthLabel");
        QFont font1;
        font1.setPointSize(15);
        HealthLabel->setFont(font1);

        gridLayout->addWidget(HealthLabel, 2, 1, 1, 1);

        Mana = new QLabel(frame);
        Mana->setObjectName("Mana");
        Mana->setFont(font1);

        gridLayout->addWidget(Mana, 3, 0, 1, 1);

        Luck = new QLabel(frame);
        Luck->setObjectName("Luck");
        Luck->setFont(font1);

        gridLayout->addWidget(Luck, 10, 0, 1, 1);

        Exp = new QLabel(frame);
        Exp->setObjectName("Exp");
        Exp->setFont(font1);

        gridLayout->addWidget(Exp, 1, 0, 1, 1);

        LevelLabel = new QLabel(frame);
        LevelLabel->setObjectName("LevelLabel");
        LevelLabel->setFont(font1);

        gridLayout->addWidget(LevelLabel, 0, 1, 1, 1);

        DexterityLabel = new QLabel(frame);
        DexterityLabel->setObjectName("DexterityLabel");
        DexterityLabel->setFont(font1);

        gridLayout->addWidget(DexterityLabel, 7, 1, 1, 1);

        LucklLabel = new QLabel(frame);
        LucklLabel->setObjectName("LucklLabel");
        LucklLabel->setFont(font1);

        gridLayout->addWidget(LucklLabel, 10, 1, 1, 1);

        DamageLabel = new QLabel(frame);
        DamageLabel->setObjectName("DamageLabel");
        DamageLabel->setFont(font1);

        gridLayout->addWidget(DamageLabel, 4, 1, 1, 1);

        ChanceOfCriticalDamage = new QLabel(frame);
        ChanceOfCriticalDamage->setObjectName("ChanceOfCriticalDamage");
        ChanceOfCriticalDamage->setFont(font1);

        gridLayout->addWidget(ChanceOfCriticalDamage, 5, 0, 1, 1);

        IntelligenceLabel = new QLabel(frame);
        IntelligenceLabel->setObjectName("IntelligenceLabel");
        IntelligenceLabel->setFont(font1);

        gridLayout->addWidget(IntelligenceLabel, 9, 1, 1, 1);

        ManaLabel = new QLabel(frame);
        ManaLabel->setObjectName("ManaLabel");
        ManaLabel->setFont(font1);

        gridLayout->addWidget(ManaLabel, 3, 1, 1, 1);

        ExperienceLabel = new QLabel(frame);
        ExperienceLabel->setObjectName("ExperienceLabel");
        ExperienceLabel->setFont(font1);

        gridLayout->addWidget(ExperienceLabel, 1, 1, 1, 1);

        ChanceLabel = new QLabel(frame);
        ChanceLabel->setObjectName("ChanceLabel");
        ChanceLabel->setFont(font1);

        gridLayout->addWidget(ChanceLabel, 5, 1, 1, 1);

        Dexterity = new QLabel(frame);
        Dexterity->setObjectName("Dexterity");
        Dexterity->setFont(font1);

        gridLayout->addWidget(Dexterity, 7, 0, 1, 1);

        Intelligence = new QLabel(frame);
        Intelligence->setObjectName("Intelligence");
        Intelligence->setFont(font1);

        gridLayout->addWidget(Intelligence, 9, 0, 1, 1);

        CriticalLabel = new QLabel(frame);
        CriticalLabel->setObjectName("CriticalLabel");
        CriticalLabel->setFont(font1);

        gridLayout->addWidget(CriticalLabel, 6, 1, 1, 1);

        CriticalDamage = new QLabel(frame);
        CriticalDamage->setObjectName("CriticalDamage");
        CriticalDamage->setFont(font1);

        gridLayout->addWidget(CriticalDamage, 6, 0, 1, 1);

        Health = new QLabel(frame);
        Health->setObjectName("Health");
        Health->setFont(font1);

        gridLayout->addWidget(Health, 2, 0, 1, 1);

        Damage = new QLabel(frame);
        Damage->setObjectName("Damage");
        Damage->setFont(font1);

        gridLayout->addWidget(Damage, 4, 0, 1, 1);

        ForceLabel = new QLabel(frame);
        ForceLabel->setObjectName("ForceLabel");
        ForceLabel->setFont(font1);

        gridLayout->addWidget(ForceLabel, 8, 1, 1, 1);

        Force = new QLabel(frame);
        Force->setObjectName("Force");
        Force->setFont(font1);

        gridLayout->addWidget(Force, 8, 0, 1, 1);

        Level = new QLabel(frame);
        Level->setObjectName("Level");
        Level->setFont(font1);

        gridLayout->addWidget(Level, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        label_info = new QLabel(MoreCharacteristics_DialogWindow);
        label_info->setObjectName("label_info");
        label_info->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        label_info->setFont(font2);
        label_info->setStyleSheet(QString::fromUtf8("color:orange;"));

        gridLayout_2->addWidget(label_info, 0, 1, 1, 1);

        frame_2 = new QFrame(MoreCharacteristics_DialogWindow);
        frame_2->setObjectName("frame_2");
        frame_2->setMaximumSize(QSize(200, 16777215));
        frame_2->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"color:white;\n"
"background-color:rgb(0, 150, 255);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Damage_2 = new QLabel(frame_2);
        Damage_2->setObjectName("Damage_2");
        Damage_2->setFont(font1);

        horizontalLayout_3->addWidget(Damage_2);

        spinBox_damage = new QSpinBox(frame_2);
        spinBox_damage->setObjectName("spinBox_damage");
        spinBox_damage->setMaximumSize(QSize(40, 50));

        horizontalLayout_3->addWidget(spinBox_damage);


        gridLayout_3->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Mana_2 = new QLabel(frame_2);
        Mana_2->setObjectName("Mana_2");
        Mana_2->setFont(font1);

        horizontalLayout_2->addWidget(Mana_2);

        spinBox_mana = new QSpinBox(frame_2);
        spinBox_mana->setObjectName("spinBox_mana");
        spinBox_mana->setMaximumSize(QSize(40, 50));
        spinBox_mana->setReadOnly(false);

        horizontalLayout_2->addWidget(spinBox_mana);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        Intelligence_2 = new QLabel(frame_2);
        Intelligence_2->setObjectName("Intelligence_2");
        Intelligence_2->setFont(font1);

        horizontalLayout_8->addWidget(Intelligence_2);

        spinBox_intelligence = new QSpinBox(frame_2);
        spinBox_intelligence->setObjectName("spinBox_intelligence");
        spinBox_intelligence->setMaximumSize(QSize(40, 50));

        horizontalLayout_8->addWidget(spinBox_intelligence);


        gridLayout_3->addLayout(horizontalLayout_8, 8, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_point = new QLabel(frame_2);
        label_point->setObjectName("label_point");
        label_point->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_point);

        label_pointCount = new QLabel(frame_2);
        label_pointCount->setObjectName("label_pointCount");

        horizontalLayout_10->addWidget(label_pointCount);


        gridLayout_3->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        Force_2 = new QLabel(frame_2);
        Force_2->setObjectName("Force_2");
        Force_2->setFont(font1);

        horizontalLayout_7->addWidget(Force_2);

        spinBox_force = new QSpinBox(frame_2);
        spinBox_force->setObjectName("spinBox_force");
        spinBox_force->setMaximumSize(QSize(40, 50));

        horizontalLayout_7->addWidget(spinBox_force);


        gridLayout_3->addLayout(horizontalLayout_7, 7, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        ChanceOfCriticalDamage_2 = new QLabel(frame_2);
        ChanceOfCriticalDamage_2->setObjectName("ChanceOfCriticalDamage_2");
        ChanceOfCriticalDamage_2->setFont(font1);

        horizontalLayout_4->addWidget(ChanceOfCriticalDamage_2);

        spinBox_chanceOfCriticalDamage = new QSpinBox(frame_2);
        spinBox_chanceOfCriticalDamage->setObjectName("spinBox_chanceOfCriticalDamage");
        spinBox_chanceOfCriticalDamage->setMaximumSize(QSize(40, 50));

        horizontalLayout_4->addWidget(spinBox_chanceOfCriticalDamage);


        gridLayout_3->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        Dexterity_2 = new QLabel(frame_2);
        Dexterity_2->setObjectName("Dexterity_2");
        Dexterity_2->setFont(font1);

        horizontalLayout_6->addWidget(Dexterity_2);

        spinBox_dexterity = new QSpinBox(frame_2);
        spinBox_dexterity->setObjectName("spinBox_dexterity");
        spinBox_dexterity->setMaximumSize(QSize(40, 50));

        horizontalLayout_6->addWidget(spinBox_dexterity);


        gridLayout_3->addLayout(horizontalLayout_6, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Health_2 = new QLabel(frame_2);
        Health_2->setObjectName("Health_2");
        Health_2->setFont(font1);

        horizontalLayout->addWidget(Health_2);

        spinBox_health = new QSpinBox(frame_2);
        spinBox_health->setObjectName("spinBox_health");
        spinBox_health->setMaximumSize(QSize(40, 50));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setStyleStrategy(QFont::PreferDefault);
        spinBox_health->setFont(font3);
        spinBox_health->setAutoFillBackground(false);
        spinBox_health->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_health->setReadOnly(false);
        spinBox_health->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_health->setAccelerated(false);
        spinBox_health->setMaximum(200);

        horizontalLayout->addWidget(spinBox_health);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        CriticalDamage_2 = new QLabel(frame_2);
        CriticalDamage_2->setObjectName("CriticalDamage_2");
        CriticalDamage_2->setFont(font1);

        horizontalLayout_5->addWidget(CriticalDamage_2);

        spinBox_criticalDamage = new QSpinBox(frame_2);
        spinBox_criticalDamage->setObjectName("spinBox_criticalDamage");
        spinBox_criticalDamage->setMaximumSize(QSize(40, 50));

        horizontalLayout_5->addWidget(spinBox_criticalDamage);


        gridLayout_3->addLayout(horizontalLayout_5, 5, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        Luck_2 = new QLabel(frame_2);
        Luck_2->setObjectName("Luck_2");
        Luck_2->setFont(font1);

        horizontalLayout_9->addWidget(Luck_2);

        spinBox_luck = new QSpinBox(frame_2);
        spinBox_luck->setObjectName("spinBox_luck");
        spinBox_luck->setMaximumSize(QSize(40, 50));

        horizontalLayout_9->addWidget(spinBox_luck);


        gridLayout_3->addLayout(horizontalLayout_9, 9, 0, 1, 1);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(false);
        pushButton->setFont(font4);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:orange;\n"
"border-radius:10px;"));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        gridLayout_3->addWidget(pushButton, 10, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 1, 1, 1, 1);


        retranslateUi(MoreCharacteristics_DialogWindow);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(MoreCharacteristics_DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *MoreCharacteristics_DialogWindow)
    {
        MoreCharacteristics_DialogWindow->setWindowTitle(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Your Charasteristics", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Mana->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Mana:", nullptr));
        Luck->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Luck:", nullptr));
        Exp->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Exp:", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        DexterityLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        LucklLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        DamageLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        ChanceOfCriticalDamage->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Chance of critical damage:", nullptr));
        IntelligenceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        ExperienceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        ChanceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Dexterity->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Dexterity:", nullptr));
        Intelligence->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Intelligence:", nullptr));
        CriticalLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        CriticalDamage->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Critical damage:", nullptr));
        Health->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Health:", nullptr));
        Damage->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Damage:", nullptr));
        ForceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Force->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Force:", nullptr));
        Level->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Level:", nullptr));
        label_info->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Update your characteristics", nullptr));
        Damage_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Damage:", nullptr));
        Mana_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Mana:", nullptr));
        Intelligence_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Intelligence:", nullptr));
        label_point->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Unused points:", nullptr));
        label_pointCount->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "12", nullptr));
        Force_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Force:", nullptr));
        ChanceOfCriticalDamage_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Chance of CD:", nullptr));
        Dexterity_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Dexterity:", nullptr));
        Health_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Health:", nullptr));
        CriticalDamage_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Critical damage:", nullptr));
        Luck_2->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Luck:", nullptr));
        pushButton->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoreCharacteristics_DialogWindow: public Ui_MoreCharacteristics_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORECHARACTERISTICS_DIALOGWINDOW_H
