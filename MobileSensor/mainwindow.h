#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}



class Monitor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showExpanded();

private:
    Ui::MainWindow *ui;
    Monitor *monitor;

public slots:


private slots:
    void onLogEvent(QString event);
    void openSettingsForm();
    void resetState();
};

#endif // MAINWINDOW_H
