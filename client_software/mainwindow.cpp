#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QStyle"
#include<string>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainmlayout->addWidget(cw);
//    login2->connect_function();
    widget->setLayout(mainmlayout);
    widget->show();
    s->connect_to_socket();
    send();
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connect_function()
{
//    connect(submit_button,SIGNAL(clicked()),this,SLOT(on_submit_button_clicked()));

}

void MainWindow::on_submit_button_clicked()
{
    mainmlayout->addWidget(t);

}

void MainWindow::on_return_to_main_window_clicked()
{

//    mainlayout->addWidget(t);

}


void MainWindow::send()
{
    TransferDataInput t1(5,"karim","loay");
    stringstream sss;
    Serializer sel;
    sel.serialize(sss,t1);
    s->send_data(sss);
}

