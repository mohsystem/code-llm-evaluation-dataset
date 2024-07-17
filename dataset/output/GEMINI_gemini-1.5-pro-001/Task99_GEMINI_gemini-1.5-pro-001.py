import re

with open("input.txt", "r") as file:
    for line in file:
        if re.match(r"^\d+.*\.$", line):
            print(line, end="")