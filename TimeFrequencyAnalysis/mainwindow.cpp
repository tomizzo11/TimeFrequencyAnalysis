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
#include "calcobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    p_display(new Display(ui)),
    p_calc_object(new CalcObject())
{
    /* create instance of widgets as defined in mainwindow.ui */
    ui->setupUi(this);

    p_display->initDisplay();
}

MainWindow::~MainWindow()
{
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

        p_display->updateFreqPlot(x, y, max_value);
}
