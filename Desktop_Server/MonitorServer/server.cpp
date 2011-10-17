#include "server.h"
#include "serverthread.h"
#include "mainwindow.h"

int* ServerThread::nextClientID;

Server::Server(MainWindow *parent, int port, int* nextClientID) :
        QTcpServer(parent), parent_(parent)
{
    ServerThread::nextClientID = nextClientID;
    bool s = start(port);
    int x = 111;
}

void Server::incomingConnection(int socketDescriptor)
{
    ServerThread *thread = new ServerThread(socketDescriptor, this);
    connect(thread,SIGNAL(deviceRegistered(DeviceInfo*)),parent_,SLOT(onDeviceRegistered(DeviceInfo*)));
    connect(thread,SIGNAL(deviceUpdated(DeviceInfo*)),parent_,SLOT(onDeviceUpdate(DeviceInfo*)));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

bool Server::start(quint16 port)
{
    if ( !this->isListening() )
        return listen(QHostAddress::Any, port);
    else
        return false;
}

void Server::stop()
{
    if ( this->isListening() )
        this->close();
}
