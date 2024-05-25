// customlineedit.h
#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMenu>

#include <QFocusEvent>

static const QString LINE_EDIT_STYLE = "QLineEdit {height:20px; border: 1px solid silver; border-radius: 8px; color: black; }";
static const QString POPUP_MENU_STYLE = "QMenu { border: 2px solid orange; color: black; }";

class CustomLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit CustomLineEdit(QWidget *parent = nullptr);
    void setText(const QString& text);
    void setStyleSheet(const QString &styleSheet);
    QString text()const;
    QString style() const;
    QLineEdit* getlineEdit()const;

    ~CustomLineEdit();

signals:
    void deleteRequested();
    void textFormattingRequested(QFont::Weight weight, bool italic, bool uppercase);
    void editingFinished();

private slots:
    void showMenu();
    void handleMenuAction();
    void handleTextFormattingRequest(QFont::Weight weight, bool italic, bool uppercase);
    void handleDeleteCustomLineEdit();
    void changeTextColor(const QColor &color);
    void changeBackgroundColor(const QColor &color);

    bool eventFilter(QObject *watched, QEvent *event);
    void manageActiveButton(bool isActive);

protected:
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

private:
    QLineEdit *lineEdit;
    QPushButton *menuButton;
    QMenu *popupMenu;

    void connectSignalsAndSlots();
    void createPopupMenu();
};

class CustomLineEditBuilder{
private:
    QWidget *parent_;
    QString text_;
    QString style_;
public:
    CustomLineEditBuilder(QWidget* parent = nullptr):parent_(parent){}

    CustomLineEditBuilder& withText(const QString& text){
        text_ = text;
        return *this;
    }

    CustomLineEditBuilder& withStyles(const QString& style){
        style_ = style;
        return *this;
    }

    CustomLineEdit* build(){
        CustomLineEdit* customLineEdit = new CustomLineEdit(parent_);
        if(!text_.isEmpty())
            customLineEdit->setText(text_);
        if(!style_.isEmpty())
            customLineEdit->setStyleSheet(style_);
        return customLineEdit;
    }
};

class CustomLineEditFactory
{
public:

    static CustomLineEdit* create(QWidget* parent = nullptr){
        return new CustomLineEdit(parent);
    }

    static CustomLineEdit* create_with_text(const QString& text = "",QWidget* parent = nullptr){
        return CustomLineEditBuilder(parent).withText(text).build();
    }

    static CustomLineEdit* create_with_style(const QString& style = "",QWidget* parent = nullptr){
        return CustomLineEditBuilder(parent).withStyles(style).build();
    }

    static CustomLineEdit* create_with_text_and_style(const QString& text = "",const QString& style = "",QWidget* parent = nullptr){
        return CustomLineEditBuilder(parent).withText(text).withStyles(style).build();
    }

};

#endif // CUSTOMLINEEDIT_H
