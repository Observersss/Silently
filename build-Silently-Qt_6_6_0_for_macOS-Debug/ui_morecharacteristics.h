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
        gridLayout = new QGridLayout(MoreCharacteristics);
        gridLayout->setObjectName("gridLayout");
        Force = new QLabel(MoreCharacteristics);
        Force->setObjectName("Force");

        gridLayout->addWidget(Force, 8, 0, 1, 1);

        Intelligence = new QLabel(MoreCharacteristics);
        Intelligence->setObjectName("Intelligence");

        gridLayout->addWidget(Intelligence, 9, 0, 1, 1);

        Level = new QLabel(MoreCharacteristics);
        Level->setObjectName("Level");

        gridLayout->addWidget(Level, 0, 0, 1, 1);

        Dexterity = new QLabel(MoreCharacteristics);
        Dexterity->setObjectName("Dexterity");

        gridLayout->addWidget(Dexterity, 7, 0, 1, 1);

        Mana = new QLabel(MoreCharacteristics);
        Mana->setObjectName("Mana");

        gridLayout->addWidget(Mana, 3, 0, 1, 1);

        CriticalDamage = new QLabel(MoreCharacteristics);
        CriticalDamage->setObjectName("CriticalDamage");

        gridLayout->addWidget(CriticalDamage, 6, 0, 1, 1);

        Luck = new QLabel(MoreCharacteristics);
        Luck->setObjectName("Luck");

        gridLayout->addWidget(Luck, 10, 0, 1, 1);

        Health = new QLabel(MoreCharacteristics);
        Health->setObjectName("Health");

        gridLayout->addWidget(Health, 2, 0, 1, 1);

        Exp = new QLabel(MoreCharacteristics);
        Exp->setObjectName("Exp");

        gridLayout->addWidget(Exp, 1, 0, 1, 1);

        ChanceOfCriticalDamage = new QLabel(MoreCharacteristics);
        ChanceOfCriticalDamage->setObjectName("ChanceOfCriticalDamage");

        gridLayout->addWidget(ChanceOfCriticalDamage, 5, 0, 1, 1);

        Damage = new QLabel(MoreCharacteristics);
        Damage->setObjectName("Damage");

        gridLayout->addWidget(Damage, 4, 0, 1, 1);

        LevelLabel = new QLabel(MoreCharacteristics);
        LevelLabel->setObjectName("LevelLabel");

        gridLayout->addWidget(LevelLabel, 0, 1, 1, 1);

        ExperienceLabel = new QLabel(MoreCharacteristics);
        ExperienceLabel->setObjectName("ExperienceLabel");

        gridLayout->addWidget(ExperienceLabel, 1, 1, 1, 1);

        HealthLabel = new QLabel(MoreCharacteristics);
        HealthLabel->setObjectName("HealthLabel");

        gridLayout->addWidget(HealthLabel, 2, 1, 1, 1);

        ManaLabel = new QLabel(MoreCharacteristics);
        ManaLabel->setObjectName("ManaLabel");

        gridLayout->addWidget(ManaLabel, 3, 1, 1, 1);

        DamgeLabel = new QLabel(MoreCharacteristics);
        DamgeLabel->setObjectName("DamgeLabel");

        gridLayout->addWidget(DamgeLabel, 4, 1, 1, 1);

        ChanceLabel = new QLabel(MoreCharacteristics);
        ChanceLabel->setObjectName("ChanceLabel");

        gridLayout->addWidget(ChanceLabel, 5, 1, 1, 1);

        CriticalLabel = new QLabel(MoreCharacteristics);
        CriticalLabel->setObjectName("CriticalLabel");

        gridLayout->addWidget(CriticalLabel, 6, 1, 1, 1);

        DexterityLabel = new QLabel(MoreCharacteristics);
        DexterityLabel->setObjectName("DexterityLabel");

        gridLayout->addWidget(DexterityLabel, 7, 1, 1, 1);

        ForceLabel = new QLabel(MoreCharacteristics);
        ForceLabel->setObjectName("ForceLabel");

        gridLayout->addWidget(ForceLabel, 8, 1, 1, 1);

        IntelligenceLabel = new QLabel(MoreCharacteristics);
        IntelligenceLabel->setObjectName("IntelligenceLabel");

        gridLayout->addWidget(IntelligenceLabel, 9, 1, 1, 1);

        LucklLabel = new QLabel(MoreCharacteristics);
        LucklLabel->setObjectName("LucklLabel");

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
