#ifndef TRAININGMODULE_H
#define TRAININGMODULE_H

#include <QLabel>
#include <QDebug>

#include <vector>

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
        unsigned int convEpoch;
        unsigned int maxEpochs;
        double learningRate;
        double desiredError;

        QLabel* w0Lbl;
        QLabel* w1Lbl;
        QLabel* w2Lbl;

        QLabel* currentEpochLbl;
        QLabel* convergenceEpochLbl;

        std::vector<Pair> trainingSet;

        void updateLabels();

    public:
        static const int RED = 0;
        static const int BLUE = 1;

        TrainingModule();

        void connectGUIToValues( QLabel* w0, QLabel* w1, QLabel* w2, QLabel* cE, QLabel* conv );

        void setup(unsigned int mE, double lR, double dE);

        void updateValues();
        void updateGUI();

        void train();

        void addPoint( double x, double y, int type = RED );
    };

#endif // TRAININGMODULE_H
