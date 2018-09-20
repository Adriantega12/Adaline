#include "errorplot.h"

ErrorPlot::ErrorPlot(QCustomPlot* eP) : errorPlot(eP) {
    errorPlot->addGraph();
    }

void ErrorPlot::addData(double epoch, double squaredError) {
    errorPlot->graph(0)->addData( epoch, squaredError );
    errorPlot->rescaleAxes();
    errorPlot->replot();
    }
