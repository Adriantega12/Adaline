#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    // Basic setup
    ui->setupUi(this);

    // Training module setup
    trainingModule = new TrainingModule;
    trainingModule->connectGUIToValues( ui->weight0Val,
                                        ui->weight1Val,
                                        ui->weight2Val,
                                        ui->currentEpochVal,
                                        ui->convergenceEpochVal );

    // Training plot setup
    trainingPlot = new TrainingPlot( ui->trainingPlot );
    connect( ui->trainingPlot, SIGNAL( mousePress(QMouseEvent*) ), this, SLOT( plotClick(QMouseEvent*) ) );
    }

MainWindow::~MainWindow() {
    delete trainingPlot;
    delete trainingModule;
    delete ui;
    }

void MainWindow::plotClick( QMouseEvent* evt ) {
    if ( ui->trainingPlot->axisRect()->rect().contains( evt->pos() ) ) {
        double x = ui->trainingPlot->xAxis->pixelToCoord( evt->x() ),
               y = ui->trainingPlot->yAxis->pixelToCoord( evt->y() );

        // Add points according to the selected class
        if ( ui->redRB->isChecked() ) {
            trainingPlot->addRedPoint( x, y );
            trainingModule->addPoint( x, y, TrainingModule::RED );
            }
        else if ( ui->blueRB->isChecked() ) {
            trainingPlot->addBluePoint( x, y );
            trainingModule->addPoint( x, y, TrainingModule::BLUE );
            }
        }
    }

void MainWindow::on_initializeBttn_clicked() {
    trainingModule->setup( ui->maxEpochsSB->value(), ui->learnRateSB->value(), ui->desiredErrorSB->value() );
    trainingModule->updateGUI();
    }
