
import os
import pwd
import subprocess
import sys

def drop_privileges(uid_name='nobody', gid_name='nogroup'):
    if os.getuid() != 0:
        raise RuntimeError("This function must be run as root.")

    # Get the uid/gid from the name
    running_uid = pwd.getpwnam(uid_name).pw_uid
    running_gid = pwd.getpwnam(gid_name).pw_gid

    # Remove group privileges
    os.setgroups([])

    # Try setting the new uid/gid
    os.setgid(running_gid)
    os.setuid(running_uid)

    # Ensure a very conservative umask
    old_umask = os.umask(0o077)

def change_password(username, new_password):
    try:
        subprocess.run(['passwd', username], input=f'{new_password}\\n{new_password}\\n', 
                       capture_output=True, text=True, check=True)
        print(f"Password for {username} changed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Failed to change password: {e.stderr}")

if __name__ == "__main__":
    if os.geteuid() != 0:
        print("This script must be run as root.")
        sys.exit(1)

    username = input("Enter username to change password: ")
    new_password = input("Enter new password: ")

    change_password(username, new_password)

    print("Dropping privileges...")
    drop_privileges()
    print("Privileges dropped. Continuing with reduced permissions.")

    # Rest of the program runs with reduced privileges
    print("Program continues with reduced privileges...")
