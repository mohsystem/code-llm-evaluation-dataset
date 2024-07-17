def encrypt(message):
    encrypted = ""
    for c in message:
        encrypted += chr(ord(c) + 3)  # Simple Caesar cipher with a shift of 3
    return encrypted


if __name__ == "__main__":
    message = input("Enter a string to encrypt: ")
    encrypted_message = encrypt(message)
    print("Encrypted message:", encrypted_message)