#include "headers/Neuron.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Neuron::Neuron(int input_size) {
  srand(time(NULL));

  this->b = (double)rand() / RAND_MAX;
  this->u = 0.0;

  for (int i = 0; i < input_size; ++i) {
    this->w.push_back((double)rand() / RAND_MAX);
  }
}

Neuron::~Neuron() {}

void Neuron::soma(const vector<double> &x) {
  this->u = this->b;

  for (int i = 0; i < x.size(); ++i) {
    this->u += this->w[i] * x[i];
  }
}

int Neuron::activate() {
  if (this->u > 0.5)
    return 1;
  else if (this->u < -0.5)
    return -1;
  else
    return 0;
}

void Neuron::learning(const vector<double> &x, double err, double lr) {
  for (int i = 0; i < x.size(); ++i) {
    this->w[i] += lr * err * x[i];
  }
  this->b += lr * err;
}