#ifndef NEURON_H
#define NEURON_H

#include "Edge.h"
#include "../helpers/utils.h"
#include "ActivationFunction.h"
#include "Layer.h"

#include <iostream>

#include <vector>
#include <limits>


enum ActivationFunction;

class Neuron
{

public:
	explicit Neuron(int id_neuron, Layer *layer, ActivationFunction function = LINEAR, bool is_bias = false);

	~Neuron();

	void trigger();

	double in();

	double output();

	double outputDerivative();

	double outputRaw();

	void clean();

	void addAccumulated(double v);

	void addNext(Neuron *n);

	void addPrevious(Edge *e);

	int getNeuronId() const;

	void setAccumulated(double v);

	void alterWeights(const vector<double> &weights);

	vector<double *> getWeights();

	vector<Edge *> getEdges();

	void randomizeAllWeights(double abs_value);

	string toString();

	void shiftWeights(float range);

	void shiftBackWeights(const vector<double> &range);

	vector<double> getBackPropagationShifts(const vector<double> &target);

	bool isBias() const;

public:
	Layer *_layer = NULL;
	int _id_neuron = 0;
	double _accumulated = 0.0;

	double _threshold = 0.0;
	vector<Edge *> _next;
	vector<Edge *> _previous;
	ActivationFunction _activation_function;
	bool _is_bias = false;
};

#endif // NEURON_H
