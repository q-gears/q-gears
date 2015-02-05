#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
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
    void on_btnInput_clicked();

    void on_btnOutput_clicked();

    void on_btnGO_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
