#ifndef TRAININGMODULE_H
#define TRAININGMODULE_H

#include <QDebug>

#include <vector>

class TrainingModule {
    private:
        struct Pair {
            double x;
            double y;
            int type;
            };

        std::vector<Pair> trainingSet;

    public:
        static const int RED = 0;
        static const int BLUE = 1;

        TrainingModule();

        void setup();

        void update();
        void plot();

        void train();

        void addPoint( double x, double y, int type = RED );
    };

#endif // TRAININGMODULE_H
