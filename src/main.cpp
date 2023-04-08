
#include "neural_network/NeuralNetwork.h"
#include "helpers/utils.h"
#include "algos/BackPropagation.h"
#include "algos/Shakingtree.h"
#include "dataset/DataSet.h"

#include <ctime>
#include <numeric>
#include <fstream>

#include <iostream>

#include <vector>
#include <limits>
#include <thread>
#include "algos/ThreadGuard.h"

double LEARNING_RATE = 0.5000;

//Main function
int main()
{
	NeuralNetwork neural_network;
	size_t hidden_layer = 5;
	neural_network.addLayer({{"type", LayerType::INPUT}, {"size", 2}});

	for (size_t i = 0; i < hidden_layer; i++)
		neural_network.addLayer({{"type", LayerType::HIDDEN}, {"size", 10}, {"activation", ActivationFunction::SIGMOID}});

	neural_network.addLayer({{"type", LayerType::OUTPUT}, {"size", 1}, {"activation", ActivationFunction::SIGMOID}});
	neural_network.autogenerate();

	//Creating DataSet
	DataSet data("../xor.txt");
	data.split(0.8);

	//Shaking Tree
	// Shakingtree algo;
	// algo.setNeuralNetwork(&neural_network);
	// algo.setDataSet(&data);
	// algo.mapParameters();

	BackPropagation algo;
	algo.setBatchSize(10);
	LEARNING_RATE = 5.5;
	algo.setNeuralNetwork(&neural_network);
	algo.setDataSet(&data);

	//Tune hyperparameters to get best fit of this model also try to reducre LEARNING_RATE
	//Init the main training loop (nb: need to reduce the score, score = loss)
	double reduce_amplitude = 1.1;
	int reduce_schedule = 50;
	int iteration = 50000;
	int validation_at = 10;
	double mintest = 1;
	int i = 0;
	clock_t t = clock();
	algo.backpropagate(data.getIns(TRAIN), data.getOuts(TRAIN));

	std::thread t1([&]
				   {
					   while (i < iteration)
					   {
						   //For Backpropagation: A batch is read by the validator, which then sends it to the neural network for computation and apply gradient.
						   //For ShakingTree: The general concept is to test random parameters and keep the good ones, depending on activity.
						   algo.backpropagate(data.getIns(TEST), data.getOuts(TEST));
						   // Uncomment minimize() when testing prediction socre.
						   //    algo.minimize();
						   // Validate when reach at validation point.
						   if (i % validation_at == 0)
						   {

							   std::cout << "output:" << neural_network.outputString() << std::endl;
							   //    std::cout << "output:" << neural_network.toString() << std::endl;

							   algo.backpropagate(data.getIns(TRAIN), data.getOuts(TRAIN));
							   // Dectecting prediction score.
							   //    double strain = neural_network.predictAllForScore(data, TRAIN);
							   //    double stest = neural_network.predictAllForScore(data, TEST);
							   //    mintest = stest < mintest ? stest : mintest;
							   //    std::cout << "itteration:" << i << "\n"
							   // 			 << "test_score:" << stest << "\ntrain_score:" << strain << "\nbest_test_score:" << mintest << "\n"
							   // 			 << std::endl;
						   }
						   if (i % reduce_schedule == 0)
						   {
							   LEARNING_RATE = LEARNING_RATE * reduce_amplitude;
							   //    cout << LEARNING_RATE << endl;
						   }
						   i++;
					   }
				   });

	Thread_guard tg(t1);
	return 0;
}

// g++ -std=c++11 ./helpers/utils.cpp ./algos/Validator.cpp ./dataset/DataSet.cpp ./algos/BackPropagation.cpp ./neural_network/Layer.cpp ./neural_network/Neuron.cpp ./neural_network/NeuralNetwork.cpp ./neural_network/Edge.cpp ./algos/ThreadGuard.cpp ./main.cpp  -o ./main