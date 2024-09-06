import random
import string

def generate_otp():
    return ''.join(random.choices(string.digits, k=6))

def login(username, password, otp):
    # Here you would normally check the username and password against a database
    # For this example, we'll just assume they're correct
    if username == 'user' and password == 'password':
        if otp == generate_otp():
            return 'Login successful'
        else:
            return 'Invalid OTP'
    else:
        return 'Invalid username or password'

# Example usage:
print(login('user', 'password', generate_otp()))