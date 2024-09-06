import re

def match_lines(file_path):
    with open(file_path, 'r') as file:
        for line in file:
            if re.match(r'^\d.*\.$', line):
                print(line.strip())