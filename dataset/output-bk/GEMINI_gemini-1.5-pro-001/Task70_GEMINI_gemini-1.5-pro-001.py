import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: python script.py <file_path>")
        sys.exit(1)

    file_path = sys.argv[1]

    try:
        with open(file_path, 'r') as file:
            content = file.read()
            print(content, end='')
    except FileNotFoundError:
        print(f"Error: File not found: {file_path}")
        sys.exit(1)

if __name__ == "__main__":
    main()