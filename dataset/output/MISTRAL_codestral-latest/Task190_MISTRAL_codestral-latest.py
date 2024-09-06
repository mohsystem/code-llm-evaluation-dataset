# Python
with open('file.txt', 'r') as file:
    lines = [line.split() for line in file]
    transposed = list(map(list, zip(*lines)))
    for line in transposed:
        print(' '.join(line))