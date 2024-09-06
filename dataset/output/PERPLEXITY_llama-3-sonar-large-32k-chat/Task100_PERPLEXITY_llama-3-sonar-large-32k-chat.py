import re
import sys

pattern = sys.argv[1]
file_name = sys.argv[2]

with open(file_name, 'r') as file:
    content = file.read()
    matches = re.findall(pattern, content)
    for match in matches:
        print(match)