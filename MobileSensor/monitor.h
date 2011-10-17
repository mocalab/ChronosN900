#ifndef MONITOR_H
#define MONITOR_H

#include <QObject>

class Chronos;
class ClientThread;
class N900Accelerometer;

class Monitor : public QObject
{
    Q_OBJECT
public:
    Monitor(QObject *parent=0);
    void start();
    void shutDown();
    void resetAccel();

signals:
    void logEvent(QString event);

public slots:
    void onReloadSettings();

private slots:
    void onLogEvent(QString event);
    void onRegistratorReceived(int id);
    void onRegistratorFailed();
    void onChronosAvailible();
    void onChronosUnAvailible();
    void onDeviceMoved();

private:
    Chronos *chronos;
    N900Accelerometer *accel;
    ClientThread *client;

    void startChronosProcess();

    QString serverAddress;
    bool deviceOK;
};

#endif // MONITOR_H
