import os
import getpass

def drop_privileges(uid, gid):
    os.setgid(gid)
    os.setuid(uid)

def main():
    username = input("Enter username: ")
    password = getpass.getpass("Enter new password: ")
    os.system(f"echo '{password}' | sudo -S passwd {username}")
    drop_privileges(1001, 1001)  # replace with desired uid and gid

if __name__ == "__main__":
    main()