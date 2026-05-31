#pragma once
#include "Neuron.h"

class Adaline {
private:
  Neuron neuron;
  double lr;

public:
  Adaline(int input_size, double lr);
  ~Adaline();

  void learning(const std::vector<double> &x, const int y);
  int predict(const std::vector<double> &x);
  void train(const std::vector<std::vector<double>> &X,
             const std::vector<int> &y, const int num_epochs);
};