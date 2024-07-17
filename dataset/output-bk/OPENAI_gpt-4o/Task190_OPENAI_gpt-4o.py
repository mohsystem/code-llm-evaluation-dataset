# Python code to transpose the content of the file
def transpose_file(file_path):
    with open(file_path, 'r') as file:
        lines = [line.strip().split(' ') for line in file.readlines()]
    transposed = zip(*lines)
    for row in transposed:
        print(' '.join(row))

transpose_file('file.txt')