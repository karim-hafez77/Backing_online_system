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
    void on_submit_button_clicked();
    void on_return_to_main_window_clicked();
    void connect_function(void);

private:
    Ui::MainWindow *ui;
    //main window widget
    client_socket *s=new client_socket(8080);

    QWidget *widget =new QWidget ;
    //main window vertical layout
    //create new account boxes
    transaction * t=new transaction();
//    login * login2 = new login();
//    create_new_account *c =new create_new_account();
    control_window * cw = new control_window();
    struct TransferDataInput
                        {
                            int message_id;
                            string data;
                            string blockCounter;
                            TransferDataInput(int i1,string i2,string i3)
                            {
                                message_id=i1;
                                data=i2;
                                blockCounter=i3;
                            }
                        private:
                            template <typename Archive>
                        void serialize(Archive &ar, const unsigned int version)
                            {
                            ar &message_id;
                            ar &data;
                            ar &blockCounter;
                            }
                            friend class boost::serialization::access;
                        };



};
#endif // MAINWINDOW_H
