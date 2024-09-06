
def encrypt(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            result += chr((ord(char) - ascii_offset + shift) % 26 + ascii_offset)
        else:
            result += char
    return result

text = input("Enter text to encrypt: ")
shift = int(input("Enter shift value: "))
encrypted_text = encrypt(text, shift)
print("Encrypted text:", encrypted_text)
