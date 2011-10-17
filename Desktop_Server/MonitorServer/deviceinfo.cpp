#include "deviceinfo.h"

DeviceInfo::DeviceInfo(
    int ID,
    QString address,
    int stateCode,
    int errorCode)
{
    this->ID = ID;
    this->address = address;

    this->stateCode = stateCode;
    this->errorCode = errorCode;
}


DeviceInfo::DeviceInfo(
    int ID,
    QString address)
{
    this->ID = ID;
    this->address = address;

    this->stateCode = StateCodes::NA;
    this->errorCode = ErrorCodes::NA;
}
