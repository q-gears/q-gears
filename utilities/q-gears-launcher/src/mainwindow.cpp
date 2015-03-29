#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ff7DataInstaller.h"
#include <QProcess>
#include <QFileDialog>
#include <QDir>
#include <QSettings>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSettings();

    ui->lineConfigDir->setText(settings->value("ConfigDir").toString());
    ui->lineDataDir->setText(settings->value("DataDir").toString());
    ui->lineQGearsExe->setText(settings->value("QGearsEXE").toString());

#ifdef _DEBUG
    // Hard coded prebaked paths for debugging to save time
    ui->lineInput->setText("C:\\Games\\FF7\\data");
    ui->lineDataDir->setText("C:\\Users\\paul\\Desktop\\q-gears\\output\\data");
#endif
}

MainWindow::~MainWindow()
{
	delete ui;
}
void MainWindow::initSettings(void)
{
    bool win=false;
    #ifdef Q_OS_WIN
        settings= new QSettings(QCoreApplication::applicationDirPath() +"/" + "launcherSettings.ini",QSettings::IniFormat);
        win=true;
    #else
        settings= new QSettings(QSettings::NativeFormat,QSettings::UserScope,"q-gears","launcher",0);
    #endif
    //Check settings
    if(settings->value("ConfigDir").isNull())
    {
        if(win){settings->setValue("ConfigDir",QString("%1/q-gears").arg(QDir::homePath()));}
        else{settings->setValue("ConfigDir",QString("%1/.q-gears").arg(QDir::homePath()));}
    }

    if(settings->value("DataDir").isNull())
    {
        if(win){settings->setValue("DataDir",QString("%1/q-gears/data").arg(QDir::homePath()));}
        else{settings->setValue("DataDir",QString("%1/.q-gears/data").arg(QDir::homePath()));}
    }

    if(settings->value("QGearsEXE").isNull())
    {
        if(win){settings->setValue("QGearsEXE",QString("%1/q-gears.exe").arg(QCoreApplication::applicationDirPath()));}
        else{settings->setValue("QGearsEXE",QString("/usr/games/q-gears"));}
    }
}

void MainWindow::on_lineConfigDir_editingFinished(){settings->setValue("ConfigDir",ui->lineConfigDir->text());}
void MainWindow::on_btnConfigDir_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Select Location of QGears Configuration Data,"),settings->value("ConfigDir").toString());
    if(!temp.isNull())
    {
        settings->setValue("ConfigDir",temp);
        ui->lineConfigDir->setText(temp);
    }

}
void MainWindow::on_lineQGearsExe_editingFinished(){settings->setValue("QGearsEXE",ui->lineQGearsExe->text());}
void MainWindow::on_btnQGearsExe_clicked()
{
    QString temp = QFileDialog::getOpenFileName(this,tr("Location of QGears Executable,"),QDir::rootPath());
    if(!temp.isNull())
    {
        settings->setValue("QGearsEXE",temp);
        ui->lineQGearsExe->setText(temp);
    }
}

void MainWindow::on_btnLaunch_clicked()
{
	QString configDir(ui->lineConfigDir->text());
	QString exe(ui->lineQGearsExe->text());

	QStringList args;
	args.append(QString("--resources-file=%1/resources.cfg").arg(ui->lineConfigDir->text()));
	args.append(QString("--config-file=%1/q-gears.cfg").arg(ui->lineConfigDir->text()));
	args.append(QString("--plugins-file=/%1/plugins.cfg").arg(ui->lineConfigDir->text()));

	// Check that the config dir is set up correctly

	QProcess qGears;
	qGears.startDetached(exe,args,configDir);

}


void MainWindow::on_btnInput_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Location of Game Data),"),QDir::homePath());
	ui->lineInput->setText(temp);
}

void MainWindow::on_lineDataDir_editingFinished(){settings->setValue("DataDir",ui->lineDataDir->text());}
void MainWindow::on_btnDataDir_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Location of QGears Data),"),settings->value("DataDir").toString());
    if(!temp.isNull())
    {
        settings->setValue("DataDir",temp);
        ui->lineDataDir->setText(temp);
    }
}



void MainWindow::on_btnGO_clicked()
{
	if (ui->lineInput->text().isEmpty())
	{
		QMessageBox::critical(this,tr("Input Error"),tr("No Input Provided"));
	}
	else if(ui->lineDataDir->text().isEmpty())
	{
		QMessageBox::critical(this,tr("Output Error"),tr("No Output Path Provided"));
	}
	else
	{
		//QMessageBox::information(this,tr("Converting Data"),tr("Attempt to convert with \n Input: %1 \n Output: %2").arg(ui->lineInput->text(),ui->lineDataDir->text()));

		QString input = QDir::fromNativeSeparators(ui->lineInput->text());
		if (!input.endsWith("/"))
		{
			input += "/";
		}

		QString output = QDir::fromNativeSeparators(ui->lineDataDir->text());
		if (!output.endsWith("/"))
		{
			output += "/";
		}

		// TODO: Enumerate files or find some better way to do this :)
		std::vector<std::string> vec;
		vec.push_back(QString("field/char.lgp").toStdString());
		vec.push_back(QString("field/flevel.lgp").toStdString());

		FF7DataInstaller conversion;
		conversion.Convert(QDir::toNativeSeparators(input).toStdString(), QDir::toNativeSeparators(output).toStdString(), vec);
	}
}

