import os
from cryptography.fernet import Fernet

def generate_key():
    """Generates a new Fernet key."""
    key = Fernet.generate_key()
    return key

def save_key(key, filename='secret.key'):
    """Saves a key to a file."""
    with open(filename, 'wb') as f:
        f.write(key)

def load_key(filename='secret.key'):
    """Loads a key from a file."""
    return open(filename, 'rb').read()

def encrypt_message(message, key):
    """Encrypts a message."""
    f = Fernet(key)
    encrypted_message = f.encrypt(message.encode())
    return encrypted_message

def decrypt_message(encrypted_message, key):
    """Decrypts a message."""
    f = Fernet(key)
    decrypted_message = f.decrypt(encrypted_message).decode()
    return decrypted_message

def main():
    """Main function."""
    while True:
        print("
Choose an option:")
        print("1. Generate a new key")
        print("2. Load an existing key")
        print("3. Encrypt a message")
        print("4. Decrypt a message")
        print("5. Exit")

        choice = input("
Enter your choice: ")

        if choice == '1':
            key = generate_key()
            save_key(key)
            print(f"Key generated and saved to 'secret.key'")
        elif choice == '2':
            try:
                key = load_key()
                print("Key loaded successfully!")
            except FileNotFoundError:
                print("Key file not found!")
        elif choice == '3':
            try:
                message = input("Enter the message to encrypt: ")
                key = load_key()
                encrypted_message = encrypt_message(message, key)
                print("Encrypted message:", encrypted_message)
            except FileNotFoundError:
                print("Key file not found!")
        elif choice == '4':
            try:
                encrypted_message = input("Enter the message to decrypt: ")
                key = load_key()
                decrypted_message = decrypt_message(encrypted_message.encode(), key)
                print("Decrypted message:", decrypted_message)
            except FileNotFoundError:
                print("Key file not found!")
        elif choice == '5':
            break
        else:
            print("Invalid choice!")

if __name__ == "__main__":
    main()