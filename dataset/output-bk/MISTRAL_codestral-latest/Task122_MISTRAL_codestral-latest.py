# Python

def signup():
    username = input("Enter username: ")
    password = input("Enter password: ")
    # In a real-world application, you would hash the password before storing it.
    # For simplicity, we're storing it as is.
    with open("passwords.txt", "a") as file:
        file.write(f"{username}:{password}
")

signup()