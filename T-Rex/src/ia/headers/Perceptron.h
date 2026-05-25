#pragma once
#include "Neuron.h"

class Perceptron {
private:
  Neuron neuron;
  double lr;

public:
  Perceptron(int input_size, double lr);
  ~Perceptron();

  int predict(const std::vector<double> &x);
  void train(const std::vector<std::vector<double>> &X,
             const std::vector<int> &y, int epochs);
};
