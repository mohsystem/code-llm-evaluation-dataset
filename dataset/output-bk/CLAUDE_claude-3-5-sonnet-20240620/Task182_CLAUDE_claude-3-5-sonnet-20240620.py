
import re

def clean_phone_number(phone):
    # Remove all non-digit characters
    cleaned = re.sub(r\'\\D\', \'\', phone)
    
    # Remove country code if present
    if len(cleaned) == 11 and cleaned.startswith(\'1\'):
        cleaned = cleaned[1:]
    
    # Check if the number is valid
    if len(cleaned) != 10 or not cleaned.startswith((\'2\', \'3\', \'4\', \'5\', \'6\', \'7\', \'8\', \'9\')):
        raise ValueError("Invalid phone number")
    
    return cleaned

# Test the function
test_numbers = [
    "+1 (613)-995-0253",
    "613-995-0253",
    "1 613 995 0253",
    "613.995.0253"
]

for number in test_numbers:
    try:
        print(clean_phone_number(number))
    except ValueError as e:
        print(f"Error: {e}")
