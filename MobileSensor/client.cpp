#include "client.h"
#include "monitor.h"

#include <QtNetwork>

QString ClientThread::serverAddress;
Monitor* ClientThread::parent;
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
        logEvent("Unable to connect to server at " + serverAddress);

        switch(task)
        {
        case REGISTER:
            this->sleep(1);
            emit registrationFailed();
            break;
        case DEVICEUPDATE:
//            emit registrationFailed();
            break;
        default:
            break;
        }

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
        out << int(0); // packet type
        socket.write(block);
        socket.waitForBytesWritten();

        int clientID;
        if (!waitForBytesReceived(socket, sizeof(int)))
            return;

        in >> clientID;
        ClientThread::deviceID = clientID;
        emit registrationInfoReceived(clientID);

        break;
    case DEVICEUPDATE:
        out << int(1); // packet type
        out << deviceID;
        out << stateCode;
        out << errorCode;
        // fill in
        socket.write(block);
        socket.waitForBytesWritten();
        break;
    default:
        break;
    }
}

void ClientThread::config(Monitor *parent, QString address,int id)
{
    ClientThread::parent = parent;
    ClientThread::serverAddress = address;
    ClientThread::serverPort = 55555;
    ClientThread::deviceID = id;
}

void ClientThread::sendRegistrationRequest()
{
    ClientThread *ct = new ClientThread();
    connect(ct,SIGNAL(logEvent(QString)),ClientThread::parent,SLOT(onLogEvent(QString)));
    connect(ct,SIGNAL(registrationInfoReceived(int)),ClientThread::parent,SLOT(onRegistratorReceived(int)));
    connect(ct,SIGNAL(registrationFailed()),ClientThread::parent,SLOT(onRegistratorFailed()));

    ct->task = REGISTER;
    ct->start();
}

void ClientThread::sendStatusUpdate(int stateCode, int errorCode)
{
    ClientThread *ct = new ClientThread();
    connect(ct,SIGNAL(logEvent(QString)),ClientThread::parent,SLOT(onLogEvent(QString)));
//    connect(ct,SIGNAL(registrationInfoReceived(int)),ClientThread::parent,SLOT(onRegistratorReceived(int)));

    ct->task = DEVICEUPDATE;
    ct->stateCode = stateCode;
    ct->errorCode = errorCode;
    ct->start();
}


bool ClientThread::waitForBytesReceived(QTcpSocket& socket, size_t numberOfBytes)
{
    const int timeOut = 5 * 1000;
    while (socket.bytesAvailable() < (int)numberOfBytes)
    {
        if (!socket.waitForReadyRead(timeOut))
        {

            return false;
        }
    }
    return true;
}
