#include "control_window.h"

control_window::control_window(QWidget *parent)
    : QWidget{parent}
{
Create_New_Account_button->setFixedSize(button_SIZE);
Transactions_button->setFixedSize(button_SIZE);
hbox1->addWidget(Create_New_Account_button);
hbox1->addWidget(Transactions_button);
vbox->addLayout(hbox1);
vbox->setAlignment(Qt::AlignCenter);
control_window_groupbox->setLayout(vbox);

main_layout->addWidget(control_window_groupbox,0,0,1,1);
setLayout(main_layout);
connect(Create_New_Account_button,SIGNAL(clicked()),this,SLOT(on_Create_New_Account_clicked));
connect(Transactions_button,SIGNAL(clicked()),this,SLOT(MainWindow::on_submit_button_clicked));
}
void control_window::on_Create_New_Account_clicked()
{
//MainWindow::mainmlayout->addWidget(c);
}
void control_window::on_Transactions_clicked(){}
