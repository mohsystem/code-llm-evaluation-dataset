import re

def clean_number(number):
    number = re.sub(r'[^0-9]', '', number)
    if number.startswith('1') and len(number) == 11:
        number = number[1:]
    return number

numbers = ['+1 (613)-995-0253', '613-995-0253', '1 613 995 0253', '613.995.0253']
cleaned_numbers = [clean_number(num) for num in numbers]
print(cleaned_numbers)