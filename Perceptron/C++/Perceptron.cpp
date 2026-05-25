#include "headers/Perceptron.h"

using namespace std;

Perceptron::Perceptron(int num_inputs, double lr)
    : neuron(num_inputs), lr(lr) {}

Perceptron::~Perceptron() {}

void Perceptron::insert_line_table(double b, vector<double> w) {
  vector<double> row;
  row.push_back(b);

  for (double val : w) {
    row.push_back(val);
  }

  this->table.push_back(row);
}

void Perceptron::print_table() {
  cout << "Epoch\t Bias\t";
  for (int i = 0; i < this->neuron.get_w().size(); i++) {
    cout << " W" << i + 1 << "\t";
  }
  cout << endl;

  int epoch = 0;
  for (vector<double> row : this->table) {
    cout << epoch << "\t";
    epoch++;
    for (double val : row) {
      printf("%7.4f ", val);
    }
    cout << endl;
  }
}

int Perceptron::predict(const vector<double> &x) {
  this->neuron.soma(x);
  return this->neuron.activation_function();
}

void Perceptron::train(const vector<vector<double>> &X, const vector<int> &y,
                       int num_epochs) {
  this->insert_line_table(this->neuron.get_b(), this->neuron.get_w());

  for (int epoch = 0; epoch < num_epochs; epoch++) {
    for (int i = 0; i < X.size(); i++) {
      int error = y[i] - this->predict(X[i]);

      if (error != 0) {
        this->neuron.learning(X[i], error, this->lr);
      }
    }
    this->insert_line_table(this->neuron.get_b(), this->neuron.get_w());
  }
}
