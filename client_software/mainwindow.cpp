#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QStyle"
#include<string>
#include <QList>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainmlayout->addWidget(cw);
    mainmlayout->addWidget(t);
    mainmlayout->addWidget(c);
    mainmlayout->addWidget(login2);

    login2->hide();
    c->hide();
    t->hide();
    connect_function();


    widget->setLayout(mainmlayout);
    widget->show();
    socket1->connect_to_socket();
    send();
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connect_function()
{
    connect(cw->Transactions_button,SIGNAL(clicked()),this,SLOT(on_transaction_button_clicked()));
    connect(cw->Create_New_Account_button,SIGNAL(clicked()),this,SLOT(on_create_new_account_window_clicked()));
    connect(c->return_to_main_window,SIGNAL(clicked()),this,SLOT(on_return_to_main_window_button_create_clicked()));
    connect(t->logout,SIGNAL(clicked()),this,SLOT(on_return_to_main_window_button_transaction_clicked()));
    connect(login2->sign_in_button,SIGNAL(clicked()),this,SLOT(on_login_button_clicked()));
    connect(c->submit_button,SIGNAL(clicked()),this,SLOT(on_submit_button_clicked()));
    connect(t->deposit_button,SIGNAL(clicked()),this,SLOT(on_deposit_button_clicked()));
    connect(t->withdraw_button,SIGNAL(clicked()),this,SLOT(on_withdraw_button_clicked()));
    connect(t->show_button,SIGNAL(clicked()),this,SLOT(on_show_button_clicked()));
    connect(login2->return_back,SIGNAL(clicked()),this,SLOT(on_return_back_button_clicked()));



}

void MainWindow::on_transaction_button_clicked()
{
    cw->hide();
    login2->show();
    login2->t_account_id->clear();
    login2->t_password->clear();
}
void MainWindow::on_create_new_account_window_clicked()
{
    cw->hide();
    c->show();
}
void MainWindow::on_return_to_main_window_button_create_clicked()
{
    c->hide();
    c->t_address->clear();
    c->t_age->clear();
    c->t_confirm_password->clear();
    c->t_id->clear();
    c->t_name->clear();
    c->t_password->clear();
    cw->show();

}
void MainWindow::on_return_to_main_window_button_transaction_clicked()
{
    t->hide();
    cw->show();
    t->t_deposit->clear();
    t->t_withdraw->clear();
    t->l_total_amount_of_money->setText("----------");
    Serializer sel;
    stringstream st_message;
    string x=" ";
    message_type message(logout_message,x);
    sel.serialize(st_message,message);
    socket1->send_data(st_message);

}
void MainWindow::on_login_button_clicked()
{
    int account_id=login2->t_account_id->toPlainText().toInt();
    login2->t_password->setEchoMode(QLineEdit::Normal);
    string account_password_string=login2->t_password->displayText().toStdString();
    login2->t_password->setEchoMode(QLineEdit::Password);
    login_info LI(account_id,account_password_string);
    Serializer sel;
    Deserializer dsel;
    stringstream st_login_info;
    stringstream st_message;
    sel.serialize(st_login_info,LI);
    string x=st_login_info.str();
    message_type message(login_message,x);
    sel.serialize(st_message,message);
    socket1->send_data(st_message);
    auto data =socket1->recieve_data();
    bool response;
    dsel.deserialize(data ,response);
    std::cout<<"response : "<<response;
    std::cout.flush();
    if(response)
    {
        MainWindow::go_to_transaction_page(account_id);
    }
    else
    {
        login2->t_account_id->setText("error account not found");
    }

}
void MainWindow::go_to_transaction_page(int account_id)
{
    login2->hide();
    t->show();
    t->l_account_id->setText(QString::number(account_id));
}
void MainWindow::on_submit_button_clicked()
{

    bool check=true;
    QString user_age=c->t_age->toPlainText();
    string user_name =c->t_name->toPlainText().toStdString();
    int age = user_age.toInt();
    string user_id=c->t_id->toPlainText().toStdString();
    string user_address=c->t_address->toPlainText().toStdString();
    string account_password=c->t_password->toPlainText().toStdString();
    string account_confirm_password=c->t_confirm_password->toPlainText().toStdString();

    for(auto &x:user_id )
    {
        if((x<'0')||(x>'9'))
        {
            check=false;

        }
    }

    if(user_address==""||user_name==""||user_age==""||user_id==""||account_password==""||account_confirm_password==""){check=false;}
    if((age<0) || (age>150))
    {
        check=false;
    }
    if(account_password !=account_confirm_password)
    {
        check=false;
    }

    if(!check)
    {
        c->t_name->setText("error");
        c->t_id->setText("error");
        c->t_age->setText("error");
        c->t_address->setText("error");
        c->t_password->setText("error");
        c->t_confirm_password->setText("error");
        c->tb_account_id->hide();
        c->l_account_id->hide();

    }
    else
    {
     AccountData AD(user_name,age,user_id,user_address,account_password);
     Serializer sel;
     Deserializer dsel;
     stringstream st_message;
     stringstream st_account_data;
     sel.serialize(st_account_data,AD);
     string x=st_account_data.str();
     message_type message(create_account_message,x);
     sel.serialize(st_message,message);
     socket1->send_data(st_message);
     auto data =socket1->recieve_data();
     int id;
     dsel.deserialize(data ,id);
     c->tb_account_id->setText(QString::number(id));
     c->tb_account_id->show();
     c->l_account_id->show();

    }


}



