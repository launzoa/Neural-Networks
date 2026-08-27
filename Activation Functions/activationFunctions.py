import numpy as np

def heaviside(x: float) -> int:
    return 1 if x >= 0 else 0

def symmetric_hard_limiter(x: float) -> int:
    if (x > 0):
        return 1
    elif (x < 0):
        return -1
    else:
        return 0

def clamping(x: float, a: float) -> float:
    return max(-a, min(x, a))

def reLU(x: float) -> float:
    return max(0, x)

def sigmoid(x: float) -> float:
    return 1 / (1 + np.exp(-x))

def tanh(x: float) -> float:
    return (1 - np.exp(-x)) / (1 + np.exp(-x))

def linear(x: float) -> float:
    return x
