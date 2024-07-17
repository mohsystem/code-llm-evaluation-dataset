import re
import sys

def main():
    if len(sys.argv) < 3:
        print("Usage: <pattern> <filename>")
        return
    pattern = sys.argv[1]
    filename = sys.argv[2]

    with open(filename, 'r') as file:
        content = file.read()
        matches = re.findall(pattern, content)
        for match in matches:
            print(match)

if __name__ == "__main__":
    main()