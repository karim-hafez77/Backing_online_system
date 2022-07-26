#ifndef CREATE_NEW_ACCOUNT_H
#define CREATE_NEW_ACCOUNT_H

#include <QWidget>
#include <QMainWindow>
#include "QLabel"
#include "QVBoxLayout"
#include <QtWidgets>

class create_new_account : public QWidget
{
    Q_OBJECT
public:
    explicit create_new_account(QWidget *parent = nullptr);
        QGroupBox *create_new_account_groupbox = new QGroupBox("Create New Account");
    //    QGroupBox *Transactions = new QGroupBox("Transactions", this);
        //create new account boxes
        QHBoxLayout * inner_horizontal_layout_control_buttons=new QHBoxLayout  ;
        QGridLayout *main_layout = new QGridLayout;

        QHBoxLayout * horizontal_layout_control=new QHBoxLayout  ;
        QHBoxLayout * inner_horizontal_layout_control_name=new QHBoxLayout  ;
        QHBoxLayout * inner_horizontal_layout_control_age=new QHBoxLayout  ;
        QHBoxLayout * inner_horizontal_layout_control_id=new QHBoxLayout  ;
        QHBoxLayout * inner_horizontal_layout_control_address=new QHBoxLayout  ;


        //main window vertical layout
        QVBoxLayout * vertical_layout_control=new QVBoxLayout  ;
        //create new account inner mainlayout
        QVBoxLayout *create_account_inner_mainlayout=new QVBoxLayout;

        QPushButton * submit_button =new QPushButton("Submit");
        QPushButton * return_to_main_window =new QPushButton("return main window");

        QTextEdit * t_name = new QTextEdit();
        QTextEdit * t_age= new QTextEdit();
        QTextEdit * t_id = new QTextEdit();
        QTextEdit * t_address = new QTextEdit();

        QLabel *l=new QLabel("Name");
        QLabel *l_name=new QLabel("Name");
        QLabel *l_age=new QLabel("Age");
        QLabel *l_id=new QLabel("National_Id");
        QLabel *l_address=new QLabel("Address");

signals:

};

#endif // CREATE_NEW_ACCOUNT_H
