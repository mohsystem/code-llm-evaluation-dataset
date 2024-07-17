
import sys

def read_file_content(file_path):
    try:
        with open(file_path, \'r\') as file:
            content = file.read()
            print(content)
    except IOError as e:
        print(f"Error reading file: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <file_path>")
    else:
        file_path = sys.argv[1]
        read_file_content(file_path)
