#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    private slots:
    void on_lineConfigDir_editingFinished();
    void on_btnConfigDir_clicked();

    void on_lineQGearsExe_editingFinished();
    void on_btnQGearsExe_clicked();

    void on_btnLaunch_clicked();

    void on_btnInput_clicked();

    void on_lineDataDir_editingFinished();
    void on_btnDataDir_clicked();

    void on_btnGO_clicked();

private slots:
    void DoProgress();

private:
    void EnableUi(bool enable);
    void OnInstallStarted();
    void OnInstallStopped();
    void initSettings(void);
private:
    Ui::MainWindow* mUi;
    QTimer* mTimer;
    QSettings *mSettings;
    std::unique_ptr<class FF7DataInstaller> mInstaller;
};

#endif // MAINWINDOW_H
