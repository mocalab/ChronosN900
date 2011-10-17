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
class Monitor;

class ClientThread:public QThread
{
        Q_OBJECT
public:
    ClientThread(QObject *parent=0);
    ~ClientThread();

    static void sendRegistrationRequest();
    static void sendStatusUpdate(int stateCode, int errorCode);
    static void config(Monitor *parent,QString address, int id);

    enum Task{
        REGISTER, DEVICEUPDATE
    };

signals:
    void registrationInfoReceived(int id);
    void registrationFailed();
    void eventUpdateFailed();

    void logEvent(QString event);

private:
    void run();
    bool waitForBytesReceived(QTcpSocket& socket, size_t numberOfBytes);


    static QString serverAddress;
    static int serverPort;
    static int deviceID;
    static Monitor* parent;

    int task;
    int stateCode;
    int alertCode;
    int errorCode;
};

#endif // CLIENT_H
