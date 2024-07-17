
import sys

with open(\'file.txt\', \'r\') as file:
    lines = file.readlines()

data = [line.strip().split() for line in lines]
transposed = list(map(list, zip(*data)))

for row in transposed:
    print(\' \'.join(row))
