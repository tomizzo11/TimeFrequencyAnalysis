#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <memory>
#include <QVector>

/* Forward declarations */
namespace Ui
{
    class MainWindow;
}

class Display
{
    public:
        Display(std::shared_ptr<Ui::MainWindow> p_ui_in);
        void initDisplay();
        void updateFreqPlot(QVector<double>& x, QVector<double>& y, double max_value);
        void changeText(const std::string& new_text);

    private:
        std::shared_ptr<Ui::MainWindow> p_ui;
};

#endif // DISPLAY_H
