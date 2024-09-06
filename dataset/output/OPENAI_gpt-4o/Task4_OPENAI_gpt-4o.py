def is_isogram(s):
    s = s.lower()
    return len(s) == len(set(s))

# Test cases
print(is_isogram("Dermatoglyphics"))  # True
print(is_isogram("aba"))              # False
print(is_isogram("moOse"))            # False