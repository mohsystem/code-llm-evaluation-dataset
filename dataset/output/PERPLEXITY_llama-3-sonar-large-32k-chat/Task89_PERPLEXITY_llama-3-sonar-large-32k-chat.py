def check_password():
    password_file = open("password.txt", "r")
    stored_password = password_file.read()
    password_file.close()
    user_password = input("Enter your password: ")
    if len(stored_password) != len(user_password):
        print("Password does not match")
    else:
        for i in range(len(stored_password)):
            if stored_password[i] != user_password[i]:
                print("Password does not match")
                return
        print("Password matches")

check_password()