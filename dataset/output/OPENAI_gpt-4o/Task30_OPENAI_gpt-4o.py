def longest(s1, s2):
    return ''.join(sorted(set(s1 + s2)))

a = "xyaabbbccccdefww"
b = "xxxxyyyyabklmopq"
print(longest(a, b))

a = "abcdefghijklmnopqrstuvwxyz"
print(longest(a, a))