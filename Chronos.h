#ifndef CHRONOS_H
#define CHRONOS_H

#include <QThread>
class UnixSerialInterface;

class Chronos : public QThread
{
    Q_OBJECT
public:
    Chronos(QObject *parent);
    ~Chronos();
    bool connect();
    void setEnabled(bool status);

signals:
    void accDataAvailible(int x, int y, int z);
    void log(QString msg);
private:
    void run();
    UnixSerialInterface* serial;
    char buffer[64];
    bool enabled;
};

#endif // CHRONOS_H
