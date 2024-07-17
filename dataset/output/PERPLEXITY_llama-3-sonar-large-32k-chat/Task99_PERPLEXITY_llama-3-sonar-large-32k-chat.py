import re

with open("input.txt", "r") as file:
    pattern = re.compile("^[0-9]+.*\\.$")
    for line in file:
        if pattern.match(line.strip()):
            print(line.strip())