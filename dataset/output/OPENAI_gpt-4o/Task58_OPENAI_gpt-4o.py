def XO(s):
    s = s.lower()
    return s.count('x') == s.count('o')

# Example usage
print(XO("ooxx"))  # True
print(XO("xooxx"))  # False
print(XO("ooxXm"))  # True
print(XO("zpzpzpp"))  # True
print(XO("zzoo"))  # False