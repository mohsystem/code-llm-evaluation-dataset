
import math

def cubeDiagonal(volume):
    side = volume ** (1/3)
    diagonal = round(math.sqrt(3) * side, 2)
    return diagonal

# Test cases
print(cubeDiagonal(8))
print(cubeDiagonal(343))
print(cubeDiagonal(1157.625))
