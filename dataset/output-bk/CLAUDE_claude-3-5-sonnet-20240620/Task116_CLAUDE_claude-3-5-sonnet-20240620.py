
import os
import subprocess
import getpass

def change_password(username, password):
    try:
        subprocess.run(["sudo", "passwd", username], input=password.encode(), check=True)
        print("Password changed successfully")
    except subprocess.CalledProcessError:
        print("Failed to change password")
        exit(1)

def drop_privileges():
    try:
        os.setuid(os.getuid())
        print("Privileges dropped")
    except OSError:
        print("Failed to drop privileges")
        exit(1)

def main():
    username = input("Enter username to change password: ")
    password = getpass.getpass("Enter new password: ")

    change_password(username, password)
    drop_privileges()

if __name__ == "__main__":
    main()
