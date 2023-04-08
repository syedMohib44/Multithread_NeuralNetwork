#pragma once

#include <vector>

using namespace std;

enum Datatype
{
	TRAIN,
	TEST
};

class DataSet
{
public:
	DataSet(string filename);
	~DataSet();

	const vector<const vector<double> *> &getIns(Datatype d) const;

	const vector<const vector<double> *> &getOuts(Datatype d) const;

	void split(double ptrain);

private:
	vector<vector<double> > _ins;
	vector<vector<double> > _outs;

	vector<const vector<double> *> _train_ins;
	vector<const vector<double> *> _train_outs;

	vector<const vector<double> *> _test_ins;
	vector<const vector<double> *> _test_outs;
};
