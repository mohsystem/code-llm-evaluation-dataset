
def longest(s1, s2):
    return ''.join(sorted(set(s1 + s2)))

# Test cases
print(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"))
print(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"))
