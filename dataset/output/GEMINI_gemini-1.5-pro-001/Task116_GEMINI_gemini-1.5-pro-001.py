import os
import pwd
import spwd
import crypt
import getpass

def drop_privileges(user_uid, user_gid):
    os.setgid(user_gid)
    os.setuid(user_uid)

def main():
    if os.geteuid() != 0:
        print("This script requires root privileges. Please run with sudo.")
        return

    try:
        # Get target username from user input
        username = input("Enter the username to change password for: ")

        # Get the user's UID and GID
        user_info = pwd.getpwnam(username)
        user_uid = user_info.pw_uid
        user_gid = user_info.pw_gid

        # Get new password securely
        while True:
            password = getpass.getpass("Enter new password: ")
            confirm_password = getpass.getpass("Confirm new password: ")
            if password == confirm_password:
                break
            else:
                print("Passwords do not match. Please try again.")

        # Hash the new password
        hashed_password = crypt.crypt(password, crypt.mksalt(crypt.METHOD_SHA512))

        # Update password in shadow password database
        spwd.getspnam(username).sp_pwd = hashed_password

        # Drop privileges to the target user
        drop_privileges(user_uid, user_gid)

        print(f"Password for user {username} changed successfully.")

    except KeyError:
        print(f"User '{username}' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()