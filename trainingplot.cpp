#include "trainingplot.h"

void TrainingPlot::addPoint( double x, double y ) {
    trainingPlot->replot();
    }

TrainingPlot::TrainingPlot( QCustomPlot* plot ) {
    bluePoints = new QCPGraph( plot->xAxis, plot->yAxis );
    redPoints = new QCPGraph( plot->xAxis, plot->yAxis );

    setup( plot );
    }

TrainingPlot::~TrainingPlot() {
    delete redPoints;
    delete bluePoints;
    }

void TrainingPlot::setup( QCustomPlot* plot ) {
    trainingPlot = plot;

    // Set styles
    redPoints->setPen( QPen(Qt::red) );
    redPoints->setLineStyle( QCPGraph::lsNone );
    redPoints->setScatterStyle(QCPScatterStyle::ssCircle);
    }

void TrainingPlot::addRedPoint( double x, double y ) {
    redPoints->addData( x, y );
    addPoint( x, y );
    }

void TrainingPlot::addBluePoint( double x, double y ) {
    bluePoints->addData( x, y );
    addPoint( x, y );
    }
