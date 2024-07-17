import re

def clean_phone_number(phone):
    phone = re.sub(r'\D', '', phone)
    if phone.startswith('1') and len(phone) == 11:
        phone = phone[1:]
    return phone

numbers = [
    "+1 (613)-995-0253",
    "613-995-0253",
    "1 613 995 0253",
    "613.995.0253"
]

for number in numbers:
    print(clean_phone_number(number))

# Java, C++, and C code will be run using appropriate methods within their respective blocks.