#pragma once
#include <vector>

class Neuron {
private:
  std::vector<double> w;
  double b;

public:
  Neuron(int input_size);
  ~Neuron();

  double soma(const std::vector<double> &x);
  int activation(const double u);

  // Getters
  std::vector<double> &getW() { return this->w; }
  double &getB() { return this->b; }
};