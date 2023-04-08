#ifndef SHAKING_TREE
#define SHAKING_TREE

#include "Validator.h"
#include <vector>
#include <random>

class Shakingtree : public Validator
{
public:
	Shakingtree();
	~Shakingtree();

	void minimize();

	void minimizeBasic(int _batch_size = 10);

	void minimizeBasicLarger(int _batch_size = 70);

	void minimizeComplex();

	void minimizeBasicPerLayer();

	void mapParameters();

public:
	default_random_engine _generator;
	vector<Edge *> _p;
	vector<vector<Edge *> > _p2;
	vector<uint> _p_ids;

	vector<vector<double> > _shift;
	vector<double> _delta_score;
	int _itmod = 10; //state how much test you want to accumulate before accepting the delta score
	double _step = 0.05;

	uint _total_iter = 0;
	uint _nogoodscore_iter = 0;
};
#endif