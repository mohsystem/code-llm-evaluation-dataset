
import sys

if len(sys.argv) != 2:
    print("Usage: python script.py <filename>")
    sys.exit(1)

filename = sys.argv[1]

try:
    with open(filename, 'r') as file:
        print(file.read())
except FileNotFoundError:
    print(f"Error: File '{filename}' not found.")
except IOError:
    print(f"Error: Unable to read file '{filename}'.")
