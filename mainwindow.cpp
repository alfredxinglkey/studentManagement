#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstudent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionaddStu_triggered()
{
//    addStudent w;
//    w.exec();
    this->a.show();
}

void MainWindow::on_actionqueryStu_triggered()
{
    this->q.show();
}

void MainWindow::on_actionabout_triggered()
{
    this->b.show();
}
