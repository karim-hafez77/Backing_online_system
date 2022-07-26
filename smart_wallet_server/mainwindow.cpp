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
                    TransferDataInput t1;
                    auto data =s->recieve_data(new_socket);
                    Deserializer dsel;
                    dsel.deserialize(data ,t1);
                    std::cout<<t1.id<<endl;
                    std::cout.flush();
                    std::cout<<t1.data<<endl;
                    std::cout.flush();
                    std::cout<<t1.blockCounter<<endl;
                    std::cout.flush();




                }
            })->start();
        }
    })->start();
}

