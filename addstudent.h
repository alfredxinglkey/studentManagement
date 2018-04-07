#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>

namespace Ui {
class addStudent;
}

class addStudent : public QDialog
{
    Q_OBJECT

public:
    explicit addStudent(QWidget *parent = 0);
    void clearUserInterface();
    void writeToFile(QString cnt);
    ~addStudent();

private slots:
    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::addStudent *ui;
};

#endif // ADDSTUDENT_H
