def longest(s1, s2):
    return ''.join(sorted(set(s1 + s2)))

print(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"))  # "abcdefklmopqwxy"
print(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"))  # "abcdefghijklmnopqrstuvwxyz"