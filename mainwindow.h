#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "trainingplot.h"
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

    public slots:
        void plotClick( QMouseEvent* );
    };

#endif // MAINWINDOW_H
