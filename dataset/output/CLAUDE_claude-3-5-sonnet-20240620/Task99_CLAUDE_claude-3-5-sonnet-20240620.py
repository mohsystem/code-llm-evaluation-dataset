
import re

pattern = r\'^\\d+.*\\.$\'

with open(\'input.txt\', \'r\') as file:
    for line in file:
        line = line.strip()
        if re.match(pattern, line):
            print(line)
