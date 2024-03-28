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
        //встановлюємо базові і мінімальні значення
        //за принципом -> spinBox_(Необхідна характеристика) setMinimum і setValue character.get(Необхідна характеристика)
        ui->spinBox_health->setMinimum(character->getHealth());
        ui->spinBox_health->setValue(character->getHealth());

        ui->spinBox_mana->setValue(character->getMana());
        ui->spinBox_mana->setMinimum(character->getMana());

        ui->spinBox_damage->setValue(character->getDamage());
        ui->spinBox_damage->setMinimum(character->getDamage());

        ui->spinBox_chanceOfCriticalDamage->setValue(character->getChanceOfCriticalDamade());
        ui->spinBox_chanceOfCriticalDamage->setMinimum(character->getChanceOfCriticalDamade());

        ui->spinBox_criticalDamage->setValue(character->getCriticalDamage());
        ui->spinBox_criticalDamage->setMinimum(character->getCriticalDamage());

        ui->spinBox_dexterity->setValue(character->getDexterity());
        ui->spinBox_dexterity->setMinimum(character->getDexterity());

        ui->spinBox_force->setValue(character->getForce());
        ui->spinBox_force->setMinimum(character->getForce());

        ui->spinBox_intelligence->setValue(character->getIntelligence());
        ui->spinBox_intelligence->setMinimum(character->getIntelligence());

        ui->spinBox_luck->setValue(character->getLuck());
        ui->spinBox_luck->setMinimum(character->getLuck());

        changeValueEvent();

        boxes[ui->spinBox_health] = character->getHealth();
        boxes[ui->spinBox_mana] = character->getMana();
        boxes[ui->spinBox_damage] = character->getDamage();
        boxes[ui->spinBox_chanceOfCriticalDamage]  = character->getChanceOfCriticalDamade();
        boxes[ui->spinBox_criticalDamage]  = character->getCriticalDamage();
        boxes[ui->spinBox_dexterity] = character->getDexterity();
        boxes[ui->spinBox_force] = character->getForce();
        boxes[ui->spinBox_intelligence] = character->getIntelligence();
        boxes[ui->spinBox_luck] = character->getLuck();


        //connect всіх spinBox_() при події valueChanged для виклику on_spinBox_valueChanged
        connect(ui->spinBox_health, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_mana, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_damage, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_chanceOfCriticalDamage, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_criticalDamage, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_dexterity, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_force, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_intelligence, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));
        connect(ui->spinBox_luck, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox_valueChanged(int)));

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
void MoreCharacteristics_DialogWindow::updateInfo(){
    //Виивід характеристик персонажа у необхідні поля
    QString healthText = QString("%1").arg(character->getHealth());
    ui->HealthLabel->setText(healthText);

    QString manatext = QString("%1").arg(character->getMana());
    ui->ManaLabel->setText(manatext);

    QString levelText =QString("%1").arg(character->getLevel());
    ui->LevelLabel->setText(levelText);

    QString experinceText =QString("%1").arg(character->getExperience());
    ui->ExperienceLabel->setText(experinceText);

    QString damageText = QString("%1").arg(character->getDamage());
    ui->DamageLabel->setText(damageText);

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
void MoreCharacteristics_DialogWindow::changeValueEvent(){
    //Встановлюємо доступну кількість вільних очок і оновлюємо максимальні значення на основі теперешнього+кількість вільних очок
    ui->label_pointCount->setText(QString::number(countPoint));

    ui->spinBox_health->setMaximum(ui->spinBox_health->value()+countPoint);
    ui->spinBox_mana->setMaximum(ui->spinBox_mana->value()+countPoint);
    ui->spinBox_damage->setMaximum(ui->spinBox_damage->value()+countPoint);
    ui->spinBox_chanceOfCriticalDamage->setMaximum(ui->spinBox_chanceOfCriticalDamage->value()+countPoint);
    ui->spinBox_criticalDamage->setMaximum(ui->spinBox_criticalDamage->value()+countPoint);
    ui->spinBox_dexterity->setMaximum(ui->spinBox_dexterity->value()+countPoint);
    ui->spinBox_force->setMaximum(ui->spinBox_force->value()+countPoint);
    ui->spinBox_intelligence->setMaximum(ui->spinBox_intelligence->value()+countPoint);
    ui->spinBox_luck->setMaximum(ui->spinBox_luck->value()+countPoint);
}

void MoreCharacteristics_DialogWindow::on_spinBox_valueChanged(int arg1)
{
    QSpinBox *senderSpinBox = qobject_cast<QSpinBox*>(sender());
    if (!senderSpinBox)
        return;

    int value = boxes[senderSpinBox] - arg1;
    value > 0 ? countPoint++ : countPoint--;
    boxes[senderSpinBox] = arg1;
    changeValueEvent();
}

