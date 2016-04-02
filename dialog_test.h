#ifndef DIALOG_TEST_H
#define DIALOG_TEST_H

#include <QWidget>

namespace Ui {
class dialog_test;
}

class dialog_test : public QWidget
{
    Q_OBJECT

public:
    explicit dialog_test(QWidget *parent = 0);
    ~dialog_test();

private:
    Ui::dialog_test *ui;
};

#endif // DIALOG_TEST_H
