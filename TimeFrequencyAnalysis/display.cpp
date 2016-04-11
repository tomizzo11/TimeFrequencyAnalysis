#include "display.h"
#include "ui_mainwindow.h"

Display::Display(std::shared_ptr<Ui::MainWindow> p_ui_in) :
    p_ui(p_ui_in)
{
}

void Display::initDisplay()
{
    /* Initialize progressBar parameters*/
    p_ui->progressBar->setMinimum(0);
    p_ui->progressBar->setMaximum(100);
    p_ui->progressBar->setValue(0);

    /* Initialize qCustomPlot */
    p_ui->customPlot->xAxis->setLabel("Frequency (Hz)");
    p_ui->customPlot->yAxis->setLabel("Relative Amplitude");
    p_ui->customPlot->xAxis->setRange(0, 20000);
    p_ui->customPlot->yAxis->setRange(0, 1000);
    p_ui->customPlot->replot();
}

void Display::updateFreqPlot(QVector<double>& x, QVector<double>& y, double max_value)
{
    p_ui->customPlot->yAxis->setRange(0, max_value);

    // create graph and assign data to it:
    p_ui->customPlot->addGraph();
    p_ui->customPlot->graph(0)->setData(x, y);
    p_ui->customPlot->replot();
}

void Display::changeText(const std::string& new_text)
{
}
