import re
def clean_phone_number(phone_number):
    cleaned_number = re.sub(r'[^0-9]', '', phone_number)
    if len(cleaned_number) == 11 and cleaned_number[0] == '1':
        return cleaned_number[1:]
    return cleaned_number if len(cleaned_number) == 10 else None

# Example usage:
phone_numbers = [
    "+1 (613)-995-0253",
    "613-995-0253",
    "1 613 995 0253",
    "613.995.0253",
    "123456789012"  # Invalid phone number
]

for number in phone_numbers:
    cleaned_number = clean_phone_number(number)
    if cleaned_number:
        print(f"Original: {number} -> Cleaned: {cleaned_number}")
    else:
        print(f"Invalid phone number: {number}")