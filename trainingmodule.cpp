#include "trainingmodule.h"

TrainingModule::TrainingModule() {

    }

void TrainingModule::setup() {

    }

void TrainingModule::update() {

    }

void TrainingModule::plot() {

    }

void TrainingModule::train() {

    }

void TrainingModule::addPoint( double x, double y, int type ) {
    Pair p;
    trainingSet.push_back( p = { x, y, type } );
    qDebug() << p.x << " " << p.y << " " << p.type;
    }
