#include "serverthread.h"
#include "deviceinfo.h"

#include <QHostAddress>

ServerThread::ServerThread(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor_(socketDescriptor){}

bool ServerThread::waitForBytesReceived(QTcpSocket& socket, size_t numberOfBytes)
{
    const int timeOut = 5 * 1000;
    while (socket.bytesAvailable() < (int)numberOfBytes)
    {
        if (!socket.waitForReadyRead(timeOut))
        {
            emit error(socket.error());
            return false;
        }
    }
    return true;
}

void ServerThread::run()
{
    QTcpSocket tcpSocket;
    if (!tcpSocket.setSocketDescriptor(socketDescriptor_))
    {
        emit error(tcpSocket.error());
        return;
    }

    QDataStream in(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_7);

    if ( !waitForBytesReceived(tcpSocket, sizeof(int)) )
        return;

    int packetType;
    in >> packetType;

    switch(packetType)
    {
        case REGISTER_REQUEST:
            handleClientRegistration(tcpSocket);
            break;
        case STATUS_UPDATE:
            handleStatusUpdate(tcpSocket);
            break;
        default:
//            logEvent("Unknown packet type received");
            break;
    }

    tcpSocket.disconnectFromHost();
}

void ServerThread::handleClientRegistration(QTcpSocket& socket)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);

    int assignedID = *nextClientID;
    *nextClientID = *nextClientID + 1;

    out << assignedID;
    socket.write(block);
    socket.waitForBytesWritten();

    QString devAddress = socket.peerAddress().toString();
    DeviceInfo *newDev = new DeviceInfo(
                assignedID,
                devAddress);

    emit deviceRegistered(newDev);
}

void ServerThread::handleStatusUpdate(QTcpSocket& socket)
{
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_4_7);

    QString devAddress = socket.peerAddress().toString();
    int devID;
    int stateCode;
    int errorCode;

    in >> devID;
    in >> stateCode;
    in >> errorCode;

    DeviceInfo *dev = new DeviceInfo(devID,
                                     devAddress,
                                     stateCode,
                                     errorCode
                                     );
    emit deviceUpdated(dev);
}
