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
MainWindow::go_to_transaction_page();
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

    for(auto &x:user_id )
    {
        if((x<'0')||(x>'9'))
        {
            check=false;

        }
    }

    if((age<0) || (age>150))
    {
        check=false;
    }

    if(!check)
    {
        c->t_name->setText("error");
        c->t_id->setText("error");
        c->t_age->setText("error");
        c->t_address->setText("error");
    }
    else
    {
     AccountData AD(user_name,age,user_id,user_address);
     Serializer sel;
     Deserializer dsel;
     stringstream st;
     sel.serialize(st,AD);
     socket1->send_data(st);


     auto data =socket1->recieve_data();
     long long id;
     dsel.deserialize(data ,id);
     std::cout<<"acoount id : "<<id;
     std::cout.flush();
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

