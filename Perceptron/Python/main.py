from src.perceptron import Perceptron
import numpy as np 

if __name__ == "__main__":
    X = np.array([[0,0], [0,1], [1,0], [1,1]])
    y = np.array([0, 1, 1, 1])

    perceptron = Perceptron(num_inputs=2, lr=0.1)
    
    perceptron.train(X, y, 10)
    
    print("\nPredict test:")
    print(f"x: {np.array([0, 1])}")
    print(f"y: {perceptron.predict(np.array([0, 1]))}")
