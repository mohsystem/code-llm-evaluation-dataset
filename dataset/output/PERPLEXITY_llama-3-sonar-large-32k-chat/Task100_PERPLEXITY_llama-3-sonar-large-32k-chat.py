import sys
import re

if len(sys.argv) != 3:
    print("Usage: python regex_search.py <pattern> <file>")
    sys.exit(1)

pattern = sys.argv[1]
file = sys.argv[2]

try:
    with open(file, 'r') as f:
        for line in f:
            for match in re.finditer(pattern, line):
                print(match.group())
except IOError as e:
    print("Error reading file:", e)