def is_pangram(s):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    for char in alphabet:
        if char not in s.lower():
            return False
    return True

print(is_pangram("The quick brown fox jumps over the lazy dog"))  # True
print(is_pangram("Hello World"))  # False