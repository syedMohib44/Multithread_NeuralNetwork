#ifndef BACK_PROPOGATION
#define BACK_PROPOGATION

#include "../helpers/utils.h"
#include "../neural_network/NeuralNetwork.h"
#include "../dataset/DataSet.h"
#include "Validator.h"
#include <unordered_map>
#include <vector>

extern double LEARNING_RATE;

class BackPropagation : public Validator
{

public:
	BackPropagation();
	~BackPropagation();
	void setLearningRate(double lr);

	vector<vector<vector<double> > > getBackPropagationShifts(const vector<double> &in, const vector<double> &out);

	void backpropagate(const vector<const vector<double> *> &ins, const vector<const vector<double> *> &outs);

	vector<Layer *> getLayers();

	void minimize();

	void setBatchSize(size_t bs);

private:
	size_t _batch_size = 20;
};

#endif