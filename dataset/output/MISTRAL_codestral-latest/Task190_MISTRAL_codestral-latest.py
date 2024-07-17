with open('file.txt', 'r') as file:
    lines = [line.split() for line in file]
    transposed_lines = [' '.join(line) for line in zip(*lines)]
    for line in transposed_lines:
        print(line)