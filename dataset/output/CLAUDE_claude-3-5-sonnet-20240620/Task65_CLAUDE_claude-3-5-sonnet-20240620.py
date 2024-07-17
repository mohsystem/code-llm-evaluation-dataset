
import sys

def read_file(filename):
    try:
        with open(filename, \'r\') as file:
            content = file.read()
        return content
    except IOError as e:
        raise IOError(f"Unable to read file \'{filename}\': {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} <filename>")
        sys.exit(1)

    filename = sys.argv[1]
    try:
        content = read_file(filename)
        print("File content:")
        print(content)
    except IOError as e:
        print(f"Error: {e}")
        sys.exit(1)
