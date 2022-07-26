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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *widget =new QWidget ;
    QVBoxLayout *mainlayout=new QVBoxLayout;
    void create_server();
    server_socket * s=new server_socket(8080);
    struct TransferDataInput
                        {
                            int id;
                            string data;
                            string blockCounter;
                        private:
                            template <typename Archive>
                        void serialize(Archive &ar, const unsigned int version)
                            {
                            ar &id;
                            ar &data;
                            ar &blockCounter;
                            }
                            friend class boost::serialization::access;
                        };


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
