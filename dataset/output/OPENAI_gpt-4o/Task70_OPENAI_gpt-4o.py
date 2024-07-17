import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <file path>")
    sys.exit(1)

file_path = sys.argv[1]

try:
    with open(file_path, 'r') as file:
        for line in file:
            print(line, end='')
except IOError as e:
    print(f"Error opening file: {e}")