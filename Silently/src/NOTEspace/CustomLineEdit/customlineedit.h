// customlineedit.h
#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMenu>

#include <iostream>
#include <QFocusEvent>
class CustomLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit CustomLineEdit(QWidget *parent = nullptr);
    QString text()const;
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
};

class CustomLineEditFactory
{
public:
    // Фабричный метод для создания экземпляра CustomLineEdit
    static CustomLineEdit *createCustomLineEdit(QWidget *parent = nullptr);
};

#endif // CUSTOMLINEEDIT_H

