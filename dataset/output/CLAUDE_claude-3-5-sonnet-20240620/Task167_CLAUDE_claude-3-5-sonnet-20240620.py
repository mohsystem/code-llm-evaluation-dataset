
import math

def cubeDiagonal(volume):
    side = volume ** (1/3)
    diagonal = math.sqrt(3) * side
    return round(diagonal, 2)
