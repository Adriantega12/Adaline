#include "trainingplot.h"

void TrainingPlot::addPoint( double x, double y ) {
    clickedPoints->addData( x, y );
    trainingPlot->replot();
    }

TrainingPlot::TrainingPlot( QCustomPlot* plot ) {
    setup( plot );
    }

TrainingPlot::~TrainingPlot() {
    delete clickedPoints;
    delete redPoints;
    delete bluePoints;
    }

void TrainingPlot::setup( QCustomPlot* plot ) {
    trainingPlot = plot;
    clickedPoints = new QCPGraph( plot->xAxis, plot->yAxis );
    redPoints = new QCPGraph( plot->xAxis, plot->yAxis );
    bluePoints = new QCPGraph( plot->xAxis, plot->yAxis );
    }

void TrainingPlot::addRedPoint( double x, double y ) {
    redPoints->addData( x, y );
    addPoint( x, y );
    }

void TrainingPlot::addBluePoint( double x, double y ) {
    bluePoints->addData( x, y );
    addPoint( x, y );
    }
