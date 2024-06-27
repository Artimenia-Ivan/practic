#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#define M_PI 3.14159265358979323846
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString s;
    int a = ui->lineEdit ->text().toInt();
    ui->lineEdit_4->clear();
    bool b=1;
    if(a<2)
    {
        ui->lineEdit_4->insert("ne prostoye, ne sostavnoye");
        return;
    }
    if(a==2)
    {
        ui->lineEdit_4->insert("prostoye");
        return;
    }
    int i=2;
    while(a>1)
    {
        while(a%i==0)
        {
            s = QString::number(i);
            ui->lineEdit_4->insert(s);
            ui->lineEdit_4->insert(" ");
            a/=i;

            b=0;
        }
        i++;
    }
    if(b)
    {
        ui->lineEdit_4->insert("prostoye");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_4->clear();
    double x = ui->lineEdit ->text().toDouble();
    double t = ui->lineEdit_2 ->text().toInt();
    double e = pow(0.1, t);
    while (x > 2 * M_PI)
    {
        x -= 2 * M_PI;
    }
    double a = x;
    double sum =0;
    int i=0;
    while (abs(a) > e)
    {
        sum += a;
        a = -a * x *x/(i+3)/(i+2);
        i += 2;
    }
    QString s = QString::number(sum);
    ui->lineEdit_4->insert(s);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit_4->clear();
    double a = ui->lineEdit ->text().toDouble();
    double b = ui->lineEdit_2 ->text().toDouble();
    double c = ui->lineEdit_3 ->text().toDouble();
    double x1,x2,D;
    if (a == 0)
    {
        if (b == 0)
        {
            if(c==0)
                ui->lineEdit_4->insert("x - luboye");
            else
                ui->lineEdit_4->insert("net resheniy(a==0&b==0)");
            return;
        }
        else
        {
            x1 = -c / b;
            QString s = QString::number(x1);
            ui->lineEdit_4->insert("odin koren' s a==0 - ");
            ui->lineEdit_4->insert(s);
            return;
        }
    }
    D = (long long)b * b - 4 * a * c;
    if (D < 0)
    {
        ui->lineEdit_4->insert("net resheniy(D<0)");
    }
    if (D == 0)
    {
        x1 = 0 - b / 2 / a;
        QString s = QString::number(x1);
        ui->lineEdit_4->insert("odin koren' - ");
        ui->lineEdit_4->insert(s);
    }
    else
    {
        if (D > 0)
        {
            x1 = (sqrt(D) - b) / 2 / a;
            x2 = (-sqrt(D) - b) / 2 / a;
            QString s = QString::number(x1);
            ui->lineEdit_4->insert(s);
            ui->lineEdit_4->insert(" ");
            s = QString::number(x2);
            ui->lineEdit_4->insert(s);
        }
    }
}


void MainWindow::on_comboBox_activated(int index)
{
    if(index ==0)
    {
        ui-> lineEdit_2 -> setVisible(0);
        ui-> lineEdit_3 -> setVisible(0);
        ui-> pushButton -> setVisible(1);
        ui-> pushButton_2 -> setVisible(0);
        ui-> pushButton_3 -> setVisible(0);
        ui-> label_2 -> setVisible(0);
        ui-> label_3 -> setVisible(0);
        ui-> label ->setText("vvedite chislo");
    }
    else if(index ==1)
    {
        ui-> lineEdit_2 -> setVisible(1);
        ui-> lineEdit_3 -> setVisible(0);
        ui-> pushButton -> setVisible(0);
        ui-> pushButton_2 -> setVisible(1);
        ui-> pushButton_3 -> setVisible(0);
        ui-> label_2 -> setVisible(1);
        ui-> label_3 -> setVisible(0);
        ui-> label ->setText("vvedite chislo");
        ui-> label_2 ->setText("vvedite tochnost'");
    }
    else if(index ==2)
    {
        ui-> lineEdit_2 -> setVisible(1);
        ui-> lineEdit_3 -> setVisible(1);
        ui-> pushButton -> setVisible(0);
        ui-> pushButton_2 -> setVisible(0);
        ui-> pushButton_3 -> setVisible(1);
        ui-> label_2 -> setVisible(1);
        ui-> label_3 -> setVisible(1);
        ui-> label ->setText("vvedite a");
        ui-> label_2 ->setText("vvedite b");
        ui-> label_3 ->setText("vvedite c");
    }
}

