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
    person p("karim","123","address",23);
    account a(p,"a");
    a.account_id=123;
    v1.push_back(a);
    create_server();


}

MainWindow::~MainWindow()
{
    delete ui;
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
                        std::cout<<a.password;
                        std::cout.flush();
                        v1.push_back(a);
                        sel.serialize(st,a.account_id);
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
                            if(x.account_id==check_account_id)
                            {
                                if(x.password == check_account_password)
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
                        std::cout<<"account id : "<<account_id<<endl;
                        std::cout.flush();
                        std::cout<<"amount : "<<amount_of_money<<endl;
                        std::cout.flush();

                        for (auto &x:v1)
                        {
                            if(x.account_id==account_id)
                            {
                                x.balance+=amount_of_money;
//                                x.deposit(amount_of_money);
                                std::cout<<"x balance : "<<x.balance<<endl;
                                std::cout.flush();
                                sws->l_total_amount_of_money_value->setText(QString::number(x.balance));
                            }
                        }

                     }


                }
            })->start();
        }
    })->start();
}

void MainWindow::access_account(account a)
{
    std::cout<<"account id: "<<a.account_id<<endl;
    std::cout.flush();
    sws->l_account_no_value->setText(QString::number(a.account_id));
    sws->l_age_value->setText(QString::number(a.p.age));
    sws->l_name_value->setText( QString::fromStdString(a.p.name));
    sws->l_national_id_value->setText( QString::fromStdString(a.p.national_id));
    sws->l_total_amount_of_money_value->setText(QString::number(a.balance));
    sws->l_address_value->setText(QString::fromStdString(a.p.address));

}

