from cryptography.fernet import Fernet

def encrypt_message(message, key):
    """Encrypts a message using a secret key.

    Args:
        message: The message to be encrypted.
        key: The secret key to use for encryption.

    Returns:
        The encrypted message.
    """
    f = Fernet(key)
    encrypted_message = f.encrypt(message.encode())
    return encrypted_message.decode()


if __name__ == "__main__":
    message = "This is a secret message"
    key = Fernet.generate_key()
    encrypted_message = encrypt_message(message, key)
    print(f"Encrypted: {encrypted_message}")