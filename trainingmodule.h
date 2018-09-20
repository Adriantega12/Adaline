#ifndef TRAININGMODULE_H
#define TRAININGMODULE_H

#include <QLabel>
#include <QDebug>
#include <QtMath>

#include <vector>
#include <functional>

#include "randdouble.h"
#include "trainingplot.h"
#include "errorplot.h"

class TrainingModule {
    private:
        struct Pair {
            double x;
            double y;
            int type;
            };

        double weight0;
        double weight1;
        double weight2;

        unsigned int currentEpoch;
        unsigned int maxEpochs;
        double learningRate;
        double desiredError;

        QLabel* w0Lbl;
        QLabel* w1Lbl;
        QLabel* w2Lbl;

        QLabel* currentEpochLbl;
        QLabel* convergenceEpochLbl;

        Rand_double rdg;

        std::vector<Pair> trainingSet;

        void updateLabels();

        // Maths
        double inputAndWeightsPointProduct(double x, double y);
        static double sigmoidFunction(double xVal);
        double activationFunctionDerivative(std::function<double (double)> activationFunction , double xVal);
        double getError(Pair p, std::function<double (double)> activationFunction);

    public:
        static const int RED = 0;
        static const int BLUE = 1;

        TrainingModule();
        ~TrainingModule();

        void connectGUIToValues( QLabel* w0, QLabel* w1, QLabel* w2, QLabel* cE, QLabel* conv );

        void setup(unsigned int mE, double lR, double dE);

        void updateValues();
        void updateGUI( TrainingPlot* tp );

        void train( TrainingPlot* tp, ErrorPlot* eP );

        void addPoint( double x, double y, int type = RED );

        double getType( double x, double y );

        double getSlope();
        double getYIntercept();
    };

#endif // TRAININGMODULE_H
