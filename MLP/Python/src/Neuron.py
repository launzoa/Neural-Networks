import numpy as np

class Neuron:
    def __init__(self, input_size: int, g: callable, dg: callable) -> None:
        self.w = np.random.uniform(-1, 1, input_size)
        self.b = np.random.uniform(-1, 1)
        self.u = 0.0
        self.delta = 0.0
        self.g = g 
        self.dg = dg

    def soma(self, x: np.array) -> None:
        self.u = np.dot(self.w, x) + self.b

    def activation(self) -> float:
        return self.g(self.u)

    def calculate_delta(self, err: float) -> None:
        self.delta = err * self.dg(self.u)

    def update_weights(self, lr: float, inputs: np.array) -> None:
        self.w += lr * self.delta * inputs 
        self.b += lr * self.delta 
    
    def delta_err(self) -> np.array:
        return self.delta * self.w 

    
    