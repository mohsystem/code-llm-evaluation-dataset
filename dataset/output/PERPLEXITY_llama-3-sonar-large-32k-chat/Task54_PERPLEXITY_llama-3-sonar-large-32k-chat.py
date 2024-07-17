import random
import time

otp = random.randint(100000, 999999)

username = input("Enter username: ")
password = input("Enter password: ")

if username == "admin" and password == "password":
    print("One Time Password (OTP) is:", otp)
    user_otp = int(input("Enter OTP: "))

    if user_otp == otp:
        print("Login successful!")
    else:
        print("Invalid OTP. Login failed.")
else:
    print("Invalid username or password. Login failed.")