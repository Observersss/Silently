#include "morecharacteristics_dialogwindow.h"
#include "ui_morecharacteristics_dialogwindow.h"

MoreCharacteristics_DialogWindow::MoreCharacteristics_DialogWindow(QWidget *parent,Character* maincharacter,bool show) :
    QDialog(parent),
    ui(new Ui::MoreCharacteristics_DialogWindow),
    character(maincharacter)
{
    ui->setupUi(this);

    updateInfo();

    if(show){
        ui->label_pointCount->setText("12");
        ui->spinBox_health->setMinimum(character->getHealth());
        ui->spinBox_health->setValue(character->getHealth());
        ui->spinBox_health->setMaximum(character->getHealth()+countPoint);

        ui->spinBox_mana->setValue(character->getMana());
        ui->spinBox_mana->setMaximum(character->getMana());
        ui->spinBox_mana->setMaximum(character->getMana()+countPoint);

        ui->spinBox_damage->setValue(character->getDamage());
        ui->spinBox_damage->setMinimum(character->getDamage());
        ui->spinBox_damage->setMaximum(character->getDamage()+countPoint);

        ui->spinBox_chanceOfCriticalDamage->setValue(character->getChanceOfCriticalDamade());
        ui->spinBox_chanceOfCriticalDamage->setMinimum(character->getChanceOfCriticalDamade());
        ui->spinBox_chanceOfCriticalDamage->setMaximum(character->getChanceOfCriticalDamade()+countPoint);

        ui->spinBox_criticalDamage->setValue(character->getCriticalDamage());
        ui->spinBox_criticalDamage->setMinimum(character->getCriticalDamage());
        ui->spinBox_criticalDamage->setMaximum(character->getCriticalDamage());

        ui->spinBox_dexterity->setValue(character->getDexterity());
        ui->spinBox_dexterity->setMinimum(character->getDexterity());
        ui->spinBox_dexterity->setMaximum(character->getDexterity()+countPoint);

        ui->spinBox_force->setValue(character->getForce());
        ui->spinBox_force->setMinimum(character->getForce());
        ui->spinBox_force->setMaximum(character->getForce()+countPoint);

        ui->spinBox_intelligence->setValue(character->getIntelligence());
        ui->spinBox_intelligence->setMinimum(character->getIntelligence());
        ui->spinBox_intelligence->setMaximum(character->getIntelligence()+countPoint);

        ui->spinBox_luck->setValue(character->getLuck());
        ui->spinBox_luck->setMinimum(character->getLuck());
        ui->spinBox_luck->setMaximum(character->getLuck()+countPoint);
    }else{
        int newWidth = width() / 2;
        resize(newWidth, height());
        ui->frame_2->hide();
        ui->label_info->hide();
    }
}

MoreCharacteristics_DialogWindow::~MoreCharacteristics_DialogWindow()
{
    delete ui;
}

void MoreCharacteristics_DialogWindow::on_pushButton_clicked()
{
    character->setHealth(ui->spinBox_health->value());
    character->setMana(ui->spinBox_mana->value());
    character->setChanceOfCriticalDamade(ui->spinBox_chanceOfCriticalDamage->value());
    character->setCriticalDamage(ui->spinBox_criticalDamage->value());
    character->setDexterity(ui->spinBox_dexterity->value());
    character->setForce(ui->spinBox_force->value());
    character->setIntelligence(ui->spinBox_intelligence->value());
    character->setLuck(ui->spinBox_luck->value());
}
void  MoreCharacteristics_DialogWindow::updateInfo(){
    QString healthText = QString("%1").arg(character->getHealth());
    ui->HealthLabel->setText(healthText);

    QString manatext = QString("%1").arg(character->getMana());
    ui->ManaLabel->setText(manatext);

    QString levelText =QString("%1").arg(character->getLevel());
    ui->LevelLabel->setText(levelText);

    QString experinceText =QString("%1").arg(character->getExperience());
    ui->ExperienceLabel->setText(experinceText);

    QString damageText = QString("%1").arg(character->getDamage());
    ui->DamgeLabel->setText(damageText);

    QString chanceOfCriticalDamadeText = QString("%1").arg(character->getChanceOfCriticalDamade());
    ui->ChanceLabel->setText(chanceOfCriticalDamadeText);

    QString criticalDamageText = QString("%1").arg(character->getCriticalDamage());
    ui->CriticalLabel->setText(criticalDamageText);

    QString dexterityText = QString("%1").arg(character->getDexterity());
    ui->DexterityLabel->setText(dexterityText);

    QString forceText = QString("%1").arg(character->getForce());
    ui->ForceLabel->setText(forceText);

    QString intelligenceText = QString("%1").arg(character->getIntelligence());
    ui->IntelligenceLabel->setText(intelligenceText);

    QString luckText = QString("%1").arg(character->getLuck());
    ui->LucklLabel->setText(luckText);
}

