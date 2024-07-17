import sys

def main():
    if len(sys.argv) < 2:
        print("Please provide a filename as a command line argument.")
        return

    filename = sys.argv[1]

    try:
        with open(filename, 'r') as file:
            for line in file:
                print(line, end='')
    except FileNotFoundError:
        print(f"Invalid or non-existent file: {filename}")

if __name__ == "__main__":
    main()