import sys

def read_file(file_path):
    try:
        with open(file_path, 'r') as file:
            return file.read()
    except FileNotFoundError:
        return "File not found"

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python file_reader.py <file_path>")
    else:
        print(read_file(sys.argv[1]))