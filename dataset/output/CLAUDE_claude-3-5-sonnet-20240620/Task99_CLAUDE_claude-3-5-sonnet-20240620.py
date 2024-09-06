
import re

pattern = r'^\\d+.*\\.$'

with open('input.txt', 'r') as file:
    for line in file:
        if re.match(pattern, line.strip()):
            print(line.strip())
