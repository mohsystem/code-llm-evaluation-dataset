
import re
import sys

if len(sys.argv) != 3:
    print("Usage: python script.py <regex_pattern> <file_name>")
    sys.exit(1)

pattern = sys.argv[1]
file_name = sys.argv[2]

try:
    regex = re.compile(pattern)
    with open(file_name, 'r') as file:
        for line in file:
            if regex.search(line):
                print(line.strip())
except re.error:
    print("Invalid regular expression")
except IOError:
    print("Error reading file")
