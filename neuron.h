#ifndef NEURON_H
#define NEURON_H



class Neuron {
    public:
        Neuron();

        virtual double getError() = 0;
    };

#endif // NEURON_H
