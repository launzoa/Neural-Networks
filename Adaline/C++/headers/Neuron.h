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
  std::vector<double> getW() const { return this->w; }
  double getB() const { return this->b; }

  // Setters
  void setW(const std::vector<double> &w) { this->w = w; }
  void setB(const double b) { this->b = b; }
};