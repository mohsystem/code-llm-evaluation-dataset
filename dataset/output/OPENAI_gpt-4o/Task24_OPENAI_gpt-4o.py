def validate_pin(pin):
    if len(pin) == 4 or len(pin) == 6:
        return pin.isdigit()
    return False

print(validate_pin("1234"))  # true
print(validate_pin("12345")) # false
print(validate_pin("a234"))  # false