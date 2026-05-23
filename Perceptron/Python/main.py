# pyrefly: ignore [missing-import]
import numpy as np 
from perceptron import Perceptron

class FeedForward: 
    def __init__(self, input_size:int=4, output_size:int=1, learning_rate:float=0.1):
        self.input_size = input_size 
        self.output_size = output_size 
        self.learning_rate = learning_rate 
        self.output_layer = Perceptron(input_size)

    def predict(self, input:np.array) -> float:
        val = self.output_layer.soma(input)
        return self.output_layer.activation(val)

    def train(self, input:np.array, target:np.array, epochs:int):
        for epoch in range(epochs):
            print(f"Epoch {epoch}")
            
            for i in range(len(input)):
                predicted = self.predict(input[i])
                self.output_layer.update_weights(input[i], target[i], predicted, self.learning_rate)
        
    def test(self, input, target):
        for i in range(len(input)):
            print(f"Input: {input[i]}, Output: {self.predict(input[i])}, Target: {target[i]}")

    def print_weights(self):
        print(f"Weights: {self.output_layer.get_weights()}")


if __name__ == "__main__":
    inputs = np.array([[0,0], [0,1], [1,0], [1,1]]) # AND input
    targets = np.array([0, 0, 0, 1]) # AND output

    perceptron_network = FeedForward(2)
    perceptron_network.train(inputs, targets, 100)
    perceptron_network.test(inputs, targets)
    perceptron_network.print_weights()