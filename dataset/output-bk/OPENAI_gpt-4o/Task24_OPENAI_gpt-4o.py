# Python code
import re

def validate_pin(pin):
    return bool(re.fullmatch(r'\d{4}|\d{6}', pin))

# Test cases
print(validate_pin("1234"))   # True
print(validate_pin("12345"))  # False
print(validate_pin("a234"))   # False