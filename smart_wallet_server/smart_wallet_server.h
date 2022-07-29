#ifndef SMART_WALLET_SERVER_H
#define SMART_WALLET_SERVER_H

#include <QWidget>
#include "common_includes.h"
class smart_wallet_server : public QWidget
{
    Q_OBJECT
public:
    explicit smart_wallet_server(QWidget *parent = nullptr);
    QGridLayout *main_layout = new QGridLayout;
    QGroupBox *transactions = new QGroupBox("Transactions");
    QGroupBox *account_info = new QGroupBox("account info");

    QVBoxLayout * vbox_account_info=new QVBoxLayout;
    QVBoxLayout * vbox_tracsaction=new QVBoxLayout;

    QHBoxLayout * hbox1=new QHBoxLayout;
    QHBoxLayout * hbox2=new QHBoxLayout;
    QHBoxLayout * hbox3=new QHBoxLayout;
    QHBoxLayout * hbox4=new QHBoxLayout;
    QHBoxLayout * hbox5=new QHBoxLayout;
    QHBoxLayout * hbox6=new QHBoxLayout;

    QLabel * l_account_no = new QLabel("Account Number");
    QLabel * l_name=new QLabel("Name");
    QLabel * l_age=new QLabel("Age");
    QLabel * l_national_id=new QLabel("National ID");
    QLabel * l_address=new QLabel("Address");
    QLabel * l_total_amount_of_money=new QLabel("Total Amount Of Money");

    QLabel * l_account_no_value = new QLabel("---------");
    QLabel * l_name_value=new QLabel("---------");
    QLabel * l_age_value=new QLabel("---------");
    QLabel * l_national_id_value=new QLabel("---------");
    QLabel * l_address_value=new QLabel("---------");
    QLabel * l_total_amount_of_money_value=new QLabel("---------");

    QTextBrowser * Transactions_log=new QTextBrowser();



signals:


};

#endif // SMART_WALLET_SERVER_H
