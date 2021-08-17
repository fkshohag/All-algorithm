import numpy as np
import pandas as pd

def eucledian_distance(vec1, vec2):
    """
    Calculate the eucledian distance between two vectors
    """
    return np.sqrt(np.sum((vec1 - vec2) ** 2))

def cosine_similarity(vec1, vec2):
    return np.dot(vec1, vec2) / (np.sqrt(np.dot(vec1, vec1)) * np.sqrt(np.dot(vec2, vec1)))

x = np.array([[2, 1, 0, 2, 0, 1, 1, 1], [2, 1, 1, 1, 1, 0, 1, 1]])
x0 = x[0][:-1]
x1 = x[1][:-1]
print("x0 and x1:", eucledian_distance(x0, x1))
print("x0 and x1:", cosine_similarity(x0, x1))