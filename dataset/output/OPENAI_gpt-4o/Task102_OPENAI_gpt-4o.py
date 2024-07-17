import hashlib

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def update_password_in_database(username, hashed_password):
    print(f"Updating password for user: {username}")
    # Database interaction code would go here

def main():
    username = input("Enter username: ")
    password = input("Enter new password: ")
    hashed_password = hash_password(password)
    update_password_in_database(username, hashed_password)

if __name__ == '__main__':
    main()