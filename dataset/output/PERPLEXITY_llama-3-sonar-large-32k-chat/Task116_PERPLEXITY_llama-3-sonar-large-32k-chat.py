import os
import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: python privilege_dropper.py <username>")
        return

    # Perform privileged operation
    os.setuid(0)
    os.system("passwd " + sys.argv[1])

    # Drop privileges
    os.setuid(os.getuid())

    # Verify privileges dropped
    os.system("whoami")

if __name__ == "__main__":
    main()