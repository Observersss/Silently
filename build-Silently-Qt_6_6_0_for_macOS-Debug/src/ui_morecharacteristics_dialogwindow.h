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
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MoreCharacteristics_DialogWindow
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *Level;
    QLabel *LevelLabel;
    QLabel *Exp;
    QLabel *ExperienceLabel;
    QLabel *Health;
    QLabel *HealthLabel;
    QLabel *Mana;
    QLabel *ManaLabel;
    QLabel *Damage;
    QLabel *DamgeLabel;
    QLabel *ChanceOfCriticalDamage;
    QLabel *ChanceLabel;
    QLabel *CriticalDamage;
    QLabel *CriticalLabel;
    QLabel *Dexterity;
    QLabel *DexterityLabel;
    QLabel *Force;
    QLabel *ForceLabel;
    QLabel *Intelligence;
    QLabel *IntelligenceLabel;
    QLabel *Luck;
    QLabel *LucklLabel;

    void setupUi(QDialog *MoreCharacteristics_DialogWindow)
    {
        if (MoreCharacteristics_DialogWindow->objectName().isEmpty())
            MoreCharacteristics_DialogWindow->setObjectName("MoreCharacteristics_DialogWindow");
        MoreCharacteristics_DialogWindow->resize(346, 636);
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
"background-color:rgb(0, 100, 200);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName("gridLayout");
        Level = new QLabel(frame);
        Level->setObjectName("Level");
        QFont font1;
        font1.setPointSize(15);
        Level->setFont(font1);

        gridLayout->addWidget(Level, 0, 0, 1, 1);

        LevelLabel = new QLabel(frame);
        LevelLabel->setObjectName("LevelLabel");
        LevelLabel->setFont(font1);

        gridLayout->addWidget(LevelLabel, 0, 1, 1, 1);

        Exp = new QLabel(frame);
        Exp->setObjectName("Exp");
        Exp->setFont(font1);

        gridLayout->addWidget(Exp, 1, 0, 1, 1);

        ExperienceLabel = new QLabel(frame);
        ExperienceLabel->setObjectName("ExperienceLabel");
        ExperienceLabel->setFont(font1);

        gridLayout->addWidget(ExperienceLabel, 1, 1, 1, 1);

        Health = new QLabel(frame);
        Health->setObjectName("Health");
        Health->setFont(font1);

        gridLayout->addWidget(Health, 2, 0, 1, 1);

        HealthLabel = new QLabel(frame);
        HealthLabel->setObjectName("HealthLabel");
        HealthLabel->setFont(font1);

        gridLayout->addWidget(HealthLabel, 2, 1, 1, 1);

        Mana = new QLabel(frame);
        Mana->setObjectName("Mana");
        Mana->setFont(font1);

        gridLayout->addWidget(Mana, 3, 0, 1, 1);

        ManaLabel = new QLabel(frame);
        ManaLabel->setObjectName("ManaLabel");
        ManaLabel->setFont(font1);

        gridLayout->addWidget(ManaLabel, 3, 1, 1, 1);

        Damage = new QLabel(frame);
        Damage->setObjectName("Damage");
        Damage->setFont(font1);

        gridLayout->addWidget(Damage, 4, 0, 1, 1);

        DamgeLabel = new QLabel(frame);
        DamgeLabel->setObjectName("DamgeLabel");
        DamgeLabel->setFont(font1);

        gridLayout->addWidget(DamgeLabel, 4, 1, 1, 1);

        ChanceOfCriticalDamage = new QLabel(frame);
        ChanceOfCriticalDamage->setObjectName("ChanceOfCriticalDamage");
        ChanceOfCriticalDamage->setFont(font1);

        gridLayout->addWidget(ChanceOfCriticalDamage, 5, 0, 1, 1);

        ChanceLabel = new QLabel(frame);
        ChanceLabel->setObjectName("ChanceLabel");
        ChanceLabel->setFont(font1);

        gridLayout->addWidget(ChanceLabel, 5, 1, 1, 1);

        CriticalDamage = new QLabel(frame);
        CriticalDamage->setObjectName("CriticalDamage");
        CriticalDamage->setFont(font1);

        gridLayout->addWidget(CriticalDamage, 6, 0, 1, 1);

        CriticalLabel = new QLabel(frame);
        CriticalLabel->setObjectName("CriticalLabel");
        CriticalLabel->setFont(font1);

        gridLayout->addWidget(CriticalLabel, 6, 1, 1, 1);

        Dexterity = new QLabel(frame);
        Dexterity->setObjectName("Dexterity");
        Dexterity->setFont(font1);

        gridLayout->addWidget(Dexterity, 7, 0, 1, 1);

        DexterityLabel = new QLabel(frame);
        DexterityLabel->setObjectName("DexterityLabel");
        DexterityLabel->setFont(font1);

        gridLayout->addWidget(DexterityLabel, 7, 1, 1, 1);

        Force = new QLabel(frame);
        Force->setObjectName("Force");
        Force->setFont(font1);

        gridLayout->addWidget(Force, 8, 0, 1, 1);

        ForceLabel = new QLabel(frame);
        ForceLabel->setObjectName("ForceLabel");
        ForceLabel->setFont(font1);

        gridLayout->addWidget(ForceLabel, 8, 1, 1, 1);

        Intelligence = new QLabel(frame);
        Intelligence->setObjectName("Intelligence");
        Intelligence->setFont(font1);

        gridLayout->addWidget(Intelligence, 9, 0, 1, 1);

        IntelligenceLabel = new QLabel(frame);
        IntelligenceLabel->setObjectName("IntelligenceLabel");
        IntelligenceLabel->setFont(font1);

        gridLayout->addWidget(IntelligenceLabel, 9, 1, 1, 1);

        Luck = new QLabel(frame);
        Luck->setObjectName("Luck");
        Luck->setFont(font1);

        gridLayout->addWidget(Luck, 10, 0, 1, 1);

        LucklLabel = new QLabel(frame);
        LucklLabel->setObjectName("LucklLabel");
        LucklLabel->setFont(font1);

        gridLayout->addWidget(LucklLabel, 10, 1, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(MoreCharacteristics_DialogWindow);

        QMetaObject::connectSlotsByName(MoreCharacteristics_DialogWindow);
    } // setupUi

    void retranslateUi(QDialog *MoreCharacteristics_DialogWindow)
    {
        MoreCharacteristics_DialogWindow->setWindowTitle(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Your Charasteristics", nullptr));
        Level->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Level:", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Exp->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Exp:", nullptr));
        ExperienceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Health->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Health:", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Mana->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Mana:", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Damage->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Damage:", nullptr));
        DamgeLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        ChanceOfCriticalDamage->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Chance of critical damage:", nullptr));
        ChanceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        CriticalDamage->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Critical damage:", nullptr));
        CriticalLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Dexterity->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Dexterity:", nullptr));
        DexterityLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Force->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Force:", nullptr));
        ForceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Intelligence->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Intelligence:", nullptr));
        IntelligenceLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
        Luck->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "Luck:", nullptr));
        LucklLabel->setText(QCoreApplication::translate("MoreCharacteristics_DialogWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoreCharacteristics_DialogWindow: public Ui_MoreCharacteristics_DialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORECHARACTERISTICS_DIALOGWINDOW_H
