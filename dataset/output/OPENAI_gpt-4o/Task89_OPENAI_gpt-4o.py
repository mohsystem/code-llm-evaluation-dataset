import os

password = "correctpassword"
with open('password.txt', 'w') as file:
    file.write(password)

def check_password(input_password):
    with open('password.txt', 'r') as file:
        stored_password = file.read()
    
    if len(stored_password) != len(input_password):
        return False
    
    for i in range(len(stored_password)):
        if stored_password[i] != input_password[i]:
            return False
    return True

user_input = input("Enter your password: ")
if check_password(user_input):
    print("Password is correct")
else:
    print("Password is incorrect")