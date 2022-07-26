#ifndef CONTROL_WINDOW_H
#define CONTROL_WINDOW_H

#include <QWidget>
#include "widget_size.h"
#include "create_new_account.h"


class control_window : public QWidget
{
    Q_OBJECT
public:
    explicit control_window(QWidget *parent = nullptr);
    create_new_account *c =new create_new_account();
    QGridLayout *main_layout = new QGridLayout;
    QGroupBox *control_window_groupbox = new QGroupBox("Control Window");

    QVBoxLayout * vbox=new QVBoxLayout;

    QPushButton * Create_New_Account_button =new QPushButton("Create New Account");
    QPushButton * Transactions_button =new QPushButton("Transactions");

    QHBoxLayout * hbox1=new QHBoxLayout;



private slots:
    void on_Create_New_Account_clicked();
    void on_Transactions_clicked();
};

#endif // CONTROL_WINDOW_H
