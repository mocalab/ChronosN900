#include "n900accelerometer.h"

N900Accelerometer::N900Accelerometer() : x(0), y(0), z(0), oax(0), oay(0), oaz(0),ocnt(0)
{
    update();
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
            *ax=oax+(x-oax)*0.1;
            *ay=oay+(y-oay)*0.1;
            *az=oaz+(z-oaz)*0.1;
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
