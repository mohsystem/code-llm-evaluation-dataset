import sys
import os

if len(sys.argv) != 2:
    print("Usage: python <file.py> <filename>")
else:
    filename = sys.argv[1]
    if not os.path.exists(filename):
        print("File does not exist")
    else:
        try:
            with open(filename, 'r') as file:
                print(file.read())
        except Exception as e:
            print(f"Error reading file: {e}")