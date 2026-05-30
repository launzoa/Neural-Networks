#include "headers/Neuron.h"
#include <cstdlib>
#include <ctime>

Neuron::Neuron(int input_size) {
  srand(time(NULL));

  this->b = (rand() / ((double)RAND_MAX)) * 2 - 1;

  for (int i = 0; i < input_size; i++) {
    this->w.push_back((rand() / ((double)RAND_MAX)) * 2 - 1);
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

int Neuron::activation(const double u) { return (u >= 0) ? 1 : -1; }
