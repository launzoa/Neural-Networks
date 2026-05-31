#include "headers/Perceptron.h"
#include <iostream>

using namespace std;

int main() {
  vector<vector<double>> X = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  vector<int> y = {0, 1, 1, 1};

  Perceptron perceptron(2, 0.1);

  perceptron.train(X, y, 10);

  cout << endl << "Predict test:" << endl;

  for (int i = 0; i < X.size(); i++) {
    cout << "x: [" << X[i][0] << ", " << X[i][1] << "]" << endl;
    cout << "y: " << perceptron.predict(X[i]) << endl;
    cout << endl;
  }

  return 0;
}