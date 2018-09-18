#-------------------------------------------------
#
# Project created by QtCreator 2018-09-15T16:40:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Adaline
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    trainingplot.cpp \
<<<<<<< HEAD
    trainingmodule.cpp \
    adaline.cpp \
    perceptron.cpp
=======
    trainingmodule.cpp
>>>>>>> parent of 87f3c46... Add Adaline operations

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    trainingplot.h \
    trainingmodule.h \
<<<<<<< HEAD
    randdouble.h \
    adaline.h \
    perceptron.h \
    neuron.h \
    pair.h
=======
    randdouble.h
>>>>>>> parent of 87f3c46... Add Adaline operations

FORMS += \
        mainwindow.ui
