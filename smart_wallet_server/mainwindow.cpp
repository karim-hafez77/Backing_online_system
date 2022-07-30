#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "common_includes.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainlayout->addWidget(sws);
    widget->setLayout(mainlayout);
    widget->show();
    setCentralWidget(widget);
    create_server();
    connect(this,SIGNAL(signal_logout()),this,SLOT(logout_handler()));
    connect(this,SIGNAL(signal_login()),this,SLOT(login_handler()));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::logout_handler()
{

    sws->Transactions_log->clear();
    sws->l_account_no_value->clear();
    sws->l_address_value->clear();
    sws->l_national_id_value->clear();
    sws->l_total_amount_of_money_value->clear();
    sws->l_name_value->clear();
    sws->l_age_value->clear();
}

void MainWindow::login_handler()
{
    auto account_transactions=accessed_account.get_transaction_list();
    for(auto &x : account_transactions)
        {
        usleep(1000);
        string op="operation : "+x.get_operation();
        string money_value = "money value : " + std::to_string(x.get_amount_of_money());
        sws->Transactions_log->append(QString::fromStdString(op));
        sws->Transactions_log->append(QString::fromStdString(money_value));
        sws->Transactions_log->append("-----------------------------------");

        }
}

void MainWindow::create_server()
{
    QThread::create([this]{
        while(1)
        {
            cout<<"thread created"<<endl;
            auto new_socket = s->listen_l();
            QThread::create([this,new_socket]()
            {
                while(1)
                {
                    AccountData AD;
                    login_info LI;
                    s_transaction trans;
                    message_type recived_message;
                    float amount_of_money;
                    auto data =s->recieve_data(new_socket);
                    Deserializer dsel;
                    Serializer sel;
                    stringstream st;
                    stringstream st_message;
                    dsel.deserialize(data ,recived_message);


                    if(recived_message.message_name=="create_new_account")
                    {
                        st_message<<recived_message.message;
                        dsel.deserialize(st_message ,AD);
                        person p(AD.name,AD.national_id,AD.address,AD.age);
                        account a(p,AD.password);
                        v1.push_back(a);
                        sel.serialize(st,a.get_account_id());
                        s->send_data(st,new_socket);
                    }


                    else if(recived_message.message_name=="login_message")
                    {
                        st_message<<recived_message.message;
                        dsel.deserialize(st_message ,LI);
                        int check_account_id=LI.account_id;
                        string check_account_password=LI.password;
                        bool check_result;
                        check_result = false;
                        account result_account;
                        for(auto &x: v1)
                        {
                            if(x.get_account_id()==check_account_id)
                            {
                                if(x.get_password() == check_account_password)
                                {
                                    check_result = true;
                                    result_account=x;
                                }
                            }
                        }
                        sel.serialize(st,check_result);
                        s->send_data(st,new_socket);
                        if(check_result)
                        {
                            access_account(result_account);

                        }
                    }

                    else if(recived_message.message_name=="deposit_message")
                    {
                        st_message<<recived_message.message;
                        dsel.deserialize(st_message ,trans);
                        int account_id=trans.account_id;
                        amount_of_money=trans.amount_of_money;
                        for (auto &x:v1)
                        {
                            if(x.get_account_id()==account_id)
                            {
                                x.deposit(amount_of_money);
                                sws->l_total_amount_of_money_value->setText(QString::number(x.get_balance()));
                                string op="operation : "+x.get_transaction_list().front().get_operation();
                                string money_value = "money value : " + std::to_string(x.get_transaction_list().back().get_amount_of_money());
                                sws->Transactions_log->append(QString::fromStdString(op));
                                sws->Transactions_log->append(QString::fromStdString(money_value));
                                sws->Transactions_log->append("-----------------------------------");
                            }
                        }

                     }

                    else if(recived_message.message_name=="withdraw_message")
                    {
                        st_message<<recived_message.message;
                        dsel.deserialize(st_message ,trans);
                        int account_id=trans.account_id;
                        amount_of_money=trans.amount_of_money;
                        for (auto &x:v1)
                        {
                            if(x.get_account_id()==account_id)
                            {
                                x.withdraw(amount_of_money);
                                sws->l_total_amount_of_money_value->setText(QString::number(x.get_balance()));
                                string op="operation : "+x.get_transaction_list().back().get_operation();
                                string money_value = "money value : " + std::to_string(x.get_transaction_list().back().get_amount_of_money());
                                if(x.get_transaction_list().back().get_operation()!="unavailable transaction")
                                {
                                    sws->Transactions_log->append(QString::fromStdString(op));
                                    sws->Transactions_log->append(QString::fromStdString(money_value));
                                    sws->Transactions_log->append("-----------------------------------");
                                }
                                else
                                {
                                    sws->Transactions_log->append(QString::fromStdString(op));
                                    sws->Transactions_log->append("-----------------------------------");

                                }

                            }
                        }

                     }

                    else if(recived_message.message_name=="show_account_balance")
                    {
                        st_message<<recived_message.message;
                        dsel.deserialize(st_message ,trans);
                        int account_id=trans.account_id;
                        for (auto &x:v1)
                        {
                            if(x.get_account_id()==account_id)
                            {
                                string account_balance=std::to_string(x.show_account_balance());
//                                s_transaction transaction1(x.account_id,x.balance);
                                Serializer sel2;
                                sel2.serialize(st,account_balance);
                                s->send_data(st,new_socket);
//                                sws->l_total_amount_of_money_value->setText(QString::number());
                            }
                        }

                     }

                    else if(recived_message.message_name=="logout_message")
                    {
                        emit signal_logout();
                    }


                }
            })->start();
        }
    })->start();
}

void MainWindow::access_account(account a)
{    
    emit signal_logout();
    usleep(1000);
    emit signal_login();
    accessed_account=a;
    sws->l_account_no_value->setText(QString::number(a.get_account_id()));
    sws->l_age_value->setText(QString::number(a.get_account_owner().get_age()));
    sws->l_name_value->setText( QString::fromStdString(a.get_account_owner().get_name()));
    sws->l_national_id_value->setText( QString::fromStdString(a.get_account_owner().get_id()));
    sws->l_total_amount_of_money_value->setText(QString::number(a.get_balance()));
    sws->l_address_value->setText(QString::fromStdString(a.get_account_owner().get_address()));




}

