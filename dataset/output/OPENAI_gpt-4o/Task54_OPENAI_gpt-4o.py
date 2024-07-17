import random

def main():
    username = "user"
    password = "password"
    
    input_username = input("Enter username:
")
    input_password = input("Enter password:
")

    if input_username == username and input_password == password:
        # Generate OTP
        otp = random.randint(0, 999999)
        print(f"Generated OTP: {otp:06d}")
        input_otp = int(input("Enter OTP:
"))

        if input_otp == otp:
            print("Login Successful")
        else:
            print("Invalid OTP")
    else:
        print("Invalid username or password")

if __name__ == "__main__":
    main()