#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include <QObject>

class UnixSerialInterface : public QObject
{
Q_OBJECT
public:
    UnixSerialInterface();
    ~UnixSerialInterface();
    bool init(QString portName);
    int read(char* buffer,qint64 maxSize);
    int write(char* buffer,qint64 length);

private:

    int baudRate;
    int readIntervalTimout;
    bool started;

    int fd;
};

#endif // SERIALINTERFACE_H
