import re

with open("file.txt", "r") as file:
    for line in file:
        if re.match(r"^[0-9].*\.$", line):
            print(line)