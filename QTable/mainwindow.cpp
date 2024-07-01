#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItemModel>
#include<QStandardItem>
#include<QTextStream>
#include<QFile>
#include"Rep1.cpp"
#include"Rep2.cpp"
#include<algorithm>
#include<iostream>
#include<QVariant>
#include<QModelIndex>
using namespace std;
int Index;
Months m;
Person per;
int Temp=0;
int Temp2=0;
QFile mon("Months.txt");
QFile Per("Person.txt");
QStandardItemModel *model1;
QStandardItemModel *model2;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setWindowTitle("QTableView");
    ui->tableView->hide();
    ui->lineEdit->hide();
    ui->pushButton->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->pushButton_3->hide();
    ui->pushButton_2->hide();
    ui->pushButton_4->hide();
    ui->DeleteButton->hide();
    ui->DeleteLabel->hide();
    ui->DeleteLine->hide();
    ui->label->setFont(QFont("Arial",14,QFont::Bold));
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_comboBox_activated(int index)
{
    if(index==0){
        Index=0;
        ui->tableView->hide();
    }
    if(index==1){
        Index=1;
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->lineEdit->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->tableView->hide();
        ui->tableView->setVisible(true);

        ui->DeleteButton->setVisible(true);
        ui->DeleteLabel->setVisible(true);
        ui->DeleteLine->setVisible(true);

        if(Temp!=1){


        Temp=1;
        if(mon.open(QIODevice::ReadOnly)){
            cout<<"SUCC";
        }

        QTextStream in(&mon);
        in>>m;
        }
        mon.close();
        model1=new QStandardItemModel(12,2);
        model1->setHeaderData(0,Qt::Horizontal,"Месяц");
        model1->setHeaderData(1,Qt::Horizontal,"Дни");
        for(int i=0;i<m.months.size();i++){
            model1->setItem(i,0,new QStandardItem(m.months[i].Name));
            model1->setItem(i,1,new QStandardItem(QString::number(m.months[i].Days)));
        }
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->pushButton_2->setVisible(true);

        ui->tableView->setModel(model1);

    }
    if(index==2){
        ui->DeleteButton->setVisible(true);
        ui->DeleteLabel->setVisible(true);
        ui->DeleteLine->setVisible(true);

        Index=2;
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);

        ui->lineEdit->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->tableView->hide();
        ui->tableView->setVisible(true);
      if(Temp2!=1){

        if(Per.open(QIODevice::ReadOnly)){
            cout<<"Succ";
        }
        Temp2=1;
        QTextStream in(&Per);
        in>>per;
        }
        Per.close();
        model2=new QStandardItemModel(per.size,3);
        model2->setHeaderData(0,Qt::Horizontal,"Имя");
        model2->setHeaderData(1,Qt::Horizontal,"Фамилия");
        model2->setHeaderData(2,Qt::Horizontal,"Возраст");
        for(int i=0;i<(int)per.persons.size();i++){
            model2->setItem(i,0,new QStandardItem(per.persons[i].Name));
            model2->setItem(i,1,new QStandardItem(per.persons[i].Surname));
            model2->setItem(i,2,new QStandardItem(QString::number(per.persons[i].Age)));
        }
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->lineEdit_4->setVisible(true);
        ui->pushButton_2->setVisible(true);

          ui->tableView->setModel(model2);

    }
}


