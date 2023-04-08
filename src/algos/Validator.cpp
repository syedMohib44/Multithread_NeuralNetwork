#include "Validator.h"
#include <thread>


Validator::Validator()
{
	LEARNING_RATE = 1;
}


Validator::~Validator()
{
}

void Validator::minimize()
{
}

void Validator::setDataSet(DataSet* dataset)
{
	_d = dataset;
}

void Validator::setNeuralNetwork(NeuralNetwork* net)
{
	_n = net;
}


double Validator::getScore(Datatype d, int limit)
{
	return _n->predictAllForScore(*_d,d, limit);
}
