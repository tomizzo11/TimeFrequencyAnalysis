#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T16:08:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

TARGET = TimeFrequencyAnalysis
TEMPLATE = app


SOURCES +=  main.cpp\
            mainwindow.cpp \
            qcustomplot.cpp \
    uiprocessor.cpp \
    display.cpp \
    calcobject.cpp

HEADERS  += mainwindow.h \
            qcustomplot.h \
    aquila/source/generator/Generator.h \
    aquila/source/generator/PinkNoiseGenerator.h \
    aquila/source/generator/SineGenerator.h \
    aquila/source/generator/SquareGenerator.h \
    aquila/source/generator/TriangleGenerator.h \
    aquila/source/generator/WhiteNoiseGenerator.h \
    aquila/ml/Dtw.h \
    aquila/ml/DtwPoint.h \
    aquila/source/window/BarlettWindow.h \
    aquila/source/window/BlackmanWindow.h \
    aquila/source/window/FlattopWindow.h \
    aquila/source/window/GaussianWindow.h \
    aquila/source/window/HammingWindow.h \
    aquila/source/window/HannWindow.h \
    aquila/source/window/RectangularWindow.h \
    aquila/source/Frame.h \
    aquila/source/FramesCollection.h \
    aquila/source/PlainTextFile.h \
    aquila/source/RawPcmFile.h \
    aquila/source/SignalSource.h \
    aquila/source/WaveFile.h \
    aquila/source/WaveFileHandler.h \
    aquila/synth/KarplusStrongSynthesizer.h \
    aquila/synth/SineSynthesizer.h \
    aquila/synth/Synthesizer.h \
    aquila/tools/TextPlot.h \
    aquila/transform/AquilaFft.h \
    aquila/transform/Dct.h \
    aquila/transform/Dft.h \
    aquila/transform/Fft.h \
    aquila/transform/FftFactory.h \
    aquila/transform/Mfcc.h \
    aquila/transform/OouraFft.h \
    aquila/transform/Spectrogram.h \
    aquila/wrappers/SoundBufferAdapter.h \
    uiprocessor.h \
    display.h \
    calcobject.h

FORMS    += \
    mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../AquilPractice/aquila-build/release/ -lAquila
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../AquilPractice/aquila-build/debug/ -lAquila
else:unix: LIBS += -L$$PWD/../../AquilPractice/aquila-build/ -lAquila

INCLUDEPATH += $$PWD/../../AquilPractice/aquila-build
DEPENDPATH += $$PWD/../../AquilPractice/aquila-build

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/release/libAquila.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/debug/libAquila.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/release/Aquila.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/debug/Aquila.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/libAquila.a

OTHER_FILES += \
    ../../AquilPractice/aquila-build/libAquila.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../AquilPractice/aquila-build/lib/release/ -lOoura_fft
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../AquilPractice/aquila-build/lib/debug/ -lOoura_fft
else:unix: LIBS += -L$$PWD/../../AquilPractice/aquila-build/lib/ -lOoura_fft

INCLUDEPATH += $$PWD/../../AquilPractice/aquila-build
DEPENDPATH += $$PWD/../../AquilPractice/aquila-build

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/lib/release/libOoura_fft.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/lib/debug/libOoura_fft.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/lib/release/Ooura_fft.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/lib/debug/Ooura_fft.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../AquilPractice/aquila-build/lib/libOoura_fft.a
