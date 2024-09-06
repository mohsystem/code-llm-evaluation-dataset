from cryptography.fernet import Fernet

def generate_key():
    """
    Generates a Fernet key and saves it to a file.
    """
    key = Fernet.generate_key()
    with open("secret.key", "wb") as key_file:
        key_file.write(key)

def load_key():
    """
    Loads the Fernet key from a file.
    """
    return open("secret.key", "rb").read()

def encrypt_file(filename, key):
    """
    Encrypts a file using the Fernet library.
    """
    f = Fernet(key)
    with open(filename, "rb") as file:
        original_data = file.read()
    encrypted_data = f.encrypt(original_data)
    with open(filename, "wb") as file:
        file.write(encrypted_data)

def decrypt_file(filename, key):
    """
    Decrypts a file using the Fernet library.
    """
    f = Fernet(key)
    with open(filename, "rb") as file:
        encrypted_data = file.read()
    decrypted_data = f.decrypt(encrypted_data)
    with open(filename, "wb") as file:
        file.write(decrypted_data)

if __name__ == "__main__":
    generate_key()
    key = load_key()

    filename = "test.txt"
    encrypt_file(filename, key)
    print(f"Encrypted file: {filename}")

    decrypt_file(filename, key)
    print(f"Decrypted file: {filename}")