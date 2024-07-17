def main():
    input_str = "HelloWorld"
    shift = 3
    encrypted = []
    
    for char in input_str:
        if char.isalpha():
            base = 'a' if char.islower() else 'A'
            encrypted.append(chr((ord(char) - ord(base) + shift) % 26 + ord(base)))
        else:
            encrypted.append(char)
    
    print("Python:", ''.join(encrypted))
    
main()