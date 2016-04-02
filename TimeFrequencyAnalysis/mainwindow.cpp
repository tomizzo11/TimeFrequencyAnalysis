#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include "qcustomplot.h"

#include "aquila/global.h"
#include "aquila/source/generator/SineGenerator.h"
#include "aquila/tools/TextPlot.h"
#include "aquila/source/WaveFile.h"
#include <string>
#include "aquila/transform/FftFactory.h"
#include "aquila/transform/Fft.h"
#include <vector>
#include <complex>
#include <string>
#include "aquila/transform/AquilaFft.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    /* create instance of widgets as defined in mainwindow.ui */
    ui->setupUi(this);

    /* Initialize progressBar parameters*/
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    /* Initialize qCustomPlot */
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(0, .15);
    ui->customPlot->yAxis->setRange(-36, 36);
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString sound_filename= QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "wav file (*.wav*)"
                );

    if (!sound_filename.isNull())
    {
        ui->filePathLabel->setText(sound_filename);
    }
}

void MainWindow::on_startButton_clicked()
{
    /* Get a file name from user inputted text */
    QString file_name = ui->filePathLabel->text();

    /* Create a wavefile object in heap, return pointer to it */
    std::unique_ptr<Aquila::WaveFile> pWaveFile(new Aquila::WaveFile(file_name.toStdString()));

    /* Get some information from the newly created wave file object */


    const std::size_t SIZE = pWaveFile->getSamplesCount();
    const Aquila::FrequencyType sampleFreq = pWaveFile->getSampleFrequency();



    /* Calculate the FFT */

        //std::shared_ptr<Aquila::Fft> pFftInterface = Aquila::FftFactory::getFft(SIZE);  // This returns a shared pointer to an FFT calculation object.
        std::unique_ptr<Aquila::AquilaFft> pAquilaFft(new Aquila::AquilaFft(SIZE));
        auto time_array = pWaveFile->toArray();

        //auto spectrum_vector = pAquilaFft->fft(pWaveFile->toArray());


        /* All this is a vector of complex type */
        //std::unique_ptr<Aquila::SpectrumType> pSpectrum(new Aquila::SpectrumType(SIZE+20000));

        /* Take the FFT object, use it to compute FFT on the wave file data in array form. BREAKS PROGRAM */
       // auto fft_vector = pFftInterface->fft(pWaveFile->toArray());  // This is the line that breaks the program


        int hi = 23;

        //  std::unique_ptr<QVector<double>> x(new QVector<double>(SIZE));
        //  std::unique_ptr<QVector<double>> y(new QVector<double>(SIZE));

       //  double maxValue = 0;
   /*      for(int i = 0; i < SIZE; i++)
        {
            (*x)[i] = i*(sampleFreq*SIZE);
            (*y)[i] = abs((*spectrum)[i]);

            if(abs((*spectrum)[i]) > maxValue)
            {
                maxValue = abs((*spectrum)[i]);
            }
        } */

        // Initialize qCustomPlot //
   /*     ui->customPlot->xAxis->setLabel("frequency");
        ui->customPlot->yAxis->setLabel("amplitude");
        ui->customPlot->xAxis->setRange(0, 3);
        ui->customPlot->yAxis->setRange(-maxValue, maxValue);
        ui->customPlot->replot(); */

 //   delete pWaveFile;
 //   delete spectrum;


    /* Initialize qCustomPlot */
    /*
    ui->customPlot->xAxis->setLabel("time");
    ui->customPlot->yAxis->setLabel("amplitude");
    ui->customPlot->xAxis->setRange(0, 3);
    ui->customPlot->yAxis->setRange(-maxValue, maxValue);
    ui->customPlot->replot();
    */

    // create graph and assign data to it:

    /*
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();

    */

    // input signal parameters

    /*
    const std::size_t SIZE = 1200;
    const Aquila::FrequencyType sampleFreq = 4000;
    const Aquila::FrequencyType f1 = 125, f2 = 700;

    Aquila::SineGenerator sineGenerator1 = Aquila::SineGenerator(sampleFreq);
    sineGenerator1.setAmplitude(32).setFrequency(f1).generate(SIZE);
    Aquila::SineGenerator sineGenerator2 = Aquila::SineGenerator(sampleFreq);
    sineGenerator2.setAmplitude(8).setFrequency(f2).setPhase(0.75).generate(SIZE);
    auto sum = sineGenerator1;// + sineGenerator2;
    */


    /*
    for(auto itr = sum.begin(); itr != sum.end(); itr++)
    {
        x[itr.getPosition()] = itr.getPosition()*(1.0/sampleFreq);
        y[itr.getPosition()] = *itr;

    }
    */

}
