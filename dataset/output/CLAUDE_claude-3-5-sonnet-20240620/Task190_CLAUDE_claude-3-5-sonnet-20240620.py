
import sys

with open('file.txt', 'r') as file:
    lines = file.readlines()

transposed = list(zip(*[line.strip().split() for line in lines]))

for row in transposed:
    print(' '.join(row))
