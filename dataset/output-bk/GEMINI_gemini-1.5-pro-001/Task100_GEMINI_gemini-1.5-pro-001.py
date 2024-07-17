import re
import sys

if len(sys.argv) != 3:
    print("Usage: python3 regex_file_search.py <regex> <filename>")
    sys.exit(1)

regex = sys.argv[1]
filename = sys.argv[2]

try:
    with open(filename, 'r') as file:
        content = file.read()
        matches = re.findall(regex, content)
        for match in matches:
            print(match)

except FileNotFoundError:
    print(f"Error: File '{filename}' not found.")
except Exception as e:
    print(f"An error occurred: {e}")