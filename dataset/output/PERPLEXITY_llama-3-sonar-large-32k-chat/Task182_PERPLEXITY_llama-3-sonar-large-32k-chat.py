import re

def clean_phone_number(phone_number):
    return re.sub(r'[^\d]', '', phone_number).lstrip('1')

print(clean_phone_number('+1 (613)-995-0253'))
print(clean_phone_number('613-995-0253'))
print(clean_phone_number('1 613 995 0253'))
print(clean_phone_number('613.995.0253'))