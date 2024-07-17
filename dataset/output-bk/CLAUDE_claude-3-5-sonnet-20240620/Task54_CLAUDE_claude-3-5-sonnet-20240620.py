
import random

users = {}
otps = {}

def generate_otp():
    return f"{random.randint(0, 999999):06d}"

# Register a user
username = input("Register - Enter username: ")
password = input("Enter password: ")
users[username] = password

# Login
login_username = input("Login - Enter username: ")
login_password = input("Enter password: ")

if login_username in users and users[login_username] == login_password:
    otp = generate_otp()
    otps[login_username] = otp
    print(f"OTP sent: {otp}")

    entered_otp = input("Enter OTP: ")

    if otps[login_username] == entered_otp:
        print("Login successful!")
    else:
        print("Invalid OTP. Login failed.")
else:
    print("Invalid username or password.")
