import random
import smtplib
from email.mime.text import MIMEText

def generate_otp(length=6):
    digits = "0123456789"
    otp = "".join(random.choice(digits) for _ in range(length))
    return otp

def send_otp_email(otp, recipient_email):
    sender_email = "your_email@example.com"  # Replace with your email
    sender_password = "your_password"  # Replace with your email password
    message = MIMEText(f"Your OTP is: {otp}")
    message["Subject"] = "Your Two-Factor Authentication Code"
    message["From"] = sender_email
    message["To"] = recipient_email

    with smtplib.SMTP_SSL("smtp.gmail.com", 465) as server:
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, recipient_email, message.as_string())

def main():
    username = input("Username: ")
    password = input("Password: ")

    # Simulate user authentication (replace with your actual authentication logic)
    if username == "user" and password == "password":
        otp = generate_otp()
        send_otp_email(otp, "recipient@example.com")  # Replace with user's email
        entered_otp = input("Enter OTP received on your email: ")
        if entered_otp == otp:
            print("Two-factor authentication successful. Logged in!")
        else:
            print("Incorrect OTP. Access denied.")
    else:
        print("Invalid username or password.")

if __name__ == "__main__":
    main()