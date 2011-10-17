#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"
#include <QSettings>

#define SETTINGS_FILE "config.ini"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadSettings();
    server = new Server(this, serverPort,&nextclientID);

    //**************
//    DeviceInfo *d2 = new DeviceInfo(1110,"zxcxzc",StateCodes::NA,ErrorCodes::NA,AlertCodes::DEVICEMOVED);
//    DeviceInfo *d1 = new DeviceInfo(1220,"xzczxc",StateCodes::NA,ErrorCodes::CHRONOS,AlertCodes::DEVICEMOVED);

//    addDevice(d1);
//    addDevice(d2);
//    d1->address = "hello";
//    addDevice(d1);

//    getDeviceIndex(d2);
}

MainWindow::~MainWindow()
{
    saveDeviceInfo();
    delete ui;
}

void MainWindow::loadSettings()
{
    QSettings settings(SETTINGS_FILE,QSettings::IniFormat);
    this->serverPort = settings.value("port",55555).toInt();
    this->nextclientID = settings.value("nextClientID",0).toInt();

    int devCnt = settings.beginReadArray("devices");
    nextclientID = devCnt;

    for (int row = 0; row < devCnt; ++row)
    {
        settings.setArrayIndex(row);
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,TableColumns::DEV_ID     ,new QTableWidgetItem( settings.value("id").toString() ));
        ui->tableWidget->setItem(row,TableColumns::DEV_ADDR   ,new QTableWidgetItem( settings.value("addr").toString() ));
        ui->tableWidget->setItem(row,TableColumns::DEV_STATE  ,new QTableWidgetItem( settings.value("state").toString() ));
        ui->tableWidget->setItem(row,TableColumns::DEV_ERROR  ,new QTableWidgetItem( settings.value("error").toString() ));
    }
    settings.endArray();
}

void MainWindow::saveDeviceInfo()
{
    QSettings settings(SETTINGS_FILE,QSettings::IniFormat);

    settings.setValue("port", serverPort);
    settings.setValue("nextClientID", nextclientID);

    int devCnt = ui->tableWidget->rowCount();
    settings.beginWriteArray("devices");

    for( int i=0; i<devCnt;i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("id",     ui->tableWidget->item(i,TableColumns::DEV_ID)->text() );
        settings.setValue("addr",   ui->tableWidget->item(i,TableColumns::DEV_ADDR)->text() );
        settings.setValue("state",  ui->tableWidget->item(i,TableColumns::DEV_STATE)->text() );
        settings.setValue("error",  ui->tableWidget->item(i,TableColumns::DEV_ERROR)->text() );

    }
    settings.endArray();
}

int MainWindow::onDeviceRegistered(DeviceInfo *dev){
    int row = getDeviceIndex(dev);
    if ( row == -1 )
    {
        row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
    }

    ui->tableWidget->setItem(row,TableColumns::DEV_ID     ,new QTableWidgetItem(QString::number(dev->ID)));
    ui->tableWidget->setItem(row,TableColumns::DEV_ADDR   ,new QTableWidgetItem(dev->address));
    ui->tableWidget->setItem(row,TableColumns::DEV_STATE  ,new QTableWidgetItem( StateName[dev->stateCode] ));
    ui->tableWidget->setItem(row,TableColumns::DEV_ERROR  ,new QTableWidgetItem( "NA" ));
    return row;
}

int MainWindow::onDeviceUpdate(DeviceInfo *dev){
    int row = getDeviceIndex(dev);
    if ( row == -1 )
    {
        row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
    }

    ui->tableWidget->setItem(row,TableColumns::DEV_ID     ,new QTableWidgetItem(QString::number(dev->ID)));
    ui->tableWidget->setItem(row,TableColumns::DEV_ADDR   ,new QTableWidgetItem(dev->address));
    ui->tableWidget->setItem(row,TableColumns::DEV_STATE  ,new QTableWidgetItem( StateName[dev->stateCode] ));

    if ( dev->stateCode == StateCodes::ERROR)
        ui->tableWidget->setItem(row,TableColumns::DEV_ERROR  ,new QTableWidgetItem( ErrorName[dev->errorCode] ));
    else if (dev->stateCode == StateCodes::ALERT)
        ui->tableWidget->setItem(row,TableColumns::DEV_ERROR  ,new QTableWidgetItem( AlertName[dev->errorCode] ));
    else
        ui->tableWidget->setItem(row,TableColumns::DEV_ERROR  ,new QTableWidgetItem( "NA" ));
}

int MainWindow::getDeviceIndex(DeviceInfo *dev){
    int items = ui->tableWidget->rowCount();
    for( int i=0; i<items;i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i,TableColumns::DEV_ID);
        if ( item != NULL){
            int devID = item->text().toInt();
            if ( devID == dev->ID)
                return i;
        }
    }
    return -1;
}
