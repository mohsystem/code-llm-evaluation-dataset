def is_isogram(string):
    string = string.lower()
    return len(string) == len(set(string))

print(is_isogram("Dermatoglyphics")) # true
print(is_isogram("aba")) # false
print(is_isogram("moOse")) # false