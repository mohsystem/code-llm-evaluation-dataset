# Python
def encrypt(message, key):
    encrypted_message = ""
    for char in message:
        encrypted_message += chr(ord(char) + key)
    return encrypted_message

message = input("Enter the message: ")
key = int(input("Enter the secret key: "))
encrypted_message = encrypt(message, key)
print("Encrypted message: " + encrypted_message)