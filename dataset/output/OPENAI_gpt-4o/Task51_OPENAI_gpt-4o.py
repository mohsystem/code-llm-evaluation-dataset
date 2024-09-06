def encrypt(text):
    result = ""
    for char in text:
        if char.isupper():
            result += chr((ord(char) + 1 - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) + 1 - 97) % 26 + 97)
        else:
            result += char
    return result

input_text = "HelloWorld"
encrypted_text = encrypt(input_text)
print(encrypted_text)