#include "client.h"
#include <QtNetwork>

QString ClientThread::serverAddress;
int ClientThread::serverPort;
int ClientThread::deviceID;

ClientThread::ClientThread(QObject *parent):QThread(parent){}

ClientThread::~ClientThread(){}

void ClientThread::run()
{
    QTcpSocket socket;
    socket.connectToHost(serverAddress, serverPort);
    if (!socket.waitForConnected(5*1000))
    {
//        emit error(socket.error(), socket.errorString());
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_7);
    QDataStream in(&socket);
    in.setVersion(QDataStream::Qt_4_7);

    switch(task)
    {
    case REGISTER:
        out << REGISTER; // packet type
        socket.write(block);

        int clientID;
        in >> clientID;
        break;
    case DEVICEUPDATE:
        out << DEVICEUPDATE; // packet type
        out << deviceID; // packet type
        out << stateCode; // packet type
        out << alertCode; // packet type
        out << errorCode; // packet type
        // fill in
        socket.write(block);
        break;
    default:
        break;
    }
}

void ClientThread::config(QString address,int id)
{
    ClientThread::serverAddress = address;
    ClientThread::serverPort = 55555;
    ClientThread::deviceID = id;
}

void ClientThread::sendRegistrationRequest()
{
    ClientThread *ct = new ClientThread();
    ct->task = REGISTER;
    ct->start();
}

void ClientThread::sendStatusUpdate(int stateCode, int errorCode, int alertCode)
{
    ClientThread *ct = new ClientThread();
    ct->task = DEVICEUPDATE;
    ct->stateCode = stateCode;
    ct->alertCode = alertCode;
    ct->errorCode = errorCode;
    ct->start();
}
