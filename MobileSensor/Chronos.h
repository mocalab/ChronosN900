#ifndef CHRONOS_H
#define CHRONOS_H

#include <QThread>
class UnixSerialInterface;
class QTimer;

class Chronos : public QThread
{
    Q_OBJECT
public:
    Chronos(QObject *parent=0);
    ~Chronos();
    bool connectPort();
    void setEnabled(bool status);

public slots:
    void timerTick();

signals:
    void deviceAvailible();
    void deviceUnAvailible();
    void accDataAvailible(int x, int y, int z);
    void logEvent(QString msg);
private:
    void run();
    UnixSerialInterface* serial;
    char buffer[64];
    bool enabled;
    int packetsMissed;
    int packetsReceived;
    int ChronosTimeoutLimit;
    QTimer *timer;

};

#endif // CHRONOS_H