void MainWindow::on_pushButton_clicked()
{
    QString text=ui->lineEdit->text();
    QString res;
    if(Index==1){
        for(int i=0;i<ui->tableView->model()->rowCount();i++){
            QModelIndex ind=model1->index(i,0);
            QVariant data=ind.data();
            QString Name=data.toString();
            if(Name==text){
                res+=Name;
                res+=" ";
                ind=model1->index(i,1);
                data=ind.data();
                Name=data.toString();
                res+=Name;
                res+=" день(дней)";
                ui->label->setText(res);
                return;
            }
        }


        ui->label->setText("Ничего не найдено");
    }
    if(Index==2){
        QString res;
\
        QString text=ui->lineEdit->text();
        for(int i=0;i<ui->tableView->model()->rowCount();i++){
            QModelIndex ind=model2->index(i,0);
            QVariant data=ind.data();
            QString Name=data.toString();
            if(Name==text){
                res+=Name;
                res+=" ";
                ind=model2->index(i,1);
                data=ind.data();
                Name=data.toString();
                res+=Name;
                ind=model2->index(i,2);
                data=ind.data();
                Name=data.toString();
                res+=" ";
                res+=Name;
                res+=" лет";
                ui->label->setText(res);
                return;

            }
        }

          ui->label->setText("Ничего не найдено");

    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(Index==1){
        QString text=ui->lineEdit_2->text();
        int date=ui->lineEdit_3->text().toInt();
        Rep1 r(text,date);
        m.months.push_back(r);
        ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
        model1->setItem(ui->tableView->model()->rowCount()-1,0,new QStandardItem(text));
        model1->setItem(ui->tableView->model()->rowCount()-1,1,new QStandardItem(QString::number(date)));
    }
    if(Index==2){
        QString text1=ui->lineEdit_2->text();
        QString text2=ui->lineEdit_3->text();
        int age=ui->lineEdit_4->text().toInt();
        Rep2 r(text1,text2,age);
        per.persons.push_back(r);
        ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
        model2->setItem(ui->tableView->model()->rowCount()-1,0,new QStandardItem(text1));
        model2->setItem(ui->tableView->model()->rowCount()-1,1,new QStandardItem(text2));
        model2->setItem(ui->tableView->model()->rowCount()-1,2,new QStandardItem(QString::number(age)));
    }
    ui->label_3->setText("Добавлено");

}


void MainWindow::on_pushButton_3_clicked()
{
    if(Index==1){
        sort(m.months.begin(),m.months.end(),[](const Rep1& obj,const Rep1& obj2){
            return obj.Name<obj2.Name;
        });
        for(int i=0;i<m.months.size();i++){
            model1->setItem(i,0,new QStandardItem(m.months[i].Name));
            model1->setItem(i,1,new QStandardItem(QString::number(m.months[i].Days)));
        }
          ui->tableView->setModel(model1);

    }
    if(Index==2){
        sort(per.persons.begin(),per.persons.end(),[](const Rep2& obj,const Rep2& obj2){
            return obj.Name<obj2.Name;
        });
        for(int i=0;i<(int)per.persons.size();i++){
            model2->setItem(i,0,new QStandardItem(per.persons[i].Name));
            model2->setItem(i,1,new QStandardItem(per.persons[i].Surname));
            model2->setItem(i,2,new QStandardItem(QString::number(per.persons[i].Age)));
        }


        ui->tableView->setModel(model2);

    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(Index==1){
        if(mon.open(QIODevice::WriteOnly)){
            cout<<"Pob";
        }
        QTextStream out(&mon);
        out<<m;
        mon.close();
    }
    if(Index==2){
        if(Per.open(QIODevice::WriteOnly)){
            cout<<"tr";
        }
        QTextStream out(&Per);
        out<<per;
        Per.close();
    }
    ui->label_2->setText("Сохранено");
}



void MainWindow::on_DeleteButton_clicked()
{
    if(Index==1){
        int RowNum=ui->DeleteLine->text().toInt();
        if(RowNum>ui->tableView->model()->rowCount()|| ui->tableView->model()->rowCount()<0){
            ui->DeleteLabel->setText("Число должно быть меньше");
            return;
        }
        model1->removeRow(RowNum-1);
    }
    if(Index==2){
        int RowNum=ui->DeleteLine->text().toInt();
        if(RowNum>ui->tableView->model()->rowCount() || ui->tableView->model()->rowCount()<0){
            ui->DeleteLabel->setText("Число должно быть меньше");
            return;
        }
        model2->removeRow(RowNum-1);
    }
}

