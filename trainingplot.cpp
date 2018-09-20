#include "trainingplot.h"

void TrainingPlot::addPoint( double x, double y ) {
    trainingPlot->replot();
    }

TrainingPlot::TrainingPlot( QCustomPlot* plot ) {
    bluePoints = new QCPGraph( plot->xAxis, plot->yAxis );
    redPoints = new QCPGraph( plot->xAxis, plot->yAxis );

    // Line
    plot->addGraph();
    lineX.push_back(-6);
    lineX.push_back(0);
    lineX.push_back(6);
    lineY.push_back(0);
    lineY.push_back(0);
    lineY.push_back(0);

    /*for ( unsigned int i = 0; i < 100; ++i ) {
        lineX.push_back( (i < 50) * (-6.0 / 100) * i + ( i >= 50 ) * ( 6.0/100 ) * i  );
        lineY.push_back(0.0);
        }*/

    setup( plot );
    }

TrainingPlot::~TrainingPlot() {

    }

void TrainingPlot::setup( QCustomPlot* plot ) {
    trainingPlot = plot;

    // Set styles for training plot
    // Margin visibility
    plot->xAxis2->setVisible(true);
    plot->yAxis2->setVisible(true);

    // Ranges
    plot->xAxis->setRange( -5.0, 5.0 );
    plot->yAxis->setRange( -5.0, 5.0 );
    plot->xAxis2->setRange( -5.0, 5.0 );
    plot->yAxis2->setRange( -5.0, 5.0 );

    // Colors of margins
    plot->xAxis->setBasePen( QPen( Qt::gray ) );
    plot->yAxis->setBasePen( QPen( Qt::gray ) );
    plot->xAxis2->setBasePen( QPen( Qt::gray ) );
    plot->yAxis2->setBasePen( QPen( Qt::gray ) );

    // Colors of axis
    plot->xAxis->grid()->setZeroLinePen( QPen( Qt::black ) );
    plot->yAxis->grid()->setZeroLinePen( QPen( Qt::black ) );

    // Set styles for inputs
    redPoints->setPen( QPen(Qt::red) );
    redPoints->setLineStyle( QCPGraph::lsNone );
    redPoints->setScatterStyle(QCPScatterStyle::ssCircle);
    bluePoints->setPen( QPen(Qt::blue) );
    bluePoints->setLineStyle( QCPGraph::lsNone );
    bluePoints->setScatterStyle(QCPScatterStyle::ssCircle);
}

void TrainingPlot::updatePlot(double slope, double yIntercept) {
    lineY[0] = lineX[0] * slope + yIntercept;
    lineY[1] = lineX[1] * slope + yIntercept;
    lineY[2] = lineX[2] * slope + yIntercept;

    /*for ( unsigned int i = 0; i < lineY.size(); ++i ) {
        lineY[i] = lineX[i] * slope + yIntercept;
        }*/

    trainingPlot->graph(2)->setData(lineX, lineY);
    trainingPlot->replot();
    trainingPlot->repaint();
    }

void TrainingPlot::addRedPoint( double x, double y ) {
    redPoints->addData( x, y );
    addPoint( x, y );
    }

void TrainingPlot::addBluePoint( double x, double y ) {
    bluePoints->addData( x, y );
    addPoint( x, y );
    }
