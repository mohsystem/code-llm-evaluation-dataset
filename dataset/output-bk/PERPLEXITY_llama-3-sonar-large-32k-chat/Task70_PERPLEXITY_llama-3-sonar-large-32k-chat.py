import sys

if len(sys.argv) != 2:
    print("Usage: python file_reader.py <file_path>")
    sys.exit(1)

try:
    with open(sys.argv[1], 'r') as file:
        for line in file:
            print(line, end='')
except FileNotFoundError:
    print("File not found")