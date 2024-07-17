import random

def authenticate(username, password):
    # Simulated authentication function (replace with actual database check)
    return username == "user" and password == "password"

def generate_otp():
    # Generate a random 6-digit OTP
    return random.randint(100000, 999999)

if __name__ == "__main__":
    username = input("Enter username: ")
    password = input("Enter password: ")

    if authenticate(username, password):
        otp = generate_otp()
        print("One-Time Password:", otp)

        entered_otp = int(input("Enter OTP: "))

        if entered_otp == otp:
            print("Two-factor authentication successful. Access granted!")
        else:
            print("Incorrect OTP. Access denied!")
    else:
        print("Invalid username or password. Access denied!")