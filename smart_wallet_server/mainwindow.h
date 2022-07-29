#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common_includes.h"
#include "QThread"
#include "../utility/serialization.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    vector<account> v1;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *widget =new QWidget ;
    QVBoxLayout *mainlayout=new QVBoxLayout;
    smart_wallet_server * sws=new smart_wallet_server();
    server_socket * s=new server_socket(8080);
    void create_server();
    void access_account(account a);

private slots:
    void logout_handler();
    void login_handler();

signals:
    void signal_logout();
    void signal_login();

private:
    Ui::MainWindow *ui;
    account accessed_account;


};
#endif // MAINWINDOW_H
