#include "dialog_test.h"
#include "ui_dialog_test.h"

dialog_test::dialog_test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog_test)
{
    ui->setupUi(this);
}

dialog_test::~dialog_test()
{
    delete ui;
}
