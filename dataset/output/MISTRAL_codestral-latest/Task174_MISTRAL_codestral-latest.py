def shortest_palindrome(s: str) -> str:
    i = 0
    for j in range(len(s) - 1, -1, -1):
        if s[i] == s[j]:
            i += 1
    if i == len(s):
        return s
    suffix = s[i:]
    prefix = suffix[::-1]
    return prefix + shortest_palindrome(s[:i]) + suffix