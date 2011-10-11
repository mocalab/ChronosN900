#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class Chronos;
class QTimer;
class N900Accelerometer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Chronos* chronos;
    QTimer *timer;
    N900Accelerometer *acc;

public slots:
    void log(QString msg);

private slots:
    void on_pushButton_stop_clicked();
    void on_pushButton_start_clicked();
    void accDataAvailible(int x, int y, int z);
    void timerEvent();
};

#endif // MAINWINDOW_H
