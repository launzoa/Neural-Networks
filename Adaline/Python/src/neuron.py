import numpy as np 

class Neuron:
    def __init__(self, input_size:int):
        self.w = np.random.rand(input_size) * 2 - 1
        self.b = np.random.rand() * 2 - 1

    def soma(self, x):
        return np.dot(self.w, x) + self.b

    def activation(self, u): # Heaviside function
        if u >= 0:
            return 1
        else:
            return -1

    # Getters
    def getW(self) -> np.ndarray:
        return self.w
    def getB(self) -> float:
        return self.b

   # Setters
    def setW(self, w: np.ndarray):
        self.w = w
    def setB(self, b: float):
        self.b = b
