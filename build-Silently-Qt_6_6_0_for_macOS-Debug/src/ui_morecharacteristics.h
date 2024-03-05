/********************************************************************************
** Form generated from reading UI file 'morecharacteristics.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MORECHARACTERISTICS_H
#define UI_MORECHARACTERISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MoreCharacteristics
{
public:
    QGridLayout *gridLayout;
    QLabel *Force;
    QLabel *Intelligence;
    QLabel *Level;
    QLabel *Dexterity;
    QLabel *Mana;
    QLabel *CriticalDamage;
    QLabel *Luck;
    QLabel *Health;
    QLabel *Exp;
    QLabel *ChanceOfCriticalDamage;
    QLabel *Damage;
    QLabel *LevelLabel;
    QLabel *ExperienceLabel;
    QLabel *HealthLabel;
    QLabel *ManaLabel;
    QLabel *DamgeLabel;
    QLabel *ChanceLabel;
    QLabel *CriticalLabel;
    QLabel *DexterityLabel;
    QLabel *ForceLabel;
    QLabel *IntelligenceLabel;
    QLabel *LucklLabel;

    void setupUi(QDialog *MoreCharacteristics)
    {
        if (MoreCharacteristics->objectName().isEmpty())
            MoreCharacteristics->setObjectName("MoreCharacteristics");
        MoreCharacteristics->resize(375, 507);
        QFont font;
        font.setPointSize(16);
        MoreCharacteristics->setFont(font);
        MoreCharacteristics->setStyleSheet(QString::fromUtf8("border-radius:12px;\n"
"color:white;\n"
"background-color:rgb(0, 100, 200);"));
        gridLayout = new QGridLayout(MoreCharacteristics);
        gridLayout->setObjectName("gridLayout");
        Force = new QLabel(MoreCharacteristics);
        Force->setObjectName("Force");
        QFont font1;
        font1.setPointSize(15);
        Force->setFont(font1);

        gridLayout->addWidget(Force, 8, 0, 1, 1);

        Intelligence = new QLabel(MoreCharacteristics);
        Intelligence->setObjectName("Intelligence");
        Intelligence->setFont(font1);

        gridLayout->addWidget(Intelligence, 9, 0, 1, 1);

        Level = new QLabel(MoreCharacteristics);
        Level->setObjectName("Level");
        Level->setFont(font1);

        gridLayout->addWidget(Level, 0, 0, 1, 1);

        Dexterity = new QLabel(MoreCharacteristics);
        Dexterity->setObjectName("Dexterity");
        Dexterity->setFont(font1);

        gridLayout->addWidget(Dexterity, 7, 0, 1, 1);

        Mana = new QLabel(MoreCharacteristics);
        Mana->setObjectName("Mana");
        Mana->setFont(font1);

        gridLayout->addWidget(Mana, 3, 0, 1, 1);

        CriticalDamage = new QLabel(MoreCharacteristics);
        CriticalDamage->setObjectName("CriticalDamage");
        CriticalDamage->setFont(font1);

        gridLayout->addWidget(CriticalDamage, 6, 0, 1, 1);

        Luck = new QLabel(MoreCharacteristics);
        Luck->setObjectName("Luck");
        Luck->setFont(font1);

        gridLayout->addWidget(Luck, 10, 0, 1, 1);

        Health = new QLabel(MoreCharacteristics);
        Health->setObjectName("Health");
        Health->setFont(font1);

        gridLayout->addWidget(Health, 2, 0, 1, 1);

        Exp = new QLabel(MoreCharacteristics);
        Exp->setObjectName("Exp");
        Exp->setFont(font1);

        gridLayout->addWidget(Exp, 1, 0, 1, 1);

        ChanceOfCriticalDamage = new QLabel(MoreCharacteristics);
        ChanceOfCriticalDamage->setObjectName("ChanceOfCriticalDamage");
        ChanceOfCriticalDamage->setFont(font1);

        gridLayout->addWidget(ChanceOfCriticalDamage, 5, 0, 1, 1);

        Damage = new QLabel(MoreCharacteristics);
        Damage->setObjectName("Damage");
        Damage->setFont(font1);

        gridLayout->addWidget(Damage, 4, 0, 1, 1);

        LevelLabel = new QLabel(MoreCharacteristics);
        LevelLabel->setObjectName("LevelLabel");
        LevelLabel->setFont(font1);

        gridLayout->addWidget(LevelLabel, 0, 1, 1, 1);

        ExperienceLabel = new QLabel(MoreCharacteristics);
        ExperienceLabel->setObjectName("ExperienceLabel");
        ExperienceLabel->setFont(font1);

        gridLayout->addWidget(ExperienceLabel, 1, 1, 1, 1);

        HealthLabel = new QLabel(MoreCharacteristics);
        HealthLabel->setObjectName("HealthLabel");
        HealthLabel->setFont(font1);

        gridLayout->addWidget(HealthLabel, 2, 1, 1, 1);

        ManaLabel = new QLabel(MoreCharacteristics);
        ManaLabel->setObjectName("ManaLabel");
        ManaLabel->setFont(font1);

        gridLayout->addWidget(ManaLabel, 3, 1, 1, 1);

        DamgeLabel = new QLabel(MoreCharacteristics);
        DamgeLabel->setObjectName("DamgeLabel");
        DamgeLabel->setFont(font1);

        gridLayout->addWidget(DamgeLabel, 4, 1, 1, 1);

        ChanceLabel = new QLabel(MoreCharacteristics);
        ChanceLabel->setObjectName("ChanceLabel");
        ChanceLabel->setFont(font1);

        gridLayout->addWidget(ChanceLabel, 5, 1, 1, 1);

        CriticalLabel = new QLabel(MoreCharacteristics);
        CriticalLabel->setObjectName("CriticalLabel");
        CriticalLabel->setFont(font1);

        gridLayout->addWidget(CriticalLabel, 6, 1, 1, 1);

        DexterityLabel = new QLabel(MoreCharacteristics);
        DexterityLabel->setObjectName("DexterityLabel");
        DexterityLabel->setFont(font1);

        gridLayout->addWidget(DexterityLabel, 7, 1, 1, 1);

        ForceLabel = new QLabel(MoreCharacteristics);
        ForceLabel->setObjectName("ForceLabel");
        ForceLabel->setFont(font1);

        gridLayout->addWidget(ForceLabel, 8, 1, 1, 1);

        IntelligenceLabel = new QLabel(MoreCharacteristics);
        IntelligenceLabel->setObjectName("IntelligenceLabel");
        IntelligenceLabel->setFont(font1);

        gridLayout->addWidget(IntelligenceLabel, 9, 1, 1, 1);

        LucklLabel = new QLabel(MoreCharacteristics);
        LucklLabel->setObjectName("LucklLabel");
        LucklLabel->setFont(font1);

        gridLayout->addWidget(LucklLabel, 10, 1, 1, 1);


        retranslateUi(MoreCharacteristics);

        QMetaObject::connectSlotsByName(MoreCharacteristics);
    } // setupUi

    void retranslateUi(QDialog *MoreCharacteristics)
    {
        MoreCharacteristics->setWindowTitle(QCoreApplication::translate("MoreCharacteristics", "Dialog", nullptr));
        Force->setText(QCoreApplication::translate("MoreCharacteristics", "Force:", nullptr));
        Intelligence->setText(QCoreApplication::translate("MoreCharacteristics", "Intelligence:", nullptr));
        Level->setText(QCoreApplication::translate("MoreCharacteristics", "Level:", nullptr));
        Dexterity->setText(QCoreApplication::translate("MoreCharacteristics", "Dexterity:", nullptr));
        Mana->setText(QCoreApplication::translate("MoreCharacteristics", "Mana:", nullptr));
        CriticalDamage->setText(QCoreApplication::translate("MoreCharacteristics", "Critical damage:", nullptr));
        Luck->setText(QCoreApplication::translate("MoreCharacteristics", "Luck:", nullptr));
        Health->setText(QCoreApplication::translate("MoreCharacteristics", "Health:", nullptr));
        Exp->setText(QCoreApplication::translate("MoreCharacteristics", "Exp:", nullptr));
        ChanceOfCriticalDamage->setText(QCoreApplication::translate("MoreCharacteristics", "Chance of critical damage:", nullptr));
        Damage->setText(QCoreApplication::translate("MoreCharacteristics", "Damage:", nullptr));
        LevelLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        ExperienceLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        HealthLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        ManaLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        DamgeLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        ChanceLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        CriticalLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        DexterityLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        ForceLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        IntelligenceLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
        LucklLabel->setText(QCoreApplication::translate("MoreCharacteristics", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoreCharacteristics: public Ui_MoreCharacteristics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MORECHARACTERISTICS_H
