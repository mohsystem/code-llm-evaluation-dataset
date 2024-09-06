
import os
from cryptography.fernet import Fernet

def generate_key():
    return Fernet.generate_key()

def encrypt_file(file_path, key):
    f = Fernet(key)
    with open(file_path, 'rb') as file:
        file_data = file.read()
    encrypted_data = f.encrypt(file_data)
    with open(file_path + '.encrypted', 'wb') as file:
        file.write(encrypted_data)

def decrypt_file(file_path, key):
    f = Fernet(key)
    with open(file_path, 'rb') as file:
        encrypted_data = file.read()
    decrypted_data = f.decrypt(encrypted_data)
    with open(file_path[:-10], 'wb') as file:
        file.write(decrypted_data)

def main():
    key = generate_key()
    print(f"Generated key: {key}")

    file_path = input("Enter the file path to encrypt: ")
    encrypt_file(file_path, key)
    print(f"File encrypted: {file_path}.encrypted")

    decrypt_choice = input("Do you want to decrypt the file? (y/n): ")
    if decrypt_choice.lower() == 'y':
        decrypt_file(file_path + '.encrypted', key)
        print(f"File decrypted: {file_path}")

if __name__ == "__main__":
    main()
