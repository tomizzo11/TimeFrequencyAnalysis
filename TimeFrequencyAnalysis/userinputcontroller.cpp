#include "userinputcontroller.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

UserInputController::UserInputController(Ui::MainWindow *pui_in, MainWindow *pmw_in) :
    pui(pui_in),
    pmw(pmw_in)
{
}

void UserInputController::selectFile()
{
    QString sound_filename= QFileDialog::getOpenFileName(
                pmw,
                QObject::tr("Open File"),
                "C://",
                "wav file (*.wav*)"
                );

    if (!sound_filename.isNull())
    {
        pui->filePathLabel->setText(sound_filename);
    }
}


