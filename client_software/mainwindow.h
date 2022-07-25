#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QVBoxLayout"
#include <QtWidgets>
#include "transaction.h"
#include "login.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_submit_button_clicked();
    void on_return_to_main_window_clicked();
    void connect_function(void);

private:
    Ui::MainWindow *ui;
    //main window widget
    QWidget *widget =new QWidget ;
    //main window vertical layout
    QVBoxLayout *mainlayout=new QVBoxLayout;
    //divide the main window to 2 group boxes
//    QGroupBox *create_new_account = new QGroupBox("Create New Account", this);
//    QGroupBox *Transactions = new QGroupBox("Transactions", this);
    //create new account boxes
    transaction * t=new transaction();
    login * login2 = new login();
    QHBoxLayout * inner_vertical_layout_control_submit_button=new QHBoxLayout  ;

    QHBoxLayout * horizontal_layout_control=new QHBoxLayout  ;
    QHBoxLayout * inner_horizontal_layout_control_name=new QHBoxLayout  ;
    QHBoxLayout * inner_horizontal_layout_control_age=new QHBoxLayout  ;
    QHBoxLayout * inner_horizontal_layout_control_id=new QHBoxLayout  ;
    QHBoxLayout * inner_horizontal_layout_control_address=new QHBoxLayout  ;


    //main window vertical layout
    QVBoxLayout * vertical_layout_control=new QVBoxLayout  ;
    //create new account inner mainlayout
    QVBoxLayout *create_account_inner_mainlayout=new QVBoxLayout;



//    QGridLayout *main_layout2 = new QGridLayout;
//    QGroupBox *over_the_air = new QGroupBox("OTA", this);
//    QGroupBox *ucm = new QGroupBox("UCM", this);

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





};
#endif // MAINWINDOW_H
