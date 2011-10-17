#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settingsdialog.h"
#include "monitor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *action1 = new QAction("Settings",this);
    QAction *action2 = new QAction("Reset Accel",this);

    QMenu *menu = this->menuBar()->addMenu("&Main");
    menu->addAction(action1);
    connect(action1,SIGNAL(triggered()),this,SLOT(openSettingsForm()));
    menu->addAction(action2);
    connect(action2,SIGNAL(triggered()),this,SLOT(resetState()));

    monitor = new Monitor(this);
    connect(monitor,SIGNAL(logEvent(QString)),this,SLOT(onLogEvent(QString)));
    monitor->start();
}

void MainWindow::openSettingsForm()
{
    SettingsDialog *diag = new SettingsDialog();
    connect(diag,SIGNAL(settingsChanged()),monitor,SLOT(onReloadSettings()));
    diag->exec();
}

void MainWindow::resetState()
{
//    ui->eventTextBox->clear();
    monitor->resetAccel();
}

MainWindow::~MainWindow()
{
    monitor->shutDown();
    delete ui;
}

void MainWindow::onLogEvent(QString msg)
{
    ui->eventTextBox->appendPlainText(msg);
}


void MainWindow::showExpanded()
{
#ifdef Q_OS_SYMBIAN
    showFullScreen();
#elif defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
    showMaximized();
#else
    show();
#endif
}

