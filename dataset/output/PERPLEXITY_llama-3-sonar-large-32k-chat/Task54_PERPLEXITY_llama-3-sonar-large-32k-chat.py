import random
import time

def generate_otp():
    return str(random.randint(100000, 999999))

def authenticate(username, password, otp):
    if username == "admin" and password == "password" and otp == generate_otp():
        return "Authentication successful"
    else:
        return "Authentication failed"

username = input("Enter username: ")
password = input("Enter password: ")
otp = input("Enter OTP: ")
print(authenticate(username, password, otp))