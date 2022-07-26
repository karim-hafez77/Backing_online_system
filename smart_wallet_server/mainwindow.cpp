#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smart_wallet_server.h"
#include "common_includes.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    smart_wallet_server * s=new smart_wallet_server();
    mainlayout->addWidget(s);
    widget->setLayout(mainlayout);
    widget->show();
    setCentralWidget(widget);
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
                    auto data =s->recieve_data(new_socket);
                    Deserializer dsel;
                    Serializer sel;
                    stringstream st;
                    dsel.deserialize(data ,AD);
                    person p(AD.name,AD.national_id,AD.address,AD.age);
                    account a(p,"zzzzzz");
                    v1.push_back(a);
                    sel.serialize(st,a.account_id);
                    s->send_data(st,new_socket);
                }
            })->start();
        }
    })->start();
}

