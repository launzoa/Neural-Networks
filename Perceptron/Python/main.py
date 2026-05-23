from src.perceptron import Perceptron
import numpy as np 

if __name__ == "__main__":
    X = np.array([[0,0], [0,1], [1,0], [1,1]])
    y = np.array([0, 1, 1, 1])

    perceptron = Perceptron(num_inputs=2, learning_rate=0.1)
    
    perceptron.train(X, y, 10)
    
    print("Training history:")
    perceptron.print_table()
    
    print("\nPredict test:")
    print("x: [0, 1]")
    print("y:", perceptron.predict(np.array([0, 1])))

    perceptron.plot_history()