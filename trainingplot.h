#ifndef TRAININGPLOT_H
#define TRAININGPLOT_H

#include "qcustomplot.h"

class TrainingPlot {
    private:
        QCustomPlot* trainingPlot;

        QCPGraph* clickedPoints;
        QCPGraph* redPoints;
        QCPGraph* bluePoints;

        void addPoint( double x, double y );

    public:
        TrainingPlot( QCustomPlot* plot );
        ~TrainingPlot();

        void setup( QCustomPlot* );

        void addRedPoint( double x, double y );
        void addBluePoint( double x, double y );
    };

#endif // TRAININGPLOT_H
