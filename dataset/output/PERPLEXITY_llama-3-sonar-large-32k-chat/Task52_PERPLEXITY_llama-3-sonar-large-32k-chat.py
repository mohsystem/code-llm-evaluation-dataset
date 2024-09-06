# Python code
def caesar_encrypt(text, shift):
    result = ""

    for char in text:
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            result += chr((ord(char) - ascii_offset + shift) % 26 + ascii_offset)
        else:
            result += char

    return result

def caesar_decrypt(text, shift):
    result = ""

    for char in text:
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            result += chr((ord(char) - ascii_offset - shift) % 26 + ascii_offset)
        else:
            result += char

    return result

def encrypt_file(file_path, shift):
    with open(file_path, 'r') as file:
        text = file.read()
    encrypted_text = caesar_encrypt(text, shift)
    with open(file_path, 'w') as file:
        file.write(encrypted_text)

def decrypt_file(file_path, shift):
    with open(file_path, 'r') as file:
        text = file.read()
    decrypted_text = caesar_decrypt(text, shift)
    with open(file_path, 'w') as file:
        file.write(decrypted_text)

# Example usage
file_path = 'example.txt'
shift = 3
encrypt_file(file_path, shift)
decrypt_file(file_path, shift)