import sys
import re

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} <pattern> <filename>")
    sys.exit(1)

pattern = sys.argv[1]
filename = sys.argv[2]

with open(filename, 'r') as file:
    content = file.read()

matches = re.findall(pattern, content)

for match in matches:
    print(match)