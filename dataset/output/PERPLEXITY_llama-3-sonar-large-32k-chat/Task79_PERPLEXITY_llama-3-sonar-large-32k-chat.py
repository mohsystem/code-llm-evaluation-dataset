def create_cipher(secret_key):
    return secret_key * 10

def encrypt_message(message, cipher):
    encrypted_message = ""
    for i in range(len(message)):
        encrypted_message += chr(ord(message[i]) + ord(cipher[i % len(cipher)]))
    return encrypted_message

message = "Hello, World!"
secret_key = "mySecretKey"
cipher = create_cipher(secret_key)
encrypted_message = encrypt_message(message, cipher)
print("Encrypted Message:", encrypted_message)