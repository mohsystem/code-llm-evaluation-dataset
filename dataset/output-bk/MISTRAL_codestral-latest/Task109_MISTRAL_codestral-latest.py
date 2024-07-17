import re

input_str = input("Enter input: ")

# Regex pattern to validate input
regex = "^[a-zA-Z0-9]*$"

if re.match(regex, input_str):
    print("Valid input")
else:
    print("Invalid input")