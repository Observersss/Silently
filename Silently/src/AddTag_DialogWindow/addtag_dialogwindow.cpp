#include "addtag_dialogwindow.h"
#include "ui_addtag_dialogwindow.h"
#include <QMessageBox>
AddTag_DialogWindow::AddTag_DialogWindow(QWidget *parent, const QVector<Tag>* tags)
    : QDialog(parent)
    , ui(new Ui::AddTag_DialogWindow)
    , _tags(tags)
{
    ui->setupUi(this);

    if(_tags->empty()){
        select_tag_frame_hide = true;
        ui->select_tag_frame->hide();

        int height = this->height()-100;
        int width = this->width()-40;
        resize(width,height);
        ui->button_option->hide();
        ui->button_option->setText("Select exists tags");
    }else{
        for (size_t i = 0; i < tags->size(); ++i) {
            ui->comboBox->addItem((*tags)[i].getNameTag());
        }

        create_tag_frame_hide = true;
        ui->create_tag_frame->hide();

        int height = this->height()-100;
        int width = this->width()-40;
        resize(width,height);
        ui->button_option->setText("Create new tag");
    }
}

AddTag_DialogWindow::~AddTag_DialogWindow()
{
    delete ui;
}

void AddTag_DialogWindow::on_pushButton_clicked()
{
    QString name;
    bool needAddToAllTag = true;

    if(select_tag_frame_hide){
        name = ui->tagName->text();
    }else{
        name = ui->comboBox->currentText();
        needAddToAllTag = false;
    }

    // Создаем MainWindow
    MainWindow* w = dynamic_cast<MainWindow*>(parent());

    if (w) {

        w->addTag(name,needAddToAllTag);//Додоємо до вектора квестів персонажа
        w->updateInfoTag();
        close();
    } else {
        //Вивід повідомлення що не вдалося передати квест
        QMessageBox::warning(this, "Предупреждение", "Невдалося передати квест");
    }
}


void AddTag_DialogWindow::on_button_option_clicked()
{
    if(select_tag_frame_hide){
        ui->select_tag_frame->show();
        ui->create_tag_frame->hide();
        ui->button_option->setText("Create new tag");
        select_tag_frame_hide = false;
    }else{
        ui->create_tag_frame->show();
        ui->select_tag_frame->hide();
        ui->button_option->setText("Select exists tags");
        select_tag_frame_hide = true;
    }
}

