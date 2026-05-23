#include "headers/Neuron.h"
#include <cstdlib>
#include <ctime>

Neuron::Neuron(int input_size) {
  srand(time(NULL));

  this->u = 0.0;
  this->b = (rand() / ((double)RAND_MAX)) * 2 - 1;

  for (int i = 0; i < input_size; ++i) {
    this->w.push_back((rand() / ((double)RAND_MAX)) * 2 - 1);
  }
}

Neuron::~Neuron() {}

void Neuron::soma(const std::vector<double> &x) {
  this->u = 0.0;

  for (int i = 0; i < x.size(); ++i) {
    this->u += x[i] * this->w[i];
  }

  this->u += this->b;
}

int Neuron::activation_function() { return (this->u >= 0) ? 1 : 0; }

void Neuron::learning(const std::vector<double> &x, double err, double lr) {
  for (int i = 0; i < x.size(); ++i) {
    this->w[i] += lr * (err)*x[i];
    this->b += +lr * (err);
  }
}