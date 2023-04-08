# NeuralNetworkCpp
Multithreaded neural network implementation using C++

## Framework Design
### 1. Folders (latest version)
- neural_network: Contains classes related to the neural network
- dataset: Contains one simple dataset class
- algos: Contains a generic validator class, a classical backpropagation optimization
- helpers: Contains activation utils functions and their derivatives

### 2. Neural Network Classes
- Edge.h/.cpp: An Edge knows its next neuron (_n), the neuron its coming from (_nb), it has a weight (_w), it can memorize how much its weight was shift (_last_shift) last time it was, and it has a backpropagation memory so that it can retain a part of the chain rule to avoid useless computations
- NeuralNetwork.h/.cpp: the main class containing a model. A NeuralNetwork is composed of multiple layers
- Layer.h/.cpp: A Layer is composed of multiple neurons. It has a type (INPUT/HIDDEN/OUTPUT) because it doesn’t work the same way depending on its type and it has an activation function
- Neuron.h/.cpp: A Neuron has a parent layer. A neuron accumulates the input of the neurons connected to it (_accumulated), it outputs that input to its edges after processing it with its _activation_function (which you can change on a per-neuron basis). A neuron knows its _next and _previous edges.

### 3. DataSet / Algos
- DataSet.h/.cpp: It gives the data. One input/output is just a vector (again, no matrices, no images). So the list of all inputs is a vector of vector. The DataSet class is also responsible for doing the train/test split.
- Validation.h/.cpp: Abstract class that links the network and the dataset together. Child classes must implement a “minimize” method that is called during the optimization process to minimize the loss.
- Backpropagation.h/.cpp: Implementation of the backpropagation optimizer (though the backpropagation computations are in the neuron class for simplification). This class is mostly there to call these methods in the neuron class and to apply the new computed weights. It uses a batch size, the learning rate is a global variable because it’s common to all implemented optimizers and it’s easier to access it from anywhere.
- Thread_Guard.h: Creates threads if use within while loop we can achieve multithreaded implementation when ever we reinstantiate this class will instantiate new thread and when thread execution completed it gets terminated in the destructor.

### 4. Training / Testing
- xor.txt: It contains data set for XOR implmentation and we are training and testing on this data for this perticular implementation I believe you can use some other data set as well. 

## RUN
- cd src/
- g++ -std=c++11 ./helpers/utils.cpp ./algos/Validator.cpp ./dataset/DataSet.cpp ./algos/BackPropagation.cpp ./neural_network/Layer.cpp ./neural_network/Neuron.cpp ./neural_network/NeuralNetwork.cpp ./neural_network/Edge.cpp ./algos/ThreadGuard.cpp ./main.cpp  -o ./main