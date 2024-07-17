# Python
import getpass

def reset_password():
    current_password = getpass.getpass("Enter your current password: ")
    new_password = getpass.getpass("Enter your new password: ")
    confirm_password = getpass.getpass("Confirm your new password: ")

    if new_password == confirm_password:
        print("Password reset successful.")
    else:
        print("Passwords do not match. Password reset failed.")

reset_password()