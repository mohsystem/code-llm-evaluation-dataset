import sys

def transpose_file(file_path):
    with open(file_path, 'r') as file:
        lines = [line.strip().split() for line in file]
    transposed = zip(*lines)
    for row in transposed:
        print(' '.join(row))

if __name__ == "__main__":
    transpose_file('file.txt')