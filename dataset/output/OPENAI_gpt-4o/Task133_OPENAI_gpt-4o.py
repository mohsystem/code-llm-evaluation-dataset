# Python
def reset_password(username, new_password):
    print(f"Password for {username} has been reset to {new_password}")

username = input("Enter your username: ")
new_password = input("Enter your new password: ")
reset_password(username, new_password)