void MainWindow::send()
{
//    TransferDataInput t1(5,"karim","loay");
//    stringstream sss;
//    Serializer sel;
//    sel.serialize(sss,t1);
//    s->send_data(sss);
}

void MainWindow::on_deposit_button_clicked()
{
    bool flag=true;
    QString amount_check=t->t_deposit->toPlainText();
    for(auto &x:amount_check)
    {
        if((x<"0")||(x>"9"))
        {flag=false;}
    }
        if(flag)
        {
            float input_amount=t->t_deposit->toPlainText().toFloat();
            int accessed_account_id=t->l_account_id->text().toInt();
            s_transaction trans(accessed_account_id,input_amount);
            Serializer sel;
            Deserializer dsel;
            stringstream st_stransaction;
            stringstream st_message;
            sel.serialize(st_stransaction,trans);
            string x=st_stransaction.str();
            message_type message(deposit_message,x);
            sel.serialize(st_message,message);
            socket1->send_data(st_message);
        }
        else
            t->t_deposit->setText("error");




}
void MainWindow::on_withdraw_button_clicked()
{
    bool flag=true;
    QString amount_check=t->t_withdraw->toPlainText();
    for(auto &x:amount_check)
    {
        if((x<"0")||(x>"9"))
        {flag=false;}
    }
        if(flag)
        {
            float input_amount=t->t_withdraw->toPlainText().toFloat();
            int accessed_account_id=t->l_account_id->text().toInt();
            s_transaction trans(accessed_account_id,input_amount);
            Serializer sel;
            Deserializer dsel;
            stringstream st_stransaction;
            stringstream st_message;
            sel.serialize(st_stransaction,trans);
            string x=st_stransaction.str();
            message_type message(withdraw_message,x);
            sel.serialize(st_message,message);
            socket1->send_data(st_message);
        }
        else
            t->t_withdraw->setText("error");



}
void MainWindow::on_show_button_clicked()
{
    int accessed_account_id=t->l_account_id->text().toInt();
    s_transaction trans(accessed_account_id,0);
    Serializer sel;
    Deserializer dsel;
    stringstream st_stransaction;
    stringstream st_message;
    sel.serialize(st_stransaction,trans);
    string x=st_stransaction.str();
    message_type message(show_account_balance,x);
    sel.serialize(st_message,message);
    socket1->send_data(st_message);
    auto data =socket1->recieve_data();
    string account_balance;
    dsel.deserialize(data ,account_balance);
    t->l_total_amount_of_money->setText(QString::fromStdString(account_balance));

}


void MainWindow::on_return_back_button_clicked()
{
    login2->hide();
    login2->t_account_id->clear();
    login2->t_password->clear();
    cw->show();
}
void MainWindow::on_undo_transaction_button_clicked()
{
    Serializer sel;
    stringstream st_message;
    string x="u";
    message_type message(undo_transaction,x);
    sel.serialize(st_message,message);
    socket1->send_data(st_message);
}
