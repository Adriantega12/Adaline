#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>

#include "trainingplot.h"
#include "errorplot.h"
#include "trainingmodule.h"

namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        TrainingPlot* trainingPlot;
        TrainingModule* trainingModule;
        ErrorPlot* errorPlot;

    public slots:
        void plotClick( QMouseEvent* );
private slots:
        void on_initializeBttn_clicked();
        void on_trainBttn_clicked();
};

#endif // MAINWINDOW_H
