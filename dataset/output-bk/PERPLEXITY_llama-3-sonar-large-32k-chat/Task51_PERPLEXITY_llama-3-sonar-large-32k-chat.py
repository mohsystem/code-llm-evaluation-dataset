def encrypt(str):
    return ''.join(chr(ord(c) + 3) for c in str)

str = "Hello, World!"
print("Original:", str)
encrypted = encrypt(str)
print("Encrypted:", encrypted)