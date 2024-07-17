
def encrypt(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            ascii_offset = ord(\'A\') if char.isupper() else ord(\'a\')
            result += chr((ord(char) - ascii_offset + shift) % 26 + ascii_offset)
        else:
            result += char
    return result

text = input("Enter a string to encrypt: ")
shift = int(input("Enter the shift value: "))
encrypted = encrypt(text, shift)
print("Encrypted string:", encrypted)
