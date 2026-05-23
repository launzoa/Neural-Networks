# pyrefly: ignore [missing-import]
import numpy as np 

class Perceptron:
    def __init__(self, input_size:int):
        self.weights = np.random.rand(input_size) * 2 - 1
        self.bias = np.random.rand() * 2 - 1

    def get_weights(self) -> np.array:
        return self.weights 

    def soma(self, input:np.array) -> np.float64:
        return np.dot(input, self.weights) + self.bias

    def update_weights(self, input:np.array, target:float, predicted:float, learning_rate:float):
        self.weights = self.weights + learning_rate * (target - predicted) * input 
        self.bias = self.bias + learning_rate * (target - predicted) 
    
    def activation(self, val:float) -> int: 

        def heavyside() -> int:
            if (val >= 0):
                return 1
            else:
                return 0

        def signal() -> int:
            if (val >= 1 ): 
                return 1
            elif (val <= -1 ):
                return -1
            else:
                return 0

        return heavyside()
