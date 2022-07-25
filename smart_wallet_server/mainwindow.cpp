#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smart_wallet_server.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_server()
{
    s->create_server();
    auto new_socket = this->s->listen_l();
    auto name = this->s->recieve_data();

//    QThread::create([this]{
//        while(1)
//        {
//            cout<<"thread created"<<endl;
//            QThread::create([this,new_socket]()
//            {
//                while(1)
//                {
//                    if(this->s->recive_file(new_socket,name)){
//                        choose_handler(name);
//                        usleep(100);
//                    }
//                    else
//                    {
//                        cout<<"socket closed"<<endl;
//                        cout<<name<<endl;
//                        new_socket->close();
//                        delete new_socket;
//                        break;
//                    }
//                }
//            })->start();
//        }
//    })->start();
}
