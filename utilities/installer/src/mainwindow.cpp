#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
     set any options here
     */

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
    }
}
