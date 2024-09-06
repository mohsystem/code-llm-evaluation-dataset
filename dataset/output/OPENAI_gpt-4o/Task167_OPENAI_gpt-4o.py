import math

def cubeDiagonal(volume):
    side_length = volume ** (1/3)
    diagonal_length = side_length * math.sqrt(3)
    return round(diagonal_length, 2)

if __name__ == "__main__":
    print(cubeDiagonal(8))
    print(cubeDiagonal(343))
    print(cubeDiagonal(1157.625))