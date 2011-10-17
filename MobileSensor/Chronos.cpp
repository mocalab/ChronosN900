#include "Chronos.h"
#include "UnixSerialInterface.h"
#include <QTimer>

char START_AP[] = {0xFF,0x07,0x03};
char STOP_AP[] = {0xFF,0x09,0x03};
char ACC_DATA_REQUEST[] = {0xFF,0x08,0x07,0x00,0x00,0x00,0x00};

Chronos::Chronos(QObject *parent):QThread(parent)
{
    serial = new UnixSerialInterface();
    enabled = false;
    packetsMissed = 0;
    packetsReceived = 0;
    ChronosTimeoutLimit = 5;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTick()));
}

Chronos::~Chronos()
{
    serial->write(STOP_AP,sizeof(STOP_AP));
    delete serial;
}

void Chronos::run()
{
    int bytesRead;
    int x,y,z;

    serial->write(ACC_DATA_REQUEST,sizeof(ACC_DATA_REQUEST));
    serial->read(buffer,3);

    while(enabled)
    {
        serial->write(ACC_DATA_REQUEST,sizeof(ACC_DATA_REQUEST));
        bytesRead = serial->read(buffer,7);

        if ( buffer[3] == 0x01)
        {
            x = buffer[4];
            y = buffer[5];
            z = buffer[6];
//            emit accDataAvailible(x,y,z);

            if ( packetsReceived == 0)
            {
                emit deviceAvailible();
                timer->start(100);
            }

            packetsMissed = 0;
            packetsReceived++;
        }
    }
}

// try to open the serial port
// if succesful, send the command to start the AP
bool Chronos::connectPort()
{
    if ( !serial->init("/dev/ttyACM0") )
    {
        emit logEvent("Unable to open USB-Serial interface!");
        return false;
    }
    else
    {
        serial->write(START_AP,sizeof(START_AP));
        emit logEvent("Serial port OK");
        emit logEvent("AP started, set watch to ACC mode to start monitoring link");
        setEnabled(true);
        return true;
    }
}

void Chronos::setEnabled(bool status)
{
    if ( status && !isRunning() )
    {
        enabled = true;

        start();
    }
    else
        enabled = false;
}

void Chronos::timerTick()
{
    packetsMissed++;
    if ( packetsMissed > ChronosTimeoutLimit)
    {
        packetsReceived = 0;
        emit deviceUnAvailible();
        timer->stop();
    }
}
