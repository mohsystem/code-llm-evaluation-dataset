
import re

def validate_input(input_string, pattern):
    return re.match(pattern, input_string) is not None

email = input("Enter an email address: ")
email_pattern = r\'^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$\'

if validate_input(email, email_pattern):
    print("Valid email address")
else:
    print("Invalid email address")

phone = input("Enter a phone number (XXX-XXX-XXXX): ")
phone_pattern = r\'^\\d{3}-\\d{3}-\\d{4}$\'

if validate_input(phone, phone_pattern):
    print("Valid phone number")
else:
    print("Invalid phone number")
