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
#include <string>
#include "aquila/transform/AquilaFft.h"
#include <cstring>

#include "display.h"
#include "uiprocessor.h"
#include "calcobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    p_display(new Display(ui)),
    p_ui_processor(new UIProcessor()),
    p_calc_object(new CalcObject())
{

    /* create instance of widgets as defined in mainwindow.ui */
    ui->setupUi(this);

    /* Initialize progressBar parameters*/
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    /* Initialize qCustomPlot */
    ui->customPlot->xAxis->setLabel("Frequency (Hz)");
    ui->customPlot->yAxis->setLabel("Relative Amplitude");
    ui->customPlot->xAxis->setRange(0, 20000);
    ui->customPlot->yAxis->setRange(0, 1000);
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    /*
    QString sound_filename= QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "wav file (*.wav*)"
                );

    if (!sound_filename.isNull())
    {
        ui->filePathLabel->setText(sound_filename);
    } */
}

void MainWindow::on_startButton_clicked()
{
    /* Get a file name from user inputted text */
    QString file_name = ui->filePathLabel->text();

    /* create wave object */
    Aquila::WaveFile wave_object(file_name.toStdString());

    /* Get some information from the newly created wave file object */
    const std::size_t total_samples = wave_object.getSamplesCount();
    const Aquila::FrequencyType sample_freq = wave_object.getSampleFrequency();
    int bps = wave_object.getBitsPerSample();
    int samples = wave_object.getSamplesCount();
    ui->filePathLabel->setText(QString::fromStdString(std::to_string(samples)));

    /* sample window */
    int window_size = 16384;
        //window_size = 32768;

    /* Calculate the FFT */
    std::shared_ptr<Aquila::Fft> p_fft_interface = Aquila::FftFactory::getFft(window_size);  // This returns a shared pointer to an FFT calculation object.
    auto spectrum = p_fft_interface->fft(wave_object.toArray()+90000);

        QVector<double> x(window_size);
        QVector<double> y(window_size);

        double max_value = 0;
        /* for(int i = 0; i < window_size; i++)
        {
            x[i] = i*(sample_freq/window_size);
            y[i] = abs(spectrum[i]);

            if(abs(spectrum[i]) > max_value)
            {
                max_value = abs(spectrum[i]);
            }
        } */

        /* Iterator based loop */

        double i = 0;

        for(auto itr = wave_object.begin(); itr.getPosition() < window_size; itr++)
        {

            i = itr.getPosition();

            x[i] = i*sample_freq/window_size;
            y[i] = abs(spectrum[i]);

            if(abs(spectrum[i]) > max_value)
            {
                max_value = abs(spectrum[i]);
            }
        }

        // Initialize qCustomPlot //
        //ui->customPlot->xAxis->setRange(0, 20000);
        ui->customPlot->yAxis->setRange(0, max_value);
        ui->customPlot->replot();

        // create graph and assign data to it:
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->replot();

}
