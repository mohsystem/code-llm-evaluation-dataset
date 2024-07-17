def signup():
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    confirm_password = input("Confirm your password: ")
    if password == confirm_password:
        with open("users.txt", "a") as file:
            file.write(f"{username}:{password}
")
        print("Signup successful!")
    else:
        print("Passwords don't match. Please try again.")

signup()