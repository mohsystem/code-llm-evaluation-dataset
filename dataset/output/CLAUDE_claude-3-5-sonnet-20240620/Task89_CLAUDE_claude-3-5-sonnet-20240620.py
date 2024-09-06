
import sys

def check_password(stored_password, entered_password):
    if len(stored_password) != len(entered_password):
        return False
    for s, e in zip(stored_password, entered_password):
        if s != e:
            return False
    return True

def main():
    try:
        with open('password.txt', 'r') as file:
            stored_password = file.read().strip()
    except FileNotFoundError:
        print("Password file not found.")
        sys.exit(1)

    entered_password = input("Enter your password: ")

    if check_password(stored_password, entered_password):
        print("Password correct!")
    else:
        print("Password incorrect.")

if __name__ == "__main__":
    main()
