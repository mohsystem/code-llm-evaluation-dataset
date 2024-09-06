code here:
def create_cipher(key):
    cipher = {}
    for i in range(26):
        cipher[chr(65+i)] = chr(65+(i+key)%26)
        cipher[chr(97+i)] = chr(97+(i+key)%26)
    return cipher

def encrypt_message(message, key):
    cipher = create_cipher(key)
    encrypted_message = ""
    for char in message:
        if char in cipher:
            encrypted_message += cipher[char]
        else:
            encrypted_message += char
    return encrypted_message

key = 3
message = "Hello, World!"
print("Original Message:", message)
print("Encrypted Message:", encrypt_message(message, key))