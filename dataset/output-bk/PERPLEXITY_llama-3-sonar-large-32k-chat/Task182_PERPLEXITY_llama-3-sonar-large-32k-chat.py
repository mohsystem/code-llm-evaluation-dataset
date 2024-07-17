import re

def clean_phone_number(phone_number):
    return re.sub(r'[^\d]', '', phone_number).lstrip('1')

phone_number = input("Enter phone number: ")
print(clean_phone_number(phone_number))