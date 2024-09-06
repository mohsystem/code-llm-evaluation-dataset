
import sys
import os

def read_file(filename):
    if not filename.endswith('.txt'):
        print("Error: File must have a .txt extension")
        return

    if not os.path.exists(filename):
        print(f"Error: File '{filename}' does not exist")
        return

    try:
        with open(filename, 'r') as file:
            data = file.read()
            print(f"File contents:\\n{data}")
    except IOError:
        print(f"Error: Unable to read file '{filename}'")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
    else:
        read_file(sys.argv[1])
