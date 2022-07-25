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

