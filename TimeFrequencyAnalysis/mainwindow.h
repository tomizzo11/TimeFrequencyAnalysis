#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userinputcontroller.h"

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
    UserInputController ui_controller;

};

#endif // MAINWINDOW_H
