import numpy as np
import pandas as pd

def eucledian_distance(vec1, vec2):
    """
    Calculate the eucledian distance between two vectors
    """
    return np.sqrt(np.sum((vec1 - vec2) ** 2))

def product_of_magnitude(vec):
    total = 0
    for x in vec:
        total += (x * x)
    return np.sqrt(total)

def dot_product(vec1, vec2):
    return np.dot(vec1, vec2)

def cosine_similarity(vec1, vec2):
    return np.dot(vec1, vec2) / (np.sqrt(np.dot(vec1, vec1)) * np.sqrt(np.dot(vec2, vec1)))

x = np.array([[2,4,4,5], [0,4,3,0]])
x0 = x[0]
x1 = x[1]
print(x0)
print(x1)
print("x0 and x1:", eucledian_distance(x0, x1))
print("cosine x0 and x1:", cosine_similarity(x0, x1))
print("dot:", dot_product(x0,x1))