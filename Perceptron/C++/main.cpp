#include "headers/Perceptron.h"
#include <iostream>

using namespace std;

int main() {
  vector<vector<double>> X = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  vector<int> y = {0, 1, 1, 1};

  Perceptron perceptron(2, 0.1);

  perceptron.train(X, y, 10);

  cout << "Training history: " << endl;
  perceptron.print_table();

  cout << endl << "Predict test:" << endl;
  cout << "x: [0, 1]" << endl;
  cout << "y: " << perceptron.predict({0, 1}) << endl;

  return 0;
}