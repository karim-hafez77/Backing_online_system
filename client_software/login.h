#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "QLabel"
#include "QVBoxLayout"
#include <QtWidgets>
#include "widget_size.h"
#include <QLineEdit>
#include <iostream>
#include <QTextEdit>

using namespace std;
class login : public QWidget
{
    Q_OBJECT
public:
    explicit login(QWidget *parent = nullptr);
    QGridLayout *main_layout = new QGridLayout;
    QGroupBox *login_groupbox = new QGroupBox("Login");

    QVBoxLayout * vbox=new QVBoxLayout;
    QHBoxLayout * hbox1=new QHBoxLayout;
    QHBoxLayout * hbox2=new QHBoxLayout;
    QHBoxLayout * hbox3=new QHBoxLayout;
    QHBoxLayout * hbox4=new QHBoxLayout;
    QHBoxLayout * hbox5=new QHBoxLayout;


    QPushButton * sign_in_button =new QPushButton("Login");
    QPushButton * return_back =new QPushButton("return");


    QTextEdit * t_account_id = new QTextEdit();
    QLineEdit * t_password = new QLineEdit();
    bool t=true;

//    t_account_id->setPlaceholderText("awq");

    QLabel * l_account_id = new QLabel("Account ID");
    QLabel * l_password=new QLabel("Password");
    QLabel * l_test = new QLabel("");

    void connect_function(void);


private slots:

    void on_sign_in_button_clicked();
};

#endif // LOGIN_H
