
import random

def encrypt_message(message, key):
    cipher = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    random.seed(key)
    random.shuffle(cipher)
    
    encrypted = ''
    for char in message.upper():
        if char.isalpha():
            index = ord(char) - ord('A')
            encrypted += cipher[index]
        else:
            encrypted += char
    
    return encrypted

# Example usage
message = "Hello, World!"
key = 42
encrypted = encrypt_message(message, key)
print(f"Original: {message}")
print(f"Encrypted: {encrypted}")
