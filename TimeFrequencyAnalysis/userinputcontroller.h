#ifndef USERINPUTCONTROLLER_H
#define USERINPUTCONTROLLER_H

/* Forward Declarations */
namespace Ui {
class MainWindow;
}

class MainWindow;

/* UserInputController Class Definition */
class UserInputController
{
public:
    UserInputController(Ui::MainWindow *pui_in, MainWindow *pmw_in);
    void selectFile();

private:
    Ui::MainWindow *pui;
    MainWindow *pmw;
};

#endif // USERINPUTCONTROLLER_H
