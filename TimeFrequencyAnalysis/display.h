#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <memory>

/* Forward declarations */
namespace Ui
{
    class MainWindow;
}

class Display
{
    public:
        Display(Ui::MainWindow* p_ui_in);
        void InitDisplay();
        void ChangeText(const std::string& new_text);

    private:
        std::shared_ptr<Ui::MainWindow> p_ui;
};

#endif // DISPLAY_H
