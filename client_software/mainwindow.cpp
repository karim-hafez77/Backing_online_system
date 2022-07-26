#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QStyle"
#include<string>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    t_name->setFixedSize(text_SIZE);
//    l_name->setFixedSize(label_SIZE);
//    t_age->setFixedSize(text_SIZE);
//    l_age->setFixedSize(label_SIZE);
//    t_address->setFixedSize(text_SIZE);
//    l_address->setFixedSize(label_SIZE);
//    t_id->setFixedSize(text_SIZE);
//    l_id->setFixedSize(label_SIZE);
//    submit_button->setFixedSize(button_SIZE);
//    return_to_main_window->setFixedSize(button_SIZE);

//    vertical_layout_control->addWidget(create_new_account);

//    inner_horizontal_layout_control_name->addWidget(l_name);
//    inner_horizontal_layout_control_name->addWidget(t_name);

//    inner_horizontal_layout_control_age->addWidget(l_age);
//    inner_horizontal_layout_control_age->addWidget(t_age);


//    inner_horizontal_layout_control_address->addWidget(l_address);
//    inner_horizontal_layout_control_address->addWidget(t_address);


//    inner_horizontal_layout_control_id->addWidget(l_id);
//    inner_horizontal_layout_control_id->addWidget(t_id);

//    inner_vertical_layout_control_submit_button->addWidget(submit_button);
//    inner_vertical_layout_control_submit_button->addWidget(return_to_main_window);
//    inner_vertical_layout_control_submit_button->setAlignment(Qt::AlignHCenter);
//    create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_name);
//    create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_age);
//    create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_id);
//    create_account_inner_mainlayout->addLayout(inner_horizontal_layout_control_address);
//    create_account_inner_mainlayout->addLayout(inner_vertical_layout_control_submit_button);


//    //create new account groupbox layout control
//    create_new_account->setLayout(create_account_inner_mainlayout);


    //outer window layout control
//    mainlayout->addLayout(vertical_layout_control);

    mainlayout->addWidget(login2);
    login2->connect_function();
    widget->setLayout(mainlayout);
    widget->show();
    s->connect_to_socket();

    send();
//    s->~client_socket();

    setCentralWidget(widget);
//    connect_function();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connect_function()
{
    connect(submit_button,SIGNAL(clicked()),this,SLOT(on_submit_button_clicked()));

}

void MainWindow::on_submit_button_clicked()
{
    QString name=t_name->toPlainText();
    l_age->setText(name);
    t_name->setText("submitted");
    t_age->setText("submitted");
    t_id->setText("submitted");
    t_address->setText("submitted");
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

