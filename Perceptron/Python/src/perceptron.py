import numpy as np 
from src.neuron import Neuron 


class Perceptron: 
    def __init__(self, num_inputs: int, lr: float):
        self.neuron = Neuron(num_inputs)
        self.lr = lr 


    def learning(self, x: np.ndarray, err: float, lr: float): # Perceptron's rule 
        w = self.neuron.getW()
        b = self.neuron.getB()
        
        w = w + lr * err * x  
        b = b + lr * err

        self.neuron.setW(w)
        self.neuron.setB(b)

    def predict(self, x: np.ndarray) -> int:
        u = self.neuron.soma(x)
        return self.neuron.activation(u)

    def train(self, X: np.ndarray, y: np.ndarray, num_epochs: int):
        for epoch in range(num_epochs):           
            for i in range(len(X)):
                y_pred = self.predict(X[i])
                err = y[i] - y_pred 

                if err != 0:
                    self.learning(X[i], err, self.lr)
