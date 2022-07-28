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
    connect(t->return_to_main_window,SIGNAL(clicked()),this,SLOT(on_return_to_main_window_button_transaction_clicked()));
    connect(login2->sign_in_button,SIGNAL(clicked()),this,SLOT(on_login_button_clicked()));
//    connect(c->submit_button,SIGNAL(clicked()),c,SLOT(read_data()));
    connect(c->submit_button,SIGNAL(clicked()),this,SLOT(on_submit_button_clicked()));

}

void MainWindow::on_transaction_button_clicked()
{
    cw->hide();
    login2->show();
}
void MainWindow::on_create_new_account_window_clicked()
{
    cw->hide();
    c->show();
}
void MainWindow::on_return_to_main_window_button_create_clicked()
{
    c->hide();
    cw->show();

}
void MainWindow::on_return_to_main_window_button_transaction_clicked()
{
    t->hide();
    cw->show();
}
void MainWindow::on_login_button_clicked()
{
    string account_id=login2->t_account_id->toPlainText().toStdString();
    string account_password=login2->t_password->toPlainText().toStdString();
    login_info LI(account_id,account_password);
    Serializer sel;
    Deserializer dsel;
    stringstream st;
    sel.serialize(st,LI);
    socket1->send_data(st);


    auto data =socket1->recieve_data();
    string response;
    dsel.deserialize(data ,response);
    std::cout<<"acoount id : "<<response;
    std::cout.flush();

//MainWindow::go_to_transaction_page();
}
void MainWindow::go_to_transaction_page()
{
    login2->hide();
    t->show();
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
     std::cout<<st_message.str();
     std::cout.flush();
     socket1->send_data(st_message);
     auto data =socket1->recieve_data();
     long long id;
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

