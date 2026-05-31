import numpy as np 

class Neuron:
    def __init__(self, input_size: int):
        self.w = np.random.rand(input_size) * 2 - 1
        self.b = np.random.rand() * 2 - 1

    def soma(self, x: np.ndarray):
        return np.dot(x, self.w) + self.b

    def activation(self, u): # Heaviside function 
        if u >= 0:
            return 1
        else:
            return -1

   