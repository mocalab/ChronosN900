#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "UnixSerialInterface.h"
#include "Chronos.h"
#include <QDebug>
#include <QTimer>
#include "n900accelerometer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chronos = new Chronos(this);
    connect(chronos,SIGNAL(accDataAvailible(int,int,int)),this,SLOT(accDataAvailible(int,int,int)));
    connect(chronos,SIGNAL(log(QString)),this,SLOT(log(QString)));

    // TEMP
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerEvent()));
    timer->start(50);

    acc = new N900Accelerometer();

    if ( chronos->connect() )
    {
        log("serial port opened");
        chronos->setEnabled(true);
    }
    else
        log("unable to open serial port");
}

void MainWindow::timerEvent(){
    if( acc->update()){
        int x,y,z;
        acc->readSmooth(&x,&y,&z);
        ui->horizontalSlider_nx->setValue(x/10);
        ui->horizontalSlider_ny->setValue(y/10);
        ui->horizontalSlider_nz->setValue(z/10);
//        ui->lineEdit_nx->setText(QString::number(x));
//        ui->lineEdit_ny->setText(QString::number(y));
//        ui->lineEdit_nz->setText(QString::number(z));
    }
}

MainWindow::~MainWindow()
{
    delete chronos;
    delete ui;
}

void MainWindow::accDataAvailible(int x, int y, int z)
{
    ui->horizontalSlider_cx->setValue(x);
    ui->horizontalSlider_cy->setValue(y);
    ui->horizontalSlider_cz->setValue(z);
//    ui->lineEdit_x->setText(QString::number(x));
//    ui->lineEdit_y->setText(QString::number(y));
//    ui->lineEdit_z->setText(QString::number(z));
}

void MainWindow::log(QString msg)
{
    ui->textEdit_log->append(msg);
}

void MainWindow::on_pushButton_start_clicked()
{
    chronos->setEnabled(true);
//    ui->pushButton_stop->setEnabled(true);
//    ui->pushButton_start->setEnabled(false);
}

void MainWindow::on_pushButton_stop_clicked()
{
    chronos->setEnabled(false);
//    ui->pushButton_stop->setEnabled(false);
//    ui->pushButton_start->setEnabled(true);
}
