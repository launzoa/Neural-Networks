import numpy as np 

class Neuron:
    def __init__(self, input_size: int):
        self.w = np.random.rand(input_size) * 2 - 1
        self.b = np.random.rand() * 2 - 1
        self.u = 0.0

    def get_w(self) -> np.ndarray:
        return self.w 

    def get_b(self) -> float:
        return self.b

    def soma(self, x: np.ndarray):
        self.u = np.dot(x, self.w) + self.b

    def activation_function(self) -> int: 
        return 1 if self.u >= 0 else 0

    def learning(self, x: np.ndarray, err: float, lr: float):
        self.w += lr * err * x 
        self.b += lr * err 