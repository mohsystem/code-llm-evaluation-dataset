import math
def cubeDiagonal(volume):
    return round(math.sqrt(3) * (volume ** (1. / 3)), 2)
print(cubeDiagonal(8))  # 3.46
print(cubeDiagonal(343))  # 12.12
print(cubeDiagonal(1157.625))  # 18.19