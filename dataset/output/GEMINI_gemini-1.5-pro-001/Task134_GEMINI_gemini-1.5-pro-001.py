from cryptography.fernet import Fernet

def generate_key():
    """Generates a new Fernet key and saves it to a file."""
    key = Fernet.generate_key()
    with open("secret.key", "wb") as key_file:
        key_file.write(key)

def load_key():
    """Loads the Fernet key from a file."""
    return open("secret.key", "rb").read()

def encrypt_message(message, key):
    """Encrypts a message using the provided Fernet key."""
    f = Fernet(key)
    encrypted_message = f.encrypt(message.encode())
    return encrypted_message.decode()

def decrypt_message(encrypted_message, key):
    """Decrypts a message using the provided Fernet key."""
    f = Fernet(key)
    decrypted_message = f.decrypt(encrypted_message.encode())
    return decrypted_message.decode()

if __name__ == "__main__":
    while True:
        print("\nCryptographic Key Manager:")
        print("1. Generate a new key")
        print("2. Encrypt a message")
        print("3. Decrypt a message")
        print("4. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            generate_key()
            print("New key generated and saved to 'secret.key'")
        elif choice == '2':
            message = input("Enter the message to encrypt: ")
            key = load_key()
            encrypted_message = encrypt_message(message, key)
            print("Encrypted message:", encrypted_message)
        elif choice == '3':
            encrypted_message = input("Enter the message to decrypt: ")
            key = load_key()
            decrypted_message = decrypt_message(encrypted_message, key)
            print("Decrypted message:", decrypted_message)
        elif choice == '4':
            break
        else:
            print("Invalid choice. Please try again.")