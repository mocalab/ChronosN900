#include "UnixSerialInterface.h"
//#include <QDebug>
#include <termios.h>
#include <fcntl.h>

#define BAUDRATE B115200

UnixSerialInterface::UnixSerialInterface()
{
    started = false;
    fd = -1;
    readIntervalTimout = 10;
}

UnixSerialInterface::~UnixSerialInterface()
{
    //qDebug() << "closing linux serial interface";
    //if ( rfcomm.isOpen())
    //    rfcomm.kill();
}

bool UnixSerialInterface::init(QString portName)
{
    //portName = "/dev/ttyACM0";

    struct termios oldtio,newtio;

    fd = open(portName.toAscii(), O_RDWR | O_NOCTTY );

    if ( fd <0 )
    {
        //unable to open serial port
        return false;
    }

    tcgetattr(fd,&oldtio); /* save current port settings */
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;

    /* set input mode (non-canonical, no echo,...) */
    newtio.c_lflag = 0;

    newtio.c_cc[VTIME]    = 0;   /* inter-character timer unused */
    newtio.c_cc[VMIN]     = 1;   /* blocking read until 1 chars received */

    tcflush(fd, TCIFLUSH);
    tcsetattr(fd,TCSANOW,&newtio);

    started = true;
    return true;
}

int UnixSerialInterface::read(char* readBuffer,qint64 maxSize)
{
    if ( started )
    {
        int bytesRead;
        bytesRead = ::read(fd,readBuffer,maxSize);
        return bytesRead;
    }
    else
        return -1;
}

int UnixSerialInterface::write(char* buffer,qint64 length)
{
    if ( started )
    {
        int bytesWritten;
        bytesWritten = ::write(fd,buffer,length);
        return bytesWritten;
    }
    else
        return -1;
}
