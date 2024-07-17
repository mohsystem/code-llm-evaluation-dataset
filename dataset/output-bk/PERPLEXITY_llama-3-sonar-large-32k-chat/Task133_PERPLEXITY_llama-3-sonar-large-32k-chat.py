def password_reset():
    username = input("Enter your username: ")
    old_password = input("Enter your old password: ")
    new_password = input("Enter your new password: ")
    confirm_password = input("Confirm your new password: ")

    if new_password == confirm_password:
        print("Password reset successfully!")
    else:
        print("New password and confirm password do not match. Please try again.")

password_reset()