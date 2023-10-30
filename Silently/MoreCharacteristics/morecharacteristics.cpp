#include "morecharacteristics.h"
#include "ui_morecharacteristics.h"

MoreCharacteristics::MoreCharacteristics(QWidget *parent,Character maincharacter) :
    QDialog(parent),
    ui(new Ui::MoreCharacteristics),
    character(maincharacter)
{
    ui->setupUi(this);

    int health = character.getHealth();
    QString healthText = QString("%1").arg(health);
    ui->HealthLabel->setText(healthText);

    int mana = character.getMana();
    QString manatext = QString("%1").arg(mana);
    ui->ManaLabel->setText(manatext);

    int level = character.getLevel();
    QString levelText =QString("%1").arg(level);
    ui->LevelLabel->setText(levelText);

    int experience = character.getExperience();
    QString experinceText =QString("%1").arg(experience);
    ui->ExperienceLabel->setText(experinceText);

    int damage = character.getDamage();
    QString damageText = QString("%1").arg(damage);
    ui->DamgeLabel->setText(damageText);

    int chanceOfCriticalDamade = character.getChanceOfCriticalDamade();
    QString chanceOfCriticalDamadeText = QString("%1").arg(chanceOfCriticalDamade);
    ui->ChanceLabel->setText(chanceOfCriticalDamadeText);

    int criticalDamage = character.getCriticalDamage();
    QString criticalDamageText = QString("%1").arg(criticalDamage);
    ui->CriticalLabel->setText(criticalDamageText);

    int dexterity = character.getDexterity();
    QString dexterityText = QString("%1").arg(dexterity);
    ui->DexterityLabel->setText(dexterityText);

    int force = character.getForce();
    QString forceText = QString("%1").arg(force);
    ui->ForceLabel->setText(forceText);

    int intelligence = character.getIntelligence();
    QString intelligenceText = QString("%1").arg(intelligence);
    ui->IntelligenceLabel->setText(intelligenceText);

    int luck = character.getLuck();
    QString luckText = QString("%1").arg(luck);
    ui->LucklLabel->setText(luckText);

}

MoreCharacteristics::~MoreCharacteristics()
{
    delete ui;
}
