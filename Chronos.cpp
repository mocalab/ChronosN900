#include "Chronos.h"
#include "UnixSerialInterface.h"

char START_AP[] = {0xFF,0x07,0x03};
char STOP_AP[] = {0xFF,0x09,0x03};
char ACC_DATA_REQUEST[] = {0xFF,0x08,0x07,0x00,0x00,0x00,0x00};

Chronos::Chronos(QObject *parent):QThread(parent)
{
    serial = new UnixSerialInterface();
    enabled = false;
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
    serial->read(buffer,3);// ack?

    while(enabled)
    {
        serial->write(ACC_DATA_REQUEST,sizeof(ACC_DATA_REQUEST));
        bytesRead = serial->read(buffer,7);

        if ( buffer[3] == 0x01)
        {
            x = buffer[4];
            y = buffer[5];
            z = buffer[6];
            emit accDataAvailible(x,y,z);
        }
    }
}

// try to open the serial port
// if succesful, send the command to start the AP
bool Chronos::connect()
{
    if ( !serial->init("/dev/ttyACM0") )
        return false;
    else
    {
        serial->write(START_AP,sizeof(START_AP));
        log("AP started, set watch to ACC mode");
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
