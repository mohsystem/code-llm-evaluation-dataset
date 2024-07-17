import os
import subprocess

def drop_privileges():
    try:
        from pwd import getpwnam
        nobody = getpwnam("nobody")
        os.setgid(nobody.pw_gid)
        os.setuid(nobody.pw_uid)
    except Exception as e:
        print(f"Failed to drop privileges: {e}")

def change_password(username, new_password):
    try:
        process = subprocess.Popen(['sudo', 'passwd', username], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = process.communicate(input=f"{new_password}
{new_password}
".encode())
        if process.returncode != 0:
            print(f"Error changing password: {err.decode()}")
        else:
            print(out.decode())
    except Exception as e:
        print(f"Failed to change password: {e}")

if __name__ == "__main__":
    username = input("Enter the username: ")
    new_password = input("Enter the new password: ")

    change_password(username, new_password)
    drop_privileges()