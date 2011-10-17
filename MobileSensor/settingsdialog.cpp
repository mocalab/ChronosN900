#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QSettings>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::loadSettings()
{
    QSettings settings("company","MonitorApp");
    QString server = settings.value("serverAddress","192.168.0.6").toString();
    ui->serverAddress->setText(server);
}

void SettingsDialog::saveSettings()
{
    QSettings settings("company","MonitorApp");
    QString server = ui->serverAddress->text();
    settings.setValue("serverAddress",server);
}

void SettingsDialog::on_buttonBox_accepted()
{
    saveSettings();
    emit settingsChanged();
}
