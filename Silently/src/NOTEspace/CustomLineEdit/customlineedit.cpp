// customlineedit.cpp
#include "customlineedit.h"
#include <QHBoxLayout>
#include <QEvent>

CustomLineEdit::CustomLineEdit(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0); // Установка нулевых отступов для макета

    lineEdit = new QLineEdit(this);
    menuButton = new QPushButton("...", this);
    popupMenu = new QMenu(this);

    lineEdit->setStyleSheet(LINE_EDIT_STYLE);

    popupMenu->setStyleSheet(POPUP_MENU_STYLE);

    QAction *boldAction = popupMenu->addAction("Bold");
    QAction *italicAction = popupMenu->addAction("Italic");
    QAction *uppercaseAction = popupMenu->addAction("Uppercase");
    QAction *deleteAction = popupMenu->addAction("Delete");

    // Создаем подменю для выбора цвета текста и цвета заднего фона
    QMenu *textColorSubMenu = popupMenu->addMenu("Text Color");
    QAction *textDefaultAction = textColorSubMenu->addAction("Default");
    QAction *textGrayAction = textColorSubMenu->addAction("Gray");
    QAction *textBrownAction = textColorSubMenu->addAction("Brown");
    QAction *textOrangeAction = textColorSubMenu->addAction("Orange");
    QAction *textYellowAction = textColorSubMenu->addAction("Yellow");
    QAction *textGreenAction = textColorSubMenu->addAction("Green");
    QAction *textBlueAction = textColorSubMenu->addAction("Blue");
    QAction *textPurpleAction = textColorSubMenu->addAction("Purple");
    QAction *textRedAction = textColorSubMenu->addAction("Red");

    QMenu *backgroundColorSubMenu = popupMenu->addMenu("Background Color");
    QAction *bgDefaultAction = backgroundColorSubMenu->addAction("Default");
    QAction *bgGrayAction = backgroundColorSubMenu->addAction("Gray");
    QAction *bgBrownAction = backgroundColorSubMenu->addAction("Brown");
    QAction *bgOrangeAction = backgroundColorSubMenu->addAction("Orange");
    QAction *bgYellowAction = backgroundColorSubMenu->addAction("Yellow");
    QAction *bgGreenAction = backgroundColorSubMenu->addAction("Green");
    QAction *bgBlueAction = backgroundColorSubMenu->addAction("Blue");
    QAction *bgPurpleAction = backgroundColorSubMenu->addAction("Purple");
    QAction *bgRedAction = backgroundColorSubMenu->addAction("Red");

    layout->addWidget(menuButton);
    layout->addWidget(lineEdit);

    connect(menuButton, &QPushButton::clicked, this, &CustomLineEdit::showMenu);
    connect(deleteAction, &QAction::triggered, this, &CustomLineEdit::deleteRequested);

    connect(boldAction, &QAction::triggered, this, [this]() { handleTextFormattingRequest(QFont::Bold, false, false); });
    connect(italicAction, &QAction::triggered, this, [this]() { handleTextFormattingRequest(QFont::Normal, true, false); });
    connect(uppercaseAction, &QAction::triggered, this, [this]() { handleTextFormattingRequest(QFont::Normal, false, true); });

    // Подключаем действия для выбора цвета текста и цвета заднего фона
    connect(textDefaultAction, &QAction::triggered, this, [this]() { changeTextColor(Qt::black); });
    connect(textGrayAction, &QAction::triggered, this, [this]() { changeTextColor(Qt::gray); });
    connect(textBrownAction, &QAction::triggered, this, [this]() { changeTextColor(QColor("#987654")); }); // Brown
    connect(textOrangeAction, &QAction::triggered, this, [this]() { changeTextColor("#FFE5B4"); });
    connect(textYellowAction, &QAction::triggered, this, [this]() { changeTextColor("#FFFFE0"); });
    connect(textGreenAction, &QAction::triggered, this, [this]() { changeTextColor("#90EE90"); });
    connect(textBlueAction, &QAction::triggered, this, [this]() { changeTextColor("#ADD8E6"); });
    connect(textPurpleAction, &QAction::triggered, this, [this]() { changeTextColor("#E6E6FA"); });
    connect(textRedAction, &QAction::triggered, this, [this]() { changeTextColor("#FFC0CB"); });

    connect(bgDefaultAction, &QAction::triggered, this, [this]() { changeBackgroundColor(Qt::white); });
    connect(bgGrayAction, &QAction::triggered, this, [this]() { changeBackgroundColor(Qt::lightGray); });
    connect(bgBrownAction, &QAction::triggered, this, [this]() { changeBackgroundColor(QColor("#987654")); }); // Brown
    connect(bgOrangeAction, &QAction::triggered, this, [this]() { changeBackgroundColor("#FFE5B4"); });
    connect(bgYellowAction, &QAction::triggered, this, [this]() { changeBackgroundColor("#FFFFE0"); });
    connect(bgGreenAction, &QAction::triggered, this, [this]() { changeBackgroundColor("#90EE90"); });
    connect(bgBlueAction, &QAction::triggered, this, [this]() { changeBackgroundColor("#ADD8E6"); });
    connect(bgPurpleAction, &QAction::triggered, this, [this]() { changeBackgroundColor("#E6E6FA"); });
    connect(bgRedAction, &QAction::triggered, this, [this]() { changeBackgroundColor("#FFC0CB"); });


    lineEdit->installEventFilter(this);
    lineEdit->setText(" ");
}
void CustomLineEdit::setText(const QString& text){
    lineEdit->setText(text);
}
void CustomLineEdit::setStyleSheet(const QString &styleSheet){
    lineEdit->setStyleSheet(styleSheet);
}

