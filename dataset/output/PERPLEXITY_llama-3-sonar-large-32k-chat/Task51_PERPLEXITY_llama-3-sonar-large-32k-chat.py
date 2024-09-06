def encrypt(text, shift):
    result = ""

    for char in text:
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            result += chr((ord(char) - ascii_offset + shift) % 26 + ascii_offset)
        else:
            result += char

    return result

text = "Hello, World!"
shift = 3
print("Text : " + text)
print("Shift : " + str(shift))
print("Cipher: " + encrypt(text, shift))