#pragma once
#include "Neuron.h"
#include <iostream>
#include <vector>

class Perceptron {
private:
  Neuron neuron;
  double lr;
  std::vector<std::vector<double>> table;

public:
  Perceptron(int num_inputs, double lr);
  ~Perceptron();

  void insert_line_table(double b, std::vector<double> w);
  void print_table();

  int predict(const std::vector<double> &x);
  void train(const std::vector<std::vector<double>> &X,
             const std::vector<int> &y_target, int num_epochs);
};