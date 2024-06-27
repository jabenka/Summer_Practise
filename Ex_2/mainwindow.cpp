#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Sources.cpp"
#include<QString>
#include<vector>
QString text1;
QString text2;
QString text3;
int Index;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Text1->hide();
    ui->Text2->hide();
    ui->Text3->hide();
    ui->Button1->hide();
    ui->Button2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    if(index==1){
        ui->Text1->setVisible(true);
        ui->Button1->setVisible(true);
        Index=1;
    }
    if(index==2){

        ui->Text1->setVisible(true);
        ui->Button1->setVisible(true);
        ui->Text2->setVisible(true);
        Index=2;
    }
    if(index==3){
        ui->Button1->setVisible(true);

        ui->Text1->setVisible(true);
        ui->Text2->setVisible(true);
        ui->Text3->setVisible(true);
        Index=3;
    }

}

void MainWindow::on_Button1_clicked()
{
    if(Index==1){


        int a=ui->Text1->text().toInt();
        Prime pr;
        if(pr.IsPrime(a)){
            ui->label->setText("Простое");
        }else{
            vector<unsigned int> res;
            res=pr.isPrime(a);
            QString TEXt1;
            TEXt1+="Coставное";
            TEXt1+=" ";
            for(int i=0;i<res.size();i++){
                TEXt1+=to_string(res[i]);
                TEXt1+=" ";
            }
                ui->label->setText(TEXt1);

        }
    }
    if(Index==2){
        double x=ui->Text1->text().toDouble();
        double eps=ui->Text2->text().toDouble();
        Sinus sinus;
        double ans= sinus.Sin(x,eps);
        QString res;
        res+=to_string(ans);
        ui->label->setText(res);
    }
    if(Index==3){
        double a=ui->Text1->text().toDouble();
        double b=ui->Text2->text().toDouble();
        double c=ui->Text3->text().toDouble();
        Root roots;
        vector<double> result;
        result=roots.Roots(a,b,c);
        QString re;
        for(int i=0;i<result.size();i++){
            re+=to_string(result[i]);
            re+=" ";
        }
        ui->label->setText(re);
    }
}




