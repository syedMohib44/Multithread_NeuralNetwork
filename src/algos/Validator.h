#pragma once

#include "../dataset/DataSet.h"
#include "../neural_network/NeuralNetwork.h"

class Validator
{
public:
	Validator();
	~Validator();

	virtual void minimize();

	void setNeuralNetwork(NeuralNetwork *net);

	void setDataSet(DataSet *dataset);

	double getScore(Datatype d, int limit = -1);

protected:
	NeuralNetwork *_n;

	DataSet *_d;
};
