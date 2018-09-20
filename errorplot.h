#ifndef ERRORPLOT_H
#define ERRORPLOT_H

#include "qcustomplot.h"

class ErrorPlot {
    private:
        QCustomPlot* errorPlot;

    public:
        ErrorPlot( QCustomPlot* );

        void addData( double epoch, double squaredError );
    };

#endif // ERRORPLOT_H
