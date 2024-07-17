with open('file.txt', 'r') as f:
    lines = [line.split() for line in f.readlines()]
    for i in range(len(lines[0])):
        print(' '.join([line[i] for line in lines]))