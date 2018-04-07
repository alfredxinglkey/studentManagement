#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addstudent.h"
#include "querystu.h"
#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionaddStu_triggered();

    void on_actionqueryStu_triggered();

    void on_actionabout_triggered();

private:
    Ui::MainWindow *ui;
    addStudent a;
    queryStu q;
    about b;
};

#endif // MAINWINDOW_H
