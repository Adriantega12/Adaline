#ifndef TRAININGPLOT_H
#define TRAININGPLOT_H

#include "qcustomplot.h"

class TrainingPlot {
    private:
        QCustomPlot* trainingPlot;

        QCPGraph* redPoints;
        QCPGraph* bluePoints;

        QVector<double> lineX;
        QVector<double> lineY;

        void addPoint( double x, double y );

    public:
        TrainingPlot( QCustomPlot* plot );
        ~TrainingPlot();

        void setup( QCustomPlot* plot );

        void updatePlot(double slope, double yIntercept);

        void addRedPoint( double x, double y );
        void addBluePoint( double x, double y );
    };

#endif // TRAININGPLOT_H
