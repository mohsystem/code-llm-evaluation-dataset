import re

def clean_phone_number(phone_number):
    cleaned_number = re.sub(r'\D', '', phone_number)
    if cleaned_number.startswith('1'):
        cleaned_number = cleaned_number[1:]
    return cleaned_number