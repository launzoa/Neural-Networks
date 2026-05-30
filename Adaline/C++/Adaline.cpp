#include "headers/Adaline.h"
using namespace std;

Adaline::Adaline(int input_size, double lr) : neuron(input_size), lr(lr) {}

Adaline::~Adaline() {}

void Adaline::learning(const std::vector<double> &x, const int y) {

  vector<double> w = this->neuron.getW();
  double b = this->neuron.getB();

  double u = this->neuron.soma(x);

  for (int i = 0; i < x.size(); ++i) {
    w[i] = w[i] + this->lr * (y - u) * x[i];
  }
  b = b + this->lr * (y - u);

  this->neuron.setW(w);
  this->neuron.setB(b);
}

int Adaline::predict(const std::vector<double> &x) {

  double u = this->neuron.soma(x);

  return this->neuron.activation(u);
}

void Adaline::train(const std::vector<std::vector<double>> &X,
                    const std::vector<int> &y, const int num_epochs) {
  for (int epoch = 0; epoch < num_epochs; epoch++) {
    for (int i = 0; i < X.size(); i++) {
      this->learning(X[i], y[i]);
    }
  }
}