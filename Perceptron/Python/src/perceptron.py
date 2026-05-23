import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt
from src.neuron import Neuron 


class Perceptron: 
    def __init__(self, num_inputs: int, learning_rate: float):
        self.neuron = Neuron(num_inputs)
        self.lr = learning_rate 
        self.table = []

    def insert_line_table(self, b: float, w: np.ndarray):
        row = [b] + w.tolist()
        self.table.append(row)

    def predict(self, x: np.ndarray) -> int:
        self.neuron.soma(x)
        return self.neuron.activation_function()

    def train(self, X: np.ndarray, y_target: np.ndarray, num_epochs: int):
        self.insert_line_table(self.neuron.get_b(), self.neuron.get_w())
        for epoch in range(num_epochs):           
            for i in range(len(X)):
                y_pred = self.predict(X[i])
                error = y_target[i] - y_pred 
                if error != 0:
                    self.neuron.learning(X[i], error, self.lr)
            self.insert_line_table(self.neuron.get_b(), self.neuron.get_w())
        
    def print_table(self):
        cols = ['Bias'] + [f'W{i+1}' for i in range(len(self.neuron.get_w()))]
        df = pd.DataFrame(self.table, columns=cols)
        df.index.name = 'Epoch'
        print(df)

    def plot_history(self):
        cols = ['Bias'] + [f'W{i+1}' for i in range(len(self.neuron.get_w()))]
        df = pd.DataFrame(self.table, columns=cols)
        
        plt.figure(figsize=(8, 5))
        for col in cols:
            plt.plot(df.index, df[col], marker='o', label=col)
        
        plt.title('Graph Perceptron')
        plt.xlabel('Epoch')
        plt.ylabel('Value')
        plt.legend(loc='best')
        plt.grid(True)
        plt.show()
        plt.savefig("Perceptron/Python/assets/graph.png")


