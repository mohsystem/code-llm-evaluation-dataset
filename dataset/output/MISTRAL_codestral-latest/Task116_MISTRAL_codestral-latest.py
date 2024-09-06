import os
import pwd
import subprocess

def change_password(username):
    new_password = input(f"Enter new password for {username}: ")
    subprocess.run(['sudo', 'chpasswd'], input=f'{username}:{new_password}', text=True, check=True)

def drop_privileges(uid_name='nobody', gid_name='nogroup'):
    if os.getuid() != 0:
        raise RuntimeError('We need to be root to drop privileges.')

    running_uid = pwd.getpwnam(uid_name).pw_uid
    running_gid = pwd.getpwnam(gid_name).pw_gid

    os.setgid(running_gid)
    os.setuid(running_uid)

username = input("Enter username: ")
change_password(username)
drop_privileges()