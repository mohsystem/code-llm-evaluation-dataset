def encrypt(text, key):
    result = ''
    for i in range(len(text)):
        char = text[i]
        if char.isalpha():
            start = ord('a') if char.islower() else ord('A')
            shifted_char = chr((ord(char) - start + key) % 26 + start)
        elif char.isdigit():
            shifted_char = str((int(char) + key) % 10)
        else:
            shifted_char = char
        result += shifted_char
    return result

# Example usage (modify input and key as needed)
input_string = "Hello, world 123!"
encryption_key = 3
encrypted_string = encrypt(input_string, encryption_key)
print("Encrypted:", encrypted_string)