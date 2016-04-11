#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

/* Forward declarations */
namespace Ui
{
    class MainWindow;
}

class Display;
class InputController;
class CalcObject;

/* Main Window Class */
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
        std::shared_ptr<Ui::MainWindow> ui;
        std::unique_ptr<Display> p_display;
        std::unique_ptr<CalcObject> p_calc_object;
};

#endif // MAINWINDOW_H
