#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>


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

private:
	//private functions;
	void initSettings(void);
	//private vars
	Ui::MainWindow *ui;
	QSettings *settings;
};

#endif // MAINWINDOW_H
