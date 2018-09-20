#include "trainingmodule.h"

void TrainingModule::updateLabels() {
    w0Lbl->setText( QString::number( weight0 ) );
    w1Lbl->setText( QString::number( weight1 ) );
    w2Lbl->setText( QString::number( weight2 ) );
    currentEpochLbl->setText( QString::number( currentEpoch ) );
    convergenceEpochLbl->setText( QString::number( convEpoch ) );
    }

double TrainingModule::inputAndWeightsPointProduct(double x, double y) {
    return x * weight1 + y * weight2 - weight0;
}

double TrainingModule::sigmoidFunction(double xVal) {
    return 1.0 / (1.0 + qExp( -xVal ) );
    }

double TrainingModule::activationFunctionDerivative(std::function<double(double)> activationFunction, double xVal) {
    double functionRes = activationFunction( xVal );
    return functionRes * ( 1 - functionRes );
    }

double TrainingModule::getError(Pair p, std::function<double (double)> activationFunction) {
    return p.type - activationFunction( inputAndWeightsPointProduct( p.x, p.y ) );
    }

TrainingModule::TrainingModule()
    : weight0(0.0), weight1(0.0), weight2(0.0), currentEpoch(0), convEpoch(0),
      maxEpochs(99999), learningRate(0.0), desiredError(0.0), rdg(-5.0, 5.0) {

    }

TrainingModule::~TrainingModule() {

    }

void TrainingModule::connectGUIToValues(QLabel *w0, QLabel *w1, QLabel *w2, QLabel *cE, QLabel *conv) {
    w0Lbl = w0;
    w1Lbl = w1;
    w2Lbl = w2;
    currentEpochLbl = cE;
    convergenceEpochLbl = conv;
    }

void TrainingModule::setup(unsigned int mE, double lR, double dE) {
    maxEpochs = mE;
    learningRate = lR;
    desiredError = dE;
    weight0 = rdg();
    weight1 = rdg();
    weight2 = rdg();
    }

void TrainingModule::updateValues() {

    }

void TrainingModule::updateGUI( TrainingPlot* tp ) {
    tp->updatePlot( getSlope(), getYIntercept() );
    updateLabels();
    }

void TrainingModule::train( TrainingPlot* tp ) {
    double error;
    double squaredError = 1.0;
    double actFuncDerivative;
    currentEpoch = 0;

    while (currentEpoch < maxEpochs and squaredError > desiredError) {
        squaredError = error = 0.0;
        for ( unsigned int j = 0; j < trainingSet.size(); ++j ) {
            error = getError( trainingSet[j], sigmoidFunction );
            squaredError += (error * error) / 2;
            actFuncDerivative = activationFunctionDerivative( TrainingModule::sigmoidFunction,
                                inputAndWeightsPointProduct( trainingSet[j].x, trainingSet[j].y ) );
            weight0 += learningRate * error * actFuncDerivative * (-1);
            weight1 += learningRate * error * actFuncDerivative * trainingSet[j].x;
            weight2 += learningRate * error * actFuncDerivative * trainingSet[j].y;
            }
        updateGUI( tp );
        currentEpoch++;
        qDebug() << currentEpoch << ":" << "Error:"<< error << "Error cuadrático:" << squaredError;
        }
    }

void TrainingModule::addPoint( double x, double y, int type ) {
    Pair p;
    trainingSet.push_back( p = { x, y, type } );
}

int TrainingModule::getType(double x, double y) {
    return inputAndWeightsPointProduct( x, y );
    }

double TrainingModule::getSlope() {
    return - ( weight0 / weight2 ) / ( weight0 / weight1 );
    }

double TrainingModule::getYIntercept() {
    return weight0 / weight2;
    }
