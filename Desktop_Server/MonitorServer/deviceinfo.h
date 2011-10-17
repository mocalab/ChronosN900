#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QString>

static QString StateName[] = {
    "NA",
    "OFF",
    "OK",
    "ERROR",
    "ALERT"};

struct StateCodes{
    enum
    {
        NA,
        OFF,
        ON,
        ERROR,
        ALERT
    };
};

static QString ErrorName[] = {
    "NA",
    "Serial Port",
    "Chronos Lost",
    "ACCELEROMETER",
    "OTHER"};

struct ErrorCodes{
    enum
    {
        NA,
        SERIAL,
        CHRONOS,
        ACCELEROMETER,
        OTHER
    };
};

static QString AlertName[] = {
    "NA",
    "DEVICEMOVED",
    "CHRONOSLOST",
    "GPSCHANGE",
    "WIFICHANGE",
    "OTHER"};


struct AlertCodes{
    enum
    {
        NA,
        DEVICEMOVED,
        CHRONOSLOST,
        GPSCHANGE,
        WIFICHANGE,
        OTHER
    };
};

class DeviceInfo
{
public:
    DeviceInfo(int ID,
               QString address,
               int stateCode,
               int errorCode);

    DeviceInfo(int ID,
               QString address);

    int ID;
    QString address;
    int stateCode;
    int errorCode;
};

#endif // DEVICEINFO_H
