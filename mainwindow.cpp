#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    // Basic setup
    ui->setupUi(this);

    // Training plot setup
    trainingPlot = new TrainingPlot( ui->trainingPlot );
    connect( ui->trainingPlot, SIGNAL( mousePress(QMouseEvent*) ), this, SLOT( plotClick(QMouseEvent*) ) );
    }

MainWindow::~MainWindow() {
    delete trainingPlot;
    delete ui;
    }

void MainWindow::plotClick( QMouseEvent* evt ) {
    if ( ui->trainingPlot->axisRect()->rect().contains( evt->pos() ) ) {
        double x = ui->trainingPlot->xAxis->pixelToCoord( evt->x() ),
               y = ui->trainingPlot->yAxis->pixelToCoord( evt->y() );

        trainingPlot->addRedPoint( x, y );
        }
    }
