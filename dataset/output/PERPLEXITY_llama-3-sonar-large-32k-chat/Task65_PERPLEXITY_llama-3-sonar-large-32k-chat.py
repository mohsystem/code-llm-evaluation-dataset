import sys

def is_valid_filename(filename):
    # Add your filename validation logic here
    return True

if len(sys.argv) != 2:
    print("Usage: python script.py <filename>")
    sys.exit(1)

filename = sys.argv[1]
if not is_valid_filename(filename):
    print("Invalid filename format")
    sys.exit(1)

try:
    with open(filename, 'r') as file:
        for line in file:
            print(line, end='')
except FileNotFoundError:
    print("File does not exist or is inaccessible")
    sys.exit(1)