def is_pangram(s):
    alphabet = set("abcdefghijklmnopqrstuvwxyz")
    return alphabet <= set(s.lower())

# Example usage
s = "The quick brown fox jumps over the lazy dog"
print(is_pangram(s))  # Output: True