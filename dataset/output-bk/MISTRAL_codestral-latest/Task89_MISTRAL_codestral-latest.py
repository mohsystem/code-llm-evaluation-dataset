input_password = input("Enter password: ")

try:
    with open("password.txt", "r") as file:
        stored_password = file.readline().strip()
        if input_password == stored_password:
            print("Password is correct.")
        else:
            print("Password is incorrect.")
except FileNotFoundError:
    print("An error occurred while reading the file.")