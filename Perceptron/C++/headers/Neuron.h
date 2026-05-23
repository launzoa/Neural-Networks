#pragma once
#include <vector>

class Neuron {
private:
  std::vector<double> w;
  double b;
  double u;

public:
  Neuron(int num_inputs);
  ~Neuron();

  void soma(const std::vector<double> &x);
  int activation_function();
  void learning(const std::vector<double> &x, double err, double lr);

  // Getters
  const std::vector<double> &get_w() const { return this->w; }
  double get_b() const { return this->b; }
};