
import random
import string
import time

def generate_otp():
    return ''.join(random.choices(string.digits, k=6))

def send_otp(otp):
    print(f"OTP sent: {otp}")

def verify_otp(user_otp, generated_otp):
    return user_otp == generated_otp

def login():
    username = input("Enter username: ")
    password = input("Enter password: ")
    
    if username == "user" and password == "password":
        otp = generate_otp()
        send_otp(otp)
        
        user_otp = input("Enter OTP: ")
        if verify_otp(user_otp, otp):
            print("Login successful!")
        else:
            print("Invalid OTP. Login failed.")
    else:
        print("Invalid username or password.")

if __name__ == "__main__":
    login()
