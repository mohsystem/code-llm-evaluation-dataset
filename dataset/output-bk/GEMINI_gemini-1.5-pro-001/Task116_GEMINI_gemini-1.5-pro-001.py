import os
import pwd
import crypt
import sys

def drop_privileges(user_uid, user_gid):
    os.setgid(user_gid)
    os.setuid(user_uid)

def main():
    if os.geteuid() != 0:
        print("This script requires root privileges. Please run with sudo.")
        sys.exit(1)

    username = input("Enter the username: ")
    password = input("Enter the new password: ")

    try:
        user = pwd.getpwnam(username)
    except KeyError:
        print(f"User '{username}' not found.")
        sys.exit(1)

    encrypted_password = crypt.crypt(password, crypt.mksalt(crypt.METHOD_SHA512))

    try:
        with open(f'/etc/shadow', 'r+') as shadow_file:
            lines = shadow_file.readlines()
            for i, line in enumerate(lines):
                if line.startswith(username + ':'):
                    parts = line.split(':')
                    parts[1] = encrypted_password
                    lines[i] = ':'.join(parts) + '
'
                    break
            else:
                print(f"User '{username}' not found in shadow file.")
                sys.exit(1)

            shadow_file.seek(0)
            shadow_file.writelines(lines)
            shadow_file.truncate()

        print(f"Password for user '{username}' changed successfully.")

    except Exception as e:
        print(f"An error occurred: {e}")
        sys.exit(1)

    drop_privileges(user.pw_uid, user.pw_gid)

    print(f"Running as user: {os.getlogin()}")

if __name__ == '__main__':
    main()