import numpy as np
from activation_functions import leaky_ReLu, leaky_ReLu_derivative, sigmoid, sigmoid_derivative
from Layer import Layer 

class MLP:
    def __init__(self, input_layer_size: int, hidden_layer_size: list[int], output_layer_size: int, lr: float) -> None:
        self.lr = lr
        self.layers = []
        current_input = input_layer_size

        for num_neurons in hidden_layer_size:
            self.layers.append(Layer(current_input, num_neurons, leaky_ReLu, leaky_ReLu_derivative))
            current_input = num_neurons

        self.layers.append(Layer(current_input, output_layer_size, sigmoid, sigmoid_derivative))
    

    def train(self, X: np.ndarray, y: np.ndarray, num_epochs: int) -> None:
        for epoch in range(num_epochs):
            for i in range(X.shape[0]):
                output = X[i]
                for layer in self.layers:
                    output = layer.forward(output)

                err = np.array(y[i] - output)

                for layer in self.layers[::-1]:
                    err = layer.backward(err, self.lr)


    def predict(self, x:np.array) -> None:
        output = x 

        for layer in self.layers:
            output = layer.forward(output)
            
        return output
        
    