import sys

def read_file(filename):
    try:
        with open(filename, 'r') as file:
            return file.read()
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return None
    except PermissionError:
        print(f"Error: Permission denied to read file '{filename}'.")
        return None
    except Exception as e:
        print(f"Error: An error occurred while reading file '{filename}': {str(e)}")
        return None

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
    else:
        filename = sys.argv[1]
        data = read_file(filename)
        if data is not None:
            print(data)