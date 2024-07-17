
def is_pangram(sentence):
    return len(set(char.lower() for char in sentence if char.isalpha())) == 26

# Test cases
print(is_pangram("The quick brown fox jumps over the lazy dog"))  # True
print(is_pangram("This is not a pangram"))  # False
