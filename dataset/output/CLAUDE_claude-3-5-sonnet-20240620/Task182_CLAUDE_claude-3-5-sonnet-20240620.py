
def clean_phone_number(phone):
    digits = ''.join(filter(str.isdigit, phone))
    if len(digits) == 11 and digits.startswith('1'):
        return digits[1:]
    elif len(digits) == 10:
        return digits
    else:
        raise ValueError("Invalid phone number")

# Example usage
try:
    print(clean_phone_number("+1 (613)-995-0253"))
    print(clean_phone_number("613-995-0253"))
    print(clean_phone_number("1 613 995 0253"))
    print(clean_phone_number("613.995.0253"))
except ValueError as e:
    print(f"Error: {e}")
