#ifndef N900ACCELEROMETER_H
#define N900ACCELEROMETER_H

#include <stdio.h>

#define ACCELEROMETER_FILE_N900 "/sys/class/i2c-adapter/i2c-3/3-001d/coord"

class N900Accelerometer
{
private:
    int x;
    int y;
    int z;

    int oax,oay,oaz,ocnt;
public:
    N900Accelerometer();
    bool update();
    void readSmooth(int *ax,int *ay,int *az);

};

#endif // N900ACCELEROMETER_H
