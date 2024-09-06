with open("file.txt", "r") as f:
    lines = f.readlines()

words = [line.strip().split() for line in lines]
transposed = zip(*words)

for row in transposed:
    print(" ".join(row))