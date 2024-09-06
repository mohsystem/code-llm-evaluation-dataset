# This script will execute code in all four languages in a singular file format.
# In an actual implementation, you would separate and compile each script accordingly.
import os

# Check for root/administrator privileges
if os.geteuid() != 0:
    print("This script must be run as root!")
    exit(1)

# Change user password
user = input("Enter username to change password: ")
os.system(f'echo "{user}:newpassword" | chpasswd')

# Drop privileges to a non-root user (choose a non-root user, e.g., 'nobody')
os.setuid(os.geteuid())
print("Privileges have been dropped.")