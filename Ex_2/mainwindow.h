#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(int index);






    void on_Button1_clicked();

private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
