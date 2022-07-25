#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "QLabel"
#include "QVBoxLayout"
#include <QtWidgets>
#include "widget_size.h"
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

    QPushButton * sign_in_button =new QPushButton("Login");

    QTextEdit * t_account_id = new QTextEdit("enter account id");
    QTextEdit * t_password = new QTextEdit("enter password");

    QLabel * l_account_id = new QLabel("Account ID");
    QLabel * l_password=new QLabel("Password");
    QLabel * l_test = new QLabel("");



private:
static void connectfun();
};

#endif // LOGIN_H
