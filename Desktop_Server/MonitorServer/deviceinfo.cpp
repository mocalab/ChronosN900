#include "deviceinfo.h"

DeviceInfo::DeviceInfo(
    int ID,
    QString address,
    int stateCode,
    int errorCode,
    int alertCode)
{
    this->ID = ID;
    this->address = address;

    this->stateCode = stateCode;
    this->errorCode = errorCode;
    this->alertCode = alertCode;
}


DeviceInfo::DeviceInfo(
    int ID,
    QString address)
{
    this->ID = ID;
    this->address = address;

    this->stateCode = StateCodes::NA;
    this->errorCode = ErrorCodes::NA;
    this->alertCode = AlertCodes::NA;
}
