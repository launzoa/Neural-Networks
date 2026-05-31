#include "headers/Perceptron.h"

using namespace std;

Perceptron::Perceptron(int num_inputs, double lr)
    : neuron(num_inputs), lr(lr) {}

Perceptron::~Perceptron() {}

void Perceptron::learning(const std::vector<double> &x, double err, double lr) {
  vector<double> w = this->neuron.getW();
  double b = this->neuron.getB();

  for (int i = 0; i < x.size(); ++i) {
    w[i] += lr * (err)*x[i];
  }
  b += lr * (err);

  this->neuron.setW(w);
  this->neuron.setB(b);
}

int Perceptron::predict(const vector<double> &x) {
  double u = this->neuron.soma(x);
  return this->neuron.activation(u);
}

void Perceptron::train(const vector<vector<double>> &X, const vector<int> &y,
                       int num_epochs) {

  for (int epoch = 0; epoch < num_epochs; epoch++) {
    for (int i = 0; i < X.size(); i++) {
      int error = y[i] - this->predict(X[i]);

      if (error != 0) {
        this->learning(X[i], error, this->lr);
      }
    }
  }
}
