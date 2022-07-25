#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "common_includes.h"
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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
