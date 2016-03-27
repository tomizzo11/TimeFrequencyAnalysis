#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /* create instance of widgets as defined in mainwindow.ui */
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString soundfilename1 = ui->filePathLabel->text();
    QString soundfilename2 = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*)"
                );

    if(!soundfilename2.isNull())
    {
        ui->filePathLabel->setText(soundfilename2);
    }
    else
    {
        ui->filePathLabel->setText(soundfilename1);
    }
}

void MainWindow::on_startButton_clicked()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
}
