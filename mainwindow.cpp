#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    // Basic setup
    ui->setupUi(this);

    // Train plot setup
    connect( ui->trainingPlot, SIGNAL( mousePress(QMouseEvent*) ), this, SLOT( plotClick(QMouseEvent*) ) );
    }

MainWindow::~MainWindow() {
    delete ui;
    }

void MainWindow::plotClick( QMouseEvent* evt ) {
    if ( ui->trainingPlot->axisRect()->rect().contains( evt->pos() ) ) {
        double x = ui->trainingPlot->xAxis->pixelToCoord( evt->x() ),
               y = ui->trainingPlot->yAxis->pixelToCoord( evt->y() );
        }
    }
