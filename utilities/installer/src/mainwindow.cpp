#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ff7DataInstaller.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
     set any options here
     */
#ifdef _DEBUG
    ui->lineInput->setText("C:\\Games\\FF7\\data\\");
    ui->lineOutput->setText("C:\\Users\\paul\\Desktop\\q-gears\\output\\_data\\");
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnInput_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Location of Game Data),"),QDir::homePath());
    ui->lineInput->setText(temp);
}


void MainWindow::on_btnOutput_clicked()
{
    QString temp = QFileDialog::getExistingDirectory(this,tr("Location of QGears Data),"),QDir::homePath());
    ui->lineOutput->setText(temp);
}


void MainWindow::on_btnGO_clicked()
{
    if (ui->lineInput->text().isEmpty())
    {
        QMessageBox::critical(this,tr("Input Error"),tr("No Input Provided"));
    }
    else if(ui->lineOutput->text().isEmpty())
    {
        QMessageBox::critical(this,tr("Output Error"),tr("No Output Path Provided"));
    }
    else
    {
        QMessageBox::information(this,tr("Converting Data"),tr("Attempt to convert with \n Input: %1 \n Output: %2").arg(ui->lineInput->text(),ui->lineOutput->text()));

        FF7DataInstaller conversion;
        std::vector<std::string> vec;

        // TODO: Enumerate files or find some better way to do this :)
        vec.push_back("field\\char.lgp");

        // TODO: Debug build using release qt dlls so toStdString mixes heaps and crashes
        auto qinput = ui->lineInput->text();
        std::wstring input = reinterpret_cast<wchar_t*>(qinput.data());
        auto qoutput = ui->lineOutput->text();
        std::wstring output = reinterpret_cast<wchar_t*>(qoutput.data());
        conversion.Convert(std::string(input.begin(), input.end()), std::string(output.begin(), output.end()), vec);
    }
}
