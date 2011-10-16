#ifndef CLIENT_H
#define CLIENT_H

#include <QThread>

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

class QTcpSocket;

class ClientThread:public QThread
{
        Q_OBJECT
public:
    ClientThread(QObject *parent=0);
    ~ClientThread();

    static void sendRegistrationRequest();
    static void sendStatusUpdate(int,int,int);
    static void config(QString address, int id);

    enum Task{
        REGISTER, DEVICEUPDATE
    };

signals:
    void registrationInfoReceived();

private:
    void run();
    static QString serverAddress;
    static int serverPort;
    static int deviceID;



    int task;
    int stateCode;
    int alertCode;
    int errorCode;

};

#endif // CLIENT_H
