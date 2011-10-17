#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

signals:
    void settingsChanged();


private slots:
    void on_buttonBox_accepted();

private:
    Ui::SettingsDialog *ui;
    void loadSettings();
    void saveSettings();
};

#endif // SETTINGSDIALOG_H
