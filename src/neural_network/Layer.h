#ifndef LAYER_H
#define LAYER_H

#include "Neuron.h"
#include <unordered_map>

#include <iostream>

#include <vector>
#include <limits>

enum LayerType
{
	HIDDEN = 0, // Standard layer : fully connected perceptrons
	OUTPUT,		  // Output : No bias neuron
	INPUT,		  // Input: Standard input (output of neurons is outputRaw() )
	SOFTMAX		  // K-Class Classification Layer

};

enum ActivationFunction;

//Layer of the network
class Layer
{
public:
	Layer(int id_layer, NeuralNetwork *net, unordered_map<string, double> parameters);

	~Layer();

	int getId() const;

	void initLayer();

	void clean();

	void trigger();

	void connectComplete(Layer *next);

	vector<double> output();

	const vector<Neuron *> &neurons() const;

	void alterWeights(const vector<vector<double> > &weights);

	void shiftBackWeights(const vector<vector<double> > &weights);

	vector<vector<double *> > getWeights();

	vector<vector<Edge *> > getEdges();

	void randomizeAllWeights(double abs_value);

	string toString();

	void shiftWeights(float range);

	const unordered_map<string, double> &getParameters() const;

	vector<vector<double> > getBackPropagationShifts(const vector<double> &target);

	LayerType getType() const;

	ActivationFunction getActivation() const;

	NeuralNetwork *getNet() const;

public:
	NeuralNetwork *_net;
	int _id_layer;
	vector<Neuron *> _neurons;
	LayerType _type;
	ActivationFunction _activation;
	unordered_map<string, double> _parameters;
};

#endif // LAYER_H
