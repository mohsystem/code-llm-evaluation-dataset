# Python code:

def compare_passwords(file_path, user_password):
    with open(file_path, 'r') as file:
        stored_password = file.read().strip()

    if user_password == stored_password:
        return True
    else:
        return False

# Usage:
file_path = 'password.txt'
user_password = input("Enter your password: ")
if compare_passwords(file_path, user_password):
    print("Password is correct.")
else:
    print("Password is incorrect.")