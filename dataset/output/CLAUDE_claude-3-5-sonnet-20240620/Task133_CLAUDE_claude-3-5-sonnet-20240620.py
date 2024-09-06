
import random
import string

def generate_password(length=12):
    characters = string.ascii_letters + string.digits + string.punctuation
    return ''.join(random.choice(characters) for _ in range(length))

def reset_password(username):
    new_password = generate_password()
    print(f"Password for {username} has been reset.")
    print(f"New password: {new_password}")
    # In a real system, you would hash and save this password securely
    return new_password

def main():
    username = input("Enter username to reset password: ")
    reset_password(username)

if __name__ == "__main__":
    main()
