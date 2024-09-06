def encrypt_string(input_string, key):
    encrypted_string = ""
    for char in input_string:
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            encrypted_string += chr((ord(char) - ascii_offset + key) % 26 + ascii_offset)
        else:
            encrypted_string += char
    return encrypted_string

input_string = "HELLO WORLD"
key = 3
encrypted_string = encrypt_string(input_string, key)
print(encrypted_string)