import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt
from src.neuron import Neuron 

class Adaline:
    def __init__(self, num_inputs:int, lr:float):
        self.neuron = Neuron(num_inputs)
        self.lr = lr 

    def learning(self, lr: float, y: float, x: np.ndarray): # Delta rule
        w = self.neuron.getW()
        b = self.neurongetB()
        u = self.neuron.soma(x)

        w = w + lr * (y - u) * x
        b = b + lr * (y - u)

        self.neuron.setW(w)
        self.neuron.setB(b)

    def predict(self, x:np.ndarray):
        u = self.neuron.soma(x)
        return self.neuron.activation(u)

    def train(self, X: np.ndarray, y: np.ndarray, num_epochs: int):
        for epoch in range(num_epochs):
            for i in range(len(X)):
                self.learning(self.lr, y[i], X[i])
