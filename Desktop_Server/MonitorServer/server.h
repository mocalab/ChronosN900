#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

class MainWindow;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(MainWindow *paren,int port, int* nextClientID);
    void stop();
    MainWindow *parent_;

protected:
    bool start(quint16 port);
    void incomingConnection(int socketDescriptor);
};

#endif // TCPSERVER_H
