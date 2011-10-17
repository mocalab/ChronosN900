#ifndef N900ACCELEROMETER_H
#define N900ACCELEROMETER_H

#include <QThread>
#include <stdio.h>

#define ACCELEROMETER_FILE_N900 "/sys/class/i2c-adapter/i2c-3/3-001d/coord"

class N900Accelerometer : public QThread
{
    Q_OBJECT

public:
    N900Accelerometer(QObject *parent=0);
    bool update();
    void readSmooth(int *ax,int *ay,int *az);
    void startMonitoring();

signals:
    void deviceMoved();

private:
    int x;
    int y;
    int z;

    int oax,oay,oaz,ocnt;

    int bx, by, bz;

    void run();
    void calibrate();
    bool enabled;

private slots:

};

#endif // N900ACCELEROMETER_H
