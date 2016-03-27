#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T16:08:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TimeFrequencyAnalysis
TEMPLATE = app


SOURCES +=  main.cpp\
            mainwindow.cpp \
            qcustomplot.cpp

HEADERS  += mainwindow.h \
            qcustomplot.h

FORMS    += \
    mainwindow.ui
