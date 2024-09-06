import re
import sys

def main():
    if len(sys.argv) < 3:
        print("Usage: python script.py <regex_pattern> <file_name>")
        sys.exit(1)

    pattern = sys.argv[1]
    file_name = sys.argv[2]

    try:
        regex = re.compile(pattern)
    except re.error as e:
        print(f"Invalid regex pattern: {e}")
        sys.exit(1)

    try:
        with open(file_name, 'r') as file:
            for line in file:
                match = regex.search(line)
                if match:
                    print(line, end='')
    except FileNotFoundError:
        print(f"File not found: {file_name}")
        sys.exit(1)

if __name__ == "__main__":
    main()