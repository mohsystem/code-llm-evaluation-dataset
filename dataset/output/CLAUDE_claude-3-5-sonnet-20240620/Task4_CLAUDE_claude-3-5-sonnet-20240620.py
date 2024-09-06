
def is_isogram(string):
    return len(set(string.lower())) == len(string)
    
# Test cases
print(is_isogram("Dermatoglyphics"))  # True
print(is_isogram("aba"))  # False
print(is_isogram("moOse"))  # False
