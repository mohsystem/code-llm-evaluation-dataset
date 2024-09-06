def is_isogram(string):
    string = string.lower()
    return len(string) == len(set(string))

print(is_isogram("Dermatoglyphics"))  # True
print(is_isogram("aba"))  # False
print(is_isogram("moOse"))  # False