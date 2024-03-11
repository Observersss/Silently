#include "morecharacteristics_dialogwindow.h"
#include "ui_morecharacteristics_dialogwindow.h"

MoreCharacteristics_DialogWindow::MoreCharacteristics_DialogWindow(QWidget *parent,Character maincharacter) :
    QDialog(parent),
    ui(new Ui::MoreCharacteristics_DialogWindow),
    character(maincharacter)
{
    ui->setupUi(this);

    QString healthText = QString("%1").arg(character.getHealth());
    ui->HealthLabel->setText(healthText);

    QString manatext = QString("%1").arg(character.getMana());
    ui->ManaLabel->setText(manatext);

    QString levelText =QString("%1").arg(character.getLevel());
    ui->LevelLabel->setText(levelText);

    QString experinceText =QString("%1").arg(character.getExperience());
    ui->ExperienceLabel->setText(experinceText);

    QString damageText = QString("%1").arg(character.getDamage());
    ui->DamgeLabel->setText(damageText);

    QString chanceOfCriticalDamadeText = QString("%1").arg(character.getChanceOfCriticalDamade());
    ui->ChanceLabel->setText(chanceOfCriticalDamadeText);

    QString criticalDamageText = QString("%1").arg(character.getCriticalDamage());
    ui->CriticalLabel->setText(criticalDamageText);

    QString dexterityText = QString("%1").arg(character.getDexterity());
    ui->DexterityLabel->setText(dexterityText);

    QString forceText = QString("%1").arg(character.getForce());
    ui->ForceLabel->setText(forceText);

    QString intelligenceText = QString("%1").arg(character.getIntelligence());
    ui->IntelligenceLabel->setText(intelligenceText);

    QString luckText = QString("%1").arg(character.getLuck());
    ui->LucklLabel->setText(luckText);

}

MoreCharacteristics_DialogWindow::~MoreCharacteristics_DialogWindow()
{
    delete ui;
}
