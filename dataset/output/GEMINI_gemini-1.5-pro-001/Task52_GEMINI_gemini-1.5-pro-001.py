import os
from cryptography.fernet import Fernet

def generate_key():
    """Generates a Fernet key and saves it to a file."""
    key = Fernet.generate_key()
    with open("filekey.key", "wb") as key_file:
        key_file.write(key)

def load_key():
    """Loads the Fernet key from the file."""
    return open("filekey.key", "rb").read()

def encrypt_file(filename, key):
    """Encrypts a file."""
    f = Fernet(key)
    with open(filename, "rb") as file:
        original = file.read()
    encrypted = f.encrypt(original)
    with open(filename + ".enc", "wb") as file:
        file.write(encrypted)
    print(f"Encrypted {filename} to {filename}.enc")

def decrypt_file(filename, key):
    """Decrypts a file."""
    f = Fernet(key)
    with open(filename, "rb") as file:
        encrypted = file.read()
    decrypted = f.decrypt(encrypted)
    with open(filename[:-4], "wb") as file:
        file.write(decrypted)
    print(f"Decrypted {filename} to {filename[:-4]}")

if __name__ == "__main__":
    filename = input("Enter the filename: ")
    
    if not os.path.exists("filekey.key"):
        generate_key()

    key = load_key()

    encrypt_file(filename, key)
    decrypt_file(filename + ".enc", key)