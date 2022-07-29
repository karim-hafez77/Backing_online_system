#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QWidget>

#include "widget_size.h"

class transaction : public QWidget
{
    Q_OBJECT
public:
    explicit transaction(QWidget *parent = nullptr);
    QGridLayout *main_layout = new QGridLayout;
    QGroupBox *transactions = new QGroupBox("Transactions");

    QVBoxLayout * vbox=new QVBoxLayout;

    QHBoxLayout * hbox1=new QHBoxLayout;
    QHBoxLayout * hbox2=new QHBoxLayout;
    QHBoxLayout * hbox3=new QHBoxLayout;
    QHBoxLayout * hbox4=new QHBoxLayout;
    QHBoxLayout * hbox5=new QHBoxLayout;

    QPushButton * deposit_button =new QPushButton("Deposit");
    QPushButton * withdraw_button =new QPushButton("Withdraw");
    QPushButton * show_button =new QPushButton("Show");
    QPushButton * redo_button =new QPushButton("Redo Transaction");
    QPushButton * undo_button =new QPushButton("Undo Transaction");
    QPushButton * logout =new QPushButton("logout");

    QTextEdit * t_deposit = new QTextEdit();
    QTextEdit * t_withdraw = new QTextEdit();

    QLabel * l_account_id = new QLabel("---------");
    QLabel *l_account_number=new QLabel("Account Number");
    QLabel *l_deposit_amount=new QLabel("Deposit Amount");
    QLabel *l_withdraw_amount=new QLabel("Withdraw Amount");
    QLabel *l_total=new QLabel("Toatal Amount");
    QLabel *l_total_amount_of_money=new QLabel("-------------");


private slots:
    void on_deposit_button_clicked();
    void on_withdraw_button_clicked();
    void on_show_button_clicked();
    void on_redo_button_clicked();
    void on_undo_button_clicked();


};

#endif // TRANSACTION_H