QString CustomLineEdit::text()const{
    return lineEdit->text();
}
QString CustomLineEdit::style() const{
    return lineEdit->styleSheet();
}

QLineEdit* CustomLineEdit::getlineEdit()const{
    return lineEdit;
}


void CustomLineEdit::changeTextColor(const QColor &color)
{
    // Создаем таблицу стилей
    QString styleSheet = "QLineEdit {"
                         "color: %1;" // Цвет текста
                         "background-color: %2;" // Фоновый цвет
                         "border: 1px solid silver;" // Остальные стили, если необходимо
                         "border-radius: 8px;" // Остальные стили, если необходимо
                         "}";

    // Применяем таблицу стилей к родительскому элементу
    setStyleSheet(styleSheet.arg(color.name()).arg(lineEdit->palette().color(QPalette::Base).name()));

    // Устанавливаем цвет текста для QLineEdit
    lineEdit->setStyleSheet("color: " + color.name());
}


void CustomLineEdit::changeBackgroundColor(const QColor &color)
{
    QString styleSheet = "QLineEdit {"
                         "background-color: %1;" // Фоновый цвет
                         "border: 1px solid silver;" // Остальные стили, если необходимо
                         "border-radius: 8px;" // Остальные стили, если необходимо
                         "color: black;" // Остальные стили, если необходимо
                         "}";

    // Применяем таблицу стилей к родительскому элементу
    setStyleSheet(styleSheet.arg(color.name()));

    // Устанавливаем цвет фона для QLineEdit
    QPalette palette = lineEdit->palette();
    palette.setColor(QPalette::Base, color);
    lineEdit->setPalette(palette);
}


void CustomLineEdit::handleTextFormattingRequest(QFont::Weight weight, bool italic, bool uppercase)
{
    QFont font = lineEdit->font();
    font.setWeight(weight);
    font.setItalic(italic);
    lineEdit->setFont(font);
    if (uppercase) {
        lineEdit->setText(lineEdit->text().toUpper());
    }
}


void CustomLineEdit::showMenu()
{
    popupMenu->popup(menuButton->mapToGlobal(QPoint(0, menuButton->height())));
}

void CustomLineEdit::handleMenuAction()
{
    QAction *action = qobject_cast<QAction*>(sender());
    if (action) {
        if (action->text() == "Delete") {
            emit deleteRequested();
        }
    }
}

void CustomLineEdit::handleDeleteCustomLineEdit(){
    delete lineEdit;
    delete menuButton;
    delete popupMenu;
}


// В customlineedit.cpp

void CustomLineEdit::focusInEvent(QFocusEvent *event)
{
    QWidget::focusInEvent(event);
    if (menuButton) {
        menuButton->setVisible(true);
    }
}

void CustomLineEdit::focusOutEvent(QFocusEvent *event)
{
    QWidget::focusOutEvent(event);
    if (menuButton) {
        menuButton->setVisible(false);
    }
}

bool CustomLineEdit::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == lineEdit) {
        if (event->type() == QEvent::FocusIn) {
            manageActiveButton(true);
        } else if (event->type() == QEvent::FocusOut) {
            manageActiveButton(false);
        }
    }
    return QWidget::eventFilter(watched, event);
}

void CustomLineEdit::manageActiveButton(bool isActive)
{
    if (isActive) {
        // Кнопка становится серой, круглой и без границы
        menuButton->setStyleSheet("QPushButton { backgro"
                                  "und-color: white; border: 1px solid silver; border-radius: 10px; width:30px; height:20px; color:orange;  font-size: 20px; padding-bottom:8px; }");
        menuButton->setEnabled(true);
    } else {
        // Кнопка становится белой, круглой и без границы
        menuButton->setStyleSheet("QPushButton { background-color: white; border: none; border-radius: 10px; width:20px; height:20px; color:black;  font-size: 14px; }");
        menuButton->setEnabled(true);
    }
}

void CustomLineEdit::connectSignalsAndSlots(){

}
void CustomLineEdit::createPopupMenu(){

}
CustomLineEdit::~CustomLineEdit(){
    lineEdit->deleteLater();
    menuButton->deleteLater();
    popupMenu->deleteLater();
}
