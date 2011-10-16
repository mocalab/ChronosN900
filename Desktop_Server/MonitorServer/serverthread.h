#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QTcpSocket>

class QDate;
class DeviceInfo;

class ServerThread : public QThread
{
    Q_OBJECT
public:
    ServerThread(int socketDescriptor, QObject *parent = 0);
    void run();

    static int *nextClientID;

signals:
    void error(QTcpSocket::SocketError socketError);
    void deviceRegistered(DeviceInfo *dev);
    void deviceUpdated(DeviceInfo *dev);

public slots:

private:
    int socketDescriptor_;
    bool waitForBytesReceived(QTcpSocket& socket, size_t numberOfBytes);
    void handleClientRegistration(QTcpSocket& socket);
    void handleStatusUpdate(QTcpSocket& socket);

    enum PacketType
    {
        REGISTER_REQUEST,
        STATUS_UPDATE,
        STATUS_REQUEST
    };
};

#endif // SERVERTHREAD_H
