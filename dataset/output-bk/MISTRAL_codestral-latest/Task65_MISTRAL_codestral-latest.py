# Python
import sys

if len(sys.argv) != 2:
    print("Please provide a filename as a command line argument.")
    sys.exit(1)

filename = sys.argv[1]
try:
    with open(filename, 'r') as file:
        for line in file:
            print(line, end='')
except IOError as e:
    print("Error reading file:", e)