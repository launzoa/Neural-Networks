import numpy as np

def leaky_ReLu(u: float) -> float:
    a = 0.01
    
    if u > 0:
        return u
    else:
        return a * u

def leaky_ReLu_derivative(u: float) -> float:
    a = 0.01

    if u > 0: 
        return 1
    else: 
        return a

def sigmoid(u: float) -> float:
    return 1 / (1 + np.exp(-u))

def sigmoid_derivative(u: float) -> float:
    return sigmoid(u) * (1 - sigmoid(u))