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
                    login_info LI;
                    message_type recived_message;
                    auto data =s->recieve_data(new_socket);
                    Deserializer dsel;
                    Serializer sel;
                    stringstream st;
                    stringstream st_message;
                    dsel.deserialize(data ,recived_message);
                    if(recived_message.message_name=="create_new_account"){
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
                    else if(recived_message.message_name=="login_message"){
                        st_message<<recived_message.message;
                        dsel.deserialize(st_message ,LI);
                        string check_account_id=LI.account_id;
                        string check_account_password=LI.password;
                        bool check_result;
                        check_result = false;
                        for(auto &x: v1)
                        {
                            if(x.account_id==check_account_id)
                            {
                                if(x.password == check_account_password)
                                {
                                    check_result = true;
                                }
                            }
                        }

                        sel.serialize(st,check_result);
                        s->send_data(st,new_socket);
                    }

                }
            })->start();
        }
    })->start();
}

