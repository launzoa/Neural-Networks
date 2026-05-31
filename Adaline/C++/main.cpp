#include "headers/Adaline.h"
#include <iostream>

using namespace std;

int main() {
  vector<vector<double>> X = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  vector<int> y = {-1, 1, 1, 1};

  Adaline adaline(2, 0.01);

  adaline.train(X, y, 1000);

  cout << endl << "Predict test:" << endl;

  for (int i = 0; i < X.size(); i++) {
    cout << "x: [" << X[i][0] << ", " << X[i][1] << "]" << endl;
    cout << "y: " << adaline.predict(X[i]) << endl;
    cout << endl;
  }

  return 0;
}