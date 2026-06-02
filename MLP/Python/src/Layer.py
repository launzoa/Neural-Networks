import numpy as np 
from Neuron import Neuron

class Layer:
    def __init__(self, input_size: int, num_neurons: int,  g: callable, dg: callable):
        self.neurons = np.array([Neuron(input_size, g, dg) for _ in range(num_neurons)])
        self.x = np.array([])
        self.y = np.array([])
    
    def forward(self, x: np.ndarray) -> np.array:
        self.x = x
        outputs = []

        for neuron in self.neurons:
            neuron.soma(x)
            outputs.append(neuron.activation())
        
        self.y = np.array(outputs)
        return self.y

    def backward(self, err: np.array, lr: float) -> np.array:     
        delta_err = [] 

        for i, neuron in enumerate(self.neurons):
            neuron.calculate_delta(err[i])
            neuron.update_weights(lr, self.x)
            delta_err.append(neuron.delta_err()) 

        return np.sum(delta_err, axis=0)
