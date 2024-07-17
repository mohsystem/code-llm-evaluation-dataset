import re

def match_lines(file_name):
    pattern = re.compile(r"^[0-9].*\.$")
    
    with open(file_name, 'r') as file:
        for line in file:
            if pattern.match(line):
                print(line, end='')

if __name__ == "__main__":
    file_name = "input.txt"
    match_lines(file_name)