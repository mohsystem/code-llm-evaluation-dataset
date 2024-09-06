import sys
import os

def read_file(filename):
    try:
        with open(filename, 'r') as file:
            data = file.read()
            return data
    except FileNotFoundError:
        return "Error: File not found."
    except IOError:
        return "Error: Unable to read the file."

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
    else:
        filename = sys.argv[1]
        result = read_file(filename)
        print(result)