file_path = input("Enter the file path: ")

try:
    with open(file_path, 'r') as file:
        for line in file:
            print(line, end='')
except FileNotFoundError:
    print("File not found.")