#ifndef TRAININGMODULE_H
#define TRAININGMODULE_H

#include <QLabel>
#include <QDebug>
#include <QtMath>

#include <vector>
#include <functional>

#include "randdouble.h"
#include "pair.h"

class TrainingModule {
    private:
        double weight0;
        double weight1;
        double weight2;

        unsigned int currentEpoch;
        unsigned int convEpoch;
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
        double inputAndWeightsPointProduct( double x, double y );
        double sigmoidFunction( double xVal );
        double getError( Pair p, std::function<double(double)> activationFunction);

    public:
        static const int RED = 0;
        static const int BLUE = 1;

        TrainingModule();
        ~TrainingModule();

        void connectGUIToValues( QLabel* w0, QLabel* w1, QLabel* w2, QLabel* cE, QLabel* conv );

        void setup(unsigned int mE, double lR, double dE);

        void updateValues();
        void updateGUI();

        void train();

        void addPoint( double x, double y, int type = RED );
    };

#endif // TRAININGMODULE_H
