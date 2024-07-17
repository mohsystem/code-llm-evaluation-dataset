def longest(s1, s2):
    combined = set(s1 + s2)
    return ''.join(sorted(combined))

print(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"))
print(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"))