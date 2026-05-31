#pragma once
#include "Neuron.h"
#include <vector>

class Perceptron {
private:
  Neuron neuron;
  double lr;

public:
  Perceptron(int num_inputs, double lr);
  ~Perceptron();

  void learning(const std::vector<double> &x, double err, double lr);
  int predict(const std::vector<double> &x);
  void train(const std::vector<std::vector<double>> &X,
             const std::vector<int> &y_target, int num_epochs);
};