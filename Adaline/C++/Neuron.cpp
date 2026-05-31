#include "headers/Neuron.h"
#include <random>

Neuron::Neuron(int input_size) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(-1.0, 1.0);

  this->b = dist(gen);
  for (int i = 0; i < input_size; i++) {
    this->w.push_back(dist(gen));
  }
}

Neuron::~Neuron() {}

double Neuron::soma(const std::vector<double> &x) {
  double u = 0.0;

  for (int i = 0; i < x.size(); ++i) {
    u += x[i] * this->w[i];
  }

  return u + this->b;
}

int Neuron::activation(const double u) { return (u >= 0) ? 1 : 0; }
