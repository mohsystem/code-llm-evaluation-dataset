import random
import time

def generate_otp():
    return random.randint(100000, 999999)

def verify_otp(user_otp, actual_otp):
    return user_otp == actual_otp

# Example usage
username = input("Enter username: ")
password = input("Enter password: ")

# Simulate verifying username and password
user_auth = (username == "user" and password == "pass")
if user_auth:
    otp = generate_otp()
    print(f"Your OTP is: {otp}")
    user_otp = int(input("Enter the OTP you received: "))
    if verify_otp(user_otp, otp):
        print("Login successful!")
    else:
        print("Invalid OTP!")
else:
    print("Invalid username or password!")