def reset_password():
    while True:
        current_password = input("Enter your current password: ")
        if current_password == "password123":
            break
        else:
            print("Incorrect password. Please try again.")

    while True:
        new_password = input("Enter your new password: ")
        confirm_password = input("Confirm your new password: ")
        if new_password == confirm_password:
            print("Password reset successful.")
            break
        else:
            print("Passwords don't match. Please try again.")

reset_password()