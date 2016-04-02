/********************************************************************************
** Form generated from reading UI file 'mainwindow_test.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_TEST_H
#define UI_MAINWINDOW_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWindow_Size;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadButton;
    QLabel *filePathLabel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *startButton;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(588, 406);
        MainWindow->setMinimumSize(QSize(588, 406));
        MainWindow->setMaximumSize(QSize(588, 406));
        actionWindow_Size = new QAction(MainWindow);
        actionWindow_Size->setObjectName(QStringLiteral("actionWindow_Size"));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setMaximumSize(QSize(588, 16777215));
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        customPlot = new QCustomPlot(widget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(0, 250));

        verticalLayout_2->addWidget(customPlot);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 65));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 2, 3, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        loadButton = new QPushButton(frame);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy);
        loadButton->setMinimumSize(QSize(100, 27));
        loadButton->setMaximumSize(QSize(100, 27));

        horizontalLayout->addWidget(loadButton);

        filePathLabel = new QLabel(frame);
        filePathLabel->setObjectName(QStringLiteral("filePathLabel"));
        filePathLabel->setMinimumSize(QSize(0, 27));
        filePathLabel->setMaximumSize(QSize(16777215, 27));
        QFont font;
        font.setPointSize(12);
        filePathLabel->setFont(font);
        filePathLabel->setFrameShape(QFrame::Panel);
        filePathLabel->setFrameShadow(QFrame::Sunken);
        filePathLabel->setAlignment(Qt::AlignCenter);
        filePathLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable|Qt::TextSelectableByMouse);

        horizontalLayout->addWidget(filePathLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        startButton = new QPushButton(frame);
        startButton->setObjectName(QStringLiteral("startButton"));
        sizePolicy.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy);
        startButton->setMinimumSize(QSize(100, 27));
        startButton->setMaximumSize(QSize(100, 27));
        startButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(startButton);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_3->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_3);

        filePathLabel->raise();

        verticalLayout_2->addWidget(frame);

        MainWindow->setCentralWidget(widget);
        customPlot->raise();
        frame->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 588, 25));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionWindow_Size);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionWindow_Size->setText(QApplication::translate("MainWindow", "Window Size", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load File", 0));
        filePathLabel->setText(QApplication::translate("MainWindow", "Please load file", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_TEST_H
