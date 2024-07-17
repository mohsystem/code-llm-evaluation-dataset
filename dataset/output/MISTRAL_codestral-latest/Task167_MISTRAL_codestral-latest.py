import math

def cube_diagonal(volume):
    side_length = round(volume ** (1. / 3), 2)
    diagonal_length = round(side_length * math.sqrt(3), 2)
    return diagonal_length