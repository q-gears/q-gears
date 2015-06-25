#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ff7DataInstaller.h"
#include <QProcess>
#include <QFileDialog>
#include <QDir>
#include <QSettings>
#include <QMessageBox>
#include <QTimer>

static bool installerCreated = false;

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), mUi(new Ui::MainWindow)
{
    mUi->setupUi(this);

    // Goto the data tab by default
    mUi->tabWidget->setCurrentIndex(1);

    // Turn off the launcher tab for now since it dosen't actually work
    mUi->tabWidget->setTabEnabled(0, false);

    initSettings();

    mUi->lineConfigDir->setText(mSettings->value("ConfigDir").toString());
    mUi->lineDataDir->setText(mSettings->value("DataDir").toString());
    mUi->lineQGearsExe->setText(mSettings->value("QGearsEXE").toString());

#ifdef _DEBUG
    // Hard coded prebaked paths for debugging to save time
    mUi->lineInput->setText("C:\\Games\\FF7\\data");
    mUi->lineDataDir->setText("C:\\Users\\paul\\Desktop\\q-gears\\output\\data");
#endif

    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(DoProgress()));
}

MainWindow::~MainWindow()
{
	delete mUi;
}
void MainWindow::initSettings(void)
{
    bool win=false;
    #ifdef Q_OS_WIN
        mSettings= new QSettings(QCoreApplication::applicationDirPath() +"/" + "launcherSettings.ini",QSettings::IniFormat);
        win=true;
    #else
        mSettings= new QSettings(QSettings::NativeFormat,QSettings::UserScope,"q-gears","launcher",0);
    #endif
    //Check settings
    if(mSettings->value("ConfigDir").isNull())
    {
        if(win){mSettings->setValue("ConfigDir",QString("%1/q-gears").arg(QDir::homePath()));}
        else{mSettings->setValue("ConfigDir",QString("%1/.q-gears").arg(QDir::homePath()));}
    }

    if(mSettings->value("DataDir").isNull())
    {
        if(win){mSettings->setValue("DataDir",QString("%1/q-gears/data").arg(QDir::homePath()));}
        else{mSettings->setValue("DataDir",QString("%1/.q-gears/data").arg(QDir::homePath()));}
    }

    if(mSettings->value("QGearsEXE").isNull())
    {
        if(win){mSettings->setValue("QGearsEXE",QString("%1/q-gears.exe").arg(QCoreApplication::applicationDirPath()));}
        else{mSettings->setValue("QGearsEXE",QString("/usr/games/q-gears"));}
    }
}

void MainWindow::on_lineConfigDir_editingFinished(){mSettings->setValue("ConfigDir",mUi->lineConfigDir->text());}
void MainWindow::on_btnConfigDir_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Select Location of QGears Configuration Data,"),mSettings->value("ConfigDir").toString());
    if(!temp.isNull())
    {
        mSettings->setValue("ConfigDir",temp);
        mUi->lineConfigDir->setText(temp);
    }

}
void MainWindow::on_lineQGearsExe_editingFinished(){mSettings->setValue("QGearsEXE",mUi->lineQGearsExe->text());}
void MainWindow::on_btnQGearsExe_clicked()
{
    QString temp = QFileDialog::getOpenFileName(this,tr("Location of QGears Executable,"),QDir::rootPath());
    if(!temp.isNull())
    {
        mSettings->setValue("QGearsEXE",temp);
        mUi->lineQGearsExe->setText(temp);
    }
}

void MainWindow::on_btnLaunch_clicked()
{
	QString configDir(mUi->lineConfigDir->text());
	QString exe(mUi->lineQGearsExe->text());

	QStringList args;
	args.append(QString("--resources-file=%1/resources.cfg").arg(mUi->lineConfigDir->text()));
	args.append(QString("--config-file=%1/q-gears.cfg").arg(mUi->lineConfigDir->text()));
	args.append(QString("--plugins-file=/%1/plugins.cfg").arg(mUi->lineConfigDir->text()));

	// Check that the config dir is set up correctly

	QProcess qGears;
	qGears.startDetached(exe,args,configDir);

}


void MainWindow::on_btnInput_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Location of Game Data),"),QDir::homePath());
	mUi->lineInput->setText(temp);
}

void MainWindow::on_lineDataDir_editingFinished(){mSettings->setValue("DataDir",mUi->lineDataDir->text());}
void MainWindow::on_btnDataDir_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Location of QGears Data),"),mSettings->value("DataDir").toString());
    if(!temp.isNull())
    {
        mSettings->setValue("DataDir",temp);
        mUi->lineDataDir->setText(temp);
    }
}



void MainWindow::on_btnGO_clicked()
{
    if (mUi->lineInput->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Input error"), tr("No input to installed FF7 PC data provided"));
    }
    else if (mUi->lineDataDir->text().isEmpty())
    {
        QMessageBox::critical(this, tr("Output error"), tr("No output path provided"));
    }
    else
    {
        // Normalize the paths so its in / format seperators
        QString input = QDir::fromNativeSeparators(mUi->lineInput->text());
        if (!input.endsWith("/"))
        {
            input += "/";
        }

        QString output = QDir::fromNativeSeparators(mUi->lineDataDir->text());
        if (!output.endsWith("/"))
        {
            output += "/";
        }

        // TODO: Enumerate files or find some better way to do this :)
        const std::vector<std::string> requiredFiles = 
        {
            "field/char.lgp",
            "field/flevel.lgp"
        };

        // Ensure required files are in the input dir
        for (auto& file : requiredFiles)
        {
            QString fullPath = input + QString::fromStdString(file);
            if (!QFile::exists(fullPath))
            {
                QMessageBox::critical(this, tr("Missing input file"), tr("File not found: ") + fullPath);
                return;
            }
        }

        if (installerCreated)
        {
            QMessageBox::critical(this, tr("Error"), tr("Due to use of singletons install function can only be used once, please restart the application :("));
            return;
        }

        // Start data conversion
        try
        {
            installerCreated = true;
            mInstaller = std::make_unique<FF7DataInstaller>(
                QDir::toNativeSeparators(input).toStdString(), 
                QDir::toNativeSeparators(output).toStdString(),
                [this](std::string outputLine)
                {
                mUi->txtOutput->append(outputLine.c_str());
                } );
            OnInstallStarted();
        }
        catch (const std::exception&)
        {
            OnInstallStopped();
        }
    }
}

void MainWindow::EnableUi(bool enable)
{
    mUi->btnGO->setEnabled(enable);
    mUi->lineInput->setEnabled(enable);
    mUi->btnInput->setEnabled(enable);
    mUi->lineDataDir->setEnabled(enable);
    mUi->btnDataDir->setEnabled(enable);
    mUi->progressBar->setValue(0);
    if (!enable)
    {
        mTimer->start(0);
    }
    else
    {
        mTimer->stop();
    }
}

void MainWindow::OnInstallStarted()
{
    EnableUi(false);
}

void MainWindow::OnInstallStopped()
{
    EnableUi(true);
}

void MainWindow::DoProgress()
{
    try
    {
        const int progress = mInstaller->Progress();
        mUi->progressBar->setValue(progress);
        if (progress >= 100)
        {
            OnInstallStopped();
        }
    }
    catch (const std::exception& ex)
    {
        OnInstallStopped();
        QMessageBox::critical(this, tr("Data conversion exception"), ex.what());
    }
}
