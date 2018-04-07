#include "querystu.h"
#include "ui_querystu.h"
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>


queryStu::queryStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::queryStu)
{
    ui->setupUi(this);
    if(readFromLine() == -1){
        QMessageBox::critical(this, "Error", "open file error, please retry");
        this->close();
    }
    this->model = new QStandardItemModel;
    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("爱好"));

    this->ui->tableView->setModel(model);

    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,50);
    this->ui->tableView->setColumnWidth(3,50);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);
}

queryStu::~queryStu()
{
    delete ui;
}

int queryStu::readFromLine()
{
    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return -1;
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
         QString line = in.readLine();
         stu_lines.append(line);
    }
    file.close();

    for(int i = 0; i < stu_lines.length(); i++){
        qDebug()<<stu_lines.at(i);
    }
}

void queryStu::on_btn_search_clicked()
{
    this->model->clear();
    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("爱好"));

    this->ui->tableView->setColumnWidth(0,100);
    this->ui->tableView->setColumnWidth(1,150);
    this->ui->tableView->setColumnWidth(2,50);
    this->ui->tableView->setColumnWidth(3,50);
    this->ui->tableView->setColumnWidth(4,100);
    this->ui->tableView->setColumnWidth(5,150);

    int index = this->ui->cbb_method->currentIndex();
    QString cnt = this->ui->le_content->text();
    doQuery(index, cnt);
}

void queryStu::doQuery(int index, QString cnt)
{
    int row = 0;
    for(int i = 0; i < stu_lines.length(); i++){
        QString line = stu_lines.at(i);
        line = line.trimmed();
        QStringList subs = line.split(" ");
        switch (index) {
        case 0:
            if(cnt == subs.at(0)){
                display(row++, subs);
            }
            break;
        case 1:
            if(cnt == subs.at(1)){
                display(row++, subs);
            }
            break;
        case 2:
            if(cnt == subs.at(4)){
                display(row++, subs);
            }
            break;
        default:
            break;
        }
    }
}

void queryStu::display(int row, QStringList subs)
{
    for(int i = 0; i < 5; i++){
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));
    }

    QString ins;
    for(int i = 5; i < subs.length(); i++){
        ins += subs.at(i) + ",";
    }
    this->model->setItem(row, 5, new QStandardItem(ins));
}
