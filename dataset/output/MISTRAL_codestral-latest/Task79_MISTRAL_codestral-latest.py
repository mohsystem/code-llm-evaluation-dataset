# Python
def encrypt(message, key):
    cipher = ''
    for char in message:
        if char.isalpha():
            shift = 65 if char.isupper() else 97
            cipher += chr((ord(char) - shift + key) % 26 + shift)
        else:
            cipher += char
    return cipher

message = "HELLO WORLD"
key = 3
encrypted_message = encrypt(message, key)
print(encrypted_message)