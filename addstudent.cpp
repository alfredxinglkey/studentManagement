#include "addstudent.h"
#include "ui_addstudent.h"
#include <QString>
#include <QMessageBox>
#include <QList>
#include <QAbstractButton>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

addStudent::addStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStudent)
{
    ui->setupUi(this);
}

addStudent::~addStudent()
{
    delete ui;
}

void addStudent::on_btn_ok_clicked()
{
    QString name = this->ui->le_name->text();
    QString id = this->ui->le_id->text();
    QString age = this->ui->cbb_age->currentText();
    QString gender = this->ui->genderGroup->checkedButton()->text();
    QString college = this->ui->cbb_college->currentText();
    QList<QAbstractButton *> ins_list = this->ui->interestGroup->buttons();
    QString ins;
    for(int i = 0; i < ins_list.length(); i++){
        QAbstractButton * che = ins_list.at(i);
        if(che->isChecked()){
            ins += che->text() + " ";
        }
    }
    QString content = name + '\n' + id + "\n" + gender + "\n" + age + "\n" + college + "\n" + ins;
    QString cnt = name + ' ' + id + " " + gender + " " + age + " " + college + " " + ins + "\n";

    if(name.length() < 1 || id.length() < 1 || ins.length() < 1){
        QMessageBox::critical(this,"Info not compelete","Please complete your info","确定");
    }else{
        int ret = QMessageBox::question(this,"Verify you info", content, "确定","取消");
        if(ret == 0){
            clearUserInterface();
            writeToFile(cnt);
        }
    }
}

void addStudent::clearUserInterface()
{
    this->ui->le_name->clear();
    this->ui->le_id->clear();
    this->ui->rbtn_male->setChecked(true);
    this->ui->cbb_age->setCurrentIndex(0);
    this->ui->cbb_college->setCurrentIndex(0);
    QList<QAbstractButton *> ins_list = this->ui->interestGroup->buttons();
    for(int i = 0; i < ins_list.length(); i++){
        QAbstractButton * box = ins_list.at(i);
        box->setChecked(false);
    }
    this->ui->le_name->setFocus();
}

void addStudent::on_btn_cancel_clicked()
{
    this->close();
}

void addStudent::writeToFile(QString cnt)
{
    QFile file("stu.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text)){
        QMessageBox::critical(this,"Open fail", "Fail to open file","确定");
        return;
    }
    QTextStream out(&file);
    out << cnt;
    file.close();
}
