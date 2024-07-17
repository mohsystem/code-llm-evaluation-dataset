import re

def validate_python_input():
    input_string = input("Enter a string in Python:
")
    if re.match("^[a-zA-Z0-9]*$", input_string):
        print("Valid Python Input")
    else:
        print("Invalid Python Input")

validate_python_input()