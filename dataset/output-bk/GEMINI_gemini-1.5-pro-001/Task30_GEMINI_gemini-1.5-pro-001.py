def longest(s1, s2):
    seen = set()
    result = []
    for c in s1 + s2:
        if c not in seen:
            result.append(c)
            seen.add(c)
    return ''.join(sorted(result))


print(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq"))
print(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"))