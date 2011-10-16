#include "server.h"
#include "serverthread.h"
#include "mainwindow.h"

int* ServerThread::nextClientID;

Server::Server(MainWindow *parent, int port, int* nextClientID) :
        QTcpServer(parent), parent_(parent)
{
    ServerThread::nextClientID = nextClientID;
    this->start(port);
}

void Server::incomingConnection(int socketDescriptor)
{
    ServerThread *thread = new ServerThread(socketDescriptor, this);
    connect(thread,SIGNAL(packetReceived()),parent_,SLOT(packetReceived()));
    connect(thread,SIGNAL(packetSent()),parent_,SLOT(packetSent()));
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
