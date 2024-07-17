import fileinput

matrix = []
for line in fileinput.input("file.txt"):
    matrix.append(line.strip().split())

for j in range(len(matrix[0])):
    for i in range(len(matrix)):
        print(matrix[i][j], end=" ")
    print()