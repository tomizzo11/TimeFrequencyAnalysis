/********************************************************************************
** Form generated from reading UI file 'test_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_DIALOG_H
#define UI_TEST_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearButton;
    QPushButton *closeButton;

    void setupUi(QWidget *test_dialog)
    {
        if (test_dialog->objectName().isEmpty())
            test_dialog->setObjectName(QStringLiteral("test_dialog"));
        test_dialog->resize(332, 167);
        verticalLayout = new QVBoxLayout(test_dialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(test_dialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        clearButton = new QPushButton(test_dialog);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        closeButton = new QPushButton(test_dialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(test_dialog);

        QMetaObject::connectSlotsByName(test_dialog);
    } // setupUi

    void retranslateUi(QWidget *test_dialog)
    {
        test_dialog->setWindowTitle(QApplication::translate("test_dialog", "Form", 0));
        clearButton->setText(QApplication::translate("test_dialog", "Clear", 0));
        closeButton->setText(QApplication::translate("test_dialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class test_dialog: public Ui_test_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_DIALOG_H
