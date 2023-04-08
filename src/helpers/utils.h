#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>
#include <utility>
#include <vector>
#include <limits>
#include <string>
#include <iostream>

using namespace std;

//Sigmoid Function
double sigmoid(double x);
double sigmoid_derivative(double x);

//Relu Function
double relu(double x);
double relu_derivative(double x);

//Random float getter function
double random(double low, double high);

double distanceVector(const vector<double> &v1, const vector<double> &v2);

#endif // FUNCTIONS_H
