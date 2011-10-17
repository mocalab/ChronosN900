#include "n900accelerometer.h"

N900Accelerometer::N900Accelerometer(QObject *parent):QThread(parent)
{
    x = 0;
    y = 0;
    z = 0;
    oax = 0;
    oay = 0;
    oaz = 0;
    update();
}

void N900Accelerometer::startMonitoring()
{
    if (  !isRunning() )
    {
        enabled = true;
        start();
    }
}

void N900Accelerometer::run()
{
    calibrate();

    while(enabled)
    {
        readSmooth(&x,&y,&z);

        int diff = (bx-x) + (by-y) + (bz-z);

        if ( abs(diff) > 50)
        {
            calibrate();
            emit deviceMoved();
            enabled = false;
        }
        else
            this->msleep(100);
    }
}

void N900Accelerometer::calibrate()
{
    for ( int i=0; i < 5 ; i++)
    {
        readSmooth(&x,&y,&z);
        this->msleep(100);
    }

    bx = x;
    by = y;
    bz = z;
}

bool N900Accelerometer::update()
{
    int tmp[3] = {0, 0, 0};
    FILE *fd;

    if (!(fd = fopen(ACCELEROMETER_FILE_N900, "r"))) {
        return false;
    }

    if (fscanf(fd, "%i %i %i", tmp, tmp+1, tmp+2) != 3) {
        return false;
    }

    if (fclose(fd) == EOF) {
        return false;
    }

    x = tmp[0];
    y = tmp[1];
    z = tmp[2];

    return true;
}

void N900Accelerometer::readSmooth(int *ax,int *ay,int *az){

    if ( update())
    {
        if(ocnt>0)
        {
            *ax=oax+(x-oax)*0.2;
            *ay=oay+(y-oay)*0.2;
            *az=oaz+(z-oaz)*0.2;
        }
        else
        {
            *ax = x;
            *ay = y;
            *az = z;
        }
        oax = x;
        oay = y;
        oaz = z;
        ocnt++;
    }
}
