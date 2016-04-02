#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aquila/transform/FftFactory.h"
#include "aquila/transform/Fft.h"
#include "aquila/source/WaveFile.h"

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

    void on_loadButton_clicked();
    void on_startButton_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
