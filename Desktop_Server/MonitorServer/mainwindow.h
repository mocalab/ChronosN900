#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deviceinfo.h"

namespace Ui {
    class MainWindow;
}

class  Server;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onDeviceUpdate(DeviceInfo *devUpdate);
    void onDeviceRegistered(DeviceInfo *devInfo);
    int addDevice(DeviceInfo *devInfo);

private:
    int getDeviceIndex(DeviceInfo *devInfo);
    Ui::MainWindow *ui;
    Server *server;
    int serverPort;
    int nextclientID;

    void loadSettings();
    void saveDeviceInfo();

    struct TableColumns{
        enum
        {
            DEV_ID,
            DEV_ADDR,
            DEV_STATE,
            DEV_ERROR,
            DEV_ALERT,
            RESET,
            DELETE
        };
    };

};

#endif // MAINWINDOW_H
