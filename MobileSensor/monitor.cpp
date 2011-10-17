#include "monitor.h"
#include <QSettings>
#include <QTimer>

#include "n900accelerometer.h"
#include "Chronos.h"
#include "client.h"

#define SETTINGS_FILE "config.ini"

Monitor::Monitor(QObject *parent):QObject(parent)
{
    chronos = new Chronos(this);
    connect(chronos,SIGNAL(logEvent(QString)),this,SLOT(onLogEvent(QString)));
    connect(chronos,SIGNAL(deviceAvailible()),this,SLOT(onChronosAvailible()));
    connect(chronos,SIGNAL(deviceUnAvailible()),this,SLOT(onChronosUnAvailible()));

    accel = new N900Accelerometer();
    connect(accel,SIGNAL(deviceMoved()),this,SLOT(onDeviceMoved()));

    deviceOK = false;
    accel->startMonitoring();
}

void Monitor::resetAccel()
{
    ClientThread::sendStatusUpdate(StateCodes::ON,AlertCodes::NA);
    accel->startMonitoring();
}

void Monitor::onDeviceMoved()
{
    emit logEvent("Device moved!");
    if ( deviceOK )
        ClientThread::sendStatusUpdate(StateCodes::ALERT,AlertCodes::DEVICEMOVED);
}

void Monitor::onChronosAvailible()
{
    emit logEvent("Link to chronos OK");
    ClientThread::sendStatusUpdate(StateCodes::ON,ErrorCodes::NA);
    deviceOK = true;

}

void Monitor::onChronosUnAvailible()
{
    emit logEvent("Lost connection to chronos");
    if ( deviceOK ) // link lost
        ClientThread::sendStatusUpdate(StateCodes::ALERT,AlertCodes::CHRONOSLOST);

    else
        ClientThread::sendStatusUpdate(StateCodes::ERROR,ErrorCodes::CHRONOS);

}

void Monitor::start()
{
    onReloadSettings();

}

void Monitor::shutDown()
{
    ClientThread::sendStatusUpdate(StateCodes::OFF,AlertCodes::NA);
}

void Monitor::onReloadSettings()
{
    QSettings settings("company","MonitorApp");

    int clientID = settings.value("clientID",0).toInt();
    QString serverAddressNew = settings.value("serverAddress","192.168.0.1").toString();

    ClientThread::config(this,serverAddressNew,clientID);

    if (clientID == 0 || ( serverAddress != "" && serverAddress != serverAddressNew) )
    {
        QSettings settings("company","MonitorApp");
        settings.setValue("clientID",0);

        emit logEvent("Client not registered, requesting ID from server at " + serverAddressNew);
        ClientThread::sendRegistrationRequest();
    }else
    {
         emit logEvent("Devise already registered with " + serverAddressNew + " with ID " + QString::number(clientID));
        startChronosProcess();
    }

    serverAddress = serverAddressNew;
}

void Monitor::onLogEvent(QString event)
{
    emit logEvent(event);
}

void Monitor::onRegistratorFailed()
{
    emit logEvent("Reattempting to register...");
    ClientThread::sendRegistrationRequest();
}

void Monitor::onRegistratorReceived(int id)
{
    QSettings settings("company","MonitorApp");
    settings.setValue("clientID",id);

    emit logEvent("Received ID: " + QString::number(id));

    startChronosProcess();
}

void Monitor::startChronosProcess()
{
    if ( !chronos->connectPort() )
    {
        ClientThread::sendStatusUpdate(StateCodes::ERROR,ErrorCodes::SERIAL);
    }
}
