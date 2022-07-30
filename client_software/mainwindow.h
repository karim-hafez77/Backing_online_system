#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QVBoxLayout"
#include <QtWidgets>
#include "transaction.h"
#include "login.h"
#include"client_socket.h"
#include "create_new_account.h"
#include "control_window.h"
#include "../utility/serialization.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void send();
    QVBoxLayout *mainmlayout=new QVBoxLayout;

    ~MainWindow();

private slots:
    void on_create_new_account_window_clicked();
    void on_submit_button_clicked();
    void on_transaction_button_clicked();
    void connect_function(void);
    void on_return_to_main_window_button_create_clicked();
    void on_return_to_main_window_button_transaction_clicked();
    void on_login_button_clicked();
    void go_to_transaction_page(int account_id);
    void on_deposit_button_clicked();
    void on_withdraw_button_clicked();
    void on_show_button_clicked();
    void on_return_back_button_clicked();
    void on_undo_transaction_button_clicked();


private:
    Ui::MainWindow *ui;
    //main window widget

    QWidget *widget =new QWidget ;
    //main window vertical layout
    client_socket *socket1=new client_socket(8080);
    //create new account boxes
    transaction * t=new transaction();
    login * login2 = new login();
    create_new_account *c =new create_new_account();
    control_window * cw = new control_window();
    string create_account_message ="create_new_account";
    string login_message ="login_message";
    string withdraw_message ="withdraw_message";
    string deposit_message ="deposit_message";
    string show_account_balance ="show_account_balance";
    string logout_message="logout_message";
    string undo_transaction="undo_transaction";


};
#endif // MAINWINDOW_H
