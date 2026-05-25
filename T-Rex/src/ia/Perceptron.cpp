#include "headers/Perceptron.h"

using namespace std;

Perceptron::Perceptron(int input_size, double lr)
    : neuron(input_size), lr(lr) {}

Perceptron::~Perceptron() {}

int Perceptron::predict(const vector<double> &x) {
  this->neuron.soma(x);
  return this->neuron.activate();
}

void Perceptron::train(const vector<vector<double>> &X, const vector<int> &y,
                       int epochs) {
  for (int epoch = 0; epoch < epochs; ++epoch) {
    for (int i = 0; i < X.size(); ++i) {
      int y_pred = this->predict(X[i]);
      int err = y[i] - y_pred;
      this->neuron.learning(X[i], (double)err, this->lr);
    }
  }
}
