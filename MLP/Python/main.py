import numpy as np
import sys

sys.path.append('./src')

from MLP import MLP

if __name__ == "__main__":
    X = np.array([
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1]
    ])

    y = np.array([
        [0],
        [1],
        [1],
        [0]
    ])

    mlp = MLP(input_layer_size=2, hidden_layer_size=[4], output_layer_size=1, lr=0.1)

    mlp.train(X, y, num_epochs=1000)

    for i in range(X.shape[0]):
        d = y[i][0]
        y_pred = mlp.predict(X[i])
            
        print(f"Input: {X[i]} | Expected: {d} | Prediction: {y_pred[0]:.4f}")

