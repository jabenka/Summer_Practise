#include "mainwindow.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QComboBox>
#include<QAction>
#include"Sources.cpp"
#include<iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    auto layout=w.layout();





    w.show();
    return a.exec();
}
