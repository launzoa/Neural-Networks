#pragma once
#include <vector>

class Neuron {
private:
  std::vector<double> w;
  double b;
  double u;

public:
  Neuron(int input_size);
  ~Neuron();

  void soma(const std::vector<double> &x);
  int activate();
  void learning(const std::vector<double> &x, double err, double lr);
};
