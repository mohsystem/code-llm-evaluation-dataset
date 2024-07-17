import re
import sys

if len(sys.argv) != 3:
    print("Usage: python regex_search.py <pattern> <filename>")
    sys.exit(1)

pattern = sys.argv[1]
filename = sys.argv[2]

try:
    with open(filename, 'r') as file:
        for line in file:
            matches = re.findall(pattern, line)
            for match in matches:
                print(f"Match found: {match}")
except FileNotFoundError:
    print(f"Error: File '{filename}' not found.")