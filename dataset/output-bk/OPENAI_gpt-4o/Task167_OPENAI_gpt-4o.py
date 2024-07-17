import math

def cube_diagonal(volume):
    side_length = volume**(1/3)
    diagonal = side_length * math.sqrt(3)
    return round(diagonal, 2)

print(cube_diagonal(8))         # ➞ 3.46
print(cube_diagonal(343))       # ➞ 12.12
print(cube_diagonal(1157.625))  # ➞ 18.19