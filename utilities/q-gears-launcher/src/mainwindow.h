#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
	void on_btnConfigDir_clicked();
	void on_btnLaunch_clicked();
	void on_btnQGearsExe_clicked();
	void on_btnInput_clicked();
	void on_btnOutput_clicked();
	void on_btnGO_clicked();
private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
