from src.adaline import Adaline
import numpy as np 

if __name__ == "__main__":
    X = np.array([[0,0], [0,1], [1,0], [1,1]])
    y = np.array([0, 1, 1, 1])

    adaline = Adaline(num_inputs=2, lr=0.1)
    
    adaline.train(X, y, 10)
    
    print("Predict test:")
    print("x: [0, 1]")
    print("y:", adaline.predict(np.array([0, 1])))
